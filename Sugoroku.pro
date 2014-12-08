TARGET = Sugoroku
TEMPLATE = app
QT += core gui widgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += source/main.cpp
SOURCES += source/MainWindow.cpp

HEADERS += source/MainWindow.h

FORMS += source/MainWindow.ui

RESOURCES += assets/assets.qrc
