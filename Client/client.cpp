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

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
//    setCentralWidget(new LoginWin());
    UserSocket sock("127.0.0.1", 11700);
    bool results = sock.authenticate("test","user");
    std::cout << results << std::endl;
   // sock.sendPayload("sending test message, payload: "+results);

}

Client::~Client()
{
    delete ui;
}

//TODO: Move this all to controller later?
//TODO: Make sure this doesn't cause memory leaks (I think it should be fine)
void Client::setCurrentPage(QString s)
{
    if(s == "login"){
        setCentralWidget(new LoginWin());
    }else if(s == "studwin"){
        setCentralWidget(new StudWin());
    }else if(s == "teachwin"){
        setCentralWidget(new TeachWin());
    }else if(s == "studreg"){
        setCentralWidget(new StudReg());
    }else if(s == "teachreg"){
        setCentralWidget(new TeachReg());
    }
}
bool Client::sendLogin(QString user, QString pass){
//    UserSocket sock("127.0.0.1", 11700);
//    bool results = sock.authenticate(user,pass);

    //send payload and parse payload for usertoken and
}

//UI debug individual pages
void Client::on_pushButton_clicked()
{
    setCentralWidget(new LoginWin());
}

void Client::on_pushButton_2_clicked()
{

    setCentralWidget(new StudWin());
}

void Client::on_pushButton_3_clicked()
{

    setCentralWidget(new TeachWin());
}

void Client::on_pushButton_4_clicked()
{

    setCentralWidget(new StudReg());
}

void Client::on_pushButton_5_clicked()
{
    setCentralWidget(new TeachReg());
}
