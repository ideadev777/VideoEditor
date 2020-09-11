#ifndef CXGRAPHICSVIEW_H
#define CXGRAPHICSVIEW_H

#include <QGraphicsView>
#include "common.h"
#include "cxgraphicsscene.h"

class CxGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CxGraphicsView(QWidget *parent = 0);
    CxGraphicsScene* currentScene(){ return m_scene ; }
signals:
    
public slots:
	void setMyScene(CxGraphicsScene* sc) ;
	void fitToScreen() ;
	void onDrawMark( int role, QColor col ) ;
signals:
	void __mouseHover( bool on ) ;
protected:
	void resizeEvent(QResizeEvent *event) ;
	void enterEvent(QEvent *ev) ;
	void leaveEvent(QEvent *ev) ;
private:
	CxGraphicsScene* m_scene ;
};

#endif // CXGRAPHICSVIEW_H
