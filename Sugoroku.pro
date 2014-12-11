#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T22:00:16
#
#-------------------------------------------------

QT += core gui
QT += core gui widgets
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sugoroku
TEMPLATE = app


SOURCES += source/main.cpp\
        source/MainWindow.cpp

HEADERS  += source/MainWindow.h

FORMS    += source/MainWindow.ui

RESOURCES += assets/assets.qrc
