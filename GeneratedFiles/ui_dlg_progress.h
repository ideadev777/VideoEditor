/********************************************************************************
** Form generated from reading UI file 'dlg_progress.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_PROGRESS_H
#define UI_DLG_PROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Progress
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLabel *lbl_banner;
    QLabel *lbl_status;

    void setupUi(QDialog *Dialog_Progress)
    {
        if (Dialog_Progress->objectName().isEmpty())
            Dialog_Progress->setObjectName(QStringLiteral("Dialog_Progress"));
        Dialog_Progress->resize(688, 80);
        Dialog_Progress->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(Dialog_Progress);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Dialog_Progress);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 40));
        widget->setMaximumSize(QSize(16777215, 40));
        widget->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"border:2px;\n"
"border-color:black;\n"
"border-style:solid;\n"
"}"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 25));
        progressBar->setMaximumSize(QSize(16777215, 25));
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"color:black;\n"
"}"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(progressBar, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(Dialog_Progress);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 40));
        widget_2->setMaximumSize(QSize(16777215, 40));
        widget_2->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#00A7E8;\n"
"}"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(5);
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(5, 0, 0, 0);
        lbl_banner = new QLabel(widget_2);
        lbl_banner->setObjectName(QStringLiteral("lbl_banner"));
        lbl_banner->setMinimumSize(QSize(35, 35));
        lbl_banner->setMaximumSize(QSize(35, 35));

        gridLayout_3->addWidget(lbl_banner, 0, 0, 1, 1);

        lbl_status = new QLabel(widget_2);
        lbl_status->setObjectName(QStringLiteral("lbl_status"));
        lbl_status->setMinimumSize(QSize(0, 40));
        lbl_status->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(18);
        lbl_status->setFont(font);
        lbl_status->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:white;\n"
"}"));

        gridLayout_3->addWidget(lbl_status, 0, 1, 1, 1);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);


        retranslateUi(Dialog_Progress);

        QMetaObject::connectSlotsByName(Dialog_Progress);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Progress)
    {
        Dialog_Progress->setWindowTitle(QApplication::translate("Dialog_Progress", "Dialog", 0));
        lbl_banner->setText(QString());
        lbl_status->setText(QApplication::translate("Dialog_Progress", "Processing...", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Progress: public Ui_Dialog_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_PROGRESS_H
