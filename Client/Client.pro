#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T16:40:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = Client
TEMPLATE = app
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network


macx: LIBS += -L"/usr/local/lib"
macx: INCLUDEPATH += "/usr/local/include"
macx: DEPENDPATH += "/usr/local/include"

win32: INCLUDEPATH += C:/SFML/include/
win32: DEPENDPATH += C:/SFML/include/
win32: LIBS += -LC:/SFML/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system

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
    puzzlecomponent.cpp \
    clientsocket.cpp


HEADERS  += client.h \
    teachwin.h \
    studwin.h \
    loginwin.h \
    teachreg.h \
    studreg.h \
    datastructure.h \
    level.h \
    puzzle.h \
    puzzlecomponent.h \
    clientsocket.h

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


