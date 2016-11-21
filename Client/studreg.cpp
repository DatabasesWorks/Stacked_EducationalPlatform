#include "studreg.h"
#include "loginwin.h"
#include "client.h"
#include "ui_studreg.h"
#include "QGridLayout"
#include "QPushButton"

StudReg::StudReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudReg) {
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

StudReg::~StudReg() {
    delete ui;
}

void StudReg::on_cancelButton_clicked() {
    Client *par = (Client *)this->parentWidget();

    par->setCurrentPage("login");
}

void StudReg::on_regButton_clicked() {
    Client *par = (Client *)this->parentWidget();
    int x = par->sendReg(false, ui->userEntry->text(), ui->passEntry->text(), ui->classEntry->text());

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
