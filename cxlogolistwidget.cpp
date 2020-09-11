#include "cxlogolistwidget.h"
#define LOGOH 45
#define LOGOW 60

//////////////////////////////////////////////////////////////////////////

LogoItem::LogoItem(CxImageItem* image)
{
	m_image = image ;
	setSizeHint(QSize(LOGOW,LOGOH)) ;
	setIcon(QIcon(image->myPixmap())) ;
	m_pos = image->pos() ;
	m_size = image->rect().size() ;
	m_path = image->imageSource() ;
}


//////////////////////////////////////////////////////////////////////////

CxLogoListWidget::CxLogoListWidget(QWidget *parent)
	: QListWidget(parent)
{
	setViewMode(QListView::IconMode) ;
	setLayoutDirection(Qt::LeftToRight) ;
	setIconSize(QSize(LOGOW,LOGOH)) ;
	setFlow(QListView::LeftToRight) ;
	setDragDropMode(QAbstractItemView::NoDragDrop) ;
	setWrapping(false);
}

CxLogoListWidget::~CxLogoListWidget()
{

}

void CxLogoListWidget::addMyItem( CxImageItem* image )
{
	LogoItem* item = new LogoItem(image) ;
	addItem(item) ;
}

void CxLogoListWidget::onRemoveLogo()
{
	takeItem(currentRow()) ;
}
