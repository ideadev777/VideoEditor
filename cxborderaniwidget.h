#ifndef CXBORDERANIWIDGET_H
#define CXBORDERANIWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>

class CxBorderAniWidget : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QColor color READ myColor WRITE setMyColor )
public:
	CxBorderAniWidget(QWidget *parent);
	~CxBorderAniWidget();
	QColor myColor(){ return m_curColor ;}
	void setMyColor(QColor col) ;
signals:
	void __currentPositionChanged(qreal) ;
public slots:
	void onStartAnimation(bool on) ;
protected:
	void enterEvent(QEvent *ev) ;
	void paintEvent(QPaintEvent* event) ;
	void leaveEvent(QEvent* ev) ;
	void mousePressEvent(QMouseEvent* event) ;
private:
	QColor m_curColor ;
	QPropertyAnimation* m_anim ;
	int m_state ;
	int m_lastTime ;
	int m_lastState ;
};

#endif // CXBORDERANIWIDGET_H
