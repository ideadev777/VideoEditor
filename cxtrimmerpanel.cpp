#include "cxtrimmerpanel.h"
#include <QPainter>
#include <QResizeEvent>
#include <QMouseEvent>
#include "common.h"
#include <QLinearGradient>

#define FADEBUTTONSIZE 50

#define TOPMARGIN 20
#define BOTTOMMARGIN 20
//#define m_leftMargin 40
//#define m_rightMargin 40
#define SEEKW 20

CxTrimmerPanel::CxTrimmerPanel(QWidget *parent)
	: QLabel(parent)
{
	m_left = new QLabel(this) ;
	m_right = new QLabel(this) ;
	m_seek = new QLabel(this) ;
	m_fade = new QToolButton(this) ;
	m_fade->setText("|") ;
	m_leftMargin = m_rightMargin = 40 ;
	m_st = 0 ;
	m_en = 1 ;
	m_curSeekPos = 0 ;
	m_totMSec = 3600000 ;
	m_left->setStyleSheet("QLabel{background-color:#00E0FF;}") ;
	m_right->setStyleSheet("QLabel{background-color:#00E0FF;}") ;
	m_seek->setStyleSheet("QLabel{background-color:red;}") ;
	m_left->show() ;
	m_right->show() ;
	m_seek->show() ;
	m_fade->hide() ;
	m_movingIndex = -1 ;
	m_fileName = "" ;
	connect( m_fade, SIGNAL(clicked()), this, SLOT(onFade())) ;
	m_fade->setCheckable(true) ;
	m_fade->setChecked(true) ;
	m_fade->setFont(QFont("arial",20)) ;
	m_fade->setStyleSheet("QToolButton{color:black;}") ;
//	m_fileName = "D://Training Motivation - Floyd Mayweather - Get Money (KP).mp4" ;
}

CxTrimmerPanel::~CxTrimmerPanel()
{

}
QRect CxTrimmerPanel::availableRect()
{
	return QRect(m_left->geometry().topLeft(),m_right->geometry().bottomRight()) ;
}

void CxTrimmerPanel::paintEvent(QPaintEvent* event)
{
	QLabel::paintEvent(event) ;
	QPainter painter(this) ;

	QLinearGradient grad(0,0,1,1) ;
	grad.setCoordinateMode(QGradient::ObjectBoundingMode) ;
	grad.setColorAt(0,QColor("#212C5F")) ;
	grad.setColorAt(1,QColor("#1F2D69")) ;
	painter.setBrush(QBrush(grad)) ;

	QColor col("#1A477B") ;
	painter.setBrush(QBrush(col)) ;
	painter.setPen(Qt::white) ;

	int w = width() ;
	int h = height() ;
	int avaiW = w-m_leftMargin-m_rightMargin ;
	int avaiH = h-TOPMARGIN-BOTTOMMARGIN ;

	QRect rc(m_leftMargin,TOPMARGIN,avaiW,avaiH) ;

	painter.setOpacity(0.5) ;
	painter.drawRect(rc) ;

	painter.setOpacity(1) ;

	painter.drawRect(availableRect()) ;

	painter.setFont(QFont("arial",14)) ;
	painter.drawText( m_leftMargin, 0, width(), TOPMARGIN, Qt::AlignVCenter|Qt::AlignLeft,m_fileName) ;

	painter.setFont(QFont("arial",11)) ;

	painter.drawText(availableRect(),getTime(m_totMSec*(m_en-m_st)).toString("mm:ss"),Qt::AlignHCenter|Qt::AlignBottom) ;
	int textW = 60 ;
	painter.drawText(m_leftMargin + avaiW*m_st-textW/2, h-BOTTOMMARGIN, textW, BOTTOMMARGIN, Qt::AlignCenter,
		getTime(m_totMSec*m_st).toString("mm:ss")) ;
	painter.drawText(m_leftMargin + avaiW*m_en-textW/2, h-BOTTOMMARGIN, textW, BOTTOMMARGIN, Qt::AlignCenter,
		getTime(m_totMSec*m_en).toString("mm:ss")) ;
}

void CxTrimmerPanel::onSetSegment( qreal st, qreal en )
{
	if( st > en-1e-5 ) return ;
	m_st = st ;
	m_en = en ;
	m_curSeekPos = st ;
	fitSeekItems() ;
	repaint() ;
}

