#ifndef CXTEXTDROPDOWNMENU_H
#define CXTEXTDROPDOWNMENU_H

#include <QWidget>
#include "ui_form_text_drop_down.h"

class CxTextDropDownMenu : public QWidget
{
	Q_OBJECT

public:
	CxTextDropDownMenu(QWidget *parent);
	~CxTextDropDownMenu();
signals:
	void __addText( int role ) ;
private slots:
	void onBlack() ;
	void onFlex() ;
	void onWhite() ;
private:
	Ui::Form_Text_DropDown ui ;
};

#endif // CXTEXTDROPDOWNMENU_H
