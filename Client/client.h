#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <QMainWindow>
#include <usersocket.h>
#include <puzzlewindow.h>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    void setCurrentPage(QString);
    bool sendLogin(QString user, QString pass);
    int sendReg(QString data);
    QVector<QString> getStudents(QString classcode);
    ~Client();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Client *ui;
    //UserSocket currsock;
};

#endif // CLIENT_H
