#ifndef MYGRAPHICSTEXTITEM_H
#define MYGRAPHICSTEXTITEM_H

#include <QGraphicsTextItem>
#include <QObject>
#include "cxtexteditpanel.h"


class MyGraphicsTextItem :  public QGraphicsTextItem
{

public:
    explicit MyGraphicsTextItem(QGraphicsItem* parent);
    void setBoundingRect(QRectF rc){ m_rc = rc; }
    QRectF boundingRect() const{
        return m_rc ;
    }
	void setTextColor( QColor col ) ;
	void setEditable( bool on ) ;
signals:
    
public slots:
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;
    void focusOutEvent(QFocusEvent *event) ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;
private:
    CxTextEditPanel* m_panel ;
    QRectF m_rc ;
	bool m_isEditable ;
	QPointF m_oriPos, m_parentOriPos ;
	QGraphicsItem* m_parent ;
	bool m_isPressed ;
};

#endif // MYGRAPHICSTEXTITEM_H
