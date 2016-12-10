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

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client) {
    ui->setupUi(this);
    //move the window to the center of the screen
    move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
}

Client::~Client() {
    delete ui;
}

//TODO: Move this all to controller later?
//TODO: Make sure this doesn't cause memory leaks (I think it should be fine)
void Client::setCurrentPage(QString s) {
    if (s == "login") {
        setCentralWidget(new LoginWin());
    } else if (s == "studwin") {
        setCentralWidget(new StudWin());
    } else if (s == "teachwin") {
        setCentralWidget(new TeachWin());
    } else if (s == "studreg") {
        setCentralWidget(new StudReg());
    } else if (s == "teachreg") {
        setCentralWidget(new TeachReg());
    }
}

bool Client::sendLogin(QString user, QString pass) {
    try {
        UserSocket sock(sf::IpAddress::LocalHost, 11777);
        sock.authenticate(user.toStdString(), pass.toStdString()); //if no exceptions thrown, then we are authenticated
        sock.deauthenticate(); //when you are done deauthenticate, or save the sid for later
        //(note: the server will be configured to auto check for expired session ids -- probably every like 20 minutes or something )
    } catch (authenticationexception) { // if the client was not authenticated properly, or the session key was invalid
        return false;
    }
    //send payload and parse payload to determine if teach/student
    bool teach = false;

    if (teach) {
        setCentralWidget(new TeachWin());
    } else {
        setCentralWidget(new StudWin());
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

    setCentralWidget(new LoginWin());
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
void Client::on_pushButton_clicked() {
    setCentralWidget(new LoginWin());
}

void Client::on_pushButton_2_clicked() {
    //This logic will need to be changed later
    StudWin *studwin = new StudWin(this);

    setCentralWidget(studwin);
}

void Client::on_pushButton_3_clicked() {
    setCentralWidget(new TeachWin());
}

void Client::on_pushButton_4_clicked() {
    setCentralWidget(new StudReg());
}

void Client::on_pushButton_5_clicked() {
    setCentralWidget(new TeachReg());
}

void Client::on_pushButton_6_clicked() {
//    PuzzleWindow pw;
//    setCentralWidget(new GraphicsObjectTest);
}
