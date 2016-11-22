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
    db.h \

#osx
macx: LIBS += -L"/usr/local/lib"
macx: LIBS += -L"/usr/local/mysql/lib"
macx: INCLUDEPATH += "/usr/local/include"
macx: INCLUDEPATH += "/usr/local/mysql/include"
macx: DEPENDPATH += "/usr/local/include"
macx: DEPENDPATH += "/usr/local/mysql/include"

#this should work for a shared library on unix as well.
linux: LIBS += -L"/usr/local/lib"
linux: INCLUDEPATH += "/usr/local/include"
linux: DEPENDPATH += "/usr/local/include"

#windows
win32: INCLUDEPATH += "C:\\SFML\\include"
win32: DEPENDPATH += "C:\\SFML\\include"
win32: LIBS += -L"C:\\SFML\\lib"
win32: INCLUDEPATH += "C:\\mysql\\include"
win32: DEPENDPATH += "C:\\mysql\\include"
win32: LIBS += -L"C:\\mysql\\lib"

#internet says this makes libs add more stable?
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lmysqlclient
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window -lmysqlclient
