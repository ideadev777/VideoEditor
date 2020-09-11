#ifndef CXPAINTSEEKBAR_H
#define CXPAINTSEEKBAR_H

#include <QLabel>

#define NOMOVESTATE 0
#define MOVESTATE 1

class CxPaintSeekBar : public QLabel
{
	Q_OBJECT

public:
	CxPaintSeekBar(QWidget *parent);
	~CxPaintSeekBar();
	void setDuration( int msec ) ;
	void setCurrentSeek( int cur, bool isPressed = false ) ;
	void init() ;
	int currentSeek(){ return m_curSeek ; }
	int freezeTime() { return m_duration*m_curFreezePos; }
	void showFreezeSeekBar( bool on ) ;
	void setPlayState( bool on ) ;
signals:
	void __scenePreview(int pos, bool pressed) ;
protected:
	void paintEvent(QPaintEvent* event) ;
	void resizeEvent(QResizeEvent *event) ;
	void mousePressEvent(QMouseEvent *event) ;
	void mouseMoveEvent(QMouseEvent *event) ;
	void mouseReleaseEvent(QMouseEvent *event) ;
private:
	void refitSeekBar() ;
	int m_duration ;
	int m_curSeek ;
	QLabel* m_freezeSeek ;
	QRect m_originRect ;
	qreal m_curFreezePos ;
	int m_moveState ;
	int m_mousePressPos ;
	int m_isPlaying ;
};

#endif // CXPAINTSEEKBAR_H
