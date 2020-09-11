#include "cxmarkpanel.h"

CxMarkPanel::CxMarkPanel(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this) ;
    setWindowFlags(Qt::CustomizeWindowHint|Qt::Popup);

    ui.btn_color->setId(ui.tb_col_1, 0);
    ui.btn_color->setId(ui.tb_col_2, 1);
    ui.btn_color->setId(ui.tb_col_3, 2);
    ui.btn_color->setId(ui.tb_col_4, 3);
    ui.btn_color->setId(ui.tb_col_5, 4);
    ui.btn_color->setId(ui.tb_col_6, 5);
    ui.btn_color->setId(ui.tb_col_7, 6);
    ui.btn_color->setId(ui.tb_col_8, 7);

    ui.tb_col_1->setColor(Qt::black);
    ui.tb_col_2->setColor(Qt::magenta);
    ui.tb_col_3->setColor(Qt::red);
    ui.tb_col_4->setColor(Qt::green);
    ui.tb_col_5->setColor(Qt::blue);
    ui.tb_col_6->setColor(Qt::yellow);
    ui.tb_col_7->setColor(Qt::white);
    ui.tb_col_8->setColor(Qt::cyan);

    connect( ui.tb_rect, SIGNAL(clicked()), this, SLOT(onRect())) ;
    connect( ui.tb_circle, SIGNAL(clicked()), this, SLOT(onCircle())) ;
    connect( ui.tb_line, SIGNAL(clicked()), this, SLOT(onLine())) ;
	connect( ui.tb_number, SIGNAL(clicked()), this, SLOT(onNumber())) ;
}

void CxMarkPanel::onRect()
{
    emitSignal(RECTMARKROLE);
}

void CxMarkPanel::onCircle()
{
    emitSignal(CIRCLEMARKROLE);

}

void CxMarkPanel::onLine()
{
    emitSignal(LINEMARKROLE);
}

void CxMarkPanel::onNumber()
{
	emitSignal(NUMBERMARKROLE) ;
}

void CxMarkPanel::emitSignal(int role)
{
    QColor col(Qt::red) ;
    CxColorButton* btn = (CxColorButton*)ui.btn_color->checkedButton() ;
    if( btn ) col = btn->color() ;
    hide() ;
    emit __drawMark(role, col);
}
