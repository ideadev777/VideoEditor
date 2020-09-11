/********************************************************************************
** Form generated from reading UI file 'form_text_drop_down.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_TEXT_DROP_DOWN_H
#define UI_FORM_TEXT_DROP_DOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Text_DropDown
{
public:
    QGridLayout *gridLayout;
    QToolButton *tb_flex;
    QToolButton *tb_black;
    QToolButton *tb_white;

    void setupUi(QWidget *Form_Text_DropDown)
    {
        if (Form_Text_DropDown->objectName().isEmpty())
            Form_Text_DropDown->setObjectName(QStringLiteral("Form_Text_DropDown"));
        Form_Text_DropDown->resize(130, 150);
        gridLayout = new QGridLayout(Form_Text_DropDown);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tb_flex = new QToolButton(Form_Text_DropDown);
        tb_flex->setObjectName(QStringLiteral("tb_flex"));
        tb_flex->setMinimumSize(QSize(100, 40));
        tb_flex->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(11);
        tb_flex->setFont(font);
        tb_flex->setIconSize(QSize(16, 16));

        gridLayout->addWidget(tb_flex, 0, 0, 1, 1);

        tb_black = new QToolButton(Form_Text_DropDown);
        tb_black->setObjectName(QStringLiteral("tb_black"));
        tb_black->setMinimumSize(QSize(100, 40));
        tb_black->setMaximumSize(QSize(16777215, 40));
        tb_black->setFont(font);
        tb_black->setIconSize(QSize(16, 16));

        gridLayout->addWidget(tb_black, 1, 0, 1, 1);

        tb_white = new QToolButton(Form_Text_DropDown);
        tb_white->setObjectName(QStringLiteral("tb_white"));
        tb_white->setMinimumSize(QSize(100, 40));
        tb_white->setMaximumSize(QSize(16777215, 40));
        tb_white->setFont(font);
        tb_white->setIconSize(QSize(16, 16));

        gridLayout->addWidget(tb_white, 2, 0, 1, 1);


        retranslateUi(Form_Text_DropDown);

        QMetaObject::connectSlotsByName(Form_Text_DropDown);
    } // setupUi

    void retranslateUi(QWidget *Form_Text_DropDown)
    {
        Form_Text_DropDown->setWindowTitle(QApplication::translate("Form_Text_DropDown", "Form", 0));
        tb_flex->setText(QApplication::translate("Form_Text_DropDown", "FLEX MODE", 0));
        tb_black->setText(QApplication::translate("Form_Text_DropDown", "BLACK MODE", 0));
        tb_white->setText(QApplication::translate("Form_Text_DropDown", "WHITE MODE", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Text_DropDown: public Ui_Form_Text_DropDown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_TEXT_DROP_DOWN_H
