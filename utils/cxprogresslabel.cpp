#include "cxprogresslabel.h"
#include <QPainter>

CxProgressLabel::CxProgressLabel(QWidget *parent)
	: QLabel(parent)
{

}

CxProgressLabel::~CxProgressLabel()
{

}

void CxProgressLabel::setRange( qreal st, qreal en )
{
	m_st = st ;
	m_en = en ;
	m_cur = m_st ;
	repaint() ;
}

void CxProgressLabel::setCurrentValue( qreal cur )
{
	if( cur < 0 ) m_cur = m_st ;
	else m_cur = cur ;
	repaint() ;
}

void CxProgressLabel::paintEvent(QPaintEvent *event)
{
	QPainter painter(this) ;
	painter.setPen(Qt::NoPen) ;
	painter.setBrush(QBrush(Qt::yellow)) ;
	painter.drawRect( 0, 0, width(), height() ) ;
	painter.setBrush(Qt::red) ;
	qreal w = width() ;
	painter.drawRect( w*m_st, 0, w*(m_cur-m_st), height() ) ;
}