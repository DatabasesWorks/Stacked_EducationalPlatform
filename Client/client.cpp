#include "client.h"
#include "loginwin.h"
#include "studwin.h"
#include "teachwin.h"
#include "studreg.h"
#include "teachreg.h"
#include "ui_client.h"
#include "QGraphicsView"
#include "QGridLayout"
#include "QPushButton"
#include <usersocket.h>
#include <iostream>
#include <SFML/Audio.hpp>
#include <QDesktopWidget>
#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QTimer>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client) {
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &Client::loginWindow);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &Client::studentWindow);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &Client::teacherWindow);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &Client::studentRegistration);
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, this, &Client::teacherRegistration);
    QObject::connect(ui->pushButton_7, &QPushButton::clicked, this, &Client::on_pushButton_7_clicked);
    QObject::connect(&timer, &QTimer::timeout, this, &Client::autosave);
    //move the window to the center of the screen
    move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
    widget.addWidget(new LoginWin(this, nullptr));
    timer.start(30000); //every 30 seconds or so
    widget.addWidget(new StudWin(this, nullptr));
    widget.addWidget(new TeachWin(this, nullptr));
    widget.addWidget(new StudReg(this, nullptr));
    widget.addWidget(new TeachReg(this, nullptr));
    this->setStyleSheet("background-color: black; color: white");

    check = true;
}

Client::~Client() {
    delete ui;
    try {
        UserSocket sock(sf::IpAddress::LocalHost, 11777, getSessionId());
        sock.deauthenticate();
    } catch (std::exception) {
    }
}

//TODO: Move this all to controller later?
void Client::setCurrentPage(QString s) {
    if (check.is_lock_free() && check) {
        check = false;
        this->setCentralWidget(&widget);

        if (s == "login") {
            activeWidget = 0;
        } else if (s == "studwin") {
            activeWidget = 1;
        } else if (s == "teachwin") {
            activeWidget = 2;
            static_cast<TeachWin *>(widget.widget(activeWidget))->updateStudents();
        } else if (s == "studreg") {
            activeWidget = 3;
        } else if (s == "teachreg") {
            activeWidget = 4;
        }

        widget.setCurrentIndex(activeWidget);
        widget.currentWidget()->setFocus();
        widget.currentWidget()->activateWindow();

        check = true;
    }
}

void Client::autosave() {
    if (activeWidget == 1 && sessionid != "") {
        UserSocket sock(sf::IpAddress::LocalHost, 11777, sessionid);
        StudWin *win = static_cast<StudWin *>(widget.widget(1));
        std::vector<bool> solvedlist = win->getSolvedList();
        int index = 0;
        for (auto it = solvedlist.begin(); it < solvedlist.end(); it++) {
            bool i = *it;
            if (i) {
                std::stringstream ss;
                ss << username << "," << index+1;
                Message msg = sock.sendPayload("puzzlesolved", ss.str());
                int i = 0;
            }
            index++;
        }
        win->updatePuzzles();
    }
}

bool Client::sendLogin(QString user, QString pass) {
    try {
        UserSocket sock(sf::IpAddress::LocalHost, 11777);
        sock.authenticate(user.toStdString(), pass.toStdString()); //if no exceptions thrown, then we are authenticated
        sessionid = sock.sid();
        username = user.toStdString();
        // sock.deauthenticate(); //when you are done deauthenticate, or save the sid for later
        //(note: the server will be configured to auto check for expired session ids -- probably every like 20 minutes or something )
    } catch (authenticationexception) { // if the client was not authenticated properly, or the session key was invalid
        return false;
    }
    //send payload and parse payload to determine if teach/student
    bool teach = false;




    ///////////?!

    if (teach) {
        setCurrentPage("teachwin");
        static_cast<TeachWin *>(widget.currentWidget())->setCurrentUsername(QString::fromStdString(username));
    } else {
        setCurrentPage("studwin");
        StudWin * stud = static_cast<StudWin *>(widget.currentWidget());
        stud->updatePuzzles();
        static_cast<StudWin *>(widget.currentWidget())->setCurrentUsername(QString::fromStdString(username));
    }

    return true;
}

int Client::sendReg(QString data) {
    UserSocket sock(sf::IpAddress::LocalHost, 11777);

    try {
        Message msg = sock.sendPayload("register", data.toStdString());
    } catch (reguserexception) {
        return 1;
    } catch (regclassexception) {
        return 2;
    }

    setCurrentPage("login");
    return 0;
}

//hardcoded to class "" for now
QVector<QString> Client::getStudents(QString) { // still unimplemented
    UserSocket sock(sf::IpAddress::LocalHost, 11777);

    sock.authenticate("", "");
    Message msg = sock.sendPayload("getstudents", "");//classcode.toStdString());
    QVector<QString> students = QString::fromStdString(msg.payload).split(",").toVector();
    return students;
}

//UI debug individual pages
void Client::loginWindow() {
    setCurrentPage("login");
}

void Client::studentWindow() {
    setCurrentPage("studwin");
}

std::string Client::getSessionId() {
    return sessionid;
}

void Client::teacherWindow() {
    setCurrentPage("teachwin");
}

void Client::studentRegistration() {
    setCurrentPage("studreg");
}

void Client::teacherRegistration() {
    setCurrentPage("teachreg");
}

void Client::on_pushButton_7_clicked() {
    UserSocket sock(sf::IpAddress::LocalHost, 11777);

    try {
        sock.authenticate("squirtle", "pass");
        qDebug() << "tried to send payload";
        Message msg = sock.sendPayload("studentlist", "");
        QDesktopServices::openUrl(QUrl(QString::fromStdString(msg.payload)));
    } catch (...) {
        qDebug() << "Error 404 God not found";
    }
}
