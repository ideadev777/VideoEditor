#ifndef CXTEXTITEM_H
#define CXTEXTITEM_H
#include "cxgraphicsitem.h"
#include <QGraphicsTextItem>
#include "mygraphicstextitem.h"
#include "textedit.h"
#include <QBrush>

class CxTextItem : public CxGraphicsItem
{
public:
    CxTextItem(QString str="TEXT");
	MyGraphicsTextItem* textItem(){ return m_textItem ; }
public slots:
    void updateMe() ;
	void showEditor() ;
	void setEditorVisible(bool on) ;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) ;
    bool sceneEvent(QEvent * event) ;
private:
    MyGraphicsTextItem* m_textItem ;
    TextEdit* m_edit ;
	bool m_isEditorVisible ;
};

#endif // CXTEXTITEM_H
