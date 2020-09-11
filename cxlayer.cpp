#include "cxlayer.h"
#include <QLinearGradient>
#include <QColor>
#include <QBrush>
#include "common.h"
#include <QFileInfo>

#define LAYERITEMHEIGHT 40

//////////////////////////////////////////////////////////////////////////
CxLayerItemWidget::CxLayerItemWidget()
{
	ui.setupUi(this) ;
	ui.lbl_preview->setMyPixmap(QPixmap("D://1.jpg")) ;
	setFixedHeight(LAYERITEMHEIGHT) ;
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding) ;

	ui.lbl_rank->hide() ;
	ui.lbl_preview->hide() ;
	ui.lbl_path->setFont(QFont("Impact",11)) ;
	ui.lbl_path->setAlignment(Qt::AlignCenter) ;
}

void CxLayerItemWidget::setRank( int id )
{
	ui.lbl_rank->setText(QString::number(id)) ;
}

void CxLayerItemWidget::onSelect( bool on )
{
/*
	QFont f = ui.lbl_path->font() ;
	f.setItalic(on) ;
	ui.lbl_path->setFont(f) ;
	*/
	if( on ) {
		ui.lbl_path->setStyleSheet("color:yellow;") ;
		ui.lbl_rank->setStyleSheet("color:yellow;") ;
	}
	else
	{
		ui.lbl_path->setStyleSheet("color:white;") ;
		ui.lbl_rank->setStyleSheet("color:white;") ;
	}
}

//////////////////////////////////////////////////////////////////////////
CxLayerItem::CxLayerItem(QString str, int dur)
	:QListWidgetItem()
{
	m_w = new CxLayerItemWidget ;
	m_fileName = str ;
	m_w->setToolTip(str) ;
	m_st = 0 ;
	m_en = 1 ;
//	setFade(false) ;
	connect( m_w->form().tb_fade, SIGNAL(clicked(bool)), this, SLOT(setFade(bool))) ;
	m_scene = new CxGraphicsScene ;
	m_scene->setVideoPath(str) ;
	m_w->form().lbl_path->setText(QFileInfo(str).fileName()) ;
	if( str.contains("tmp/") && str.length() == 44 )
	{
		// means uuid mp3 so PLAIN INTRO
		m_w->form().lbl_path->setText("PLAIN INTRO") ;
	}
	initVar(dur) ;
}

int CxLayerItem::totalPlayTime()
{
	return getMSec(m_endTime)-getMSec(m_startTime) ;
}

void CxLayerItem::setSegmentPos( qreal st, qreal en )
{
	m_st = st ;
	m_en = en ;
	m_startTime = getTime(getMSec(m_totTime)*m_st) ;
	m_endTime = getTime(getMSec(m_totTime)*m_en) ;
	m_scene->setVideoRange(getMSec(m_startTime), getMSec(m_endTime)) ;
}

void CxLayerItem::setFade( bool on )
{
//	on = m_w->form().tb_fade->isChecked() ;
//	m_w->form().tb_fade->setText(on?"|":"/") ;
	m_scene->setFadeEffect(on) ;
//	m_w->form().tb_fade->setChecked(on) ;
}

void CxLayerItem::initVar( int dur )
{
	m_totTime = QTime(0,0,0,0) ;
	int totMSec = 10000 ;
	if( dur != -1 ) totMSec = dur ;
	else
	{
		VideoCapture cap(m_fileName.toStdString()) ;
		Mat img ;
		if( cap.isOpened() ) {
			totMSec = 1000*cap.get(CV_CAP_PROP_FRAME_COUNT)/cap.get(CV_CAP_PROP_FPS) ;
//			QMessageBox::information(NULL,"",QString("%1 %2").arg(cap.get(7)).arg(cap.get(CV_CAP_PROP_FPS))) ;
			cap.set(CV_CAP_PROP_POS_MSEC,totMSec>100?100:totMSec-1) ;
			cap.read(img), cap.release() ;
			m_thumbnail = Mat2QImage(img) ;
			m_videoSize = m_thumbnail.size() ;
			m_scene->setVideoFrame(m_thumbnail) ;
			if( !img.empty() ) m_w->form().lbl_preview->setMyPixmap(QPixmap::fromImage(m_thumbnail)) ;
		}
		cap.release() ;
	}
	m_totTime = getTime(totMSec) ;
	m_scene->setTotalMSec(totMSec) ;
	setSegmentPos( 0, 1 ) ;
}

