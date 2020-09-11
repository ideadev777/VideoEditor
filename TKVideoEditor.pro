#-------------------------------------------------
#
# Project created by QtCreator 2020-07-02T21:48:26
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TKVideoEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cxlayer.cpp \
    form_video_control.cpp \
    cxvideopanel.cpp \
    cxgraphicsscene.cpp \
    cxgraphicsitem.cpp \
    common.cpp \
    cxgraphicsview.cpp \
    cximageitem.cpp \
    cxtextitem.cpp \
    mygraphicstextitem.cpp \
    cxtexteditpanel.cpp \
    textedit.cpp \
    cxcolorbutton.cpp \
    cxmarkpanel.cpp \
    cxmarkitem.cpp \
    cxvideoitem.cpp

HEADERS  += mainwindow.h \
    cxlayer.h \
    form_video_control.h \
    cxvideopanel.h \
    cxgraphicsscene.h \
    cxgraphicsitem.h \
    common.h \
    cxgraphicsview.h \
    cximageitem.h \
    cxtextitem.h \
    mygraphicstextitem.h \
    cxtexteditpanel.h \
    textedit.h \
    cxcolorbutton.h \
    cxmarkpanel.h \
    cxmarkitem.h \
    cxvideoitem.h

FORMS    += mainwindow.ui \
    form_video_control.ui \
    form_text_edit.ui \
    form_mark_panel.ui

RESOURCES += \
    res.qrc
