/********************************************************************************
** Form generated from reading UI file 'form_layer_item_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_LAYER_ITEM_WIDGET_H
#define UI_FORM_LAYER_ITEM_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <cxfadebutton.h>
#include "cxresizablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_Form_Layer_Item_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *lbl_path;
    CxResizableLabel *lbl_preview;
    QLabel *lbl_rank;
    CxFadeButton *tb_fade;

    void setupUi(QWidget *Form_Layer_Item_Widget)
    {
        if (Form_Layer_Item_Widget->objectName().isEmpty())
            Form_Layer_Item_Widget->setObjectName(QStringLiteral("Form_Layer_Item_Widget"));
        Form_Layer_Item_Widget->resize(505, 40);
        Form_Layer_Item_Widget->setMinimumSize(QSize(0, 40));
        Form_Layer_Item_Widget->setMaximumSize(QSize(16777215, 40));
        gridLayout = new QGridLayout(Form_Layer_Item_Widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Form_Layer_Item_Widget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_path = new QLabel(widget);
        lbl_path->setObjectName(QStringLiteral("lbl_path"));
        lbl_path->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Century Gothic"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_path->setFont(font);
        lbl_path->setStyleSheet(QStringLiteral("color:white;"));
        lbl_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(lbl_path, 0, 2, 1, 1);

        lbl_preview = new CxResizableLabel(widget);
        lbl_preview->setObjectName(QStringLiteral("lbl_preview"));
        lbl_preview->setMinimumSize(QSize(0, 40));
        lbl_preview->setMaximumSize(QSize(40, 16777215));
        lbl_preview->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(lbl_preview, 0, 1, 1, 1);

        lbl_rank = new QLabel(widget);
        lbl_rank->setObjectName(QStringLiteral("lbl_rank"));
        lbl_rank->setMinimumSize(QSize(25, 40));
        lbl_rank->setMaximumSize(QSize(25, 167777));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_rank->setFont(font1);
        lbl_rank->setStyleSheet(QStringLiteral("color:white;"));
        lbl_rank->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lbl_rank, 0, 0, 1, 1);

        tb_fade = new CxFadeButton(widget);
        tb_fade->setObjectName(QStringLiteral("tb_fade"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tb_fade->sizePolicy().hasHeightForWidth());
        tb_fade->setSizePolicy(sizePolicy);
        tb_fade->setMinimumSize(QSize(40, 40));
        tb_fade->setMaximumSize(QSize(40, 40));
        tb_fade->setCheckable(true);
        tb_fade->setChecked(true);

        gridLayout_2->addWidget(tb_fade, 0, 3, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Form_Layer_Item_Widget);

        QMetaObject::connectSlotsByName(Form_Layer_Item_Widget);
    } // setupUi

    void retranslateUi(QWidget *Form_Layer_Item_Widget)
    {
        Form_Layer_Item_Widget->setWindowTitle(QApplication::translate("Form_Layer_Item_Widget", "Form", 0));
        lbl_path->setText(QApplication::translate("Form_Layer_Item_Widget", "Training Motivation - Floyd Mayweather - Get Money (KP).mp4", 0));
        lbl_preview->setText(QApplication::translate("Form_Layer_Item_Widget", "TextLabel", 0));
        lbl_rank->setText(QApplication::translate("Form_Layer_Item_Widget", "99", 0));
        tb_fade->setText(QApplication::translate("Form_Layer_Item_Widget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Layer_Item_Widget: public Ui_Form_Layer_Item_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_LAYER_ITEM_WIDGET_H
