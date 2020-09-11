#include "cxwhitemodetextbutton.h"
#include <QResizeEvent>


CxWhiteModeTextButton::CxWhiteModeTextButton(QWidget *parent)
	: QToolButton(parent)
{
	setMouseTracking(true) ;
}

CxWhiteModeTextButton::~CxWhiteModeTextButton()
{

}

void CxWhiteModeTextButton::enterEvent(QEvent* event)
{
	QToolButton::enterEvent(event) ;
	emit __showFlexMenu() ;
}

void CxWhiteModeTextButton::resizeEvent(QResizeEvent* event)
{
	QToolButton::resizeEvent(event) ;
}

void CxWhiteModeTextButton::leaveEvent(QEvent *event)
{
	QToolButton::leaveEvent(event) ;
}

void CxWhiteModeTextButton::focusOutEvent(QFocusEvent *e)
{
	QToolButton::focusOutEvent(e) ;
}


