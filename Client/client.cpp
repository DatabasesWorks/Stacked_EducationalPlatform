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
//#include <Box2D.h>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
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
    UserSocket sock(sf::IpAddress::LocalHost, 11777);
    bool results = sock.authenticate(user,pass);
    //if invalid credentials return false
    if(!results) return results;
    Message msg = sock.sendPayload("give me something");
    std::cout << msg.payload.toAnsiString() << std::endl;

    //send payload and parse payload to determine if teach/student
    bool teach = false;
    if(teach)
    {
        setCentralWidget(new TeachWin());
    }else
    {
        setCentralWidget(new StudWin());
    }
    return true;
}
int Client::sendReg(bool teach, QString user, QString pass, QString classCode){

    //send payload here

    //return 0 Valid
    //return 1 user taken
    //return 2 class taken

    setCentralWidget(new LoginWin());
    return 0;
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
