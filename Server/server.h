#ifndef SERVER_H
#define SERVER_H
#include <QVector>
#include <QtSql/QSqlDatabase>
#include <QThread>
#include <iostream>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <serversocket.h>
#include <message.h>
#include <sstream>
#include <QPair>

class Server
{
    void decode(Message, sf::IpAddress);
    sf::TcpListener bind;
    int rport;
    ServerSocket listener;

public:
    Server(int portnumber);
    ~Server();
    void listen();
};

#endif // SERVER_H
