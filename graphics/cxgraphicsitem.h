#ifndef CXGRAPHICSITEM_H
#define CXGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPropertyAnimation>

#include "common.h"


class CxGraphicsItem : public QObject, public QGraphicsRectItem
{
	Q_PROPERTY(qreal opac READ opacity WRITE setOpacity USER true)
	
	Q_OBJECT
public:
    explicit CxGraphicsItem();
	int itemState(){ return m_itemState ; }
	void fitToScene() ;
    int myType() { return m_type ; }
	void setItemState( int state ) ;
	void moveDuration( qreal delta ) ;
	void resizeLeft( qreal delta ) ;
	void resizeRight( qreal delta ) ;
//    void setBoundingRect( QRect rc ) { m_boundingRect = rc ; }
//    QRectF boundingRect() const { return m_boundingRect ; }
	QString itemName(){ return m_itemName ; }
	void setItemName(QString str){ m_itemName = str ; }
	void setStart( qreal st ) { m_start = st ; }
	void setEnd( qreal en ){ m_end = en ; }
	qreal durationValue(){ return m_end - m_start ; }
	qreal startValue(){ return m_start ; }
	qreal endValue(){ return m_end ; }
	void startAnimation( bool on = true ) ;
	void clickMe() ;
	bool isLogo(){ return m_isLogo ; }
	void setLogo( bool on ){ m_isLogo = on ; }
signals:
    void __itemClicked(CxGraphicsItem* item) ;
public slots:
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
    QVariant CxGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value) ;
    int m_type ;
	QString m_itemName ;
	qreal m_start, m_end ;
	int m_itemState ;
	QPropertyAnimation* m_anim ;
	bool m_isLogo ;
};

#endif // CXGRAPHICSITEM_H
