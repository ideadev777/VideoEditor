#ifndef CXTRIMMERPANEL_H
#define CXTRIMMERPANEL_H

#include <QLabel>
#include <QToolButton>

class CxTrimmerPanel : public QLabel
{
	Q_OBJECT

public:
	CxTrimmerPanel(QWidget *parent);
	~CxTrimmerPanel();
	void setFileName( QString path ) ;
	void setTotMSec( int msec ) ;
	void fit(QRect rc) ;
	void setFade( bool on ) ;
public slots:
	void onSetSegment( qreal st, qreal en ) ;
	void onRemoteSeek( qreal w ) ;
	void onFade() ;
signals:
	void __onRangeChanged( qreal st, qreal en, bool emitSignal ) ;
	void __curSeekPosChanged( qreal st ) ;
	void __preview( int msec ) ;
	void __fade(bool on) ;
protected:
	void paintEvent(QPaintEvent* event) ;
	void mousePressEvent(QMouseEvent* event) ;
	void mouseMoveEvent(QMouseEvent* event) ;
	void mouseReleaseEvent(QMouseEvent* event) ;
	void resizeEvent(QResizeEvent* event) ;
private:
	void fitSeekItems() ;
	QRect availableRect() ;
	QLabel* m_left ;
	QLabel* m_right ;
	QLabel* m_seek ;
	QToolButton* m_fade ;
	qreal m_st, m_en ;
	QString m_fileName ;
	int m_totMSec ;
	int m_movingIndex ;
	qreal m_curSeekPos ;
	QPoint m_startPnt ;
	int m_leftMargin, m_rightMargin ;
};

#endif // CXTRIMMERPANEL_H
