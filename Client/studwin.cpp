#include "studwin.h"
#include "ui_studwin.h"
#include "client.h"

StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin)
{
    ui->setupUi(this);
    levelshow = true;

}

StudWin::~StudWin()
{
    delete ui;
}

void StudWin::on_hideButton_clicked()
{
    if(levelshow)
    {
        ui->levelFrame->hide();
        levelshow = false;
        ui->hideButton->setText(QString("Show Levels"));
    }
    else
    {
        ui->levelFrame->showNormal();
        ui->hideButton->setText(QString("Hide Levels"));
        levelshow = true;
    }

}

//Move to controller?
void StudWin::on_logoutButton_clicked()
{
    Client* par = (Client*) this->parentWidget();
    par->setCurrentPage("login");
}
