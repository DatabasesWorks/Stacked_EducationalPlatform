#include "view.h"
#include "loginwin.h"
#include "studwin.h"
#include "teachwin.h"

#include "ui_view.h"
#include "QGraphicsView"
#include "QGridLayout"
#include "QPushButton"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    //Set gridlayout to centralWidget (optional -- also can do ui...I think)
    QGridLayout* grid = new QGridLayout(ui->centralWidget);
    //Selects 1 and sets stretch factor to 10 (10 is relative to other columns)
    grid->setColumnStretch(1,10);
    //Selects 2 and sets stretch factor to (90 is relative to other columns)
    grid->setColumnStretch(2, 90);
    //Adds widget (widget, row, colum, rowspan, colspan, alignment
    QPushButton* button1 = new QPushButton("BUTTON1!");
    QPushButton* button2 = new QPushButton("BUTTON2!");
    QPushButton* button3 = new QPushButton("BUTTON3!");
    grid->addWidget(button1, 1,1,1,1, Qt::AlignCenter);
    grid->addWidget(button2, 1,2,1,1, Qt::AlignCenter);
    grid->addWidget(button3, 1,3,1,1, Qt::AlignCenter);

    //Example of how to create signal/slot connecton for new buttons
    connect(button1, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

View::~View()
{
    delete ui;
}


void View::on_pushButton_clicked()
{
    setCentralWidget(new LoginWin());
}

void View::on_pushButton_3_clicked()
{
    setCentralWidget(new StudWin());
}

void View::on_pushButton_2_clicked()
{
    setCentralWidget(new TeachWin());
}

void View::on_pushButton_4_clicked()
{
    setCentralWidget(new LoginWin());
}
