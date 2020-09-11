#include "cxvideoitem.h"
#include <QPainter>

CxVideoItem::CxVideoItem(QString filePath)
{
    setVideoPath(filePath) ;
	m_isPlaying = false ;

}

void CxVideoItem::setVideoPath(QString filePath)
{
    m_filePath = filePath ;
}

void CxVideoItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QImage img = m_curFrame.scaled(SCENEWIDTH,SCENEHEIGHT,Qt::IgnoreAspectRatio,Qt::SmoothTransformation) ;
	painter->drawImage(0,0,img) ;
}

bool CxVideoItem::showNextFrame()
{
	if( !m_isPlaying ) startPlay() ;
	Mat img;
	if( !m_capture.isOpened() ) return false ;
	m_capture.read(img) ;
	if( img.empty() ) return false ;
	m_curFrame = Mat2QImage(img);
	update() ;
	return true ;
}

void CxVideoItem::startPlay(bool on)
{
	m_isPlaying = on ;
	if( on )
	{
		m_capture.open(m_filePath.toStdString()) ;
	}
}