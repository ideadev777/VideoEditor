#ifndef CXMARKPANEL_H
#define CXMARKPANEL_H

#include <QWidget>
#include "ui_form_mark_panel.h"
#include "common.h"
class CxMarkPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CxMarkPanel(QWidget *parent = 0);
    Ui::Form_Mark_Panel form(){ return ui; }
signals:
    void __drawMark( int role, QColor col ) ;
public slots:
    void onRect() ;
    void onCircle() ;
    void onLine() ;
    void onNumber() ;
private:
    Ui::Form_Mark_Panel ui ;
    void emitSignal( int role ) ;
};

#endif // CXMARKPANEL_H
