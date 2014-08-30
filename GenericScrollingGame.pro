#-------------------------------------------------
#
# Project created by QtCreator 2014-06-18T23:35:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenericScrollingGame5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    avoid.cpp \
    checkpoint.cpp \
    play.cpp \
    racer.cpp \
    work.cpp

HEADERS  += mainwindow.h \
    avoid.h \
    checkpoint.h \
    play.h \
    racer.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources/images.qrc
