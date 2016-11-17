#include "view.h"
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
    grid->addWidget(new QPushButton("BUTTON1!"), 1,1,1,1, Qt::AlignCenter);
    grid->addWidget(new QPushButton("BUTTON2!"), 1,2,1,1, Qt::AlignCenter);

    grid->addWidget(new QPushButton("BUTTON3!"), 1,3,1,1, Qt::AlignCenter);
}

View::~View()
{
    delete ui;
}
