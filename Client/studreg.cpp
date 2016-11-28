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
    QString data = ui->userEntry->text() + "," + ui->passEntry->text() + "," + ui->classEntry->text() + ",0,"+ ui->dobEntry->text();
    int x = par->sendReg(data);

    switch (x) {
        case 0: //success
            return;

        case 1: //user name taken error
            //TODO Make dialog
            ui->userEntry->setText("USERNAME TAKEN");
            ui->passEntry->setText("");
            ui->classEntry->setText("");
            break;

        case 2: //class code invalid error
            //TODO invalid dialog
            ui->classEntry->setText("CLASS DOES NOT EXIST");
            ui->passEntry->setText("");
            ui->userEntry->setText("");
            break;
    }
}

