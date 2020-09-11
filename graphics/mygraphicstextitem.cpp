#include "mygraphicstextitem.h"
#include "cxtextitem.h"
#include "cxgraphicsscene.h"

#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>

MyGraphicsTextItem::MyGraphicsTextItem(QGraphicsItem* parent) :
    QGraphicsTextItem(parent)
{
/*    setFlags(QGraphicsItem::ItemIsMovable|
             QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsFocusable|
             QGraphicsItem::ItemSendsGeometryChanges) ;
  */ 
//	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsFocusable) ;
	setTextInteractionFlags(Qt::NoTextInteraction);
	m_isEditable = false ;
    m_panel = new CxTextEditPanel ;
	m_isPressed = false ;
	m_parent = parent ;
}

void MyGraphicsTextItem::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
//	textCursor().clearSelection();
//	clearFocus() ;
	QTextCursor c = textCursor() ;
	c.clearSelection() ;
	setTextCursor(c) ;
    QGraphicsTextItem::focusOutEvent(event);
}

void MyGraphicsTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

void MyGraphicsTextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if( event->button()&Qt::RightButton )
    {
		m_isPressed = false ;
		return ;
    }

	if( !scene() ) return ;
	CxGraphicsScene* sc = (CxGraphicsScene*)scene() ;
	if( sc->drawRole() == FILLROLE ) {
		QColor col = sc->drawColor() ;
		CxTextItem* textItem = (CxTextItem*)m_parent ;
		textItem->setBrush(QBrush(col)) ;
		textItem->clickMe() ;
		return ;
	}
	QGraphicsTextItem::mousePressEvent(event) ;


	if( m_isEditable )	{
		setTextInteractionFlags(Qt::TextEditable|Qt::TextSelectableByMouse);
		setFocus() ;
	}
	QGraphicsTextItem::mousePressEvent(event) ;
	m_isPressed = true ;
	m_oriPos = pos() ;
	if( m_parent ) m_parentOriPos = m_parent->pos() ; 
}

void MyGraphicsTextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsTextItem::mouseMoveEvent(event) ;
	if( !m_isPressed ) return ;
	QPointF curPos = pos() ;
//	if( m_parent ) m_parent->setPos((curPos-m_oriPos)+m_parentOriPos) ;
//	QPointF pPos = m_parent->pos() ;
//	setPlainText(QString("%1 %2 : %3 %4 ").arg(curPos.x()).arg(curPos.y()).arg(pPos.x()).arg(pPos.y())) ;
}

void MyGraphicsTextItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	m_isPressed = false ;
	QGraphicsTextItem::mouseReleaseEvent(event) ;
}

void MyGraphicsTextItem::setTextColor( QColor col )
{
	QTextCursor cur = textCursor() ;
	QTextCharFormat cfmt ;
	QFont font = cfmt.font() ;
	if( col == QColor(Qt::white) ) 
	{
		cur.select(QTextCursor::Document) ;
		QTextBlockFormat bfmt ;
		bfmt.setAlignment(Qt::AlignLeft) ;
		cfmt.setFontPointSize(16) ;
		cfmt.setForeground(col) ;
		cur.mergeCharFormat(cfmt)  ;
		cur.mergeBlockFormat(bfmt) ;
	}
	if( col == QColor(Qt::black)) 
	{
		cur.select(QTextCursor::Document) ;
		QTextBlockFormat bfmt ;
		bfmt.setAlignment(Qt::AlignHCenter) ;
		cfmt.setFontPointSize(35) ;
		cfmt.setForeground(col) ;
		cur.mergeCharFormat(cfmt)  ;
		cur.mergeBlockFormat(bfmt) ;
	}
	cur.clearSelection() ;
}

void MyGraphicsTextItem::setEditable( bool on )
{
//	setFlag(QGraphicsItem::ItemIsSelectable,on);
	m_isEditable = on ;
}