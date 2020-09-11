#include "cxvideopanel.h"
#include <QMouseEvent>
#include <QResizeEvent>
#include "common.h"
#include <QWheelEvent>
#define TOPMARGIN 15
#define SEEKCIRCLEDIAMETER 66
#define CURSEEKWIDTH 4
#define LEFTMARGIN 20

CxVideoPanel::CxVideoPanel(QWidget *parent) 
	:QWidget(parent)
{
    ui.setupUi(this) ;
	m_left = new CxSeekItem(this) ;
	m_right = new CxSeekItem(this) ;
	m_seekItem = new CxSeekCirclePointer(this) ;
//	m_seekItem->setStyleSheet("QLabel{background-color:yellow;}") ;
	m_seek = 0 ;
	setSegment( 0, 1 ) ;
	m_movingIndex = m_lastMovingIndex = -1; 
//	connect( ui.tb_mute, SIGNAL(clicked()), this, SLOT(onMute())) ;
	m_seekItem->hide() ;
	m_left->hide() ;
	m_right->hide() ;
	ui.progressBar->hide() ;
	m_isPlaying = false ;
}

void CxVideoPanel::setSegment(QPointF seg)
{
	setSegment(seg.x(),seg.y(),false) ;
//	QMessageBox::information(NULL,"",QString("%1  %2").arg(seg.x()).arg(seg.y())) ;
}

void CxVideoPanel::setSegment(qreal st, qreal en, bool emitSignal)
{
	if( st < 0 ) st = 0 ;
	if( en > 1 ) en = 1 ;
	qreal w = ui.lbl_seek->width() ;
	if( w*st + SEEKITEMWIDTH > en*w ) return ;
	m_seek = st ;
	m_st = st , m_en = en ;
	m_left->setTime(m_totTime,m_st) ;
	m_right->setTime(m_totTime,m_en) ;
	ui.lbl_seek->setRange(st,en) ;

	if( emitSignal ) emit __rangeChanged(m_st, m_en) ;
	fitSeekItems() ;
}

void CxVideoPanel::wheelEvent(QWheelEvent *event)
{
	if( m_lastMovingIndex == -1 || m_lastMovingIndex == 2 ) return ;
	int totMSec = getMSec(m_totTime) ;
	QPoint numDegrees = event->angleDelta() / 8;
	qreal step = 1000.0/getMSec(m_totTime) ;
	if( numDegrees.y() < 0 ) step *= -1 ;
	if( m_lastMovingIndex == 0 ) setSegment( m_st+step, m_en, true ) ;
	else setSegment( m_st,m_en+step,true ) ;
	emit __preview(m_lastMovingIndex==0?totMSec*m_st : totMSec*m_en) ;
}
void CxVideoPanel::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event) ;
	fitSeekItems() ; 
}

void CxVideoPanel::mousePressEvent(QMouseEvent *event)
{
	QWidget::mousePressEvent(event) ;
	if( event->buttons() & Qt::RightButton ) return ;
	m_movingIndex = -1 ;
	QPoint pnt = event->pos() ;
  	if( m_left->geometry().contains(pnt)) m_movingIndex = 0 ;
	if( m_right->geometry().contains(pnt)) m_movingIndex = 1 ;
	if( m_seekItem->geometry().contains(pnt)) m_movingIndex = 2 ;
//	if( m_movingIndex == -1 && ui.lbl_seek->geometry().contains(pnt))
	if( m_movingIndex == -1)
	{
		qreal w = 1.0*(pnt.x()-LEFTMARGIN)/ui.lbl_seek->width() ;
		if( w < m_st ) w = m_st ;
		if( w > m_en ) w = m_en ;
		//		m_seek = w ;
		setCurrentSeekPos(w) ;
		fitSeekItems() ;
		emit __preview(getMSec(m_totTime)*w) ;
	}
}

void CxVideoPanel::onSeek( qreal w )
{
	setCurrentSeekPos(w) ;
	fitSeekItems() ;
	emit __preview(getMSec(m_totTime)*w) ;
}

