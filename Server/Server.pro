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

#osx stuff comment out if it causes problems
LIBS += -L"/usr/local/lib"
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#internet says this makes libs add more stable?
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
