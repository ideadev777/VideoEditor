#ifndef CXVIDEOPANEL_H
#define CXVIDEOPANEL_H

#include <QWidget>
#include <QTime>
#include "cxseekitem.h"
#include "cxlayer.h"
#include "ui_form_video_control.h"
#include "cxseekcirclepointer.h"

class CxVideoPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CxVideoPanel(QWidget *parent = 0);
    Ui::Form_Video_Control form(){ return ui; }
	void setSegment( QPointF pnt ) ;
	void play( bool on ) ;
	int currentSeekMSec() ;
	void setCurrentSeekPos( qreal cur ) ;
	qreal currentSeekPos() { return m_seek ; }
	qreal startPos(){ return m_st ; }
	qreal endPos(){ return m_en ; }
signals:
    void __rangeChanged( qreal st, qreal en ) ;
	void __preview( int msec ) ;
	void __curPosChanged( qreal pos ) ;
public slots:
	void setSegment( qreal st, qreal en, bool emitSignal = false ) ;
	void fitSeekItems(bool isAll = true) ;
	void onMute() ;
	void setCurrentLayerItem(CxLayerItem* item) ;
	void setCurrentTime( int msecs ) ;
	void onSeek( qreal w ) ;
protected:
	void mousePressEvent(QMouseEvent *event) ;
	void mouseMoveEvent(QMouseEvent* event) ;
	void mouseReleaseEvent(QMouseEvent* event) ;
	void resizeEvent(QResizeEvent* event) ;
	void wheelEvent(QWheelEvent *event) ;
private:
    Ui::Form_Video_Control ui ;
	qreal m_st, m_en, m_seek ;
	qreal m_prevSeek ;
	CxSeekItem* m_left ;
	CxSeekItem* m_right ;
	int m_movingIndex, m_lastMovingIndex ;
	QTime m_totTime ;
	CxLayerItem* m_curItem ;
	CxSeekCirclePointer* m_seekItem ;
	bool m_isPlaying ;
};

#endif // CXVIDEOPANEL_H