void CxVideoPanel::mouseMoveEvent(QMouseEvent* event)
{
	QWidget::mouseMoveEvent(event) ;
	if( m_movingIndex == -1 ) return ;
	qreal w = ui.lbl_seek->width() ;
	w = (event->pos().x()-LEFTMARGIN)/w ;
	int totMSec = getMSec(m_totTime) ;
	if( m_movingIndex == 2 )
	{
		if( w < m_st ) w = m_st ;
		if( w > m_en ) w = m_en ;
//		m_seek = w ;
		onSeek(w) ;
		return ;
	}
	setSegment(m_movingIndex==0?w:m_st,m_movingIndex == 0?m_en:w,true) ;
	emit __preview(m_movingIndex==0?totMSec*m_st:totMSec*m_en) ;
}

void CxVideoPanel::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget::mouseReleaseEvent(event) ;
	if( m_movingIndex == -1 ) return ;
	m_lastMovingIndex = m_movingIndex ;
	m_movingIndex = -1 ;
}
void CxVideoPanel::fitSeekItems(bool isAll)
{
	qreal w = ui.lbl_seek->width() ;
	if( isAll )
	{
		m_left->setGeometry(QRect(LEFTMARGIN+w*m_st-SEEKITEMWIDTH/2, TOPMARGIN, SEEKITEMWIDTH, SEEKITEMHEIGHT)) ;
		m_right->setGeometry(QRect(LEFTMARGIN+w*m_en-SEEKITEMWIDTH/2, TOPMARGIN, SEEKITEMWIDTH, SEEKITEMHEIGHT)) ;
	}
	m_seekItem->setGeometry(QRect(LEFTMARGIN+w*m_seek-SEEKCIRCLEDIAMETER/2, 0, SEEKCIRCLEDIAMETER, SEEKCIRCLEDIAMETER)) ;
}

void CxVideoPanel::onMute()	
{

}

void CxVideoPanel::setCurrentLayerItem(CxLayerItem* item)
{
	m_curItem = item ;
	m_movingIndex = m_lastMovingIndex = -1 ;
	if( m_curItem ){
		if( !m_isPlaying ) {
			m_seekItem->setVisible(true) ;
			m_left->setVisible(true) ;
			m_right->setVisible(true) ;
		}
		m_totTime = m_curItem->totalTime() ;
		ui.lbl_cur_time->setText(QString("%1 / %2").arg("0:00").arg(m_totTime.toString("m:ss"))) ;
		setSegment(item->segmentPos()) ;
		emit __curPosChanged(m_seek) ;
	}
	else {
		setEnabled(false) ;
		if( !m_isPlaying ) {
			m_seekItem->setVisible(true) ;
			m_left->setVisible(false) ;
			m_right->setVisible(false) ;
		}
	}
}

void CxVideoPanel::play( bool on )
{
	m_isPlaying = on ;
	m_left->setVisible(true) ;
	m_right->setVisible(true) ;
	if( !on ) {
//		ui.lbl_seek->setCurrentValue(-1) ;
		ui.lbl_cur_time->setText(QString("%1 / %2").arg("0:00").arg(m_totTime.toString("m:ss"))) ;
		if( getMSec(m_totTime)*fabs(m_seek-m_en)<1000)
		{
//			m_seek = m_prevSeek ;
			setCurrentSeekPos(m_prevSeek) ;
			fitSeekItems(false) ;
		}
	}
	else {
		m_prevSeek = m_seek ;
	}
}

void CxVideoPanel::setCurrentSeekPos( qreal cur )
{
	ui.lbl_seek->setCurrentValue(cur) ;
	m_seek = cur ;
	m_seekItem->displayTime(getMSec(m_totTime)*cur) ;
	emit __curPosChanged(cur) ;
}

void CxVideoPanel::setCurrentTime( int msecs )
{
	ui.lbl_cur_time->setText(QString("%1 / %2").arg(getTime(msecs).toString("m:ss")).arg(m_totTime.toString("m:ss"))) ;
//	ui.lbl_cur_time->setText(QString("%1 / %2").arg(msecs).arg(getMSec(m_totTime)) ;
	setCurrentSeekPos(1.0*msecs/getMSec(m_totTime)) ;
	fitSeekItems(false) ;
}

int CxVideoPanel::currentSeekMSec()
{
	return getMSec(m_totTime)*m_seek ;
}
