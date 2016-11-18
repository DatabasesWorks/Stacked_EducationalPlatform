#include "teachwin.h"
#include "ui_teachwin.h"

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
