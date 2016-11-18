#include "teachreg.h"
#include "ui_teachreg.h"
#include "client.h"

TeachReg::TeachReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachReg)
{
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

TeachReg::~TeachReg()
{
    delete ui;
}

void TeachReg::on_cancelButton_clicked()
{
    Client* par = (Client*) this->parentWidget();
    par->setCurrentPage("login");
}

void TeachReg::on_regButton_clicked()
{
    //send teacher registration
    int x = 0;
    //Controller->sendReg(bool isTeach, Qstring user, Qstring Pass, Qstring class)
    //x = Controller->sendReg(true, ui->userEntry.text(), ui->passEntry.text(), ui->classEntry.text());
    Client* par = (Client*) this->parentWidget();
    switch(x){
        case 0: //success
            par->setCurrentPage("login");
            break;
        case 1: //user name taken error
            break;
        case 2: //class code taken error
            break;
    }
}
