#include "cxitemlayer.h"
#include <QResizeEvent>
#include <QPainter>
#include <QPaintEvent>

#define GRAPHICSLISTITEMHEIGHT 30
#define XMARGIN 3
#define YMARGIN 2

#define SEEKW 15

//////////////////////////////////////////////////////////////////////////
CxItemPiece::CxItemPiece(CxGraphicsItem* item)
{
	setFixedHeight(GRAPHICSLISTITEMHEIGHT) ;
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding) ;
	m_item = item ;
	m_region = new QLabel(this) ;
	m_region->show() ;
	m_left = new QLabel(this) ;
	m_right = new QLabel(this) ;
	m_region->setStyleSheet("QLabel{background-color:green;}") ;
	m_left->setStyleSheet("QLabel{background-color:red;}") ;
	m_right->setStyleSheet("QLabel{background-color:red;}") ;
	m_left->show() ;
	m_right->show() ;
	refit() ;
	QString str = "IMAGE" ;
	if( item->myType() == MARKITEM ){
		m_region->setStyleSheet("QLabel{background-color:magenta;}") ;
		str = "MARK" ;
	}
	if( item->myType() == TEXTITEM ) {
		str = "TEXT" ;
		m_region->setStyleSheet("QLabel{background-color:yellow;}") ;
	}
	m_region->setText(str) ;
	m_region->setAlignment(Qt::AlignCenter) ;


	m_state = NOSTATE ;
}

void CxItemPiece::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event) ;
	refit() ;
}

void CxItemPiece::onSelect()
{
	bool on = m_item->isSelected() ;
	if( !on ){
		m_left->setStyleSheet("QLabel{background-color:red;}") ;
		m_right->setStyleSheet("QLabel{background-color:red;}") ;
	}
	else
	{
		m_left->setStyleSheet("QLabel{background-color:blue;}") ;
		m_right->setStyleSheet("QLabel{background-color:blue;}") ;
	}
}
void CxItemPiece::refit()
{
	int w = width() ;
	int h = height() ;
	int itemW = (w-2*XMARGIN)*m_item->durationValue() ;
	int itemH = h-2*YMARGIN ;
	QPoint st( XMARGIN+m_item->startValue()*(w-2*XMARGIN) , YMARGIN) ;
	m_region->setGeometry(st.x(),st.y(),itemW,itemH) ;
	m_left->setGeometry(st.x()-SEEKW/2, st.y(), SEEKW, itemH ) ;
	m_right->setGeometry(itemW+st.x()-SEEKW/2, st.y(), SEEKW, itemH ) ;
}

void CxItemPiece::mousePressEvent(QMouseEvent *event)
{
	if( event->buttons() & Qt::RightButton ) {
		QWidget::mousePressEvent(event) ;
		return ;
	}
	QPoint pnt = event->pos() ;
	if( m_region->geometry().contains(pnt) ) m_state = MOVESTATE ;
	if( m_left->geometry().contains(pnt) ) m_state = LEFTMOVINGSTATE ;
	if( m_right->geometry().contains(pnt) ) m_state = RIGHTMOVINGSTATE ;
	m_startPnt = pnt ;
//	QMessageBox::information(NULL,"",QString("%1").arg(m_state)) ;
}

void CxItemPiece::mouseMoveEvent(QMouseEvent *event)
{
	QWidget::mouseMoveEvent(event) ;
	if( m_state == NOSTATE ) return ;
	QPoint pnt = event->pos() ;
	int dx = pnt.x()-m_startPnt.x() ;
	qreal delta = 1.0*dx/(width()-2*XMARGIN) ;
	if( m_state == MOVESTATE )
	{
		m_item->moveDuration(delta) ;
	}
	if( m_state == LEFTMOVINGSTATE )
	{
		m_item->resizeLeft(delta) ;
	}
	if( m_state == RIGHTMOVINGSTATE )
	{
		m_item->resizeRight(delta) ;
	}
	m_startPnt = pnt ;
	refit() ;
}

