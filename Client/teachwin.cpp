#include "teachwin.h"
#include "ui_teachwin.h"
#include "client.h"
#include <vector>
#include <iostream>

TeachWin::TeachWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachWin) {
    ui->setupUi(this);
    //Query DB and get this info
    ui->classLabel->setText("Class: CS3505");
    ui->userLabel->setText("Welcome: TestUser");
    //this->setStyleSheet("background-color: black; color: white;");
    QObject::connect(ui->addStudentButton, &QPushButton::clicked, this, &TeachWin::deleteStudentButton);
}

TeachWin::TeachWin(Client *client, QWidget *parent) : TeachWin(parent) {
    this->client = client;
}

TeachWin::~TeachWin() {
    delete ui;
}

void TeachWin::logoutButton() {
    Client *par = client;
    UserSocket sock(sf::IpAddress::LocalHost, 11777, par->getSessionId());

    sock.deauthenticate();
    par->setCurrentPage("login");
}

void TeachWin::updateStudents() {
    ui->listWidget->clear();
    Client *par = client;
    QVector<QString> students = par->getStudents("class");
    for (int i = 0; i < students.length(); i++) {
        ui->listWidget->addItem(students.at(i));
    }

    ui->listWidget->setCurrentRow(0);
}

void TeachWin::deleteStudent(std::string username){
    Client *par = client;
    UserSocket sock(sf::IpAddress::LocalHost, 11777, par->getSessionId());
    Message msg = sock.sendPayload("deleteStudent",username);
    updateStudents();
}


void TeachWin::on_listWidget_itemSelectionChanged() {
    //get data from student database and put into main widget
}

void TeachWin::deleteStudentButton() {
    //remove student from database here
    std::string str = ui->listWidget->currentItem()->text().toStdString();
    deleteStudent(str);
}

void TeachWin::setCurrentUsername(QString currentUsername) {
    this->currentUsername = currentUsername;
    ui->userLabel->setText("Welcome: " + this->currentUsername);
}

void TeachWin::addStudentButton(){
    QString str = ui->addStudentField->text();
    UserSocket sock(sf::IpAddress::LocalHost, 11777, client->getSessionId());
    Message msg = sock.sendPayload("regStudent",str.toStdString());
    updateStudents();
}




