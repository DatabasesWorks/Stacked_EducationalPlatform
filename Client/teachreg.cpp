#include "teachreg.h"
#include "ui_teachreg.h"
#include "client.h"

TeachReg::TeachReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachReg) {
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

TeachReg::~TeachReg() {
    delete ui;
}

void TeachReg::on_cancelButton_clicked() {
    Client *par = (Client *)this->parentWidget();

    par->setCurrentPage("login");
}

void TeachReg::on_regButton_clicked() {
    Client *par = (Client *)this->parentWidget();
    int x = par->sendReg(true, ui->userEntry->text(), ui->passEntry->text(), ui->classEntry->text());

    switch (x) {
        case 0: //success
            return;

        case 1: //user name taken error
            //TODO invalid dialog
            break;

        case 2: //class code invalid error
            //TODO invalid dialog
            break;
    }
}
