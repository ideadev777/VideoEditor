#include "cximageitem.h"
#include <QPainter>

CxImageItem::CxImageItem()
{
    m_type = PIXITEM ;
}

void CxImageItem::setImageSource(QString str)
{
    m_imgSrc = str ;
	setPixmap(QPixmap(str)) ;
}

void CxImageItem::setPixmap( QPixmap pix )
{
	m_pix = pix ;
}

void CxImageItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    CxGraphicsItem::paint(painter,option,widget) ;
//    return ;
    painter->setRenderHints(QPainter::SmoothPixmapTransform|QPainter::Antialiasing);
    QPixmap pix = m_pix.scaled( boundingRect().width(), boundingRect().height(),
                                Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) ;
    painter->drawPixmap(0, 0, pix ) ;
    painter->setBrush(Qt::red);
    painter->setPen(QPen(Qt::red,6)) ;
}

