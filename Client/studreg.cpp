#include "studreg.h"
#include "loginwin.h"
#include "client.h"
#include "ui_studreg.h"
#include "QGridLayout"
#include "QPushButton"
#include <QRegExp>

StudReg::StudReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudReg) {
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

StudReg::StudReg(Client *client, QWidget* parent) : StudReg(parent){
     this->client=client;
}



StudReg::~StudReg() {
    delete ui;
}

void StudReg::on_cancelButton_clicked() {

    Client *par = client;

    par->setCurrentPage("login");
}

void StudReg::on_regButton_clicked() {
    if(!Validate(ui->userEntry->text())){
        ui->userEntry->setText("bad chars");
        //make an error dialog here
    }else if(!Validate(ui->passEntry->text())){
         ui->passEntry->setText("bad chars");
         //make an error dialog here
    }

    Client *par = client;
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

//alphanumeric 4-16
bool StudReg::Validate(QString s){
    QRegExp re("[A-Za-z0-9]{4,16}");
    return re.exactMatch(s);
}

