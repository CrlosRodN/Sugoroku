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


SOURCES += main.cpp\
        MainWindow.cpp \
    Sugoroku.cpp \
    Token.cpp

HEADERS  += MainWindow.h \
    Sugoroku.h \
    Token.h

FORMS    += MainWindow.ui

RESOURCES += assets/assets.qrc
