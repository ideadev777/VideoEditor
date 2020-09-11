#ifndef COMMON_H
#define COMMON_H

#define SCENEWIDTH 1280
#define SCENEHEIGHT 720

#include <QMessageBox>
#include <QString>
#include <QObject>
#include <QTime>
#include <QPixmap>

#include "core/core.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"

using namespace cv ;

#define NORESIZESTATE -1
#define MOVESTATE 10
#define TOPLEFTSTATE 0
#define TOPMIDDLESTATE 1
#define TOPRIGHTSTATE 2
#define MIDDLERIGHTSTATE 3
#define BOTTOMRIGHTSTATE 4
#define BOTTOMMIDDLESTATE 5
#define BOTTOMLEFTSTATE 6
#define MIDDLELEFTSTATE 7

#define NOMARKROLE -1
#define RECTMARKROLE 0
#define CIRCLEMARKROLE 1
#define LINEMARKROLE 2
#define NUMBERMARKROLE 3
#define RIGHTARROWROLE 4
#define LEFTARROWROLE 5
#define UPARROWROLE 6
#define DOWNARROWROLE 7
#define FILLROLE 8
#define BLACKCIRCLEROLE 9

#define TEXTITEM 0
#define PIXITEM 1
#define MARKITEM 2

#define SEEKITEMWIDTH 40
#define SEEKITEMHEIGHT 60

QString  createUuid() ;
QString createSimpleUuid() ;
int getMSec(QTime t) ;
QTime getTime(int msec) ;

QImage Mat2QImage(Mat const& src) ;
Mat QImage2Mat(QImage const& src) ;

void runProcess( QObject* parent, QString path, QStringList arg ) ;
#define DEFAULTFRAMERATE 29.7

#define VIDEOSCENE 0
#define AUDIOSCENE 1
#define CONTENTSCENE 2

#endif // COMMON_H