//////////////////////////////////////////////////////////////////////////
CxLayer::CxLayer(QWidget *parent) :
    QListWidget(parent)
{
//    setIconSize();
/*    setStyleSheet(
         "QListWidget::item {"
            "border-style: solid;"
            "border-width:1px;"
            "border-color:white;"
            "background-color: green;"
         "}"
         "QListWidget::item:selected {"
            "background-color: red;"
         "}");
*/
    setSpacing(1);
	setDragDropMode(QAbstractItemView::DragDrop) ;
	setDragEnabled(true) ;
	setDefaultDropAction(Qt::MoveAction) ;
	connect( this, SIGNAL(itemSelectionChanged()), this, SLOT(onSelectionChanged())) ;
}

CxLayerItem* CxLayer::onAddVideoLayer(QString fileName, int pos, int dur )
{
	CxLayerItem* item = new CxLayerItem(fileName , dur) ;
	QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, 1));
	linearGrad.setCoordinateMode(QGradient::StretchToDeviceMode);
	QColor col1(Qt::black) ;
	col1.setAlphaF(0.9) ;
	QColor col2(Qt::white) ;
	//    col2.setAlphaF(0.5) ;
	linearGrad.setColorAt(0, col1);
	linearGrad.setColorAt(0.5, col2);
	linearGrad.setColorAt(1, col1);
	item->setForeground(Qt::white);
	item->setBackground(QBrush(linearGrad)) ;

	if( pos == -1 ) pos = count() ;
	insertItem(pos,item) ;
	setItemWidget( item, item->widget() ) ;
	item->setSizeHint(QSize(width()-50,LAYERITEMHEIGHT));
	item->widget()->setRank(count()) ;
	m_itemList.insert(pos,item) ;
	for( int i = m_itemList.count()-1; i >= 0; i-- ) 
		m_itemList.at(i)->widget()->setRank(i+1) ;
	setCurrentItem(item) ;
	return item ;
}

void CxLayer::deleteCurItem()
{
	if( selectedItems().count() != 1 ) return ;
	clearSelection() ;
	int cur = currentRow() ;
	takeItem(cur) ;
	m_itemList.takeAt(cur) ;
	for( int i = m_itemList.count()-1; i >= 0; i-- ) 
		m_itemList.at(i)->widget()->setRank(i+1) ;
}

void CxLayer::onSeekRangeChanged( qreal st, qreal en )
{
	if( selectedItems().count() != 1 ) return ;
	m_itemList.at(currentRow())->setSegmentPos(st,en) ;
}

void CxLayer::onSelectionChanged()
{
	CxLayerItem* ret = NULL ;
	int cnt = selectedItems().count() ;
	for( int i = count()-1; i >= 0; i-- )
	{
		CxLayerItemWidget* w = itemAt(i)->widget() ;
		w->onSelect(item(i)->isSelected()) ;
	}
	if( cnt ) ret = m_itemList.at(currentRow()) ;
	emit __currentItemChanged(ret) ;
}

void CxLayer::dropEvent(QDropEvent* event)
{
	QListWidget::dropEvent(event) ;
	m_itemList.clear() ;
	for( int i = 0; i < count(); i++ )
	{
		CxLayerItem* layerItem = (CxLayerItem*) item(i) ;
		m_itemList << layerItem ;
		layerItem->widget()->setRank(i+1) ;
	}
}

void CxLayer::onChangeCurFade(bool on)
{
	int cur = currentRow() ;
	if( cur < 0 || cur >= count() ) return ;
	itemAt(cur)->setFade(on) ;
}