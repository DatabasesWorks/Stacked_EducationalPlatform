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
#linux: QT += x11extras

#osx stuff comment out if it causes problems
macx: LIBS += -L"/usr/local/lib"
macx: LIBS += -L"$$PWD"
macx: INCLUDEPATH += "/usr/local/include"
macx: DEPENDPATH += "/usr/local/include"
#this should work for a shared library on unix as well.
linux: LIBS += -L"/usr/local/lib"
linux: INCLUDEPATH += "/usr/local/include"
linux: DEPENDPATH += "/usr/local/include"
#windows
win32: INCLUDEPATH += "C:\\SFML\\include"
win32: DEPENDPATH += "C:\\SFML\\include"
win32: LIBS += -L"C:\\SFML\\lib"

LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
#LIBS += -lBox2d
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

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
    usersocket.cpp \
    message.cpp \
    graphicsobject.cpp \
    graphicsobjecttest.cpp


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
    usersocket.h \
    message.h \
    graphicsobject.h \
    graphicsobjecttest.h
    # Box2D.h

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


