#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <QMainWindow>
#include <usersocket.h>
#include <puzzlewindow.h>
#include <QStackedWidget>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    QStackedWidget widget;
    explicit Client(QWidget *parent = 0);
    void setCurrentPage(QString);
    bool sendLogin(QString user, QString pass);
    int sendReg(QString data);
    QVector<QString> getStudents(QString classcode);
    ~Client();
    std::string getSessionId();



private:
    QTimer timer;
    std::string sessionid;
    std::string username;
    Ui::Client *ui;
    std::atomic_bool check;
    //UserSocket currsock;
    std::vector<QWidget*> widgets;
    unsigned int activeWidget = 0;
private slots:
    void autosave();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

};

#endif // CLIENT_H
