#include "cxtextdropdownmenu.h"

CxTextDropDownMenu::CxTextDropDownMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this) ;
	connect( ui.tb_flex, SIGNAL(clicked()), this, SLOT(onFlex())) ;
	connect( ui.tb_white, SIGNAL(clicked()), this, SLOT(onWhite())) ;
	connect( ui.tb_black, SIGNAL(clicked()), this, SLOT(onBlack())) ;
	ui.tb_black->hide() ;
}

CxTextDropDownMenu::~CxTextDropDownMenu()
{

}

void CxTextDropDownMenu::onBlack()
{
	emit __addText(1) ;
}

void CxTextDropDownMenu::onWhite()
{
	emit __addText(2) ;
}

void CxTextDropDownMenu::onFlex()
{
	emit __addText(0) ;
}