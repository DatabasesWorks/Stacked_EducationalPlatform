#include "teachreg.h"
#include "ui_teachreg.h"

TeachReg::TeachReg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachReg)
{
    ui->setupUi(this);
}

TeachReg::~TeachReg()
{
    delete ui;
}
