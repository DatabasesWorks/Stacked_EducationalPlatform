#include "teachwin.h"
#include "ui_teachwin.h"
#include "client.h"

TeachWin::TeachWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachWin)
{
    ui->setupUi(this);
    updateStudents();
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
void TeachWin::updateStudents()
{
    //query database get list of students in class
    ui->listWidget->clear();
    for(int i = 1; i<=20; i++)
    {
         ui->listWidget->addItem("StudentName");
    }
    ui->listWidget->setCurrentRow(0);
}

void TeachWin::on_listWidget_itemSelectionChanged()
{
    //get data from student database and put into main widget
}

void TeachWin::on_pushButton_clicked()
{
    //remove student from database here

    updateStudents();
}
