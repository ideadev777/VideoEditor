#include "cxseekitem.h"
#include <QPainter>
#include "common.h"
#include <QPolygon>

CxSeekItem::CxSeekItem(QWidget *parent)
	: QLabel(parent)
{
//	setStyleSheet("{background-color:white;}") ;
	setPalette(Qt::transparent);
	setAttribute( Qt::WA_TranslucentBackground, true );
	setAttribute( Qt::WA_OpaquePaintEvent, true );
	setAutoFillBackground(false);
	setStyleSheet("QWidget{background-color: transparent;}");
	setAttribute(Qt::WA_NoSystemBackground);
}

CxSeekItem::~CxSeekItem()
{

}

void CxSeekItem::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	painter.setRenderHint(QPainter::Antialiasing) ;
	painter.setPen(Qt::NoPen) ;
	painter.setBrush(Qt::black) ;
	QPolygon poly ;
	poly<<QPoint(SEEKITEMWIDTH*1.5/4,0)<<QPoint(SEEKITEMWIDTH*2.5/4,0)<<QPoint(SEEKITEMWIDTH*2.5/4,SEEKITEMHEIGHT/2)
		<<QPoint(SEEKITEMWIDTH,SEEKITEMHEIGHT)<<QPoint(0,SEEKITEMHEIGHT)<<QPoint(SEEKITEMWIDTH*1.5/4,SEEKITEMHEIGHT/2)
		<<QPoint(SEEKITEMWIDTH*1.5/4,0) ;
	painter.drawPolygon(poly) ;
	painter.setFont(QFont("arial",10)) ;
	painter.setPen(Qt::yellow);
	painter.drawText(0,0,width(),height(),Qt::AlignBottom|Qt::AlignHCenter,m_time ) ;
}

void CxSeekItem::setTime(QTime t, qreal val)
{
	QTime ret = getTime(getMSec(t)*val) ;
	m_time = ret.toString("m:ss") ;
	repaint() ;
}