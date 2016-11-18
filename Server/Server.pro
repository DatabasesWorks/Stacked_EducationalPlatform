QT += core

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    server.cpp

HEADERS += \
    server.h

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network


