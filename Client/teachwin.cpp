#include "teachwin.h"
#include "ui_teachwin.h"
#include "client.h"

TeachWin::TeachWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachWin)
{
    ui->setupUi(this);
    setupStudents();
    ui->listWidget->setCurrentRow(0);
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
void TeachWin::setupStudents()
{
    for(int i = 1; i<=20; i++)
    {
         ui->listWidget->addItem("StudentName");
    }
}
