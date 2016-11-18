#ifndef SERVER_H
#define SERVER_H
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QThread>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <iostream>
#include <SFML/Network/IpAddress.hpp>

class Server
{
    QTimer * timer;
    void decode(QString, sf::IpAddress);
    sf::TcpListener bind;
public:
    Server();
    ~Server();
    void listen();
};

#endif // SERVER_H
