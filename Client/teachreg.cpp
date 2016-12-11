#include "teachreg.h"
#include "ui_teachreg.h"
#include "client.h"

TeachReg::TeachReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachReg) {
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
    //this->setStyleSheet("background-color: black; color: white;");
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
    QString data = ui->userEntry->text() + "," + ui->passEntry->text() + "," + ui->classEntry->text() + ",1," + ui->dobEntry->text();
    int x = par->sendReg(data);

    switch (x) {
        case 0: //success
            return;

        case 1: //user name taken error
            //TODO Placeholder add invalid dialog
            ui->userEntry->setText("USERNAME TAKEN");
            ui->passEntry->setText("");
            ui->classEntry->setText("");
            break;

        case 2: //class code invalid error
            //TODO Placeholder add invalid dialog
            ui->classEntry->setText("CLASS TAKEN");
            ui->passEntry->setText("");
            ui->userEntry->setText("");
            break;
    }
}
