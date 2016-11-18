#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T16:40:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stacked
TEMPLATE = app


SOURCES += main.cpp\
    teachwin.cpp \
    studwin.cpp \
    loginwin.cpp \
    teachreg.cpp \
    studreg.cpp \
    client.cpp
    datastructure.cpp \
    level.cpp \
    puzzle.cpp \
    puzzlecomponent.cpp


HEADERS  += \
    teachwin.h \
    studwin.h \
    loginwin.h \
    teachreg.h \
    studreg.h \
    client.h
    datastructure.h \
    level.h \
    puzzle.h \
    puzzlecomponent.h

FORMS    += \
    teachwin.ui \
    studwin.ui \
    loginwin.ui \
    teachreg.ui \
    studreg.ui \
    client.ui

RESOURCES += \
    style.qrc

DISTFILES += \
    Stacked.pro.user
