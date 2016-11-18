#include "studwin.h"
#include "ui_studwin.h"

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

void StudWin::on_pushButton_clicked()
{
    if(levelshow)
    {
        ui->levelFrame->hide();
        levelshow = false;
        ui->pushButton->setText(QString("Show Levels"));
    }
    else
    {
        ui->levelFrame->showNormal();
        ui->pushButton->setText(QString("Hide Levels"));
        levelshow = true;
    }

}

//Move to controller?
void StudWin::on_pushButton_2_clicked()
{
    View* par = (View*) this->parentWidget();
    par->setCurrentPage("login");
}
