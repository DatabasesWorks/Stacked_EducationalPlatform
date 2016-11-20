QT += core

CONFIG += c++11

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    server.cpp \
    serversocket.cpp \
    message.cpp \
    db.cpp

HEADERS += \
    server.h \
    serversocket.h \
    message.h \
    exceptions.h \
    db.h

#osx stuff comment out if it causes problems
macx: LIBS += -L"/usr/local/lib"
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

#internet says this makes libs add more stable?
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
