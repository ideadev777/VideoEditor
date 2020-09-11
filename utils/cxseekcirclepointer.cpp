#include "cxseekcirclepointer.h"
#include <QPainter>

CxSeekCirclePointer::CxSeekCirclePointer(QWidget *parent)
	: QLabel(parent)
{
	setPalette(Qt::transparent);
	setAttribute( Qt::WA_TranslucentBackground, true );
	setAttribute( Qt::WA_OpaquePaintEvent, true );
	setAutoFillBackground(false);
	setStyleSheet("QWidget{background-color: transparent;}");
	setAttribute(Qt::WA_NoSystemBackground);
}

CxSeekCirclePointer::~CxSeekCirclePointer()
{

}

void CxSeekCirclePointer::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	painter.setRenderHint(QPainter::Antialiasing) ;
	painter.setPen(Qt::NoPen) ;
	painter.setBrush(Qt::red) ;
	painter.drawEllipse(QPoint(width()/2,height()/2),12,12) ;
//	painter.drawText()
	QFont f("arial",11) ;
	f.setBold(true) ;
	painter.setPen(QPen(Qt::red,2)) ;
	painter.setFont(f) ;
	painter.drawText( 0, 0, width(), height()/2, Qt::AlignHCenter|Qt::AlignTop, m_time ) ;
}

void CxSeekCirclePointer::displayTime( int msec )
{
	m_time = getTime(msec).toString("m:ss") ;
	repaint() ;
}