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
}

TeachWin::TeachWin(Client *client, QWidget *parent) : TeachWin(parent) {
    this->client = client;
}

TeachWin::~TeachWin() {
    delete ui;
}

void TeachWin::on_logoutButton_clicked() {
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

void TeachWin::deleteStudent(QString username){
    Client *par = client;
    UserSocket sock(sf::IpAddress::LocalHost, 11777, par->getSessionId());
    Message msg = sock.sendPayload("deleteStudent",username);
    updateStudents();
}


void TeachWin::on_listWidget_itemSelectionChanged() {
    //get data from student database and put into main widget
}

void TeachWin::on_pushButton_clicked() {
    //remove student from database here

    updateStudents();
}

void TeachWin::setCurrentUsername(QString currentUsername) {
    this->currentUsername = currentUsername;
    ui->userLabel->setText("Welcome: " + this->currentUsername);
}
