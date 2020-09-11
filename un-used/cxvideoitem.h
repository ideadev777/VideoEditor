#ifndef CXVIDEOITEM_H
#define CXVIDEOITEM_H

#include <QGraphicsVideoItem>
#include "common.h"

class CxVideoItem : public QGraphicsRectItem
{
public:
    CxVideoItem(QString filePath="");
    void setVideoPath(QString filePath) ;
	bool showNextFrame() ;
public slots:
	void startPlay(bool on=true) ;
protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = 0 */) ;
private:
    QString m_filePath ;
	VideoCapture m_capture ;
	bool m_isPlaying; 
	QImage m_curFrame ;
};

#endif // CXVIDEOITEM_H
