#ifndef CXTEXTEDITPANEL_H
#define CXTEXTEDITPANEL_H

#include <QWidget>
#include "ui_form_text_edit.h"
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextDocument>
#include <QGraphicsTextItem>

class CxTextEditPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CxTextEditPanel(QWidget *parent = 0);
    Ui::Form_Text_Edit form(){ return ui; }
    void showTextCursor(QGraphicsTextItem* item) ;
signals:
    
public slots:
    void onFontFamilyChanged(QFont f) ;
    void onFontSizeChanged( QString str ) ;
    void onUnderlineStateChanged() ;
private:
    Ui::Form_Text_Edit ui ;
    QGraphicsTextItem* m_item;
    bool m_isRemote ;
};

#endif // CXTEXTEDITPANEL_H
