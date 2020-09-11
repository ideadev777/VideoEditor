#include "form_video_control.h"
#include "ui_form_video_control.h"

Form_Video_Control::Form_Video_Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Video_Control)
{
    ui->setupUi(this);
}

Form_Video_Control::~Form_Video_Control()
{
    delete ui;
}
