#include "cxmarkitem.h"
#include <QPainter>

CxMarkItem::CxMarkItem(int role, int markNum)
    :CxGraphicsItem()
{
    m_role = role ;
    m_type = MARKITEM ;
	m_markNum = markNum ;
}

void CxMarkItem::setRole(int role)
{
    m_role = role ;
//    update() ;
}

void CxMarkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
	painter->setRenderHints(QPainter::Antialiasing) ;
    qreal w = boundingRect().width() ;
    qreal h = boundingRect().height() ;
    if( m_role == LINEMARKROLE ) painter->drawLine(0, 0, w, h );
    if( m_role == CIRCLEMARKROLE ) painter->drawEllipse(QRectF(0,0,w,h));
    if( m_role == RECTMARKROLE ) painter->drawRect(0 ,0, w, h);
	if( m_role == BLACKCIRCLEROLE )
	{
		painter->setPen(Qt::NoPen) ;
		painter->drawEllipse(0,0,w,h) ;
	}
	if( m_role == NUMBERMARKROLE )
	{
		painter->setPen(pen()) ;
		qreal ratio = 0.7 ;
		painter->setFont(QFont("arial",qMin(qAbs(w*ratio),qAbs(h*ratio)))) ;
		painter->drawText(0,0,w,h,Qt::AlignCenter,QString::number(m_markNum)) ;
	}
	painter->setBrush(pen().color()) ;
	QPolygon poly ;
	if( m_role == RIGHTARROWROLE )
	{
		poly << QPoint(0,h/4)<< QPoint(w/2,h/4) << QPoint(w/2,0) << QPoint(w,h/2) << QPoint(w/2,h) 
			<< QPoint(w/2,h*3/4) << QPoint(0,h*3/4) ;
		painter->drawPolygon(poly) ;
	}
	if( m_role == LEFTARROWROLE )
	{
		poly<<QPoint(0,h/2)<<QPoint(w/2,0)<<QPoint(w/2,h/4)<<QPoint(w,h/4)<<QPoint(w,h*3/4)<<
			QPoint(w/2,h*3/4)<<QPoint(w/2,h) ;
		painter->drawPolygon(poly) ;
	}
	if( m_role == UPARROWROLE )
	{
		poly<<QPoint(0,h/2)<<QPoint(w/2,0)<<QPoint(w,h/2)<<QPoint(w*3/4,h/2)<<QPoint(w*3/4,h)
			<<QPoint(w/4,h)<<QPoint(w/4,h/2) ;
		painter->drawPolygon(poly) ;
	}
	if( m_role == DOWNARROWROLE )
	{
		poly<<QPoint(w/4,0)<<QPoint(w*3/4,0)<<QPoint(w*3/4,h/2)<<QPoint(w,h/2)<<QPoint(w/2,h)
			<<QPoint(0,h/2)<<QPoint(w/4,h/2) ;
		painter->drawPolygon(poly) ;
	}
}
