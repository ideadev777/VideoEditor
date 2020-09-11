#ifndef CXPROGRESSLABEL_H
#define CXPROGRESSLABEL_H

#include <QLabel>
#include <QPointF>

class CxProgressLabel : public QLabel
{
	Q_OBJECT

public:
	CxProgressLabel(QWidget *parent);
	~CxProgressLabel();
	void setRange( qreal st, qreal en ) ;
	void setRange(QPointF pnt){ setRange(pnt.x(), pnt.y()) ; }
	void setCurrentValue( qreal cur ) ;
protected:
	void paintEvent(QPaintEvent *event) ;
private:
	qreal m_st, m_en, m_cur ;
};

#endif // CXPROGRESSLABEL_H
