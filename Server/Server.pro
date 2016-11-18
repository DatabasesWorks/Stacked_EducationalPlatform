QT += core

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    datastructure.cpp \
    level.cpp \
    puzzle.cpp \
    puzzlecomponent.cpp \
    server.cpp

HEADERS += \
    datastructure.h \
    level.h \
    puzzle.h \
    puzzlecomponent.h \
    server.h

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network


