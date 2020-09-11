/********************************************************************************
** Form generated from reading UI file 'form_mark_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_MARK_PANEL_H
#define UI_FORM_MARK_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "cxcolorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_Form_Mark_Panel
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    CxColorButton *tb_col_1;
    CxColorButton *tb_col_2;
    CxColorButton *tb_col_3;
    CxColorButton *tb_col_4;
    CxColorButton *tb_col_5;
    CxColorButton *tb_col_6;
    CxColorButton *tb_col_7;
    CxColorButton *tb_col_8;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    QToolButton *tb_rect;
    QToolButton *tb_circle;
    QToolButton *tb_line;
    QToolButton *tb_number;
    QButtonGroup *btn_color;

    void setupUi(QWidget *Form_Mark_Panel)
    {
        if (Form_Mark_Panel->objectName().isEmpty())
            Form_Mark_Panel->setObjectName(QStringLiteral("Form_Mark_Panel"));
        Form_Mark_Panel->resize(185, 140);
        Form_Mark_Panel->setMaximumSize(QSize(185, 16777215));
        gridLayout = new QGridLayout(Form_Mark_Panel);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(Form_Mark_Panel);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(111, 16777215));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(35, 35));
        label->setMaximumSize(QSize(35, 35));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/mark.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(Form_Mark_Panel);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(155, 16777215));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 25));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tb_col_1 = new CxColorButton(widget_3);
        btn_color = new QButtonGroup(Form_Mark_Panel);
        btn_color->setObjectName(QStringLiteral("btn_color"));
        btn_color->addButton(tb_col_1);
        tb_col_1->setObjectName(QStringLiteral("tb_col_1"));
        tb_col_1->setMinimumSize(QSize(20, 20));
        tb_col_1->setMaximumSize(QSize(20, 20));
        tb_col_1->setCheckable(true);
        tb_col_1->setChecked(true);

        gridLayout_4->addWidget(tb_col_1, 0, 0, 1, 1);

        tb_col_2 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_2);
        tb_col_2->setObjectName(QStringLiteral("tb_col_2"));
        tb_col_2->setMinimumSize(QSize(20, 20));
        tb_col_2->setMaximumSize(QSize(20, 20));
        tb_col_2->setCheckable(true);

        gridLayout_4->addWidget(tb_col_2, 0, 1, 1, 1);

        tb_col_3 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_3);
        tb_col_3->setObjectName(QStringLiteral("tb_col_3"));
        tb_col_3->setMinimumSize(QSize(20, 20));
        tb_col_3->setMaximumSize(QSize(20, 20));
        tb_col_3->setCheckable(true);

        gridLayout_4->addWidget(tb_col_3, 0, 2, 1, 1);

        tb_col_4 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_4);
        tb_col_4->setObjectName(QStringLiteral("tb_col_4"));
        tb_col_4->setMinimumSize(QSize(20, 20));
        tb_col_4->setMaximumSize(QSize(20, 20));
        tb_col_4->setCheckable(true);

        gridLayout_4->addWidget(tb_col_4, 0, 3, 1, 1);

        tb_col_5 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_5);
        tb_col_5->setObjectName(QStringLiteral("tb_col_5"));
        tb_col_5->setMinimumSize(QSize(20, 20));
        tb_col_5->setMaximumSize(QSize(20, 20));
        tb_col_5->setCheckable(true);

        gridLayout_4->addWidget(tb_col_5, 0, 4, 1, 1);

        tb_col_6 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_6);
        tb_col_6->setObjectName(QStringLiteral("tb_col_6"));
        tb_col_6->setMinimumSize(QSize(20, 20));
        tb_col_6->setMaximumSize(QSize(20, 20));
        tb_col_6->setCheckable(true);

        gridLayout_4->addWidget(tb_col_6, 0, 5, 1, 1);

        tb_col_7 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_7);
        tb_col_7->setObjectName(QStringLiteral("tb_col_7"));
        tb_col_7->setMinimumSize(QSize(20, 20));
        tb_col_7->setMaximumSize(QSize(20, 20));
        tb_col_7->setCheckable(true);

        gridLayout_4->addWidget(tb_col_7, 0, 6, 1, 1);

        tb_col_8 = new CxColorButton(widget_3);
        btn_color->addButton(tb_col_8);
        tb_col_8->setObjectName(QStringLiteral("tb_col_8"));
        tb_col_8->setMinimumSize(QSize(20, 20));
        tb_col_8->setMaximumSize(QSize(20, 20));
        tb_col_8->setCheckable(true);

        gridLayout_4->addWidget(tb_col_8, 0, 7, 1, 1);


        gridLayout_3->addWidget(widget_3, 0, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        tb_rect = new QToolButton(widget_4);
        tb_rect->setObjectName(QStringLiteral("tb_rect"));
        tb_rect->setMinimumSize(QSize(75, 60));
        tb_rect->setMaximumSize(QSize(100, 75));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_rect->setIcon(icon);
        tb_rect->setIconSize(QSize(50, 50));

        gridLayout_5->addWidget(tb_rect, 0, 0, 1, 1);

        tb_circle = new QToolButton(widget_4);
        tb_circle->setObjectName(QStringLiteral("tb_circle"));
        tb_circle->setMinimumSize(QSize(75, 60));
        tb_circle->setMaximumSize(QSize(100, 75));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_circle->setIcon(icon1);
        tb_circle->setIconSize(QSize(50, 50));

        gridLayout_5->addWidget(tb_circle, 0, 1, 1, 1);

        tb_line = new QToolButton(widget_4);
        tb_line->setObjectName(QStringLiteral("tb_line"));
        tb_line->setMinimumSize(QSize(75, 60));
        tb_line->setMaximumSize(QSize(100, 75));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_line->setIcon(icon2);
        tb_line->setIconSize(QSize(50, 50));

        gridLayout_5->addWidget(tb_line, 1, 0, 1, 1);

        tb_number = new QToolButton(widget_4);
        tb_number->setObjectName(QStringLiteral("tb_number"));
        tb_number->setMinimumSize(QSize(75, 60));
        tb_number->setMaximumSize(QSize(100, 75));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/number.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_number->setIcon(icon3);
        tb_number->setIconSize(QSize(50, 50));

        gridLayout_5->addWidget(tb_number, 1, 1, 1, 1);


        gridLayout_3->addWidget(widget_4, 1, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 1, 1, 1);


        retranslateUi(Form_Mark_Panel);

        QMetaObject::connectSlotsByName(Form_Mark_Panel);
    } // setupUi

    void retranslateUi(QWidget *Form_Mark_Panel)
    {
        Form_Mark_Panel->setWindowTitle(QApplication::translate("Form_Mark_Panel", "Form", 0));
        label->setText(QString());
        tb_col_1->setText(QString());
        tb_col_2->setText(QString());
        tb_col_3->setText(QString());
        tb_col_4->setText(QString());
        tb_col_5->setText(QString());
        tb_col_6->setText(QString());
        tb_col_7->setText(QString());
        tb_col_8->setText(QString());
        tb_rect->setText(QApplication::translate("Form_Mark_Panel", "RECTANGLE", 0));
        tb_circle->setText(QApplication::translate("Form_Mark_Panel", "CIRCLE", 0));
        tb_line->setText(QApplication::translate("Form_Mark_Panel", "LINE", 0));
        tb_number->setText(QApplication::translate("Form_Mark_Panel", "NUMBER", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Mark_Panel: public Ui_Form_Mark_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_MARK_PANEL_H
