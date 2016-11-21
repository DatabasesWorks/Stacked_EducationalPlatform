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
#include <graphicsobjecttest.h>

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
    //Some example code to demonstrate the use of the usersocket class

    try{

        //you can create your own custom commands to the server in this format:
        //sock.sendPayload(command, payload);

        UserSocket sock(sf::IpAddress::LocalHost, 11777);
        sock.authenticate(user.toStdString(),pass.toStdString()); //if no exceptions thrown, then we are authenticated

        Message msg = sock.sendPayload("rawpayload","give me something"); //once authenticated you can send commands and payloads
        std::cout << msg.payload.toAnsiString() << std::endl;

        //create another socket using the same session id
        UserSocket sock2(sf::IpAddress::LocalHost,11777,sock.sid());
        Message msg2 = sock2.sendPayload("rawpayload","give me something else");
        std::cout << msg2.payload.toAnsiString() << std::endl;

        sock2.deauthenticate(); //when you are done deauthenticate, or save the sid for later
        //(note: the server will be configured to auto check for expired session ids -- probably every like 20 minutes or something )

    }catch(authenticationexception){ // if the client was not authenticated properly, or the session key was invalid
    }catch(socketexception){ // if the there was some socket binding error
    }catch(packetexception){ // if a packet was made incorrectly
    }catch(timeoutexception){ // this can happen with a bad connection ( or no response from the server )

    }

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
    UserSocket sock(sf::IpAddress::LocalHost, 11777);
    QString data = user+","+pass+","+classCode+","+QString::number(teach);
    Message msg = sock.sendPayload("register", data.toStdString());
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

void Client::on_pushButton_6_clicked()
{
    setCentralWidget(new GraphicsObjectTest());
}
