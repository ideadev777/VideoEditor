#ifndef CXGRAPHICSSCENE_H
#define CXGRAPHICSSCENE_H

#include <QGraphicsScene>
#include "common.h"
#include "cxgraphicsitem.h"
#include "cxtextitem.h"
#include "cximageitem.h"
#include "cxmarkitem.h"
#include "cxresizablelabel.h"
#include <QBasicTimer>

#define NOOPENED 0
#define PLAYINGNOW 1
#define PLAYFINISHED 2

class CxGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CxGraphicsScene(QObject *parent = 0);
    CxImageItem* addImageItem( QString filePath, qreal ratio = 1, int logostate = 0 ) ;
	CxImageItem* addImageItem( QPixmap pix, qreal ratio = 1, int logostate = 0 ) ;
	CxImageItem* addLogo( QString filePath, QPointF pos, QSizeF sz ) ;
    CxTextItem* addTextItem( QString str = "Hello Tom") ;
	void insertTextItem( CxTextItem* item ) ;
	bool isRunningVideo(){ return m_isRunningVideo ; }
	void setRunningVideo( bool on, int startMSec = -1) ;
    void rearrangeCtrlList() ;
	void setRecordingState( bool on ){ m_isRecording = on ; }
	bool isRecording(){ return m_isRecording ; }
	QString videoPath(){ return m_mediaPath ; }
	QBrush bgBrush(){ return m_bgBrush ; }
	void setBgBrush( QBrush brush ) ;
	void setVideoFrame( QImage img ) ;
	void setVideoPath( QString str ) ;
	int showNextFrame(int val) ;
	void setVideoRange( int st, int en ) ;
	void preview( int msec ) ;
	void setNextVideoFrame( QImage img ) ;
	QPixmap renderToPix(QSize sz=QSize(-1,-1)) ;
	int startTime(){ return m_startFrame ; }
	int endTime(){ return m_endFrame ; }
	QList<CxGraphicsItem*> availableItems() ;
	QList<CxGraphicsItem*> allItems(){ return m_itemList ; }
	void setTotalMSec( int sec ) { m_totalDurMSec = sec ; }
	int totalMSec(){ return m_totalDurMSec ; }
	bool hasFadeEffect(){ return m_isFade ; }
	void setFadeEffect( bool on ) { m_isFade = on ; }
	void setCurrentItemState( int ) ;
	void setItemState( CxGraphicsItem* item, int state ) ;
	QString sceneName(){ return m_sceneName ; }
	void pasteItem( CxGraphicsItem* item ) ;
	QString audioPath(){ return m_audioPath ; }
	void setAudioPath(QString path) ;
	void setSceneType( int _t ) { m_sceneType = _t ; }
	int sceneType(){ return m_sceneType ; }
	void setDrawColor( QColor col ) ;
	int drawRole() { return m_drawRole ; }
	QColor drawColor(){ return m_drawColor ; }
signals:
	void __mouseHover( bool on ) ;
	void __screenClicked() ;
    void __currentTimeChanged( int ) ;
	void __itemAdded(CxGraphicsItem* item) ;
	void __itemDeleted(CxGraphicsItem* item) ;
	void __initDrawRole() ;
public slots:
    void onSelectionChanged() ;
    void onDrawMark(int role, QColor col ) ;
	void onRemoveCurItem() ;
	void onRemoveAllItems() ;
	void setMovementMode() ;
	void setFillMode() ;
	void onItemClicked( CxGraphicsItem* item ) ;
protected:
	bool event(QEvent* ev) ;
	void focusInEvent(QFocusEvent *event) ;
	void focusOutEvent(QFocusEvent* event) ;
	void keyPressEvent(QKeyEvent *event) ;
    void drawBackground(QPainter * painter, const QRectF & rect) ;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) ;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) ;
	void timerEvent(QTimerEvent *event) ;
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) ;
private:
	void addMyItem( CxGraphicsItem* item ) ;
	void removeMyItem(CxGraphicsItem* item) ;
    QList<CxGraphicsItem*> m_itemList ;
    QList<QGraphicsRectItem*> m_ctrlList ;

    CxGraphicsItem* m_curItem ;
    QSizeF m_oriSize ;
    QPointF m_oriPos ;
    QPointF m_resizeStartPoint ;
    int m_resizeState ;

    int m_drawRole ;
    int m_markPenWidth ;
	int m_numberCount ;
	bool m_isPressed ;
    QColor m_drawColor ;
    QPointF m_drawStartPoint ;
    QPointF m_startPont ;
    CxMarkItem* m_curDrawItem ;
	QBasicTimer m_timer ;
	QImage m_videoFrame ;
	bool m_isRunningVideo, m_isFade ;
	qreal m_fadeValue ;
	QString m_mediaPath ;
	VideoCapture m_capture ;
	QImage m_nextVideoFrame ;
	bool m_hasNextVideo ;
	int m_startFrame, m_endFrame ;
	int m_totalDurMSec ;
	double m_curFrameTime ;
	QString m_sceneName ;
	QGraphicsRectItem* m_deleteBtn ;
	QString m_audioPath ;
	int m_sceneType ;
	QBrush m_bgBrush;
	CxGraphicsItem* m_curClickedItem ;
	bool m_isRecording ;
};

#endif // CXGRAPHICSSCENE_H
