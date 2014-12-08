#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T16:14:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sugoroku
TEMPLATE = app


SOURCES += main.cpp \
    MainWindow.cpp \
    source/main.cpp \
    source/MainWindow.cpp

HEADERS  += \
    MainWindow.h \
    source/MainWindow.h

FORMS    += \
    MainWindow.ui

RESOURCES += \
    assets/assets.qrc
