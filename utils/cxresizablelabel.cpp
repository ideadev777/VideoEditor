#include "cxresizablelabel.h"
#include <QPainter>

CxResizableLabel::CxResizableLabel(QWidget *parent)
	: QLabel(parent)
{
}

CxResizableLabel::~CxResizableLabel()
{

}

void CxResizableLabel::setMyPixmap(QPixmap pix)
{
	m_pix = pix ; 
}

void CxResizableLabel::paintEvent(QPaintEvent* event)
{
	QPainter painter(this) ;
	painter.setRenderHints(QPainter::Antialiasing) ;
	if( m_pix.isNull() )
	{
		painter.setBrush(Qt::white) ;
		painter.drawRect(rect()) ;
		return ;
	}
	painter.drawPixmap( 0, 0, m_pix.scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
}