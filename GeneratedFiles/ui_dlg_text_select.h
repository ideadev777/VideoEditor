/********************************************************************************
** Form generated from reading UI file 'dlg_text_select.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_TEXT_SELECT_H
#define UI_DLG_TEXT_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "cxcolorbutton.h"
#include "cxcustombutton.h"
#include "cxgraphicsview.h"
#include "cxpaintseekbar.h"
#include "cxwhitemodetextbutton.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog_Text_Popup
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    CxPaintSeekBar *lbl_seek;
    CxGraphicsView *graphicsView;
    QWidget *widget_3;
    QGridLayout *gridLayout_4;
    CxColorButton *tb_text_col_4;
    QToolButton *tb_justify;
    QToolButton *tb_right;
    QToolButton *tb_fill;
    QToolButton *tb_italic;
    CxColorButton *tb_text_col_2;
    QToolButton *tb_underline;
    CxColorButton *tb_text_col_1;
    QToolButton *tb_left;
    QToolButton *tb_delete_item;
    CxWhiteModeTextButton *tb_white_mode;
    QToolButton *tb_bold;
    QComboBox *comboBox;
    QToolButton *tb_center;
    QToolButton *tb_movement;
    CxColorButton *tb_text_col_3;
    QFrame *line;
    QFontComboBox *fontComboBox;
    CxColorButton *tb_text_col_5;
    QToolButton *tb_insert_black_circle_mark;
    QWidget *widget_4;
    QGridLayout *gridLayout_15;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tb_play;
    QWidget *w_scene_control;
    QGridLayout *gridLayout_16;
    QToolButton *tb_next_video;
    QToolButton *tb_prev_video;
    QLabel *label_5;
    QToolButton *tb_add_new_scene;
    QToolButton *tb_item_dur_inc;
    QToolButton *tb_item_dur_dec;
    QLabel *lbl_video_index;
    QToolButton *tb_delete_scene;
    QDoubleSpinBox *dsp_item_dur;
    QTextEdit *textEdit;
    QWidget *w_right;
    QGridLayout *gridLayout_3;
    QToolButton *tb_create;
    QFrame *line_2;
    QFrame *line_3;
    QSpacerItem *verticalSpacer;
    CxCustomButton *tb_change_audio;
    QToolButton *tb_new_video;
    QToolButton *tb_inside_video;
    QWidget *w_draw_panel;
    QGridLayout *gridLayout_17;
    QWidget *w_add_image;
    QGridLayout *gridLayout_20;
    CxCustomButton *tb_image_fullscreen;
    CxCustomButton *tb_image;
    QWidget *widget_12;
    QGridLayout *gridLayout_19;
    QToolButton *tb_arrow_left;
    QToolButton *tb_arrow_down;
    QToolButton *tb_arrow_right;
    QToolButton *tb_arrow_up;
    QWidget *widget_11;
    QGridLayout *gridLayout_18;
    QToolButton *tb_rect;
    QToolButton *tb_circle;
    QToolButton *tb_mark;
    QToolButton *tb_line;
    QToolButton *tb_show_image_panel;
    QWidget *w_inside_video;
    QGridLayout *gridLayout_11;
    QWidget *widget_14;
    QGridLayout *gridLayout_22;
    QTimeEdit *te_insert_pos;
    QLabel *label_7;
    QToolButton *tb_insert_into_video;
    QGroupBox *groupBox_audio;
    QGridLayout *gridLayout_7;
    QWidget *widget_7;
    QGridLayout *gridLayout_9;
    QLabel *label_3;
    QTimeEdit *te_total;
    QWidget *w_audio_dur;
    QGridLayout *gridLayout_12;
    QLabel *label_6;
    QTimeEdit *te_end;
    QTimeEdit *te_start;
    QLabel *label_4;
    QWidget *w_freeze;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QSpinBox *sp_freeze_duration;
    QLabel *label_8;
    QLabel *label_2;
    QToolButton *tb_freeze_save;
    QToolButton *tb_freeze;
    QButtonGroup *btn_text_group;

    void setupUi(QDialog *Dialog_Text_Popup)
    {
        if (Dialog_Text_Popup->objectName().isEmpty())
            Dialog_Text_Popup->setObjectName(QStringLiteral("Dialog_Text_Popup"));
        Dialog_Text_Popup->resize(1378, 875);
        gridLayout = new QGridLayout(Dialog_Text_Popup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        widget = new QWidget(Dialog_Text_Popup);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, -1, -1, -1);
        lbl_seek = new CxPaintSeekBar(widget);
        lbl_seek->setObjectName(QStringLiteral("lbl_seek"));
        lbl_seek->setMinimumSize(QSize(0, 30));
        lbl_seek->setMaximumSize(QSize(16777215, 30));
        lbl_seek->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(lbl_seek, 3, 0, 1, 1);

        graphicsView = new CxGraphicsView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_2->addWidget(graphicsView, 1, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 40));
        gridLayout_4 = new QGridLayout(widget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(2);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tb_text_col_4 = new CxColorButton(widget_3);
        btn_text_group = new QButtonGroup(Dialog_Text_Popup);
        btn_text_group->setObjectName(QStringLiteral("btn_text_group"));
        btn_text_group->addButton(tb_text_col_4);
        tb_text_col_4->setObjectName(QStringLiteral("tb_text_col_4"));
        tb_text_col_4->setMinimumSize(QSize(40, 40));
        tb_text_col_4->setMaximumSize(QSize(40, 40));
        tb_text_col_4->setCheckable(true);

        gridLayout_4->addWidget(tb_text_col_4, 0, 16, 1, 1);

        tb_justify = new QToolButton(widget_3);
        tb_justify->setObjectName(QStringLiteral("tb_justify"));
        tb_justify->setMinimumSize(QSize(40, 40));
        tb_justify->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/win/textjustify.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_justify->setIcon(icon);
        tb_justify->setCheckable(true);

        gridLayout_4->addWidget(tb_justify, 0, 10, 1, 1);

        tb_right = new QToolButton(widget_3);
        tb_right->setObjectName(QStringLiteral("tb_right"));
        tb_right->setMinimumSize(QSize(40, 40));
        tb_right->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/win/textright.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_right->setIcon(icon1);
        tb_right->setCheckable(true);

        gridLayout_4->addWidget(tb_right, 0, 9, 1, 1);

        tb_fill = new QToolButton(widget_3);
        tb_fill->setObjectName(QStringLiteral("tb_fill"));
        tb_fill->setMinimumSize(QSize(40, 40));
        tb_fill->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/bucket.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_fill->setIcon(icon2);
        tb_fill->setIconSize(QSize(32, 32));
        tb_fill->setCheckable(false);
        tb_fill->setChecked(false);

        gridLayout_4->addWidget(tb_fill, 0, 12, 1, 1);

        tb_italic = new QToolButton(widget_3);
        tb_italic->setObjectName(QStringLiteral("tb_italic"));
        tb_italic->setMinimumSize(QSize(40, 40));
        tb_italic->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/win/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_italic->setIcon(icon3);
        tb_italic->setCheckable(true);

        gridLayout_4->addWidget(tb_italic, 0, 3, 1, 1);

        tb_text_col_2 = new CxColorButton(widget_3);
        btn_text_group->addButton(tb_text_col_2);
        tb_text_col_2->setObjectName(QStringLiteral("tb_text_col_2"));
        tb_text_col_2->setMinimumSize(QSize(40, 40));
        tb_text_col_2->setMaximumSize(QSize(40, 40));
        tb_text_col_2->setCheckable(true);

        gridLayout_4->addWidget(tb_text_col_2, 0, 14, 1, 1);

        tb_underline = new QToolButton(widget_3);
        tb_underline->setObjectName(QStringLiteral("tb_underline"));
        tb_underline->setMinimumSize(QSize(40, 40));
        tb_underline->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/win/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_underline->setIcon(icon4);
        tb_underline->setCheckable(true);

        gridLayout_4->addWidget(tb_underline, 0, 4, 1, 1);

        tb_text_col_1 = new CxColorButton(widget_3);
        btn_text_group->addButton(tb_text_col_1);
        tb_text_col_1->setObjectName(QStringLiteral("tb_text_col_1"));
        tb_text_col_1->setMinimumSize(QSize(40, 40));
        tb_text_col_1->setMaximumSize(QSize(40, 40));
        tb_text_col_1->setCheckable(true);
        tb_text_col_1->setChecked(true);

        gridLayout_4->addWidget(tb_text_col_1, 0, 13, 1, 1);

        tb_left = new QToolButton(widget_3);
        tb_left->setObjectName(QStringLiteral("tb_left"));
        tb_left->setMinimumSize(QSize(40, 40));
        tb_left->setMaximumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/win/textleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_left->setIcon(icon5);
        tb_left->setCheckable(true);

        gridLayout_4->addWidget(tb_left, 0, 6, 1, 1);

        tb_delete_item = new QToolButton(widget_3);
        tb_delete_item->setObjectName(QStringLiteral("tb_delete_item"));
        tb_delete_item->setMinimumSize(QSize(40, 40));
        tb_delete_item->setMaximumSize(QSize(40, 40));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/res/del.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_delete_item->setIcon(icon6);
        tb_delete_item->setIconSize(QSize(30, 30));
        tb_delete_item->setCheckable(false);

        gridLayout_4->addWidget(tb_delete_item, 0, 21, 1, 1);

        tb_white_mode = new CxWhiteModeTextButton(widget_3);
        tb_white_mode->setObjectName(QStringLiteral("tb_white_mode"));
        tb_white_mode->setMinimumSize(QSize(0, 40));
        tb_white_mode->setMaximumSize(QSize(15555, 40));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(16);
        tb_white_mode->setFont(font);
        tb_white_mode->setCheckable(false);

        gridLayout_4->addWidget(tb_white_mode, 0, 5, 1, 1);

        tb_bold = new QToolButton(widget_3);
        tb_bold->setObjectName(QStringLiteral("tb_bold"));
        tb_bold->setMinimumSize(QSize(40, 40));
        tb_bold->setMaximumSize(QSize(40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/win/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_bold->setIcon(icon7);
        tb_bold->setCheckable(true);

        gridLayout_4->addWidget(tb_bold, 0, 2, 1, 1);

        comboBox = new QComboBox(widget_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 40));
        comboBox->setMaximumSize(QSize(40, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Impact"));
        font1.setPointSize(10);
        comboBox->setFont(font1);

        gridLayout_4->addWidget(comboBox, 0, 1, 1, 1);

        tb_center = new QToolButton(widget_3);
        tb_center->setObjectName(QStringLiteral("tb_center"));
        tb_center->setMinimumSize(QSize(40, 40));
        tb_center->setMaximumSize(QSize(40, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/win/textcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_center->setIcon(icon8);
        tb_center->setCheckable(true);

        gridLayout_4->addWidget(tb_center, 0, 8, 1, 1);

        tb_movement = new QToolButton(widget_3);
        tb_movement->setObjectName(QStringLiteral("tb_movement"));
        tb_movement->setMinimumSize(QSize(40, 40));
        tb_movement->setMaximumSize(QSize(40, 40));
        tb_movement->setCheckable(false);

        gridLayout_4->addWidget(tb_movement, 0, 20, 1, 1);

        tb_text_col_3 = new CxColorButton(widget_3);
        btn_text_group->addButton(tb_text_col_3);
        tb_text_col_3->setObjectName(QStringLiteral("tb_text_col_3"));
        tb_text_col_3->setMinimumSize(QSize(40, 40));
        tb_text_col_3->setMaximumSize(QSize(40, 40));
        tb_text_col_3->setCheckable(true);

        gridLayout_4->addWidget(tb_text_col_3, 0, 15, 1, 1);

        line = new QFrame(widget_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 19, 1, 1);

        fontComboBox = new QFontComboBox(widget_3);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Impact"));
        font2.setPointSize(12);
        fontComboBox->setFont(font2);

        gridLayout_4->addWidget(fontComboBox, 0, 0, 1, 1);

        tb_text_col_5 = new CxColorButton(widget_3);
        btn_text_group->addButton(tb_text_col_5);
        tb_text_col_5->setObjectName(QStringLiteral("tb_text_col_5"));
        tb_text_col_5->setMinimumSize(QSize(40, 40));
        tb_text_col_5->setMaximumSize(QSize(40, 40));
        tb_text_col_5->setCheckable(true);

        gridLayout_4->addWidget(tb_text_col_5, 0, 17, 1, 1);

        tb_insert_black_circle_mark = new QToolButton(widget_3);
        tb_insert_black_circle_mark->setObjectName(QStringLiteral("tb_insert_black_circle_mark"));
        tb_insert_black_circle_mark->setMinimumSize(QSize(40, 40));
        tb_insert_black_circle_mark->setMaximumSize(QSize(40, 40));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/res/blackcircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_insert_black_circle_mark->setIcon(icon9);
        tb_insert_black_circle_mark->setIconSize(QSize(32, 32));
        tb_insert_black_circle_mark->setCheckable(true);
        tb_insert_black_circle_mark->setChecked(false);

        gridLayout_4->addWidget(tb_insert_black_circle_mark, 0, 11, 1, 1);


        gridLayout_2->addWidget(widget_3, 0, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 50));
        widget_4->setMaximumSize(QSize(16777215, 50));
        gridLayout_15 = new QGridLayout(widget_4);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 20, 0);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        tb_play = new QToolButton(widget_4);
        tb_play->setObjectName(QStringLiteral("tb_play"));
        tb_play->setMinimumSize(QSize(150, 50));
        tb_play->setMaximumSize(QSize(150, 50));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/res/Media-Controls-Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QStringLiteral(":/res/Media-Controls-Pause-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        tb_play->setIcon(icon10);
        tb_play->setIconSize(QSize(50, 50));
        tb_play->setCheckable(true);

        gridLayout_15->addWidget(tb_play, 0, 0, 1, 1);

        w_scene_control = new QWidget(widget_4);
        w_scene_control->setObjectName(QStringLiteral("w_scene_control"));
        w_scene_control->setMinimumSize(QSize(0, 40));
        w_scene_control->setMaximumSize(QSize(16777215, 40));
        gridLayout_16 = new QGridLayout(w_scene_control);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setHorizontalSpacing(3);
        gridLayout_16->setVerticalSpacing(0);
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        tb_next_video = new QToolButton(w_scene_control);
        tb_next_video->setObjectName(QStringLiteral("tb_next_video"));
        tb_next_video->setMinimumSize(QSize(35, 40));
        tb_next_video->setMaximumSize(QSize(35, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Impact"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        tb_next_video->setFont(font3);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/res/Actions-go-next-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_next_video->setIcon(icon11);
        tb_next_video->setIconSize(QSize(40, 40));

        gridLayout_16->addWidget(tb_next_video, 0, 8, 1, 1);

        tb_prev_video = new QToolButton(w_scene_control);
        tb_prev_video->setObjectName(QStringLiteral("tb_prev_video"));
        tb_prev_video->setMinimumSize(QSize(35, 40));
        tb_prev_video->setMaximumSize(QSize(35, 40));
        tb_prev_video->setFont(font3);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/res/Actions-go-previous-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_prev_video->setIcon(icon12);
        tb_prev_video->setIconSize(QSize(40, 40));

        gridLayout_16->addWidget(tb_prev_video, 0, 6, 1, 1);

        label_5 = new QLabel(w_scene_control);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(16777215, 30));
        QFont font4;
        font4.setFamily(QStringLiteral("Impact"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        label_5->setFont(font4);

        gridLayout_16->addWidget(label_5, 0, 0, 1, 1);

        tb_add_new_scene = new QToolButton(w_scene_control);
        tb_add_new_scene->setObjectName(QStringLiteral("tb_add_new_scene"));
        tb_add_new_scene->setMinimumSize(QSize(100, 40));
        tb_add_new_scene->setMaximumSize(QSize(16777215, 40));
        QFont font5;
        font5.setFamily(QStringLiteral("Impact"));
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setWeight(50);
        tb_add_new_scene->setFont(font5);
        tb_add_new_scene->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"background:#fff200;\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"background:#FFD764;\n"
"}"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/res/add_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_add_new_scene->setIcon(icon13);
        tb_add_new_scene->setIconSize(QSize(40, 40));
        tb_add_new_scene->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_16->addWidget(tb_add_new_scene, 0, 4, 1, 1);

        tb_item_dur_inc = new QToolButton(w_scene_control);
        tb_item_dur_inc->setObjectName(QStringLiteral("tb_item_dur_inc"));
        tb_item_dur_inc->setMinimumSize(QSize(40, 40));
        tb_item_dur_inc->setMaximumSize(QSize(40, 40));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/res/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_item_dur_inc->setIcon(icon14);
        tb_item_dur_inc->setIconSize(QSize(32, 32));

        gridLayout_16->addWidget(tb_item_dur_inc, 0, 3, 1, 1);

        tb_item_dur_dec = new QToolButton(w_scene_control);
        tb_item_dur_dec->setObjectName(QStringLiteral("tb_item_dur_dec"));
        tb_item_dur_dec->setMinimumSize(QSize(40, 40));
        tb_item_dur_dec->setMaximumSize(QSize(40, 40));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/res/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_item_dur_dec->setIcon(icon15);
        tb_item_dur_dec->setIconSize(QSize(32, 32));

        gridLayout_16->addWidget(tb_item_dur_dec, 0, 1, 1, 1);

        lbl_video_index = new QLabel(w_scene_control);
        lbl_video_index->setObjectName(QStringLiteral("lbl_video_index"));
        lbl_video_index->setMinimumSize(QSize(60, 0));
        lbl_video_index->setFont(font);
        lbl_video_index->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(lbl_video_index, 0, 7, 1, 1);

        tb_delete_scene = new QToolButton(w_scene_control);
        tb_delete_scene->setObjectName(QStringLiteral("tb_delete_scene"));
        tb_delete_scene->setMinimumSize(QSize(0, 40));
        tb_delete_scene->setMaximumSize(QSize(16777215, 40));
        tb_delete_scene->setFont(font3);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/res/delete_image.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_delete_scene->setIcon(icon16);
        tb_delete_scene->setIconSize(QSize(40, 40));

        gridLayout_16->addWidget(tb_delete_scene, 0, 5, 1, 1);

        dsp_item_dur = new QDoubleSpinBox(w_scene_control);
        dsp_item_dur->setObjectName(QStringLiteral("dsp_item_dur"));
        dsp_item_dur->setMinimumSize(QSize(50, 40));
        dsp_item_dur->setMaximumSize(QSize(40, 50));
        QFont font6;
        font6.setFamily(QStringLiteral("Impact"));
        font6.setPointSize(11);
        dsp_item_dur->setFont(font6);
        dsp_item_dur->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dsp_item_dur->setMinimum(0.5);
        dsp_item_dur->setMaximum(60);
        dsp_item_dur->setSingleStep(0.5);
        dsp_item_dur->setValue(1);

        gridLayout_16->addWidget(dsp_item_dur, 0, 2, 1, 1);


        gridLayout_15->addWidget(w_scene_control, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_4, 4, 0, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 2, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        w_right = new QWidget(Dialog_Text_Popup);
        w_right->setObjectName(QStringLiteral("w_right"));
        w_right->setMinimumSize(QSize(220, 0));
        w_right->setMaximumSize(QSize(220, 16777215));
        gridLayout_3 = new QGridLayout(w_right);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 10);
        tb_create = new QToolButton(w_right);
        tb_create->setObjectName(QStringLiteral("tb_create"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tb_create->sizePolicy().hasHeightForWidth());
        tb_create->setSizePolicy(sizePolicy);
        tb_create->setMinimumSize(QSize(150, 40));
        tb_create->setMaximumSize(QSize(16777215, 40));
        tb_create->setFont(font5);

        gridLayout_3->addWidget(tb_create, 9, 0, 1, 1);

        line_2 = new QFrame(w_right);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 4, 0, 1, 1);

        line_3 = new QFrame(w_right);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 14, 0, 1, 1);

        tb_change_audio = new CxCustomButton(w_right);
        tb_change_audio->setObjectName(QStringLiteral("tb_change_audio"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_change_audio->sizePolicy().hasHeightForWidth());
        tb_change_audio->setSizePolicy(sizePolicy1);
        tb_change_audio->setMinimumSize(QSize(30, 40));
        tb_change_audio->setMaximumSize(QSize(4444, 40));
        QFont font7;
        font7.setFamily(QStringLiteral("Impact"));
        font7.setPointSize(15);
        tb_change_audio->setFont(font7);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/win/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_change_audio->setIcon(icon17);
        tb_change_audio->setIconSize(QSize(25, 25));
        tb_change_audio->setCheckable(false);

        gridLayout_3->addWidget(tb_change_audio, 5, 0, 1, 1);

        tb_new_video = new QToolButton(w_right);
        tb_new_video->setObjectName(QStringLiteral("tb_new_video"));
        tb_new_video->setEnabled(false);
        tb_new_video->setMinimumSize(QSize(220, 40));
        tb_new_video->setFont(font4);

        gridLayout_3->addWidget(tb_new_video, 0, 0, 1, 1);

        tb_inside_video = new QToolButton(w_right);
        tb_inside_video->setObjectName(QStringLiteral("tb_inside_video"));
        tb_inside_video->setEnabled(false);
        tb_inside_video->setMinimumSize(QSize(220, 40));
        tb_inside_video->setFont(font3);

        gridLayout_3->addWidget(tb_inside_video, 1, 0, 1, 1);

        w_draw_panel = new QWidget(w_right);
        w_draw_panel->setObjectName(QStringLiteral("w_draw_panel"));
        w_draw_panel->setMinimumSize(QSize(0, 0));
        gridLayout_17 = new QGridLayout(w_draw_panel);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        w_add_image = new QWidget(w_draw_panel);
        w_add_image->setObjectName(QStringLiteral("w_add_image"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(w_add_image->sizePolicy().hasHeightForWidth());
        w_add_image->setSizePolicy(sizePolicy2);
        w_add_image->setMinimumSize(QSize(0, 84));
        w_add_image->setMaximumSize(QSize(16777215, 84));
        gridLayout_20 = new QGridLayout(w_add_image);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        tb_image_fullscreen = new CxCustomButton(w_add_image);
        tb_image_fullscreen->setObjectName(QStringLiteral("tb_image_fullscreen"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tb_image_fullscreen->sizePolicy().hasHeightForWidth());
        tb_image_fullscreen->setSizePolicy(sizePolicy3);
        tb_image_fullscreen->setMinimumSize(QSize(0, 40));
        tb_image_fullscreen->setMaximumSize(QSize(16777215, 40));
        tb_image_fullscreen->setFont(font2);

        gridLayout_20->addWidget(tb_image_fullscreen, 0, 0, 1, 1);

        tb_image = new CxCustomButton(w_add_image);
        tb_image->setObjectName(QStringLiteral("tb_image"));
        sizePolicy.setHeightForWidth(tb_image->sizePolicy().hasHeightForWidth());
        tb_image->setSizePolicy(sizePolicy);
        tb_image->setMinimumSize(QSize(100, 40));
        tb_image->setMaximumSize(QSize(16777215, 40));
        tb_image->setFont(font2);

        gridLayout_20->addWidget(tb_image, 1, 0, 1, 1);


        gridLayout_17->addWidget(w_add_image, 3, 0, 1, 1);

        widget_12 = new QWidget(w_draw_panel);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 50));
        widget_12->setMaximumSize(QSize(16777215, 50));
        gridLayout_19 = new QGridLayout(widget_12);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        tb_arrow_left = new QToolButton(widget_12);
        tb_arrow_left->setObjectName(QStringLiteral("tb_arrow_left"));
        sizePolicy3.setHeightForWidth(tb_arrow_left->sizePolicy().hasHeightForWidth());
        tb_arrow_left->setSizePolicy(sizePolicy3);
        tb_arrow_left->setMinimumSize(QSize(0, 50));
        tb_arrow_left->setMaximumSize(QSize(16777215, 50));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/res/arrow-left-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_arrow_left->setIcon(icon18);
        tb_arrow_left->setIconSize(QSize(32, 32));

        gridLayout_19->addWidget(tb_arrow_left, 0, 1, 1, 1);

        tb_arrow_down = new QToolButton(widget_12);
        tb_arrow_down->setObjectName(QStringLiteral("tb_arrow_down"));
        sizePolicy3.setHeightForWidth(tb_arrow_down->sizePolicy().hasHeightForWidth());
        tb_arrow_down->setSizePolicy(sizePolicy3);
        tb_arrow_down->setMinimumSize(QSize(0, 50));
        tb_arrow_down->setMaximumSize(QSize(16777215, 50));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/res/arrow-down-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_arrow_down->setIcon(icon19);
        tb_arrow_down->setIconSize(QSize(32, 32));

        gridLayout_19->addWidget(tb_arrow_down, 0, 3, 1, 1);

        tb_arrow_right = new QToolButton(widget_12);
        tb_arrow_right->setObjectName(QStringLiteral("tb_arrow_right"));
        sizePolicy3.setHeightForWidth(tb_arrow_right->sizePolicy().hasHeightForWidth());
        tb_arrow_right->setSizePolicy(sizePolicy3);
        tb_arrow_right->setMinimumSize(QSize(0, 50));
        tb_arrow_right->setMaximumSize(QSize(16777215, 50));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/res/arrow-right-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_arrow_right->setIcon(icon20);
        tb_arrow_right->setIconSize(QSize(32, 32));

        gridLayout_19->addWidget(tb_arrow_right, 0, 0, 1, 1);

        tb_arrow_up = new QToolButton(widget_12);
        tb_arrow_up->setObjectName(QStringLiteral("tb_arrow_up"));
        sizePolicy3.setHeightForWidth(tb_arrow_up->sizePolicy().hasHeightForWidth());
        tb_arrow_up->setSizePolicy(sizePolicy3);
        tb_arrow_up->setMinimumSize(QSize(0, 50));
        tb_arrow_up->setMaximumSize(QSize(16777215, 50));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/res/arrow-up-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_arrow_up->setIcon(icon21);
        tb_arrow_up->setIconSize(QSize(32, 32));

        gridLayout_19->addWidget(tb_arrow_up, 0, 2, 1, 1);


        gridLayout_17->addWidget(widget_12, 1, 0, 1, 1);

        widget_11 = new QWidget(w_draw_panel);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setMinimumSize(QSize(0, 50));
        widget_11->setMaximumSize(QSize(16777215, 50));
        gridLayout_18 = new QGridLayout(widget_11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setHorizontalSpacing(0);
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        tb_rect = new QToolButton(widget_11);
        tb_rect->setObjectName(QStringLiteral("tb_rect"));
        tb_rect->setMinimumSize(QSize(55, 50));
        tb_rect->setMaximumSize(QSize(55, 50));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/res/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_rect->setIcon(icon22);
        tb_rect->setIconSize(QSize(32, 32));

        gridLayout_18->addWidget(tb_rect, 0, 0, 1, 1);

        tb_circle = new QToolButton(widget_11);
        tb_circle->setObjectName(QStringLiteral("tb_circle"));
        tb_circle->setMinimumSize(QSize(55, 50));
        tb_circle->setMaximumSize(QSize(55, 50));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/res/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_circle->setIcon(icon23);
        tb_circle->setIconSize(QSize(32, 32));

        gridLayout_18->addWidget(tb_circle, 0, 1, 1, 1);

        tb_mark = new QToolButton(widget_11);
        tb_mark->setObjectName(QStringLiteral("tb_mark"));
        tb_mark->setMinimumSize(QSize(55, 50));
        tb_mark->setMaximumSize(QSize(55, 50));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/res/number.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_mark->setIcon(icon24);
        tb_mark->setIconSize(QSize(32, 32));

        gridLayout_18->addWidget(tb_mark, 0, 3, 1, 1);

        tb_line = new QToolButton(widget_11);
        tb_line->setObjectName(QStringLiteral("tb_line"));
        tb_line->setMinimumSize(QSize(55, 50));
        tb_line->setMaximumSize(QSize(55, 50));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/res/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_line->setIcon(icon25);
        tb_line->setIconSize(QSize(50, 50));

        gridLayout_18->addWidget(tb_line, 0, 2, 1, 1);


        gridLayout_17->addWidget(widget_11, 0, 0, 1, 1);

        tb_show_image_panel = new QToolButton(w_draw_panel);
        tb_show_image_panel->setObjectName(QStringLiteral("tb_show_image_panel"));
        tb_show_image_panel->setMinimumSize(QSize(220, 50));
        tb_show_image_panel->setMaximumSize(QSize(16777215, 50));
        tb_show_image_panel->setFont(font);
        tb_show_image_panel->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"background:#545454;\n"
"}"));

        gridLayout_17->addWidget(tb_show_image_panel, 2, 0, 1, 1);


        gridLayout_3->addWidget(w_draw_panel, 3, 0, 1, 1);

        w_inside_video = new QWidget(w_right);
        w_inside_video->setObjectName(QStringLiteral("w_inside_video"));
        w_inside_video->setMinimumSize(QSize(0, 100));
        gridLayout_11 = new QGridLayout(w_inside_video);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_14 = new QWidget(w_inside_video);
        widget_14->setObjectName(QStringLiteral("widget_14"));
        widget_14->setMinimumSize(QSize(0, 30));
        widget_14->setMaximumSize(QSize(16777215, 30));
        gridLayout_22 = new QGridLayout(widget_14);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        gridLayout_22->setContentsMargins(5, 0, 5, 0);
        te_insert_pos = new QTimeEdit(widget_14);
        te_insert_pos->setObjectName(QStringLiteral("te_insert_pos"));
        te_insert_pos->setMinimumSize(QSize(0, 30));
        te_insert_pos->setMaximumSize(QSize(70, 30));

        gridLayout_22->addWidget(te_insert_pos, 0, 1, 1, 1);

        label_7 = new QLabel(widget_14);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));

        gridLayout_22->addWidget(label_7, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_14, 0, 0, 1, 1);

        tb_insert_into_video = new QToolButton(w_inside_video);
        tb_insert_into_video->setObjectName(QStringLiteral("tb_insert_into_video"));
        sizePolicy.setHeightForWidth(tb_insert_into_video->sizePolicy().hasHeightForWidth());
        tb_insert_into_video->setSizePolicy(sizePolicy);
        tb_insert_into_video->setMinimumSize(QSize(150, 40));
        tb_insert_into_video->setFont(font5);

        gridLayout_11->addWidget(tb_insert_into_video, 1, 0, 1, 1);


        gridLayout_3->addWidget(w_inside_video, 11, 0, 1, 1);

        groupBox_audio = new QGroupBox(w_right);
        groupBox_audio->setObjectName(QStringLiteral("groupBox_audio"));
        groupBox_audio->setMinimumSize(QSize(0, 0));
        QFont font8;
        font8.setPointSize(10);
        groupBox_audio->setFont(font8);
        gridLayout_7 = new QGridLayout(groupBox_audio);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(0);
        gridLayout_7->setContentsMargins(0, 0, 0, 10);
        widget_7 = new QWidget(groupBox_audio);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 30));
        widget_7->setMaximumSize(QSize(16777215, 30));
        gridLayout_9 = new QGridLayout(widget_7);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(5, 0, 5, 0);
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));

        gridLayout_9->addWidget(label_3, 0, 0, 1, 1);

        te_total = new QTimeEdit(widget_7);
        te_total->setObjectName(QStringLiteral("te_total"));
        te_total->setEnabled(false);
        te_total->setMinimumSize(QSize(0, 30));
        te_total->setMaximumSize(QSize(70, 30));
        te_total->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_9->addWidget(te_total, 0, 1, 1, 1);


        gridLayout_7->addWidget(widget_7, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_audio, 7, 0, 1, 1);

        w_audio_dur = new QWidget(w_right);
        w_audio_dur->setObjectName(QStringLiteral("w_audio_dur"));
        w_audio_dur->setMinimumSize(QSize(0, 30));
        w_audio_dur->setMaximumSize(QSize(16777215, 30));
        gridLayout_12 = new QGridLayout(w_audio_dur);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(5, 0, 5, 0);
        label_6 = new QLabel(w_audio_dur);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 30));
        label_6->setMaximumSize(QSize(16777215, 30));
        label_6->setFont(font8);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_6, 0, 2, 1, 1);

        te_end = new QTimeEdit(w_audio_dur);
        te_end->setObjectName(QStringLiteral("te_end"));
        te_end->setMinimumSize(QSize(0, 30));
        te_end->setMaximumSize(QSize(70, 30));

        gridLayout_12->addWidget(te_end, 0, 3, 1, 1);

        te_start = new QTimeEdit(w_audio_dur);
        te_start->setObjectName(QStringLiteral("te_start"));
        te_start->setMinimumSize(QSize(0, 30));
        te_start->setMaximumSize(QSize(70, 30));

        gridLayout_12->addWidget(te_start, 0, 1, 1, 1);

        label_4 = new QLabel(w_audio_dur);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 30));
        label_4->setMaximumSize(QSize(16777215, 30));
        label_4->setFont(font8);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(w_audio_dur, 6, 0, 1, 1);

        w_freeze = new QWidget(w_right);
        w_freeze->setObjectName(QStringLiteral("w_freeze"));
        w_freeze->setMinimumSize(QSize(0, 0));
        gridLayout_5 = new QGridLayout(w_freeze);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(w_freeze);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font9;
        font9.setFamily(QStringLiteral("Impact"));
        font9.setPointSize(22);
        label->setFont(font9);
        label->setStyleSheet(QLatin1String("QLabel{\n"
"color:#5B5B5B;\n"
"}"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        widget_2 = new QWidget(w_freeze);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#C3C3C3;\n"
"}"));
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(10);
        gridLayout_6->setVerticalSpacing(5);
        gridLayout_6->setContentsMargins(10, 5, 5, 5);
        sp_freeze_duration = new QSpinBox(widget_2);
        sp_freeze_duration->setObjectName(QStringLiteral("sp_freeze_duration"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sp_freeze_duration->sizePolicy().hasHeightForWidth());
        sp_freeze_duration->setSizePolicy(sizePolicy4);
        QFont font10;
        font10.setFamily(QStringLiteral("Impact"));
        font10.setPointSize(20);
        sp_freeze_duration->setFont(font10);
        sp_freeze_duration->setStyleSheet(QLatin1String("QSpinBox\n"
"{\n"
"border-color:#E9E9E9;\n"
"border-width:7px;\n"
"border-style:solid;\n"
"}"));
        sp_freeze_duration->setAlignment(Qt::AlignCenter);
        sp_freeze_duration->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sp_freeze_duration->setMinimum(1);

        gridLayout_6->addWidget(sp_freeze_duration, 0, 1, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        QFont font11;
        font11.setFamily(QStringLiteral("Impact"));
        font11.setPointSize(18);
        label_8->setFont(font11);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_8, 0, 2, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 50));
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/res/clock.png")));
        label_2->setScaledContents(true);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(w_freeze, 12, 0, 1, 1);

        tb_freeze_save = new QToolButton(w_right);
        tb_freeze_save->setObjectName(QStringLiteral("tb_freeze_save"));
        sizePolicy.setHeightForWidth(tb_freeze_save->sizePolicy().hasHeightForWidth());
        tb_freeze_save->setSizePolicy(sizePolicy);
        tb_freeze_save->setMinimumSize(QSize(150, 40));
        tb_freeze_save->setFont(font5);

        gridLayout_3->addWidget(tb_freeze_save, 13, 0, 1, 1);

        tb_freeze = new QToolButton(w_right);
        tb_freeze->setObjectName(QStringLiteral("tb_freeze"));
        tb_freeze->setEnabled(false);
        tb_freeze->setMinimumSize(QSize(220, 40));
        tb_freeze->setFont(font3);

        gridLayout_3->addWidget(tb_freeze, 2, 0, 1, 1);


        gridLayout->addWidget(w_right, 0, 1, 1, 1);


        retranslateUi(Dialog_Text_Popup);

        QMetaObject::connectSlotsByName(Dialog_Text_Popup);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Text_Popup)
    {
        Dialog_Text_Popup->setWindowTitle(QApplication::translate("Dialog_Text_Popup", "Movie Missle", 0));
        lbl_seek->setText(QString());
        tb_text_col_4->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_justify->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_right->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_fill->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_italic->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_text_col_2->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_underline->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_text_col_1->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_left->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_delete_item->setText(QApplication::translate("Dialog_Text_Popup", "X", 0));
        tb_white_mode->setText(QApplication::translate("Dialog_Text_Popup", "WHITELINE MODE", 0));
        tb_bold->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_center->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_movement->setText(QApplication::translate("Dialog_Text_Popup", "M", 0));
        tb_text_col_3->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_text_col_5->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_insert_black_circle_mark->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_play->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_next_video->setText(QApplication::translate("Dialog_Text_Popup", ">", 0));
        tb_prev_video->setText(QApplication::translate("Dialog_Text_Popup", "<", 0));
        label_5->setText(QApplication::translate("Dialog_Text_Popup", " Image Duration: ", 0));
        tb_add_new_scene->setText(QApplication::translate("Dialog_Text_Popup", "    ADD  ", 0));
        tb_item_dur_inc->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_item_dur_inc->setShortcut(QApplication::translate("Dialog_Text_Popup", "Ctrl+S, Ctrl+R", 0));
        tb_item_dur_dec->setText(QApplication::translate("Dialog_Text_Popup", "...", 0));
        tb_item_dur_dec->setShortcut(QApplication::translate("Dialog_Text_Popup", "Ctrl+S, Ctrl+R", 0));
        lbl_video_index->setText(QApplication::translate("Dialog_Text_Popup", "1 / 1", 0));
        tb_delete_scene->setText(QApplication::translate("Dialog_Text_Popup", "DEL", 0));
        dsp_item_dur->setSuffix(QApplication::translate("Dialog_Text_Popup", "s", 0));
        tb_create->setText(QApplication::translate("Dialog_Text_Popup", "SAVE SEQUENCE", 0));
        tb_change_audio->setText(QApplication::translate("Dialog_Text_Popup", "ADD AUDIO", 0));
        tb_new_video->setText(QApplication::translate("Dialog_Text_Popup", "CREATE NEW VIDEO - PAINT", 0));
        tb_inside_video->setText(QApplication::translate("Dialog_Text_Popup", "ADD INSIDE VIDEO - PAINT", 0));
        tb_image_fullscreen->setText(QString());
        tb_image->setText(QString());
        tb_arrow_left->setText(QApplication::translate("Dialog_Text_Popup", "<-", 0));
        tb_arrow_down->setText(QApplication::translate("Dialog_Text_Popup", "v", 0));
        tb_arrow_right->setText(QApplication::translate("Dialog_Text_Popup", "->", 0));
        tb_arrow_up->setText(QApplication::translate("Dialog_Text_Popup", "^", 0));
        tb_rect->setText(QString());
        tb_circle->setText(QString());
        tb_mark->setText(QString());
        tb_line->setText(QApplication::translate("Dialog_Text_Popup", "LINE", 0));
        tb_show_image_panel->setText(QApplication::translate("Dialog_Text_Popup", "UPLOAD IMAGE", 0));
        te_insert_pos->setDisplayFormat(QApplication::translate("Dialog_Text_Popup", "mm:ss", 0));
        label_7->setText(QApplication::translate("Dialog_Text_Popup", "Start Time:", 0));
        tb_insert_into_video->setText(QApplication::translate("Dialog_Text_Popup", "SAVE SEQUENCE", 0));
        groupBox_audio->setTitle(QApplication::translate("Dialog_Text_Popup", "Audio", 0));
        label_3->setText(QApplication::translate("Dialog_Text_Popup", "Total Duration:", 0));
        te_total->setDisplayFormat(QApplication::translate("Dialog_Text_Popup", "mm:ss", 0));
        label_6->setText(QApplication::translate("Dialog_Text_Popup", "End:", 0));
        te_end->setDisplayFormat(QApplication::translate("Dialog_Text_Popup", "mm:ss", 0));
        te_start->setDisplayFormat(QApplication::translate("Dialog_Text_Popup", "mm:ss", 0));
        label_4->setText(QApplication::translate("Dialog_Text_Popup", "Start:", 0));
        label->setText(QApplication::translate("Dialog_Text_Popup", "FREEZE MODE", 0));
        label_8->setText(QApplication::translate("Dialog_Text_Popup", "SEK", 0));
        label_2->setText(QString());
        tb_freeze_save->setText(QApplication::translate("Dialog_Text_Popup", "SAVE", 0));
        tb_freeze->setText(QApplication::translate("Dialog_Text_Popup", "FREEZE VIDEO - PAINT", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Text_Popup: public Ui_Dialog_Text_Popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_TEXT_SELECT_H
