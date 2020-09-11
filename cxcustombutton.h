#ifndef CXCUSTOMBUTTON_H
#define CXCUSTOMBUTTON_H

#include <QToolButton>

#define EDITVIDEOBTN 0
#define INPUTIMAGEBTN 1
#define FULLSCREENIMAGEBTN 2

#define SHOWCATEGORYBTN 3
#define SHOWFULLSCREENBTN 4
#define PLAYBTN 5

#define ADDAUDIOBTN 6

#define CREATENEWVIDEOBTN 7
#define SINGLEGRAPHICVID 8

class CxCustomButton : public QToolButton
{
	Q_OBJECT

public:
	CxCustomButton(QWidget *parent);
	~CxCustomButton();
	void setRole( int role ) ;
protected:
	void paintEvent(QPaintEvent *event) ;
	void enterEvent(QEvent *event) ;
	void leaveEvent(QEvent* event) ;
private slots:
	void onClick() ;
private:
	bool isDefaultButton() ;
	int m_role ;
	QColor m_color ;
};

#endif // CXCUSTOMBUTTON_H
