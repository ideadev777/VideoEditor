#include "cxborderaniwidget.h"
#include <QPainter>
#include "common.h"
#include <QTime>
#include <QMouseEvent>

CxBorderAniWidget::CxBorderAniWidget(QWidget *parent)
	: QWidget(parent)
{
//C4C1C4
	m_curColor = QColor("#C4C1C4") ;
	m_anim = new QPropertyAnimation(this,"color") ;
	m_anim->setDuration(500) ;
	m_state = -1 ;
	m_lastState = -1 ;
	m_lastTime = 0 ;
}

CxBorderAniWidget::~CxBorderAniWidget()
{

}

void CxBorderAniWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	painter.setPen(Qt::NoPen) ;
	painter.setBrush(QBrush(m_curColor)) ;
	painter.drawRect(rect()) ;
}

void CxBorderAniWidget::onStartAnimation(bool on)
{
	if( m_state == on ) return ;
	m_anim->stop() ;
	m_lastState = m_state ;
	m_state = on ;
	if( !on && m_lastState == 1 )
	{
		m_lastTime = getMSec(QTime::currentTime()) ;
	}
	if( on ) {
		m_anim->setStartValue(QColor("#C4C1C4")) ;
		m_anim->setKeyValueAt(0.2,QColor("#C4C1C4")) ;
		m_anim->setEndValue(QColor(Qt::darkGray)) ;
	}
	else
	{
		m_anim->setEndValue(QColor("#C4C1C4")) ;
		m_anim->setStartValue(QColor(Qt::darkGray)) ;
		m_anim->setKeyValueAt(0.2,QColor(Qt::darkGray)) ;
	}
	m_anim->start() ;
}

void CxBorderAniWidget::setMyColor(QColor col)
{
	m_curColor = col ;
	repaint() ;
}

void CxBorderAniWidget::enterEvent(QEvent *ev)
{
	QWidget::enterEvent(ev) ;
	int cur = getMSec(QTime::currentTime()) ;
	if( cur-m_lastTime<100 ) onStartAnimation(true) ;
}

void CxBorderAniWidget::leaveEvent(QEvent* ev)
{
	QWidget::leaveEvent(ev) ;
	if( m_state == 1 ) onStartAnimation(false) ;

}

void CxBorderAniWidget::mousePressEvent(QMouseEvent* event)
{
	QWidget::mousePressEvent(event) ;
//	emit __currentPositionChanged(event->posF().rx() / width()) ;
}