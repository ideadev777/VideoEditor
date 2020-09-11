#ifndef CXITEMLAYER_H
#define CXITEMLAYER_H

#include <QListWidget>
#include <QLabel>
#include "cxgraphicsitem.h"
#include "cxgraphicsscene.h"

#define NOSTATE -1
#define LEFTMOVINGSTATE 0
#define RIGHTMOVINGSTATE 1
#define CENTERMOVINGSTATE 2

//////////////////////////////////////////////////////////////////////////

class CxItemPiece : public QWidget
{
public:
	CxItemPiece(CxGraphicsItem* item) ;
	void refit() ;
	void onSelect() ;
protected:
	void resizeEvent(QResizeEvent* event) ;
	void mousePressEvent(QMouseEvent *event) ;
	void mouseMoveEvent(QMouseEvent *event) ;
	void mouseReleaseEvent(QMouseEvent *event) ;
private:
	QWidget* m_bound ;
	QLabel* m_region ;
	CxGraphicsItem* m_item ;
	QLabel* m_left ;
	QLabel* m_right ;
	int m_state ;
	QPoint m_startPnt ;
//	QRect m_oriRect ;
};

//////////////////////////////////////////////////////////////////////////

class CxGraphicsListItem : public QListWidgetItem
{
public:
	CxGraphicsListItem(CxGraphicsItem* item) ;
	CxItemPiece* widget(){ return m_widget ; }
	CxGraphicsItem* myItem(){ return m_item ; }
private:
	CxGraphicsItem* m_item ;
	CxItemPiece* m_widget ;
};

//////////////////////////////////////////////////////////////////////////
class CxItemLayer : public QListWidget
{
	Q_OBJECT

public:
	CxItemLayer(QWidget *parent);
	~CxItemLayer();
	void clearMe() ;
	CxGraphicsItem* graphicsItem( int id ){ return m_itemList[id]->myItem() ; }
	CxItemPiece* pieceAt( int id ){ return m_itemList[id]->widget() ; }
public slots:
	void onAddItem( CxGraphicsItem* item ) ;
	void setMyScene( CxGraphicsScene* sc ) ;
	void onItemDelete( CxGraphicsItem* item ) ;
	void onSelectionChanged() ;
	void onCurPosChanged( qreal pos ) ;
	void fitTimeLine() ;
protected:
	void paintEvent(QPaintEvent *event) ;
	void resizeEvent(QResizeEvent *event) ;
	void showEvent(QShowEvent *event) ;
	void dropEvent(QDropEvent* event) ;
private:
	QList<CxGraphicsListItem*> m_itemList ;
	CxGraphicsScene* m_scene ;
	QLabel* m_timeLine ;
	qreal m_curTimePos ;
};

#endif // CXITEMLAYER_H