void CxItemPiece::mouseReleaseEvent(QMouseEvent *event)
{
	QWidget::mouseReleaseEvent(event) ;
	m_state = NOSTATE ;
}

//////////////////////////////////////////////////////////////////////////

CxGraphicsListItem::CxGraphicsListItem(CxGraphicsItem* item)
{
	m_item = item ;
	m_widget = new CxItemPiece(item) ;
}

//////////////////////////////////////////////////////////////////////////
CxItemLayer::CxItemLayer(QWidget *parent)
	: QListWidget(parent)
{
	m_scene = NULL ;
	setSpacing(2) ;
	m_curTimePos = 0 ;
	m_timeLine = new QLabel(this) ;
	m_timeLine->setStyleSheet("QLabel{background-color:red;}") ;
	m_timeLine->setWindowOpacity(0.1) ;

	setDragDropMode(QAbstractItemView::DragDrop) ;
	setDragEnabled(true) ;
	setDefaultDropAction(Qt::MoveAction) ;

}

CxItemLayer::~CxItemLayer()
{

}

void CxItemLayer::onAddItem( CxGraphicsItem* gitem )
{
	CxGraphicsListItem* item = new CxGraphicsListItem(gitem) ;
	item->setSizeHint( QSize(viewport()->width()-100, GRAPHICSLISTITEMHEIGHT)) ;
	addItem(item) ;
	setItemWidget(item,item->widget()) ;
//	item->setSizeHint(item->widget()->sizeHint()) ;
	m_itemList << item ;
}

void CxItemLayer::setMyScene( CxGraphicsScene* sc )
{
	m_scene = sc ;
	clearMe() ;
	m_timeLine->setVisible(sc) ;
	if( sc )
	{
		QList<CxGraphicsItem*> list = sc->availableItems() ;
		int cnt = list.count() ;
		for( int i = 0; i < cnt; i++ )
		{
			onAddItem(list[i]) ;
		}
	}
}

void CxItemLayer::clearMe()
{
	clear() ;
	m_itemList.clear() ;
}

void CxItemLayer::onItemDelete( CxGraphicsItem* item )
{
//	QMessageBox::information(NULL,"", item->itemName()) ;
	for( int i = count()-1; i >= 0; i-- )
	{
		if( item->itemName() == graphicsItem(i)->itemName() )
		{
			m_itemList.takeAt(i) ;
			takeItem(i) ;
			return ;
		}
	}
}

void CxItemLayer::onSelectionChanged()
{
	for( int i = count()-1; i >= 0; i-- )
	{
		pieceAt(i)->onSelect() ;
	}
}

void CxItemLayer::resizeEvent(QResizeEvent *event)
{
	QListWidget::resizeEvent(event) ;
	fitTimeLine() ;
}

void CxItemLayer::showEvent(QShowEvent* event)
{
	QListWidget::showEvent(event) ;
}

void CxItemLayer::onCurPosChanged( qreal cur )
{
	m_curTimePos = cur ;
	fitTimeLine() ;
}

void CxItemLayer::fitTimeLine()
{
	int w = width()-2*XMARGIN ;
	m_timeLine->setGeometry( 2*XMARGIN+w*m_curTimePos-3, 0, 6, height()) ;
}

void CxItemLayer::dropEvent(QDropEvent* event)
{
	QListWidget::dropEvent(event) ;
	m_itemList.clear() ;
	int cnt = count() ;
	for( int i = 0; i < cnt; i++ )
	{
		CxGraphicsListItem* cur = (CxGraphicsListItem*)item(i) ;
		m_itemList<<cur ;
		cur->myItem()->setZValue(i+1) ;
	}
}

void CxItemLayer::paintEvent(QPaintEvent *event)
{
//	QListWidget::paintEvent(event) ;
	QPainter painter(this) ;
	painter.setOpacity(1) ;
	painter.setBrush(Qt::yellow) ;
	painter.drawRect( 0, 0, width()/2, height()) ;
}