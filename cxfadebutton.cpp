#include "cxfadebutton.h"
#include <QPainter>

CxFadeButton::CxFadeButton(QWidget *parent)
	: QToolButton(parent)
{
	connect( this, SIGNAL(clicked()), this, SLOT(onClick())) ;
	m_color = QColor(Qt::black) ;
}

CxFadeButton::~CxFadeButton()
{

}

void CxFadeButton::onClick()
{
	repaint() ;
}

void CxFadeButton::enterEvent(QEvent *event)
{
	m_color = QColor(Qt::blue) ;
	repaint() ;
}

void CxFadeButton::leaveEvent(QEvent *event)
{
	m_color = QColor(Qt::black) ;
	repaint() ;
}
void CxFadeButton::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	painter.setPen(Qt::NoPen) ;
	int w = width() ;
	int h = height() ;
	painter.setBrush(QBrush(QColor("#7F7F7F"))) ;
	painter.drawRect(0,0,w,h) ;
	painter.setBrush(Qt::black) ;
	if( isChecked() ) {
		painter.setBrush(QBrush(m_color)) ;
		painter.drawRect(w/2-2,4,4,h-8) ;
	}
	else 
	{
		painter.setPen(QPen(QBrush(m_color),5)) ;
		painter.drawLine(10,h-10,w-10,10) ;
	}
}