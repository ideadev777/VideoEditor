#ifndef CXWHITEMODETEXTBUTTON_H
#define CXWHITEMODETEXTBUTTON_H

#include <QToolButton>
#include <QEvent.h>
#include <QMenu>

class CxWhiteModeTextButton : public QToolButton
{
	Q_OBJECT

public:
	CxWhiteModeTextButton(QWidget *parent);
	~CxWhiteModeTextButton();
protected:
	void enterEvent(QEvent* event) ;
	void leaveEvent(QEvent *event) ;
	void focusOutEvent(QFocusEvent *e) ;
	void resizeEvent(QResizeEvent* event) ;
signals:
	void __showFlexMenu() ;
private:
};

#endif // CXWHITEMODETEXTBUTTON_H
