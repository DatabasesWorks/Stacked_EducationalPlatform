#include "studreg.h"
#include "loginwin.h"
#include "ui_studreg.h"
#include "QGridLayout"
#include "QPushButton"

StudReg::StudReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudReg)
{
    ui->setupUi(this);
}

StudReg::~StudReg()
{
    delete ui;
}

void StudReg::on_cancelButton_clicked()
{
//    this = new LoginWin();
}
