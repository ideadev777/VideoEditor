#include "cxpaintseekbar.h"
#include <QPainter>
#include <QMouseEvent>

#define FREEZESEEKWIDTH 50
#define POSSEEKWIDTH 30

CxPaintSeekBar::CxPaintSeekBar(QWidget *parent)
	: QLabel(parent)
{
	m_curSeek = 0 ;
	m_duration = 100 ;
	m_mousePressPos = 0 ;
	m_curFreezePos = 0 ;
	m_freezeSeek = new QLabel(this) ;
	m_freezeSeek->setStyleSheet("QLabel{background:#7F7F7F;}") ;
	m_moveState = NOMOVESTATE ;
	m_isPlaying = false ;
}

CxPaintSeekBar::~CxPaintSeekBar()
{

}

void CxPaintSeekBar::setDuration(int msec)
{
	m_duration = msec ;
	setCurrentSeek(0) ;
	repaint() ;
}

void CxPaintSeekBar::init()
{
	m_curSeek = 0 ;
	repaint() ;
}

void CxPaintSeekBar::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	int w = width() ;
	int h = height() ;
	int hmargin = 4 ; 
	painter.setPen(Qt::NoPen) ;
	painter.setBrush(QColor("#00A2E8")) ;
	painter.drawRect( 0, hmargin, w, h-2*hmargin ) ;
	painter.setBrush(QColor("#FFF200")) ;
//	painter.setBrush(QColor("#3F48CC")) ;
	if( !m_duration ) return ;
	int x = (w-POSSEEKWIDTH)*m_curSeek/m_duration ;
	painter.drawRect( x,hmargin , POSSEEKWIDTH, h-2*hmargin ) ;
}

void CxPaintSeekBar::setCurrentSeek( int sec, bool isPressed ) 
{
	m_curSeek = sec ;
	repaint() ;
	if( m_freezeSeek->isVisible() ) emit __scenePreview(sec,isPressed) ;
}

void CxPaintSeekBar::refitSeekBar()
{
	m_freezeSeek->setGeometry(QRect( m_curFreezePos*width(), 0, FREEZESEEKWIDTH, height())) ;
}

void CxPaintSeekBar::resizeEvent(QResizeEvent *event)
{
	QLabel::resizeEvent(event) ;
	refitSeekBar() ;
}

void CxPaintSeekBar::showFreezeSeekBar( bool on )
{
	m_freezeSeek->setVisible(on) ;
}

void CxPaintSeekBar::mousePressEvent(QMouseEvent *event)
{
	QLabel::mousePressEvent(event) ;
	if( !m_freezeSeek->isVisible() ) return ;
	QRect geo = m_freezeSeek->geometry() ;
	int px = event->pos().x() ;
	if( !geo.contains(event->pos()) ) {
		setCurrentSeek(m_duration*px/(width()-POSSEEKWIDTH),true) ;
		return ;
	}
	if( m_isPlaying ) return ;
	m_moveState = MOVESTATE ;
	m_originRect = geo ;
	m_mousePressPos = px ;
}

void CxPaintSeekBar::mouseMoveEvent(QMouseEvent *event)
{
	QLabel::mouseMoveEvent(event) ;
	if( m_moveState == NOMOVESTATE ) return ;
	int nx = event->pos().x()-m_mousePressPos+m_originRect.topLeft().x() ;
	nx = qMax(0,nx) ;
	nx = qMin(width()-FREEZESEEKWIDTH,nx) ;
	m_curFreezePos = nx*1.0/(width()-FREEZESEEKWIDTH) ;
	QRect rc = m_originRect ;
	rc.moveLeft(nx) ;
	setCurrentSeek(m_curFreezePos*m_duration) ;
	m_freezeSeek->setGeometry(rc) ;
}

void CxPaintSeekBar::mouseReleaseEvent(QMouseEvent *event)
{
	QLabel::mouseReleaseEvent(event) ;
	m_moveState == NOMOVESTATE ;
}

void CxPaintSeekBar::setPlayState( bool on )
{
	m_isPlaying = on ;
}