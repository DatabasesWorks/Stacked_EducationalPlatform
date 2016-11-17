#include "teachreg.h"
#include "ui_teachreg.h"
#include "view.h"

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

void TeachReg::on_cancelButton_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("login");
}

void TeachReg::on_regButton_clicked()
{
    //later add checking for validity and probably a success
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("login");
}
