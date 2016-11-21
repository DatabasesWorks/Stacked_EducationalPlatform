#include "loginwin.h"
#include "ui_loginwin.h"
#include "client.h"

LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin) {
    ui->setupUi(this);
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

LoginWin::~LoginWin() {
    delete ui;
}

void LoginWin::on_loginButton_clicked() {
    Client *par = (Client *)this->parentWidget();

    if (!par->sendLogin(ui->userEntry->text(), ui->passEntry->text())) {
        //TODO Make dialog
        ui->userEntry->setText("INVALID CREDENTIALS");
        ui->passEntry->setText("");
    }
}

void LoginWin::on_regStud_clicked() {
    Client *par = (Client *)this->parentWidget();

    par->setCurrentPage("studreg");
}

void LoginWin::on_regTeach_clicked() {
    Client *par = (Client *)this->parentWidget();

    par->setCurrentPage("teachreg");
}
