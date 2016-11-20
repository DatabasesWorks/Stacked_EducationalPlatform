#include "loginwin.h"
#include "ui_loginwin.h"
#include "client.h"

LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::on_loginButton_clicked()
{
    //send user and pass to controller and check validity
    int x = 0;
    //x = Controller->sendLogin(ui->userEntry.text(), ui->passEntry.text());
    Client* par = (Client*) this->parentWidget();

//    switch(x){
//        case 0:  //if student
//            par->setCurrentPage("studwin");

//            break;
//        case 1: //if teacher
//            par->setCurrentPage("teachwin");
//            break;
//        case 2: //invalid credentials
//            //TODO
//            break;
//    }
}

void LoginWin::on_regStud_clicked()
{
    Client* par = (Client*) this->parentWidget();
    par->setCurrentPage("studreg");
}

void LoginWin::on_regTeach_clicked()
{
    Client* par = (Client*) this->parentWidget();
    par->setCurrentPage("teachreg");
}
