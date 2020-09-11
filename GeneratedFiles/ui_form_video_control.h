/********************************************************************************
** Form generated from reading UI file 'form_video_control.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VIDEO_CONTROL_H
#define UI_FORM_VIDEO_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>
#include "cxborderaniwidget.h"
#include "cxprogresslabel.h"

QT_BEGIN_NAMESPACE

class Ui_Form_Video_Control
{
public:
    QGridLayout *gridLayout;
    CxBorderAniWidget *w_ani;
    QGridLayout *gridLayout_4;
    CxProgressLabel *lbl_seek;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *lbl_cur_time;
    QProgressBar *progressBar;

    void setupUi(QWidget *Form_Video_Control)
    {
        if (Form_Video_Control->objectName().isEmpty())
            Form_Video_Control->setObjectName(QStringLiteral("Form_Video_Control"));
        Form_Video_Control->resize(369, 100);
        Form_Video_Control->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(Form_Video_Control);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 0, 20, 0);
        w_ani = new CxBorderAniWidget(Form_Video_Control);
        w_ani->setObjectName(QStringLiteral("w_ani"));
        w_ani->setMinimumSize(QSize(0, 51));
        w_ani->setMaximumSize(QSize(16777215, 51));
        gridLayout_4 = new QGridLayout(w_ani);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 25, 0, 15);
        lbl_seek = new CxProgressLabel(w_ani);
        lbl_seek->setObjectName(QStringLiteral("lbl_seek"));
        lbl_seek->setMinimumSize(QSize(0, 16));
        lbl_seek->setMaximumSize(QSize(16777215, 16));
        lbl_seek->setStyleSheet(QStringLiteral("background-color: red;"));

        gridLayout_4->addWidget(lbl_seek, 0, 0, 1, 1);


        gridLayout->addWidget(w_ani, 0, 0, 1, 1);

        widget = new QWidget(Form_Video_Control);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("background-color:#535353\n"
""));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lbl_cur_time = new QLabel(widget_3);
        lbl_cur_time->setObjectName(QStringLiteral("lbl_cur_time"));
        QFont font;
        font.setPointSize(12);
        lbl_cur_time->setFont(font);
        lbl_cur_time->setStyleSheet(QLatin1String("color:white;\n"
""));

        gridLayout_3->addWidget(lbl_cur_time, 0, 0, 1, 1);

        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QFont font1;
        font1.setPointSize(14);
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QStringLiteral("color:white;"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(Form_Video_Control);

        QMetaObject::connectSlotsByName(Form_Video_Control);
    } // setupUi

    void retranslateUi(QWidget *Form_Video_Control)
    {
        Form_Video_Control->setWindowTitle(QApplication::translate("Form_Video_Control", "Form", 0));
        lbl_seek->setText(QString());
        lbl_cur_time->setText(QApplication::translate("Form_Video_Control", "0:00/0:00", 0));
    } // retranslateUi

};

namespace Ui {
    class Form_Video_Control: public Ui_Form_Video_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VIDEO_CONTROL_H
