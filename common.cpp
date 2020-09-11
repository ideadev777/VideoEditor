#include "common.h"
#include <QUuid>
#include <QProcess>

QString createUuid()
{
	return QUuid::createUuid().toString() ;
}

QString createSimpleUuid()
{
	QString ret = createUuid() ;
	ret.chop(1) ;
	ret = ret.right(ret.length()-1) ;
	return ret ;
}

int getMSec(QTime t) 
{
	int ret = t.hour()*3600 ;
	ret += t.minute()*60 ;
	ret += t.second() ;
	ret = ret*1000+t.msec() ;
	return ret ;
}

QTime getTime(int msec) 
{
	int s = msec/1000 ;
	msec %= 1000 ;
	int h = s/3600 ;
	s %= 3600 ;
	int m = s/60 ;
	s%=60 ;
	return QTime(h,m,s,msec) ;
}

QImage Mat2QImage(cv::Mat const& src)
{
	cv::Mat temp; // make the same cv::Mat
	cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
	QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits(); // enforce deep copy, see documentation 
	// of QImage::QImage ( const uchar * data, int width, int height, Format format )
	return dest;
}

cv::Mat QImage2Mat(QImage const& qimage)
{
	cv::Mat mat = cv::Mat(qimage.height(), qimage.width(), CV_8UC4, (uchar*)qimage.bits(), qimage.bytesPerLine());
	cv::Mat mat2 = cv::Mat(mat.rows, mat.cols, CV_8UC3 );
	int from_to[] = { 0,0,  1,1,  2,2 };
	cv::mixChannels( &mat, 1, &mat2, 1, from_to, 3 );
	return mat2;
}

void runProcess( QObject* parent, QString path, QStringList arg )
{
	QProcess *myProcess = new QProcess(parent);
	myProcess->start(path,arg);
	if (myProcess->waitForStarted(-1)) {
		while(myProcess->waitForReadyRead(-1)) {
		}
	}
}