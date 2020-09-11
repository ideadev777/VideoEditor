/********************************************************************************
** Form generated from reading UI file 'form_text_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TEXT_EDIT_H
#define UI_FORM_TEXT_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Text_Edit
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QToolButton *tb_col_5;
    QToolButton *tb_col_6;
    QToolButton *tb_col_4;
    QToolButton *tb_col_2;
    QToolButton *tb_col_3;
    QToolButton *tb_col_1;
    QComboBox *cb_font_size;
    QToolButton *tb_col_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QFontComboBox *fontComboBox;
    QToolButton *toolButton_6;
    QToolButton *tb_underline;

    void setupUi(QWidget *Form_Text_Edit)
    {
        if (Form_Text_Edit->objectName().isEmpty())
            Form_Text_Edit->setObjectName(QStringLiteral("Form_Text_Edit"));
        Form_Text_Edit->resize(241, 70);
        gridLayout = new QGridLayout(Form_Text_Edit);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(Form_Text_Edit);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tb_col_5 = new QToolButton(widget);
        tb_col_5->setObjectName(QStringLiteral("tb_col_5"));
        tb_col_5->setMinimumSize(QSize(24, 24));
        tb_col_5->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_5, 0, 4, 1, 1);

        tb_col_6 = new QToolButton(widget);
        tb_col_6->setObjectName(QStringLiteral("tb_col_6"));
        tb_col_6->setMinimumSize(QSize(24, 24));
        tb_col_6->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_6, 0, 5, 1, 1);

        tb_col_4 = new QToolButton(widget);
        tb_col_4->setObjectName(QStringLiteral("tb_col_4"));
        tb_col_4->setMinimumSize(QSize(24, 24));
        tb_col_4->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_4, 0, 3, 1, 1);

        tb_col_2 = new QToolButton(widget);
        tb_col_2->setObjectName(QStringLiteral("tb_col_2"));
        tb_col_2->setMinimumSize(QSize(24, 24));
        tb_col_2->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_2, 0, 1, 1, 1);

        tb_col_3 = new QToolButton(widget);
        tb_col_3->setObjectName(QStringLiteral("tb_col_3"));
        tb_col_3->setMinimumSize(QSize(24, 24));
        tb_col_3->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_3, 0, 2, 1, 1);

        tb_col_1 = new QToolButton(widget);
        tb_col_1->setObjectName(QStringLiteral("tb_col_1"));
        tb_col_1->setMinimumSize(QSize(24, 24));
        tb_col_1->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_1, 0, 0, 1, 1);

        cb_font_size = new QComboBox(widget);
        cb_font_size->setObjectName(QStringLiteral("cb_font_size"));

        gridLayout_2->addWidget(cb_font_size, 0, 7, 1, 1);

        tb_col_7 = new QToolButton(widget);
        tb_col_7->setObjectName(QStringLiteral("tb_col_7"));
        tb_col_7->setMinimumSize(QSize(24, 24));
        tb_col_7->setMaximumSize(QSize(24, 24));

        gridLayout_2->addWidget(tb_col_7, 0, 6, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget_2 = new QWidget(Form_Text_Edit);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        fontComboBox = new QFontComboBox(widget_2);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        gridLayout_3->addWidget(fontComboBox, 0, 0, 1, 1);

        toolButton_6 = new QToolButton(widget_2);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(25, 25));
        toolButton_6->setMaximumSize(QSize(25, 25));

        gridLayout_3->addWidget(toolButton_6, 0, 1, 1, 1);

        tb_underline = new QToolButton(widget_2);
        tb_underline->setObjectName(QStringLiteral("tb_underline"));
        tb_underline->setMinimumSize(QSize(25, 25));
        tb_underline->setMaximumSize(QSize(25, 25));
        tb_underline->setCheckable(true);

        gridLayout_3->addWidget(tb_underline, 0, 2, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);


        retranslateUi(Form_Text_Edit);

        QMetaObject::connectSlotsByName(Form_Text_Edit);
    } // setupUi

    void retranslateUi(QWidget *Form_Text_Edit)
    {
        Form_Text_Edit->setWindowTitle(QApplication::translate("Form_Text_Edit", "Form", 0));
        tb_col_5->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_6->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_4->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_2->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_3->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_1->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        tb_col_7->setText(QApplication::translate("Form_Text_Edit", "...", 0));
        toolButton_6->setText(QApplication::translate("Form_Text_Edit", "F", 0));
        tb_underline->setText(QApplication::translate("Form_Text_Edit", "U", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Text_Edit: public Ui_Form_Text_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TEXT_EDIT_H
