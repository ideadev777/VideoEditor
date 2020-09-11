#include "cxgraphicsitem.h"
#include "cxgraphicsscene.h"
#include <QGraphicsScene>
#include "common.h"
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include "cxtextitem.h"

#define MINDIF 0.01

CxGraphicsItem::CxGraphicsItem() :
    QGraphicsRectItem(),QObject()
{
    setFlags(QGraphicsItem::ItemIsMovable|
             QGraphicsItem::ItemIsSelectable|
             QGraphicsItem::ItemIsFocusable|
             QGraphicsItem::ItemSendsGeometryChanges) ;
	m_itemName = createUuid() ;
	m_start = 0; 
	m_end = 1 ;
	m_itemState = 0 ;
	m_anim = new QPropertyAnimation(this) ;
	m_anim->setDuration(5000) ;
	m_anim->setPropertyName("opac") ;
	m_anim->setStartValue(0) ;
	m_anim->setEndValue(1) ;
	m_isLogo = false ;
}

void CxGraphicsItem::setItemState( int state )
{
	m_itemState = state ;
	if( m_type == TEXTITEM )
	{
		CxTextItem* item = (CxTextItem*)this ;
		QTextDocument* doc = item->textItem()->document();
		if( state == 2 ) doc->setDocumentMargin(25) ;
		if( state == 1 ) doc->setDocumentMargin(7) ;
		if( state == 0 ) doc->setDocumentMargin(4) ;
	}
	setFlag(QGraphicsItem::ItemIsMovable,!state) ;
}

QVariant CxGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
//  /  QMessageBox::information(NULL,"",QString::number(pos().x())) ;
    if( scene() ) scene()->update() ;
    return QGraphicsItem::itemChange(change,value) ;
}

void CxGraphicsItem::moveDuration(qreal delta)
{
//	if( fabs(delta) < 0.1 ) return ;
	if( delta < 0 ) delta = -1*qMin( -delta, m_start ) ;
	else delta = qMin( delta, 1-m_end ) ;
	m_start += delta ;
	m_end += delta ;
//	QMessageBox::information(NULL,"",QString("%1 %2").arg(m_start).arg(m_end) ) ;
}

void CxGraphicsItem::resizeLeft( qreal delta )
{
	qreal nxt = m_start+delta ;
	if( nxt < 0 ) nxt = 0 ;
	if( nxt+MINDIF>m_end ) nxt = m_end-MINDIF ;
	m_start = nxt ;
}

void CxGraphicsItem::resizeRight( qreal delta )
{
	qreal nxt = m_end + delta ;
	if( nxt > 1 ) nxt = 1 ;
	if( nxt-MINDIF<m_start ) nxt = m_start+MINDIF ;
	m_end = nxt ;
}

void CxGraphicsItem::startAnimation( bool on )
{
	if( on ) m_anim->start() ;
	else m_anim->stop() ;
}

void CxGraphicsItem::fitToScene()
{
	if( m_type != PIXITEM ) return ;
	QGraphicsScene* sc = scene() ;
	if( !sc ) return ;
	setRect( 0, 0, sc->width(),sc->height() ) ;
	setPos(0,0) ;

}

void CxGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if( !scene() ) return ;
	CxGraphicsScene* sc = (CxGraphicsScene*)scene() ;
	if( sc->drawRole() != FILLROLE ) {
		QGraphicsItem::mousePressEvent(event) ;
		return ;
	}
	QColor col = sc->drawColor() ;
	clickMe() ;
	int m_markPenWidth = 5 ;
	if( m_type == MARKITEM )
	{
		CxMarkItem* markItem = (CxMarkItem*)this ;
		markItem->setPen(QPen(col,m_markPenWidth)) ;
		markItem->setBrush(QBrush(col)) ;
	}
	if( m_type == TEXTITEM )
	{
		CxTextItem* textItem = (CxTextItem*)this ;
		textItem->setBrush(QBrush(col)) ;
	}
}

void CxGraphicsItem::clickMe()
{
	emit __itemClicked(this) ;
}