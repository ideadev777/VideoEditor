#ifndef CXFADEBUTTON_H
#define CXFADEBUTTON_H

#include <QToolButton>

class CxFadeButton : public QToolButton
{
	Q_OBJECT

public:
	CxFadeButton(QWidget *parent);
	~CxFadeButton();
private slots:
	void onClick() ;
protected:
	void paintEvent(QPaintEvent* event) ;
	void enterEvent(QEvent *event) ;
	void leaveEvent(QEvent *event) ;
private:
	QColor m_color ;
};

#endif // CXFADEBUTTON_H
