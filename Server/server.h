#ifndef SERVER_H
#define SERVER_H
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QThread>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <iostream>

class Server
{
    QTimer * timer;
public:
    Server();
    void listen();
};

#endif // SERVER_H
