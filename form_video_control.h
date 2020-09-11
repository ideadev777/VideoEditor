#ifndef FORM_VIDEO_CONTROL_H
#define FORM_VIDEO_CONTROL_H

#include <QWidget>

namespace Ui {
class Form_Video_Control;
}

class Form_Video_Control : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form_Video_Control(QWidget *parent = 0);
    ~Form_Video_Control();
    
private:
    Ui::Form_Video_Control *ui;
};

#endif // FORM_VIDEO_CONTROL_H