void CxTrimmerPanel::mousePressEvent(QMouseEvent* event)
{
	QRect rc = availableRect() ;
	QPoint pnt = event->pos() ;
	if( m_left->geometry().contains(pnt) ) m_movingIndex = 0 ;
	if( m_right->geometry().contains(pnt) ) m_movingIndex = 1 ;
	if( m_seek->geometry().contains(pnt) ) m_movingIndex = 3 ;
	if( m_movingIndex == -1 ) {
		if( rc.contains(pnt) ) 
		{
			qreal w = 1.0*(pnt.x()-m_leftMargin)/(width()-m_leftMargin-m_rightMargin) ;
			emit __curSeekPosChanged(w) ;
		}
		return ;
	}
//	if( rc.contains(pnt) ) m_movingIndex = 2 ;
	m_startPnt = pnt ;
}

void CxTrimmerPanel::mouseMoveEvent(QMouseEvent* event)
{
	qreal w = 1.0*(event->pos().x()-m_leftMargin)/(width()-m_leftMargin-m_rightMargin) ;
	if( w < 0 || w > 1 || m_movingIndex == -1 ) return ;

	qreal st(m_st), en(m_en) ;
	qreal ww = (width()-m_leftMargin-m_rightMargin) ;
	if( m_movingIndex == 0 ) st = w ;
	if( m_movingIndex == 1 ) en = w ;
	if( m_movingIndex == 2 )
	{
		w = 1.0*(event->pos().x()-m_startPnt.x())/ww ;
		if( m_en+w > 1 ) w = 1-m_en ;
		if( m_st+w < 0 ) w = m_st ;
		st = w + m_st, en = w+m_en ;
		m_startPnt = event->pos() ;
	}
	if( m_movingIndex == 3 )
	{
		w = 1.0*(event->pos().x()-m_startPnt.x())/ww ;
		if( m_curSeekPos+w < m_st ) w = m_curSeekPos-m_st ;
		if( m_curSeekPos+w > m_en ) w = m_en-m_curSeekPos ;
		emit __curSeekPosChanged(w+m_curSeekPos) ;
		m_startPnt = event->pos() ;
		return ;
	}
	if( st > en-1e-5 ) return ;
	if( st*ww+4 > en*ww ) return ; // keep at least 4 distance each other.
	onSetSegment(st,en) ;
	repaint() ;
	emit __onRangeChanged(st,en,true) ;
	if( m_movingIndex == 0 ) emit __preview(m_totMSec*m_st) ;
	if( m_movingIndex == 1 ) emit __preview(m_totMSec*m_en) ;
}

void CxTrimmerPanel::mouseReleaseEvent(QMouseEvent* event)
{
	m_movingIndex = -1 ;
}

void CxTrimmerPanel::resizeEvent(QResizeEvent* event)
{
	QLabel::resizeEvent(event) ;
	fitSeekItems() ;
}

void CxTrimmerPanel::fitSeekItems()
{
	int w = width()-m_leftMargin-m_rightMargin ;
	int h = height() - TOPMARGIN - BOTTOMMARGIN ;
	m_left->setGeometry(m_leftMargin+w*m_st-SEEKW/2,TOPMARGIN, SEEKW, h ) ;
	m_right->setGeometry(m_leftMargin+w*m_en-SEEKW/2,TOPMARGIN, SEEKW, h ) ;
	m_seek->setGeometry(m_leftMargin+w*m_curSeekPos-SEEKW/2,TOPMARGIN, SEEKW, h) ;
	
	int fh = height()-TOPMARGIN-BOTTOMMARGIN ;
//	m_fade->setGeometry(m_leftMargin-fh/2 , TOPMARGIN+fh/3, fh/3,fh/3) ;
	repaint() ;
}

void CxTrimmerPanel::setTotMSec( int msec )
{
	m_totMSec = msec ;
	repaint() ;
}

void CxTrimmerPanel::setFileName(QString name)
{
	m_fileName = name ;
	repaint() ;
}

void CxTrimmerPanel::fit(QRect rc)
{
	QPoint st = mapFromGlobal(rc.topLeft()) ;
	m_leftMargin = st.x() ;
	m_rightMargin = width()-st.x()-rc.width() ;
	fitSeekItems() ;
}

void CxTrimmerPanel::onRemoteSeek( qreal w )
{
	m_curSeekPos = w ;
	fitSeekItems() ;
}

void CxTrimmerPanel::setFade( bool on )
{
	m_fade->setChecked(on) ;
	m_fade->setText(on?"|":"/") ;
}

void CxTrimmerPanel::onFade()
{
	bool on = m_fade->isChecked() ;
//	QMessageBox::information(NULL,"",QString("%1").arg(on)) ;
	m_fade->setText(on?"|":"/") ;
	emit __fade(on) ;	
}
