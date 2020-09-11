/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "cxcolorbutton.h"
#include "cxcustombutton.h"
#include "cxgraphicsview.h"
#include "cxitemlayer.h"
#include "cxlayer.h"
#include "cxlogolistwidget.h"
#include "cxtextdropdownmenu.h"
#include "cxtrimmerpanel.h"
#include "cxvideopanel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_vertical;
    QWidget *w_title;
    QGridLayout *gridLayout_13;
    QLabel *lbl_title;
    QWidget *widget_2;
    QGridLayout *gridLayout_11;
    QToolButton *tb_exit;
    QToolButton *tb_minimize;
    QToolButton *tb_maximize;
    CxColorButton *tb_logo;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *w_main;
    QGridLayout *gridLayout_2;
    QWidget *w_top_center;
    QGridLayout *gridLayout_3;
    CxVideoPanel *w_control;
    QWidget *widget_4;
    QGridLayout *gridLayout_9;
    CxGraphicsView *graphicsView;
    QWidget *w_top_painter;
    QGridLayout *gridLayout_5;
    QWidget *w_top_right_2;
    QGridLayout *gridLayout_4;
    QToolButton *tb_mark;
    QFrame *line_4;
    QToolButton *tb_text;
    QFrame *line_5;
    QToolButton *tb_image;
    QSpacerItem *verticalSpacer;
    QWidget *w_mark_del;
    QGridLayout *gridLayout_18;
    QToolButton *tb_delete;
    QWidget *w_image_del;
    QGridLayout *gridLayout_20;
    QToolButton *tb_delete_3;
    CxTextDropDownMenu *w_text_dropdown;
    QWidget *w_text_del;
    QGridLayout *gridLayout_19;
    QWidget *widget_8;
    QToolButton *tb_delete_2;
    QRadioButton *rb_flex;
    QRadioButton *rb_black_line;
    QRadioButton *rb_white_line;
    QToolButton *tb_scene_color;
    QToolButton *tb_paint;
    QWidget *w_left;
    QGridLayout *gridLayout_7;
    CxLayer *lw_layer;
    QWidget *widget_6;
    QGridLayout *gridLayout_15;
    QToolButton *tb_add_video;
    QToolButton *tb_delete_video;
    QWidget *widget_10;
    QGridLayout *gridLayout_22;
    QLabel *label_2;
    QToolButton *tb_upload_video;
    QWidget *w_right;
    QGridLayout *gridLayout_27;
    QWidget *w_create_video_panel;
    QGridLayout *gridLayout_21;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QToolButton *tb_show_logo_widget;
    CxLayer *lw_intro_layer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QWidget *w_inside_single_image_video;
    QGridLayout *gridLayout_23;
    QWidget *widget_5;
    QGridLayout *gridLayout_29;
    QWidget *widget_12;
    QGridLayout *gridLayout_31;
    QToolButton *tb_single_video_audio;
    QToolButton *tb_single_video_image;
    QToolButton *tb_single_video_mp4;
    QToolButton *tb_save_single_video;
    QWidget *widget_11;
    QGridLayout *gridLayout_30;
    CxCustomButton *tb_single_image_video;
    QWidget *w_logo_pos;
    QGridLayout *gridLayout_24;
    CxLogoListWidget *lw_logo_list;
    QWidget *widget_3;
    QGridLayout *gridLayout_26;
    QToolButton *tb_add_logo;
    QToolButton *tb_logo_save;
    QToolButton *tb_delete_logo;
    QWidget *w_edit_video;
    QGridLayout *gridLayout_28;
    QToolButton *tb_edit_video_freeze;
    CxCustomButton *tb_show_editvideowidget;
    QToolButton *tb_edit_video_image;
    QWidget *w_intro_layer;
    QGridLayout *gridLayout_12;
    QToolButton *tb_remove_intro;
    QToolButton *tb_add_intro;
    QLabel *label;
    QWidget *widget_13;
    QGridLayout *gridLayout_32;
    CxCustomButton *tb_create_new_video;
    QWidget *w_res;
    QGridLayout *gridLayout_8;
    QWidget *widget;
    QGridLayout *gridLayout_14;
    CxTrimmerPanel *lbl_trimmer;
    QWidget *w_control_button;
    QGridLayout *gridLayout_10;
    QToolButton *tb_expand_trimmer;
    QSpacerItem *horizontalSpacer_3;
    CxItemLayer *lw_item_layer;
    QWidget *w_bottom_left;
    QGridLayout *gridLayout_16;
    QWidget *widget_7;
    QGridLayout *gridLayout_17;
    QToolButton *tb_preview;
    QWidget *widget_9;
    QGridLayout *gridLayout_25;
    QToolButton *tb_render;
    QWidget *w_footer;
    QGridLayout *gridLayout_6;
    QLabel *lbl_footer;
    QComboBox *cb_theme;
    QButtonGroup *btn_item_mode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(887, 1060);
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter_vertical = new QSplitter(centralWidget);
        splitter_vertical->setObjectName(QStringLiteral("splitter_vertical"));
        splitter_vertical->setOrientation(Qt::Vertical);
        w_title = new QWidget(splitter_vertical);
        w_title->setObjectName(QStringLiteral("w_title"));
        w_title->setMinimumSize(QSize(0, 50));
        w_title->setMaximumSize(QSize(16777215, 50));
        gridLayout_13 = new QGridLayout(w_title);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        lbl_title = new QLabel(w_title);
        lbl_title->setObjectName(QStringLiteral("lbl_title"));
        lbl_title->setMinimumSize(QSize(300, 50));
        lbl_title->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        lbl_title->setFont(font);
        lbl_title->setStyleSheet(QLatin1String("QLabel{\n"
"color:red;\n"
"}"));

        gridLayout_13->addWidget(lbl_title, 0, 2, 1, 1);

        widget_2 = new QWidget(w_title);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_11 = new QGridLayout(widget_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setHorizontalSpacing(0);
        gridLayout_11->setContentsMargins(0, 0, 5, 0);
        tb_exit = new QToolButton(widget_2);
        tb_exit->setObjectName(QStringLiteral("tb_exit"));
        tb_exit->setMinimumSize(QSize(30, 30));
        tb_exit->setMaximumSize(QSize(30, 30));

        gridLayout_11->addWidget(tb_exit, 0, 2, 1, 1);

        tb_minimize = new QToolButton(widget_2);
        tb_minimize->setObjectName(QStringLiteral("tb_minimize"));
        tb_minimize->setMinimumSize(QSize(30, 30));
        tb_minimize->setMaximumSize(QSize(30, 30));

        gridLayout_11->addWidget(tb_minimize, 0, 0, 1, 1);

        tb_maximize = new QToolButton(widget_2);
        tb_maximize->setObjectName(QStringLiteral("tb_maximize"));
        tb_maximize->setMinimumSize(QSize(30, 30));
        tb_maximize->setMaximumSize(QSize(30, 30));

        gridLayout_11->addWidget(tb_maximize, 0, 1, 1, 1);


        gridLayout_13->addWidget(widget_2, 0, 5, 1, 1);

        tb_logo = new CxColorButton(w_title);
        tb_logo->setObjectName(QStringLiteral("tb_logo"));
        tb_logo->setMinimumSize(QSize(30, 30));
        tb_logo->setMaximumSize(QSize(30, 30));

        gridLayout_13->addWidget(tb_logo, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        splitter_vertical->addWidget(w_title);
        w_main = new QWidget(splitter_vertical);
        w_main->setObjectName(QStringLiteral("w_main"));
        w_main->setMinimumSize(QSize(0, 200));
        gridLayout_2 = new QGridLayout(w_main);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 15, 0);
        w_top_center = new QWidget(w_main);
        w_top_center->setObjectName(QStringLiteral("w_top_center"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(w_top_center->sizePolicy().hasHeightForWidth());
        w_top_center->setSizePolicy(sizePolicy);
        w_top_center->setMinimumSize(QSize(200, 0));
        gridLayout_3 = new QGridLayout(w_top_center);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        w_control = new CxVideoPanel(w_top_center);
        w_control->setObjectName(QStringLiteral("w_control"));
        w_control->setMinimumSize(QSize(0, 100));
        w_control->setMaximumSize(QSize(16777215, 100));

        gridLayout_3->addWidget(w_control, 1, 0, 1, 1);

        widget_4 = new QWidget(w_top_center);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        gridLayout_9 = new QGridLayout(widget_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(20, -1, 20, 0);
        graphicsView = new CxGraphicsView(widget_4);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_9->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_4, 0, 0, 1, 1);


        gridLayout_2->addWidget(w_top_center, 0, 1, 1, 1);

        w_top_painter = new QWidget(w_main);
        w_top_painter->setObjectName(QStringLiteral("w_top_painter"));
        w_top_painter->setMinimumSize(QSize(150, 0));
        w_top_painter->setMaximumSize(QSize(150, 16777215));
        gridLayout_5 = new QGridLayout(w_top_painter);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 20, 0);
        w_top_right_2 = new QWidget(w_top_painter);
        w_top_right_2->setObjectName(QStringLiteral("w_top_right_2"));
        w_top_right_2->setMinimumSize(QSize(0, 0));
        gridLayout_4 = new QGridLayout(w_top_right_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 9, 0, 9);
        tb_mark = new QToolButton(w_top_right_2);
        tb_mark->setObjectName(QStringLiteral("tb_mark"));
        tb_mark->setMinimumSize(QSize(130, 50));
        tb_mark->setMaximumSize(QSize(130, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        tb_mark->setFont(font1);

        gridLayout_4->addWidget(tb_mark, 6, 0, 1, 1);

        line_4 = new QFrame(w_top_right_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_4, 9, 0, 1, 1);

        tb_text = new QToolButton(w_top_right_2);
        tb_text->setObjectName(QStringLiteral("tb_text"));
        tb_text->setMinimumSize(QSize(130, 50));
        tb_text->setMaximumSize(QSize(130, 50));
        tb_text->setFont(font1);

        gridLayout_4->addWidget(tb_text, 1, 0, 1, 1);

        line_5 = new QFrame(w_top_right_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 13, 0, 1, 1);

        tb_image = new QToolButton(w_top_right_2);
        tb_image->setObjectName(QStringLiteral("tb_image"));
        tb_image->setMinimumSize(QSize(130, 50));
        tb_image->setMaximumSize(QSize(130, 50));
        tb_image->setFont(font1);

        gridLayout_4->addWidget(tb_image, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 15, 0, 1, 1);

        w_mark_del = new QWidget(w_top_right_2);
        w_mark_del->setObjectName(QStringLiteral("w_mark_del"));
        w_mark_del->setMinimumSize(QSize(0, 50));
        w_mark_del->setMaximumSize(QSize(16777215, 50));
        w_mark_del->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:transparent;\n"
"}"));
        gridLayout_18 = new QGridLayout(w_mark_del);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        tb_delete = new QToolButton(w_mark_del);
        tb_delete->setObjectName(QStringLiteral("tb_delete"));
        tb_delete->setMinimumSize(QSize(50, 50));
        tb_delete->setMaximumSize(QSize(50, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Berlin Sans FB Demi"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        tb_delete->setFont(font2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_delete->setIcon(icon1);
        tb_delete->setIconSize(QSize(40, 40));

        gridLayout_18->addWidget(tb_delete, 0, 0, 1, 1);


        gridLayout_4->addWidget(w_mark_del, 7, 0, 1, 1);

        w_image_del = new QWidget(w_top_right_2);
        w_image_del->setObjectName(QStringLiteral("w_image_del"));
        w_image_del->setMinimumSize(QSize(0, 50));
        w_image_del->setMaximumSize(QSize(16777215, 50));
        w_image_del->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:transparent;\n"
"}"));
        gridLayout_20 = new QGridLayout(w_image_del);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        tb_delete_3 = new QToolButton(w_image_del);
        tb_delete_3->setObjectName(QStringLiteral("tb_delete_3"));
        tb_delete_3->setMinimumSize(QSize(50, 50));
        tb_delete_3->setMaximumSize(QSize(50, 50));
        tb_delete_3->setFont(font2);
        tb_delete_3->setIcon(icon1);
        tb_delete_3->setIconSize(QSize(40, 40));

        gridLayout_20->addWidget(tb_delete_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(w_image_del, 5, 0, 1, 1);

        w_text_dropdown = new CxTextDropDownMenu(w_top_right_2);
        w_text_dropdown->setObjectName(QStringLiteral("w_text_dropdown"));
        w_text_dropdown->setMinimumSize(QSize(0, 150));

        gridLayout_4->addWidget(w_text_dropdown, 2, 0, 1, 1);

        w_text_del = new QWidget(w_top_right_2);
        w_text_del->setObjectName(QStringLiteral("w_text_del"));
        w_text_del->setMinimumSize(QSize(0, 150));
        w_text_del->setMaximumSize(QSize(16777215, 150));
        w_text_del->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:transparent;\n"
"}"));
        gridLayout_19 = new QGridLayout(w_text_del);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        widget_8 = new QWidget(w_text_del);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 50));
        widget_8->setMaximumSize(QSize(16777215, 50));
        tb_delete_2 = new QToolButton(widget_8);
        tb_delete_2->setObjectName(QStringLiteral("tb_delete_2"));
        tb_delete_2->setGeometry(QRect(40, 0, 50, 50));
        tb_delete_2->setMinimumSize(QSize(50, 50));
        tb_delete_2->setMaximumSize(QSize(50, 50));
        tb_delete_2->setFont(font2);
        tb_delete_2->setIcon(icon1);
        tb_delete_2->setIconSize(QSize(40, 40));

        gridLayout_19->addWidget(widget_8, 0, 0, 1, 1);

        rb_flex = new QRadioButton(w_text_del);
        btn_item_mode = new QButtonGroup(MainWindow);
        btn_item_mode->setObjectName(QStringLiteral("btn_item_mode"));
        btn_item_mode->addButton(rb_flex);
        rb_flex->setObjectName(QStringLiteral("rb_flex"));
        rb_flex->setMinimumSize(QSize(130, 0));
        rb_flex->setMaximumSize(QSize(130, 30));
        QFont font3;
        font3.setPointSize(12);
        rb_flex->setFont(font3);
        rb_flex->setChecked(true);

        gridLayout_19->addWidget(rb_flex, 1, 0, 1, 1);

        rb_black_line = new QRadioButton(w_text_del);
        btn_item_mode->addButton(rb_black_line);
        rb_black_line->setObjectName(QStringLiteral("rb_black_line"));
        rb_black_line->setMinimumSize(QSize(130, 0));
        rb_black_line->setMaximumSize(QSize(130, 16777215));
        rb_black_line->setFont(font3);

        gridLayout_19->addWidget(rb_black_line, 2, 0, 1, 1);

        rb_white_line = new QRadioButton(w_text_del);
        rb_white_line->setObjectName(QStringLiteral("rb_white_line"));
        rb_white_line->setMinimumSize(QSize(130, 0));
        rb_white_line->setMaximumSize(QSize(130, 16777215));
        rb_white_line->setFont(font3);

        gridLayout_19->addWidget(rb_white_line, 3, 0, 1, 1);


        gridLayout_4->addWidget(w_text_del, 3, 0, 1, 1);

        tb_scene_color = new QToolButton(w_top_right_2);
        tb_scene_color->setObjectName(QStringLiteral("tb_scene_color"));
        tb_scene_color->setMinimumSize(QSize(130, 50));
        tb_scene_color->setMaximumSize(QSize(130, 50));
        tb_scene_color->setFont(font1);

        gridLayout_4->addWidget(tb_scene_color, 14, 0, 1, 1);

        tb_paint = new QToolButton(w_top_right_2);
        tb_paint->setObjectName(QStringLiteral("tb_paint"));
        tb_paint->setMinimumSize(QSize(130, 50));
        tb_paint->setMaximumSize(QSize(130, 50));
        tb_paint->setFont(font1);

        gridLayout_4->addWidget(tb_paint, 0, 0, 1, 1);


        gridLayout_5->addWidget(w_top_right_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(w_top_painter, 0, 4, 1, 1);

        w_left = new QWidget(w_main);
        w_left->setObjectName(QStringLiteral("w_left"));
        w_left->setMinimumSize(QSize(270, 0));
        w_left->setMaximumSize(QSize(270, 16777215));
        gridLayout_7 = new QGridLayout(w_left);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(0);
        gridLayout_7->setContentsMargins(-1, -1, 20, -1);
        lw_layer = new CxLayer(w_left);
        lw_layer->setObjectName(QStringLiteral("lw_layer"));

        gridLayout_7->addWidget(lw_layer, 1, 0, 1, 1);

        widget_6 = new QWidget(w_left);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setMinimumSize(QSize(0, 50));
        widget_6->setMaximumSize(QSize(16777215, 50));
        widget_6->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:transparent;\n"
"\n"
"}"));
        gridLayout_15 = new QGridLayout(widget_6);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setHorizontalSpacing(4);
        gridLayout_15->setVerticalSpacing(0);
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        tb_add_video = new QToolButton(widget_6);
        tb_add_video->setObjectName(QStringLiteral("tb_add_video"));
        tb_add_video->setMinimumSize(QSize(50, 50));
        tb_add_video->setMaximumSize(QSize(50, 50));
        tb_add_video->setStyleSheet(QLatin1String("QToolButton:hover {\n"
"    background: #C3C0C3\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/add_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_add_video->setIcon(icon2);
        tb_add_video->setIconSize(QSize(32, 32));

        gridLayout_15->addWidget(tb_add_video, 0, 1, 1, 1);

        tb_delete_video = new QToolButton(widget_6);
        tb_delete_video->setObjectName(QStringLiteral("tb_delete_video"));
        tb_delete_video->setMinimumSize(QSize(50, 50));
        tb_delete_video->setMaximumSize(QSize(50, 50));
        tb_delete_video->setStyleSheet(QLatin1String("QToolButton:hover {\n"
"    background: #C3C0C3\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/res/delete_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_delete_video->setIcon(icon3);
        tb_delete_video->setIconSize(QSize(32, 32));

        gridLayout_15->addWidget(tb_delete_video, 0, 2, 1, 1);

        widget_10 = new QWidget(widget_6);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        gridLayout_22 = new QGridLayout(widget_10);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget_10);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 10));
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#0086BF;\n"
"}"));

        gridLayout_22->addWidget(label_2, 1, 0, 1, 1);

        tb_upload_video = new QToolButton(widget_10);
        tb_upload_video->setObjectName(QStringLiteral("tb_upload_video"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tb_upload_video->sizePolicy().hasHeightForWidth());
        tb_upload_video->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QStringLiteral("Impact"));
        font4.setPointSize(13);
        tb_upload_video->setFont(font4);
        tb_upload_video->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_22->addWidget(tb_upload_video, 0, 0, 1, 1);


        gridLayout_15->addWidget(widget_10, 0, 0, 1, 1);


        gridLayout_7->addWidget(widget_6, 0, 0, 1, 1);


        gridLayout_2->addWidget(w_left, 0, 0, 1, 1);

        w_right = new QWidget(w_main);
        w_right->setObjectName(QStringLiteral("w_right"));
        w_right->setMinimumSize(QSize(230, 0));
        w_right->setMaximumSize(QSize(230, 16777215));
        gridLayout_27 = new QGridLayout(w_right);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QStringLiteral("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 10, 0, 0);
        w_create_video_panel = new QWidget(w_right);
        w_create_video_panel->setObjectName(QStringLiteral("w_create_video_panel"));
        w_create_video_panel->setMinimumSize(QSize(0, 100));
        w_create_video_panel->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:transparent;\n"
"\n"
"}"));
        gridLayout_21 = new QGridLayout(w_create_video_panel);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_21->addItem(verticalSpacer_5, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_21->addItem(verticalSpacer_4, 6, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_21->addItem(verticalSpacer_2, 14, 0, 1, 1);

        tb_show_logo_widget = new QToolButton(w_create_video_panel);
        tb_show_logo_widget->setObjectName(QStringLiteral("tb_show_logo_widget"));
        tb_show_logo_widget->setEnabled(false);
        sizePolicy1.setHeightForWidth(tb_show_logo_widget->sizePolicy().hasHeightForWidth());
        tb_show_logo_widget->setSizePolicy(sizePolicy1);
        tb_show_logo_widget->setMinimumSize(QSize(230, 40));
        tb_show_logo_widget->setMaximumSize(QSize(16777215, 40));
        QFont font5;
        font5.setFamily(QStringLiteral("Impact"));
        font5.setPointSize(14);
        tb_show_logo_widget->setFont(font5);
        tb_show_logo_widget->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#535353;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
""));

        gridLayout_21->addWidget(tb_show_logo_widget, 12, 0, 1, 1);

        lw_intro_layer = new CxLayer(w_create_video_panel);
        lw_intro_layer->setObjectName(QStringLiteral("lw_intro_layer"));
        lw_intro_layer->setMaximumSize(QSize(16777215, 150));
        lw_intro_layer->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"	background:#EFE4B0;\n"
