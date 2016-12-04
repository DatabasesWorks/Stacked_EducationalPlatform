#include "studwin.h"
#include "ui_studwin.h"
#include "client.h"
#include <vector>
#include "qstandarditemmodel.h"

StudWin::StudWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudWin) {
    ui->setupUi(this);
    levelshow = true;

    ui->userLabel->setText("Welcome: TestUser");
    setupLevels();
    pw = new PuzzleWindow();
    pw->setPuzzle(new StackPuzzle());

    QGridLayout *lay = new QGridLayout(this);
    lay->addWidget(pw);
    ui->mainGameWidget->setLayout(lay);
}

StudWin::~StudWin() {
    //delete ui;
}

void StudWin::setupLevels() {
//    std::vector<QString> dataList;
//    std::vector<QString> levelList;
//    QStandardItemModel model;

//    for (int i = 0; i < 5; i++) {
//        dataList.push_back("DataStructure " + i);
//        levelList.push_back("Level " + i);
//    }
    ui->listWidget->addItem("stack");
    ui->listWidget->addItem("array");
    ui->listWidget->addItem("tree");
    ui->listWidget->addItem("list");
}

void StudWin::on_hideButton_clicked() {
    if (levelshow) {
        ui->levelFrame->hide();
        levelshow = false;
        ui->hideButton->setText(QString("Show Levels"));
    } else {
        ui->levelFrame->showNormal();
        ui->hideButton->setText(QString("Hide Levels"));
        levelshow = true;
    }
}

//Move to controller?
void StudWin::on_logoutButton_clicked() {
    Client *par = (Client *)this->parentWidget();   
    par->setCurrentPage("login");

    //emit signal to release sources?
}

//void StudWin::setMainGameWidget(QWidget *widget)
//{

//    QGridLayout *layout = new QGridLayout(this);
//    layout->addWidget(widget);
//    ui->mainGameWidget->setLayout(layout);
//}

void StudWin::on_listWidget_currentRowChanged(int currentRow)
{
    switch(currentRow){
        case 0:
            pw->setPuzzle(new StackPuzzle());
            break;
        case 1:
            pw->setPuzzle(new ArrayPuzzle());
            break;
        case 2:
            pw->setPuzzle(new TreePuzzle());
            break;
        case 3:
            pw->setPuzzle(new ListPuzzle());
            break;
    }
}
