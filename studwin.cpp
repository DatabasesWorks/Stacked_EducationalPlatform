#include "studwin.h"
#include "ui_studwin.h"

StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin)
{
    ui->setupUi(this);
//    QGridLayout* grid = new QGridLayout(ui->centralWidget);
//    //Selects 1 and sets stretch factor to 10 (10 is relative to other columns)
//    grid->setColumnStretch(1,10);
//    //Selects 2 and sets stretch factor to (90 is relative to other columns)
//    grid->setColumnStretch(2, 90);
//    //Adds widget (widget, row, colum, rowspan, colspan, alignment
//    QPushButton* button1 = new QPushButton("BUTTON1!");
//    QPushButton* button2 = new QPushButton("BUTTON2!");
//    QPushButton* button3 = new QPushButton("BUTTON3!");
//    grid->addWidget(button1, 1,1,1,1, Qt::AlignCenter);
//    grid->addWidget(button2, 1,2,1,1, Qt::AlignCenter);
//    grid->addWidget(button3, 1,3,1,1, Qt::AlignCenter);

//    //Example of how to create signal/slot connecton for new buttons
//    connect(button1, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

StudWin::~StudWin()
{
    delete ui;
}
