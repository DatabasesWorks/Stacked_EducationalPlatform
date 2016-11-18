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
    setCentralWidget(new LoginWin());
}

View::~View()
{
    delete ui;
}

//TODO: Move this all to controller later?
//TODO: Make sure this doesn't cause memory leaks (I think it should be fine)
void View::setCurrentPage(QString s)
{
    if(s == "login"){
        setCentralWidget(new LoginWin());
    }else if(s == "studwin"){
        setCentralWidget(new StudWin());
    }else if(s == "teachwin"){
        setCentralWidget(new TeachWin());
    }else if(s == "studreg"){
        setCentralWidget(new StudReg());
    }else if(s == "teachreg"){
        setCentralWidget(new TeachReg());
    }
}

//UI debug individual pages
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