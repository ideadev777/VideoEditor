#include "cxgraphicsview.h"
#include <QGraphicsScene>

CxGraphicsView::CxGraphicsView(QWidget *parent) :
    QGraphicsView(parent), m_scene(NULL)
{
	setCacheMode(QGraphicsView::CacheBackground);
    setSceneRect( 0, 0, SCENEWIDTH, SCENEHEIGHT );
	setStyleSheet("background-color:black;") ;
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
}

void CxGraphicsView::resizeEvent(QResizeEvent *event)
{
	QGraphicsView::resizeEvent(event) ;
	fitToScreen() ;
}

void CxGraphicsView::setMyScene(CxGraphicsScene* sc)
{
	m_scene = sc ;
	setScene(sc) ;
	fitToScreen() ;
}

void CxGraphicsView::fitToScreen()
{
	if( !scene() ) return ;
	resetMatrix() ;
	//	resetTransform() ;

	QGraphicsScene* sc = scene() ;
	if( !sc ) return ;

	qreal w = viewport()->width() ;
	qreal h = viewport()->height() ;

	qreal ratio = qMin( w/sc->width(), h/sc->height() ) ;
	QMatrix matrix;
	matrix.scale(ratio, ratio);

	setMatrix(matrix);
}

void CxGraphicsView::onDrawMark( int role, QColor col )
{
	if( m_scene ) m_scene->onDrawMark(role,col) ;
}

void CxGraphicsView::enterEvent(QEvent *ev)
{
	if( !m_scene ) return ;
	QGraphicsView::enterEvent(ev) ;
	emit __mouseHover(true) ;
}

void CxGraphicsView::leaveEvent(QEvent *ev)
{
	if( !m_scene ) return ;
	QGraphicsView::leaveEvent(ev) ;
	emit __mouseHover(false) ;
}