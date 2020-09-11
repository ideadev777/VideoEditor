#ifndef CXLOGOLISTWIDGET_H
#define CXLOGOLISTWIDGET_H

#include <QListWidget>
#include "common.h"
#include "cxgraphicsscene.h"

class LogoItem : public QListWidgetItem
{
public:
	LogoItem(CxImageItem* item) ;
	QPointF myPos(){ return m_pos ; }
	QSizeF mySize() { return m_size ; }
	QString imagePath(){ return m_path ; }
private:
	CxImageItem* m_image ;
	QPointF m_pos ;
	QSizeF m_size ;
	QString m_path ;
};

class CxLogoListWidget : public QListWidget
{
	Q_OBJECT

public:
	CxLogoListWidget(QWidget *parent);
	~CxLogoListWidget();
	void addMyItem( CxImageItem* item ) ;
public slots:
	void onRemoveLogo() ;
private:
	
};

#endif // CXLOGOLISTWIDGET_H
