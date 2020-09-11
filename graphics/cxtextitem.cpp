#include "cxtextitem.h"
#include <QPainter>

CxTextItem::CxTextItem(QString str): m_textItem(NULL)
{
    m_textItem = new MyGraphicsTextItem(this) ;
    m_textItem->setPos(0,0);
    m_textItem->show() ;
	QFont f("Impact") ;
	f.setPointSize(48) ;
    m_textItem->setFont(f);
    m_textItem->setPlainText(str);
    m_edit = new TextEdit(0,m_textItem) ;
    m_type = TEXTITEM ;
	setBrush(Qt::white) ;
	m_isEditorVisible = true ;

	/*
	QTextCursor cur = m_textItem->textCursor() ;
	QTextBlockFormat bfmt = cur.blockFormat() ;
	bfmt.setAlignment(Qt::AlignCenter) ;
	cur.mergeBlockFormat(bfmt) ;
	m_textItem->setTextCursor(cur) ;
	*/
}

void CxTextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    CxGraphicsItem::paint(painter,option,widget) ;
	painter->setBrush(brush()) ;
	int w = rect().width() ;
	int h = rect().height() ;
	if( m_itemState == 2 )
	{
		painter->setBrush(Qt::black) ;
		painter->drawRect( 0, 0, w, h ) ;
		painter->setBrush(brush()) ;
		int delta = 4 ;
		painter->drawRect( delta, delta, w-2*delta, h-2*delta ) ;
		return ;
	}
	painter->drawRect( 0, 0, w, h ) ;
}

void CxTextItem::updateMe()
{
    if( m_textItem ) {
		int delta = 8;
		QRectF rc = rect() ;
        m_textItem->setBoundingRect(QRectF(delta,delta,rc.width()-2*delta,rc.height()-2*delta) );
        m_textItem->setTextWidth(rc.width()-2*delta);
//		m_textItem->setBoundingRect(rect());
//		m_textItem->setTextWidth(rect().width());
    }
}

void CxTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    CxGraphicsItem::mouseDoubleClickEvent(event) ;
	showEditor() ;
}

void CxTextItem::showEditor()
{
	if( !m_isEditorVisible ) {
		return ;
	}
//	if( !m_itemState ) ;
	m_edit->showMe(m_textItem);
}

QVariant CxTextItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    updateMe() ;
    return CxGraphicsItem::itemChange(change, value) ;
}

bool CxTextItem::sceneEvent(QEvent * event)
{
    updateMe() ;
    return CxGraphicsItem::sceneEvent(event) ;
}

void CxTextItem::setEditorVisible(bool on)
{
	m_isEditorVisible = on ;
	m_textItem->setEditable(!on) ;
}