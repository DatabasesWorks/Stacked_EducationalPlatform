#include "loginwin.h"
#include "ui_loginwin.h"
#include "view.h"

LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);
}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::on_loginButton_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("studwin");
}

void LoginWin::on_regStud_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("studreg");
}

void LoginWin::on_regTeach_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("teachreg");
}