"}"));

        gridLayout_21->addWidget(lw_intro_layer, 10, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_21->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_21->addItem(verticalSpacer_6, 11, 0, 1, 1);

        w_inside_single_image_video = new QWidget(w_create_video_panel);
        w_inside_single_image_video->setObjectName(QStringLiteral("w_inside_single_image_video"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(w_inside_single_image_video->sizePolicy().hasHeightForWidth());
        w_inside_single_image_video->setSizePolicy(sizePolicy2);
        w_inside_single_image_video->setMinimumSize(QSize(0, 200));
        w_inside_single_image_video->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background:#fff200;\n"
"}"));
        gridLayout_23 = new QGridLayout(w_inside_single_image_video);
        gridLayout_23->setSpacing(0);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(w_inside_single_image_video);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        gridLayout_29 = new QGridLayout(widget_5);
        gridLayout_29->setSpacing(0);
        gridLayout_29->setContentsMargins(11, 11, 11, 11);
        gridLayout_29->setObjectName(QStringLiteral("gridLayout_29"));
        gridLayout_29->setContentsMargins(0, 0, 0, 0);
        widget_12 = new QWidget(widget_5);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setMinimumSize(QSize(0, 50));
        gridLayout_31 = new QGridLayout(widget_12);
        gridLayout_31->setSpacing(6);
        gridLayout_31->setContentsMargins(11, 11, 11, 11);
        gridLayout_31->setObjectName(QStringLiteral("gridLayout_31"));
        gridLayout_31->setContentsMargins(10, 0, 10, -1);
        tb_single_video_audio = new QToolButton(widget_12);
        tb_single_video_audio->setObjectName(QStringLiteral("tb_single_video_audio"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tb_single_video_audio->sizePolicy().hasHeightForWidth());
        tb_single_video_audio->setSizePolicy(sizePolicy3);
        tb_single_video_audio->setMinimumSize(QSize(0, 35));
        tb_single_video_audio->setMaximumSize(QSize(1111, 35));
        QFont font6;
        font6.setFamily(QStringLiteral("Impact"));
        font6.setPointSize(12);
        tb_single_video_audio->setFont(font6);
        tb_single_video_audio->setLayoutDirection(Qt::RightToLeft);
        tb_single_video_audio->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/win/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_single_video_audio->setIcon(icon4);
        tb_single_video_audio->setIconSize(QSize(25, 25));
        tb_single_video_audio->setCheckable(false);
        tb_single_video_audio->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_31->addWidget(tb_single_video_audio, 0, 0, 1, 1);

        tb_single_video_image = new QToolButton(widget_12);
        tb_single_video_image->setObjectName(QStringLiteral("tb_single_video_image"));
        sizePolicy3.setHeightForWidth(tb_single_video_image->sizePolicy().hasHeightForWidth());
        tb_single_video_image->setSizePolicy(sizePolicy3);
        tb_single_video_image->setMinimumSize(QSize(0, 35));
        tb_single_video_image->setMaximumSize(QSize(16777215, 35));
        QFont font7;
        font7.setFamily(QStringLiteral("Impact"));
        font7.setPointSize(16);
        tb_single_video_image->setFont(font7);
        tb_single_video_image->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_31->addWidget(tb_single_video_image, 1, 0, 1, 1);

        tb_single_video_mp4 = new QToolButton(widget_12);
        tb_single_video_mp4->setObjectName(QStringLiteral("tb_single_video_mp4"));
        sizePolicy3.setHeightForWidth(tb_single_video_mp4->sizePolicy().hasHeightForWidth());
        tb_single_video_mp4->setSizePolicy(sizePolicy3);
        tb_single_video_mp4->setMinimumSize(QSize(0, 35));
        tb_single_video_mp4->setMaximumSize(QSize(16777215, 35));
        tb_single_video_mp4->setFont(font7);
        tb_single_video_mp4->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_31->addWidget(tb_single_video_mp4, 2, 0, 1, 1);

        tb_save_single_video = new QToolButton(widget_12);
        tb_save_single_video->setObjectName(QStringLiteral("tb_save_single_video"));
        sizePolicy3.setHeightForWidth(tb_save_single_video->sizePolicy().hasHeightForWidth());
        tb_save_single_video->setSizePolicy(sizePolicy3);
        tb_save_single_video->setMinimumSize(QSize(0, 35));
        tb_save_single_video->setMaximumSize(QSize(16777215, 35));
        tb_save_single_video->setFont(font7);
        tb_save_single_video->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_31->addWidget(tb_save_single_video, 3, 0, 1, 1);


        gridLayout_29->addWidget(widget_12, 0, 0, 1, 1);


        gridLayout_23->addWidget(widget_5, 1, 0, 1, 1);

        widget_11 = new QWidget(w_inside_single_image_video);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        gridLayout_30 = new QGridLayout(widget_11);
        gridLayout_30->setSpacing(6);
        gridLayout_30->setContentsMargins(11, 11, 11, 11);
        gridLayout_30->setObjectName(QStringLiteral("gridLayout_30"));
        gridLayout_30->setContentsMargins(5, -1, 5, -1);
        tb_single_image_video = new CxCustomButton(widget_11);
        tb_single_image_video->setObjectName(QStringLiteral("tb_single_image_video"));
        tb_single_image_video->setEnabled(false);
        sizePolicy1.setHeightForWidth(tb_single_image_video->sizePolicy().hasHeightForWidth());
        tb_single_image_video->setSizePolicy(sizePolicy1);
        tb_single_image_video->setMinimumSize(QSize(0, 40));
        tb_single_image_video->setMaximumSize(QSize(16777215, 40));
        tb_single_image_video->setFont(font5);
        tb_single_image_video->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
""));

        gridLayout_30->addWidget(tb_single_image_video, 0, 0, 1, 1);


        gridLayout_23->addWidget(widget_11, 0, 0, 1, 1);


        gridLayout_21->addWidget(w_inside_single_image_video, 7, 0, 1, 1);

        w_logo_pos = new QWidget(w_create_video_panel);
        w_logo_pos->setObjectName(QStringLiteral("w_logo_pos"));
        w_logo_pos->setMinimumSize(QSize(0, 110));
        w_logo_pos->setMaximumSize(QSize(16777215, 110));
        gridLayout_24 = new QGridLayout(w_logo_pos);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        lw_logo_list = new CxLogoListWidget(w_logo_pos);
        lw_logo_list->setObjectName(QStringLiteral("lw_logo_list"));
        lw_logo_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lw_logo_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout_24->addWidget(lw_logo_list, 1, 0, 1, 1);

        widget_3 = new QWidget(w_logo_pos);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 40));
        gridLayout_26 = new QGridLayout(widget_3);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        gridLayout_26->setHorizontalSpacing(0);
        gridLayout_26->setContentsMargins(0, 0, 0, 0);
        tb_add_logo = new QToolButton(widget_3);
        tb_add_logo->setObjectName(QStringLiteral("tb_add_logo"));
        tb_add_logo->setMinimumSize(QSize(40, 40));
        tb_add_logo->setMaximumSize(QSize(40, 40));
        tb_add_logo->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/res/add_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_add_logo->setIcon(icon5);
        tb_add_logo->setIconSize(QSize(32, 32));

        gridLayout_26->addWidget(tb_add_logo, 0, 1, 1, 1);

        tb_logo_save = new QToolButton(widget_3);
        tb_logo_save->setObjectName(QStringLiteral("tb_logo_save"));
        sizePolicy3.setHeightForWidth(tb_logo_save->sizePolicy().hasHeightForWidth());
        tb_logo_save->setSizePolicy(sizePolicy3);
        tb_logo_save->setMinimumSize(QSize(0, 40));
        tb_logo_save->setFont(font5);
        tb_logo_save->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_26->addWidget(tb_logo_save, 0, 0, 1, 1);

        tb_delete_logo = new QToolButton(widget_3);
        tb_delete_logo->setObjectName(QStringLiteral("tb_delete_logo"));
        tb_delete_logo->setMinimumSize(QSize(40, 40));
        tb_delete_logo->setMaximumSize(QSize(40, 40));
        tb_delete_logo->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/res/Actions-remove-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_delete_logo->setIcon(icon6);
        tb_delete_logo->setIconSize(QSize(40, 40));

        gridLayout_26->addWidget(tb_delete_logo, 0, 2, 1, 1);


        gridLayout_24->addWidget(widget_3, 0, 0, 1, 1);


        gridLayout_21->addWidget(w_logo_pos, 13, 0, 1, 1);

        w_edit_video = new QWidget(w_create_video_panel);
        w_edit_video->setObjectName(QStringLiteral("w_edit_video"));
        w_edit_video->setMinimumSize(QSize(0, 120));
        w_edit_video->setMaximumSize(QSize(16777215, 120));
        gridLayout_28 = new QGridLayout(w_edit_video);
        gridLayout_28->setSpacing(6);
        gridLayout_28->setContentsMargins(11, 11, 11, 11);
        gridLayout_28->setObjectName(QStringLiteral("gridLayout_28"));
        gridLayout_28->setVerticalSpacing(0);
        gridLayout_28->setContentsMargins(5, 0, 5, 0);
        tb_edit_video_freeze = new QToolButton(w_edit_video);
        tb_edit_video_freeze->setObjectName(QStringLiteral("tb_edit_video_freeze"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tb_edit_video_freeze->sizePolicy().hasHeightForWidth());
        tb_edit_video_freeze->setSizePolicy(sizePolicy4);
        tb_edit_video_freeze->setFont(font5);
        tb_edit_video_freeze->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#DFDFDF;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_28->addWidget(tb_edit_video_freeze, 3, 0, 1, 1);

        tb_show_editvideowidget = new CxCustomButton(w_edit_video);
        tb_show_editvideowidget->setObjectName(QStringLiteral("tb_show_editvideowidget"));
        tb_show_editvideowidget->setEnabled(false);
        sizePolicy1.setHeightForWidth(tb_show_editvideowidget->sizePolicy().hasHeightForWidth());
        tb_show_editvideowidget->setSizePolicy(sizePolicy1);
        tb_show_editvideowidget->setMinimumSize(QSize(0, 40));
        tb_show_editvideowidget->setMaximumSize(QSize(16777215, 40));
        tb_show_editvideowidget->setFont(font5);
        tb_show_editvideowidget->setLayoutDirection(Qt::RightToLeft);
        tb_show_editvideowidget->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"	stop: 0  rgb(216, 216, 216), stop: 0.4 rgb(155, 155, 155),\n"
"	stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(216, 216, 216));\n"
"}\n"
""));

        gridLayout_28->addWidget(tb_show_editvideowidget, 1, 0, 1, 1);

        tb_edit_video_image = new QToolButton(w_edit_video);
        tb_edit_video_image->setObjectName(QStringLiteral("tb_edit_video_image"));
        sizePolicy4.setHeightForWidth(tb_edit_video_image->sizePolicy().hasHeightForWidth());
        tb_edit_video_image->setSizePolicy(sizePolicy4);
        tb_edit_video_image->setFont(font5);
        tb_edit_video_image->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#DFDFDF;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_28->addWidget(tb_edit_video_image, 2, 0, 1, 1);


        gridLayout_21->addWidget(w_edit_video, 5, 0, 1, 1);

        w_intro_layer = new QWidget(w_create_video_panel);
        w_intro_layer->setObjectName(QStringLiteral("w_intro_layer"));
        w_intro_layer->setMinimumSize(QSize(0, 40));
        w_intro_layer->setStyleSheet(QStringLiteral(""));
        gridLayout_12 = new QGridLayout(w_intro_layer);
        gridLayout_12->setSpacing(0);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(-1, 0, 4, 0);
        tb_remove_intro = new QToolButton(w_intro_layer);
        tb_remove_intro->setObjectName(QStringLiteral("tb_remove_intro"));
        tb_remove_intro->setMinimumSize(QSize(35, 35));
        tb_remove_intro->setMaximumSize(QSize(35, 35));
        tb_remove_intro->setIcon(icon6);
        tb_remove_intro->setIconSize(QSize(32, 32));

        gridLayout_12->addWidget(tb_remove_intro, 0, 1, 1, 1);

        tb_add_intro = new QToolButton(w_intro_layer);
        tb_add_intro->setObjectName(QStringLiteral("tb_add_intro"));
        tb_add_intro->setMinimumSize(QSize(35, 35));
        tb_add_intro->setMaximumSize(QSize(35, 35));
        tb_add_intro->setStyleSheet(QLatin1String("QToolButton\n"
"{\n"
"background:#fff200;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/res/Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        tb_add_intro->setIcon(icon7);
        tb_add_intro->setIconSize(QSize(32, 32));

        gridLayout_12->addWidget(tb_add_intro, 0, 2, 1, 1);

        label = new QLabel(w_intro_layer);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 40));
        label->setFont(font5);

        gridLayout_12->addWidget(label, 0, 0, 1, 1);


        gridLayout_21->addWidget(w_intro_layer, 9, 0, 1, 1);

        widget_13 = new QWidget(w_create_video_panel);
        widget_13->setObjectName(QStringLiteral("widget_13"));
        widget_13->setMinimumSize(QSize(0, 40));
        widget_13->setMaximumSize(QSize(16777215, 40));
        gridLayout_32 = new QGridLayout(widget_13);
        gridLayout_32->setSpacing(0);
        gridLayout_32->setContentsMargins(11, 11, 11, 11);
        gridLayout_32->setObjectName(QStringLiteral("gridLayout_32"));
        gridLayout_32->setContentsMargins(5, 0, 5, 0);
        tb_create_new_video = new CxCustomButton(widget_13);
        tb_create_new_video->setObjectName(QStringLiteral("tb_create_new_video"));
        sizePolicy1.setHeightForWidth(tb_create_new_video->sizePolicy().hasHeightForWidth());
        tb_create_new_video->setSizePolicy(sizePolicy1);
        tb_create_new_video->setMinimumSize(QSize(0, 40));
        tb_create_new_video->setMaximumSize(QSize(16777215, 40));
        tb_create_new_video->setFont(font5);
        tb_create_new_video->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#C3C0C3;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
