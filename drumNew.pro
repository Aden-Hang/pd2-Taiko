#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T20:57:12
#
#-------------------------------------------------

QT       += core gui  multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drumNew
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    pics.qrc

DISTFILES += \
    ../../Downloads/img/img/bg_miss_clear.png
