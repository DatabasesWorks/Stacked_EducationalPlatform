#include "studwin.h"
#include "ui_studwin.h"

StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin)
{
    ui->setupUi(this);
}

StudWin::~StudWin()
{
    delete ui;
}
