#ifndef CXIMAGEITEM_H
#define CXIMAGEITEM_H
#include "cxgraphicsitem.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class CxImageItem : public CxGraphicsItem
{
public:
    CxImageItem();
    void setImageSource( QString str ) ;
	void setPixmap( QPixmap pix ) ;
	QString imageSource(){ return m_imgSrc ; }
	QPixmap myPixmap(){ return m_pix ; }
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
private:
    QString m_imgSrc ;
    QPixmap m_pix ;
};

#endif // CXIMAGEITEM_H
