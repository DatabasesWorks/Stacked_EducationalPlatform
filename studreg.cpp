#include "studreg.h"
#include "loginwin.h"
#include "view.h"
#include "ui_studreg.h"
#include "QGridLayout"
#include "QPushButton"

StudReg::StudReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudReg)
{
    ui->setupUi(this);
    //maybe get rid of this
    ui->passEntry->setEchoMode(QLineEdit::Password);
}

StudReg::~StudReg()
{
    delete ui;
}

void StudReg::on_cancelButton_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("login");
}

void StudReg::on_regButton_clicked()
{
    //send teacher registration
    int x = 0;
    // sendReg(bool isTeach, Qstring user, Qstring pass, Qstring class)
    //x = Controller->sendReg(true, ui->userEntry.text(), ui->passEntry.text(), ui->classEntry.text());
    View* par = (View*) this->parentWidget();
    switch(x){
        case 0: //success
            par->setCurrentPage("login");
            break;
        case 1: //user name taken error
            break;
        case 2: //class code invalid error
            break;
    }
}
