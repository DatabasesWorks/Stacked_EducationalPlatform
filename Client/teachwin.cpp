#include "teachwin.h"
#include "ui_teachwin.h"
#include "client.h"

TeachWin::TeachWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachWin)
{
    ui->setupUi(this);
}

TeachWin::~TeachWin()
{
    delete ui;
}

void TeachWin::on_logoutButton_clicked()
{
    Client* par = (Client*) this->parentWidget();
    par->setCurrentPage("login");
}
