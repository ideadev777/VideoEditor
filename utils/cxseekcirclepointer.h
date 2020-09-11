#ifndef CXSEEKCIRCLEPOINTER_H
#define CXSEEKCIRCLEPOINTER_H

#include <QLabel>
#include "common.h"

class CxSeekCirclePointer : public QLabel
{
	Q_OBJECT

public:
	CxSeekCirclePointer(QWidget *parent);
	~CxSeekCirclePointer();
	void displayTime( int msec ) ;
protected:
	void paintEvent(QPaintEvent* event) ;
private:
	QString m_time ;
};

#endif // CXSEEKCIRCLEPOINTER_H
