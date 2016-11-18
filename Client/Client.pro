#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T16:40:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
    client.cpp \
    teachwin.cpp \
    studwin.cpp \
    loginwin.cpp \
    teachreg.cpp \
    studreg.cpp \
    datastructure.cpp \
    level.cpp \
    puzzle.cpp \
    puzzlecomponent.cpp


HEADERS  += client.h \
    teachwin.h \
    studwin.h \
    loginwin.h \
    teachreg.h \
    studreg.h \
    datastructure.h \
    level.h \
    puzzle.h \
    puzzlecomponent.h

FORMS    += client.ui \
    teachwin.ui \
    studwin.ui \
    loginwin.ui \
    teachreg.ui \
    studreg.ui

RESOURCES += \
    style.qrc

DISTFILES += \
    Stacked.pro.user