""));

        gridLayout_32->addWidget(tb_create_new_video, 0, 0, 1, 1);


        gridLayout_21->addWidget(widget_13, 2, 0, 1, 1);


        gridLayout_27->addWidget(w_create_video_panel, 0, 0, 1, 1);


        gridLayout_2->addWidget(w_right, 0, 5, 1, 1);

        splitter_vertical->addWidget(w_main);
        w_res = new QWidget(splitter_vertical);
        w_res->setObjectName(QStringLiteral("w_res"));
        w_res->setMinimumSize(QSize(0, 180));
        w_res->setMaximumSize(QSize(16777214, 180));
        gridLayout_8 = new QGridLayout(w_res);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(w_res);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 50));
        gridLayout_14 = new QGridLayout(widget);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        lbl_trimmer = new CxTrimmerPanel(widget);
        lbl_trimmer->setObjectName(QStringLiteral("lbl_trimmer"));
        lbl_trimmer->setMinimumSize(QSize(0, 150));
        lbl_trimmer->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_14->addWidget(lbl_trimmer, 1, 0, 1, 1);

        w_control_button = new QWidget(widget);
        w_control_button->setObjectName(QStringLiteral("w_control_button"));
        w_control_button->setMinimumSize(QSize(0, 25));
        w_control_button->setMaximumSize(QSize(16777215, 25));
        gridLayout_10 = new QGridLayout(w_control_button);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        tb_expand_trimmer = new QToolButton(w_control_button);
        tb_expand_trimmer->setObjectName(QStringLiteral("tb_expand_trimmer"));
        tb_expand_trimmer->setMinimumSize(QSize(20, 20));
        tb_expand_trimmer->setMaximumSize(QSize(20, 20));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/res/expand.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/res/collapse.png"), QSize(), QIcon::Normal, QIcon::On);
        tb_expand_trimmer->setIcon(icon8);
        tb_expand_trimmer->setIconSize(QSize(20, 20));
        tb_expand_trimmer->setCheckable(true);

        gridLayout_10->addWidget(tb_expand_trimmer, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_14->addWidget(w_control_button, 0, 0, 1, 1);

        lw_item_layer = new CxItemLayer(widget);
        lw_item_layer->setObjectName(QStringLiteral("lw_item_layer"));

        gridLayout_14->addWidget(lw_item_layer, 2, 0, 1, 1);


        gridLayout_8->addWidget(widget, 0, 1, 1, 1);

        w_bottom_left = new QWidget(w_res);
        w_bottom_left->setObjectName(QStringLiteral("w_bottom_left"));
        w_bottom_left->setMinimumSize(QSize(250, 0));
        w_bottom_left->setMaximumSize(QSize(250, 16777215));
        gridLayout_16 = new QGridLayout(w_bottom_left);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        widget_7 = new QWidget(w_bottom_left);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:transparent;\n"
"}"));
        gridLayout_17 = new QGridLayout(widget_7);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        tb_preview = new QToolButton(widget_7);
        tb_preview->setObjectName(QStringLiteral("tb_preview"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tb_preview->sizePolicy().hasHeightForWidth());
        tb_preview->setSizePolicy(sizePolicy5);
        tb_preview->setMinimumSize(QSize(80, 80));
        tb_preview->setMaximumSize(QSize(1111, 80));
        tb_preview->setFont(font2);
        tb_preview->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#9B9B9B;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
"\n"
""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/res/Media-Controls-Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QStringLiteral(":/res/Media-Controls-Pause-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        tb_preview->setIcon(icon9);
        tb_preview->setIconSize(QSize(80, 80));
        tb_preview->setCheckable(true);

        gridLayout_17->addWidget(tb_preview, 0, 0, 1, 1);


        gridLayout_16->addWidget(widget_7, 0, 0, 1, 1);

        widget_9 = new QWidget(w_bottom_left);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:transparent;\n"
"}"));
        gridLayout_25 = new QGridLayout(widget_9);
        gridLayout_25->setSpacing(0);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        tb_render = new QToolButton(widget_9);
        tb_render->setObjectName(QStringLiteral("tb_render"));
        sizePolicy5.setHeightForWidth(tb_render->sizePolicy().hasHeightForWidth());
        tb_render->setSizePolicy(sizePolicy5);
        tb_render->setMinimumSize(QSize(160, 60));
        tb_render->setMaximumSize(QSize(1111, 60));
        QFont font8;
        font8.setFamily(QStringLiteral("Impact"));
        font8.setPointSize(22);
        font8.setBold(true);
        font8.setWeight(75);
        tb_render->setFont(font8);
        tb_render->setStyleSheet(QLatin1String("QToolButton {\n"
"  border-style:none;\n"
"  border-left: 1px solid gray;\n"
"  border-top: 1px solid gray;\n"
"    \n"
"  border-bottom: 2px solid darkgrey;\n"
"  border-right: 2px solid darkgrey;\n"
"  color:black;\n"
"  background:#9B9B9B;\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"QToolButton:pressed {\n"
"  border-left: 2px solid gray;\n"
"  border-top: 2px solid gray;\n"
"    \n"
"  border-bottom: 1px solid grey;\n"
"  border-right: 1px solid grey;\n"
"  color:black;\n"
"  background:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0  rgb(216, 216, 216), stop: 0.1 rgb(155, 155, 155),\n"
"                                 stop: 0.5 rgb(155, 155, 155), stop: 1.0 rgb(207, 203, 207));\n"
"  padding:3px;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #545454\n"
"}\n"
"\n"
""));

        gridLayout_25->addWidget(tb_render, 0, 0, 1, 1);


        gridLayout_16->addWidget(widget_9, 1, 0, 1, 1);


        gridLayout_8->addWidget(w_bottom_left, 0, 2, 1, 1);

        splitter_vertical->addWidget(w_res);
        w_footer = new QWidget(splitter_vertical);
        w_footer->setObjectName(QStringLiteral("w_footer"));
        w_footer->setMinimumSize(QSize(0, 40));
        w_footer->setMaximumSize(QSize(16777215, 40));
        gridLayout_6 = new QGridLayout(w_footer);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(9, 0, 0, 0);
        lbl_footer = new QLabel(w_footer);
        lbl_footer->setObjectName(QStringLiteral("lbl_footer"));
        lbl_footer->setMinimumSize(QSize(0, 40));
        QFont font9;
        font9.setFamily(QStringLiteral("Berlin Sans FB Demi"));
        font9.setPointSize(14);
        font9.setBold(true);
        font9.setWeight(75);
        lbl_footer->setFont(font9);
        lbl_footer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(lbl_footer, 0, 1, 1, 1);

        cb_theme = new QComboBox(w_footer);
        cb_theme->setObjectName(QStringLiteral("cb_theme"));
        cb_theme->setMinimumSize(QSize(100, 30));
        cb_theme->setMaximumSize(QSize(100, 30));

        gridLayout_6->addWidget(cb_theme, 0, 0, 1, 1);

        splitter_vertical->addWidget(w_footer);

        gridLayout->addWidget(splitter_vertical, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Movie Missile", 0));
        lbl_title->setText(QApplication::translate("MainWindow", " MOVIEMISSILE", 0));
        tb_exit->setText(QApplication::translate("MainWindow", "X", 0));
        tb_minimize->setText(QApplication::translate("MainWindow", "_", 0));
        tb_maximize->setText(QApplication::translate("MainWindow", "M", 0));
        tb_logo->setText(QString());
        tb_mark->setText(QApplication::translate("MainWindow", "MARK", 0));
        tb_text->setText(QApplication::translate("MainWindow", "TEXT", 0));
        tb_image->setText(QApplication::translate("MainWindow", "BILD", 0));
        tb_delete->setText(QApplication::translate("MainWindow", "Del", 0));
        tb_delete_3->setText(QApplication::translate("MainWindow", "Del", 0));
        tb_delete_2->setText(QApplication::translate("MainWindow", "Del", 0));
        rb_flex->setText(QApplication::translate("MainWindow", "FLEX MODE", 0));
        rb_black_line->setText(QApplication::translate("MainWindow", "BLACK LINE", 0));
        rb_white_line->setText(QApplication::translate("MainWindow", "WHITE LINE", 0));
        tb_scene_color->setText(QApplication::translate("MainWindow", "COLOR", 0));
        tb_paint->setText(QApplication::translate("MainWindow", "PAINT", 0));
        tb_add_video->setText(QApplication::translate("MainWindow", "+", 0));
        tb_delete_video->setText(QApplication::translate("MainWindow", "X", 0));
        label_2->setText(QString());
        tb_upload_video->setText(QApplication::translate("MainWindow", "UPLOAD MP4", 0));
        tb_show_logo_widget->setText(QApplication::translate("MainWindow", "ADD LOGO", 0));
        tb_single_video_audio->setText(QApplication::translate("MainWindow", "UPLOAD AUDIO . . .", 0));
        tb_single_video_image->setText(QApplication::translate("MainWindow", "SELECT IMAGE", 0));
        tb_single_video_mp4->setText(QApplication::translate("MainWindow", "SELECT MP4-VID", 0));
        tb_save_single_video->setText(QApplication::translate("MainWindow", "SAVE", 0));
        tb_single_image_video->setText(QApplication::translate("MainWindow", "1-GRAPHIC VID", 0));
        tb_add_logo->setText(QApplication::translate("MainWindow", "...", 0));
        tb_logo_save->setText(QApplication::translate("MainWindow", "SAVE POSITION", 0));
        tb_delete_logo->setText(QApplication::translate("MainWindow", "...", 0));
        tb_edit_video_freeze->setText(QApplication::translate("MainWindow", "EDIT INSIDE", 0));
        tb_show_editvideowidget->setText(QString());
        tb_edit_video_image->setText(QApplication::translate("MainWindow", "ADD IMAGE", 0));
        tb_remove_intro->setText(QApplication::translate("MainWindow", "...", 0));
        tb_add_intro->setText(QApplication::translate("MainWindow", "...", 0));
        label->setText(QApplication::translate("MainWindow", "INTRO", 0));
        tb_create_new_video->setText(QApplication::translate("MainWindow", "CREATE NEW VIDEO", 0));
        lbl_trimmer->setText(QString());
        tb_expand_trimmer->setText(QApplication::translate("MainWindow", "...", 0));
        tb_preview->setText(QApplication::translate("MainWindow", "MARK", 0));
        tb_render->setText(QApplication::translate("MainWindow", "FINALIZE", 0));
        lbl_footer->setText(QApplication::translate("MainWindow", "Copyright \302\251 2020 Tom K.   ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
