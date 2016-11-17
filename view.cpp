#include "view.h"
#include "loginwin.h"
#include "studwin.h"
#include "teachwin.h"
#include "studreg.h"
#include "teachreg.h"

#include "ui_view.h"
#include "QGraphicsView"
#include "QGridLayout"
#include "QPushButton"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}


void View::on_pushButton_clicked()
{
    setCentralWidget(new LoginWin());
}

void View::on_pushButton_2_clicked()
{
    setCentralWidget(new StudWin());
}

void View::on_pushButton_3_clicked()
{
    setCentralWidget(new TeachWin());
}


void View::on_pushButton_4_clicked()
{
    setCentralWidget(new StudReg());
}

void View::on_pushButton_5_clicked()
{
    setCentralWidget(new TeachReg());
}
