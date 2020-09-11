#ifndef CXRESIZABLELABEL_H
#define CXRESIZABLELABEL_H

#include <QLabel>

class CxResizableLabel : public QLabel
{
	Q_OBJECT

public:
	CxResizableLabel(QWidget *parent);
	~CxResizableLabel();
	void setMyPixmap( QPixmap pix ) ;
protected:
	void paintEvent(QPaintEvent* event) ;
private:
	QPixmap m_pix ;
};

#endif // CXRESIZABLELABEL_H
