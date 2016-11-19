#include "studwin.h"
#include "ui_studwin.h"
#include "client.h"
#include <vector>
#include "qstandarditemmodel.h"

StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin)
{
    ui->setupUi(this);
    levelshow = true;

    ui->userLabel->setText("Welcome: TestUser");

    setupLevels();

}

StudWin::~StudWin()
{
    delete ui;
}

void StudWin::setupLevels()
{
    std::vector<QString> dataList;
    std::vector<QString> levelList;
    QStandardItemModel model;

    for(int i = 0; i<5; i++)
    {
         dataList.push_back("DataStructure "+i);
         levelList.push_back("Level "+i);
    }
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
