#include "cxcustombutton.h"
#include <QPainter>
#include <QFontMetrics>
#include <QPaintEvent>

CxCustomButton::CxCustomButton(QWidget *parent)
	: QToolButton(parent), m_role(-1)
{
}

CxCustomButton::~CxCustomButton()
{

}

void CxCustomButton::paintEvent(QPaintEvent *event)
{
	if( m_role == -1 ) return ;
	QPainter painter(this) ;
	int leftmargin = 10 ;
	int w = width() ;
	int h = height() ;
	if( isDefaultButton() )
	{
		painter.setBrush(Qt::black) ;
		painter.drawRect( 0, 0, w, h ) ;
		painter.setBrush(QBrush(m_color)) ;
		painter.setPen(Qt::NoPen) ;
		painter.drawRect( 2, 2, w-4, h-6 ) ;
		if( m_role == SINGLEGRAPHICVID )
		{
			painter.setBrush(QBrush(QColor("#fff200"))) ;
		}
		if( m_role == CREATENEWVIDEOBTN )
		{
			painter.setBrush(QBrush(QColor("#e21c24"))) ;
		}
		painter.setPen(Qt::NoPen) ;
		painter.drawRect(2,2,leftmargin,h-6) ;
		painter.setFont(font()) ;
		painter.setPen(Qt::black) ;
		painter.drawText(2,2,w-4,h-6,Qt::AlignCenter,text()) ;
		return ;
	}
//	if( m_role == -1 ) return ;
	QString txt ;
	QFontMetrics metrics(font()) ;
	painter.setFont(font()) ;
	painter.setPen( QPen(QBrush("#555555"),2) ) ;
	if( m_role == PLAYBTN )
	{
		QPixmap pix = QPixmap(":/res/play.png") ;
		if( isChecked() ) pix = QPixmap(":/res/pause.png") ;
		painter.drawPixmap(0,0,pix.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
	}
	if( m_role == SHOWCATEGORYBTN )
	{
		painter.setPen(Qt::NoPen) ;
		painter.setBrush(QBrush(m_color)) ;
		QPolygon poly ;
		poly << QPoint(0,h/2) << QPoint(w,0) << QPoint(w,h) ;
		painter.drawPolygon(poly) ;
	}
	if( m_role == SHOWFULLSCREENBTN )
	{
		painter.setPen(QPen(QBrush("#C3C3C3"), 3)) ;
		painter.setBrush(Qt::NoBrush) ;
		painter.drawRect(1,1,w-2,h-2) ;
		painter.setPen(Qt::NoPen) ;
		painter.setBrush(QBrush(m_color)) ;
		int x(11),y(7) ;
		painter.drawRect( x,y,w-2*x,h-2*y) ;
	}
	if( m_role == ADDAUDIOBTN )
	{
		txt = text();
		QFont ft = font() ;
		ft.setUnderline(true) ;
		painter.setFont(ft) ;
		int tw = metrics.width(txt) ;
		int sz = 30 ;
		int s = (w-tw-sz+5)/2 ;
		painter.setBrush(QBrush(m_color)) ;
		painter.drawRect(0,0,w,h) ;
		painter.setPen(Qt::black) ;
		painter.drawText(s,0,tw,h,Qt::AlignCenter,txt) ;
		painter.drawPixmap(s+tw+5, (h-sz)/2, sz,sz,QPixmap(":/res/fileopen.png").scaled(sz,sz,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
	}
	if( m_role == EDITVIDEOBTN )
	{
		txt = "EDIT VIDEO" ;
		painter.setBrush(Qt::black) ;
		painter.drawRect( 0, 0, w, h ) ;

		int tw = metrics.width(txt) ;
		int sz = 20 ;

		int s = (w-tw-sz+5)/2 ;
		painter.setBrush(QBrush(m_color)) ;
		painter.setPen(Qt::NoPen) ;
		painter.drawRect(2,2,w-4,h-6) ;
		painter.setPen(Qt::black) ;
		painter.drawText(s,0,tw,h,Qt::AlignCenter,txt) ;
		painter.drawPixmap(s+tw+5, (h-sz)/2, sz,sz,QPixmap(":/res/edit_video.png").scaled(sz,sz,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
		painter.setBrush(QBrush(QColor("#00A2E8"))) ;
		painter.setPen(Qt::NoPen) ;
		painter.drawRect(2,2,leftmargin,h-6) ;
	}
	if( m_role == INPUTIMAGEBTN )
	{
		painter.setPen( QPen(QBrush("#ADADAD"),2) ) ;
		painter.setBrush(QBrush(m_color)) ;
		painter.drawRect(0,0,w,h) ;
		txt = "INPUT IMAGE CONTENT" ;
		int tw = metrics.width(txt) ;
		int sz = 25 ;
		int s = (w-tw-sz+5)/2 ;
		painter.setPen(Qt::black) ;
		painter.drawText(s, 0, tw, h, Qt::AlignCenter, txt ) ;
		painter.setPen(QPen(Qt::black,1)) ;
		painter.setBrush(Qt::NoBrush) ;
		painter.drawRect(s+tw+5, (h-sz)/2, sz,sz);
		painter.drawRect(s+tw+5+sz/2,(h-sz)/2+3,10,10);

		/*
		txt = "CONTENT" ;
		int tw = metrics.width(txt) ;
		int sz = 18 ;
		
		painter.setPen( QPen(QBrush("#ADADAD"),2) ) ;
		painter.setBrush(QBrush(m_color)) ;
		painter.drawRect(0,0,w,h) ;
		int s = (w-tw-sz+5)/2 ;
		painter.setPen(Qt::black) ;
		painter.drawText(0,0,w,h/2,Qt::AlignCenter,"INPUT IMAGE") ;
		painter.drawText(s, h/2, tw, h/2, Qt::AlignCenter, txt ) ;

		painter.setPen(QPen(Qt::black)) ;
		painter.setBrush(Qt::NoBrush) ;
		painter.drawRect(s+tw+5, h/2+(h/2-sz)/2, sz,sz) ;
		painter.drawRect(s+tw+5+sz/2, h/2+(h/2-sz)/2+2, sz/2,sz/2) ;
//		painter.drawPixmap(s+tw+5, h/2+(h/2-sz)/2, sz,sz,QPixmap(":/res/edit_video.png").scaled(sz,sz,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)) ;
*/
	}
	if( m_role == FULLSCREENIMAGEBTN )
	{
		painter.setPen( QPen(QBrush("#ADADAD"),2) ) ;
		painter.setBrush(QBrush(m_color)) ;
		painter.drawRect(0,0,w,h) ;
		txt = "FULLSCREEN IMAGE" ;
		int tw = metrics.width(txt) ;
		int sz = 25 ;
		int s = (w-tw-sz+5)/2 ;
		painter.setPen(Qt::black) ;
		painter.drawText(s, 0, tw, h, Qt::AlignCenter, txt ) ;
		painter.setPen(QPen(Qt::black,1)) ;
		painter.setBrush(Qt::NoBrush) ;
		painter.drawRect(s+tw+5, (h-sz)/2, sz,sz);
		painter.drawRect(s+tw+3+5, (h-sz+10)/2, sz-6,sz-10);
	}
}

bool CxCustomButton::isDefaultButton()
{
	return m_role == CREATENEWVIDEOBTN || m_role == SINGLEGRAPHICVID ;
}
void CxCustomButton::enterEvent(QEvent *event)
{
	if( !isEnabled() ) return ;
	if( m_role == EDITVIDEOBTN || m_role == CREATENEWVIDEOBTN ) m_color = QColor("#535353") ;
	if( m_role == INPUTIMAGEBTN || m_role == FULLSCREENIMAGEBTN )  m_color = QColor("#E5F1FB") ;
	if( m_role == SHOWCATEGORYBTN )
	{
//		setCursor(Qt::PointingHandCursor) ;
		m_color = QColor("#FFFF00") ;
	}
	if( m_role == SHOWFULLSCREENBTN ) {
		m_color = QColor("#FFFF00") ;
	}
	if( m_role == ADDAUDIOBTN )
	{
		m_color = QColor("#FFD764") ;
	}
	repaint() ;
}

void CxCustomButton::leaveEvent(QEvent* event)
{
	if( m_role == EDITVIDEOBTN || m_role == CREATENEWVIDEOBTN ) m_color = QColor("#C3C3C3") ;
	if( m_role == INPUTIMAGEBTN || m_role == FULLSCREENIMAGEBTN )  m_color = QColor("#E1E1E1") ;
	if( m_role == SHOWCATEGORYBTN ) m_color = QColor("#FFF200") ;
	if( m_role == SHOWFULLSCREENBTN || m_role == ADDAUDIOBTN ) m_color = QColor("#FFF200") ;
}

void CxCustomButton::onClick()
{
	repaint() ;
}

void CxCustomButton::setRole( int role )
{
	m_role = role ;
	if( m_role == PLAYBTN )
	{
		connect( this, SIGNAL(clicked()), this, SLOT(onClick())) ;
		setCheckable(true) ;
	}
	if( m_role == EDITVIDEOBTN || m_role == SINGLEGRAPHICVID || m_role == CREATENEWVIDEOBTN ) m_color = QColor("#C3C3C3") ;
	if( m_role == INPUTIMAGEBTN || m_role == FULLSCREENIMAGEBTN ) m_color = QColor("#E1E1E1") ;
	if( m_role == SHOWCATEGORYBTN ) {
		m_color = QColor("#FFF200") ;
		setCursor(Qt::PointingHandCursor) ;
	}
	if( m_role == SHOWFULLSCREENBTN ) 
	{
		m_color = QColor("#FFF200") ;
		setCursor(Qt::PointingHandCursor) ;
	}
	if( m_role == ADDAUDIOBTN )
	{
		m_color = QColor("#FFF200") ;
	}
	repaint() ; 
}