#-------------------------------------------------
#
# Project created by QtCreator 2014-12-09T22:00:16
#
#-------------------------------------------------

QT += core gui
QT += core gui widgets
QT += svg

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sugoroku
TEMPLATE = app

SOURCES += source/main.cpp \
        source/MainWindow.cpp \
        source/Sugoroku.cpp \
        source/Token.cpp \
    source/Dice.cpp

HEADERS  += source/MainWindow.h \
        source/Sugoroku.h \
        source/Token.h \
    source/Dice.h

FORMS    += source/MainWindow.ui

RESOURCES += assets/assets.qrc
