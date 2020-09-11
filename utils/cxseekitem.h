#ifndef CXSEEKITEM_H
#define CXSEEKITEM_H

#include <QLabel>
#include <QTime>

class CxSeekItem : public QLabel
{
	Q_OBJECT

public:
	CxSeekItem(QWidget *parent);
	~CxSeekItem();
	void setTime(QTime t, qreal val) ;
private:
	QString m_time ;
protected:
	void paintEvent(QPaintEvent* event) ;
};

#endif // CXSEEKITEM_H
