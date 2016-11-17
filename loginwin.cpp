#include "loginwin.h"
#include "ui_loginwin.h"

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
