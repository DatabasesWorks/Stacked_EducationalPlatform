#ifndef SERVER_H
#define SERVER_H
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QTimer>
#include <QThread>
#include <iostream>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>

class Server
{
    QTimer * timer;
    void decode(sf::Packet, sf::IpAddress);
    sf::TcpListener bind;
public:
    Server(int portnumber);
    ~Server();
    void listen();
};

#endif // SERVER_H
