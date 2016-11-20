#ifndef SERVER_H
#define SERVER_H
#include <QVector>
#include <QtSql/QSqlDatabase>
#include <QThread>
#include <QPair>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/System/String.hpp>
#include <sstream>
#include <iostream>
#include <serversocket.h>
#include <message.h>

class Server
{
    ServerSocket listener;
    unsigned int rport;
    std::vector<QString> sessionids;
    void decode(Message, sf::IpAddress);
    bool verifysid(sf::String);

public:
    Server(int portnumber);
    ~Server();
    void listen();
};

#endif // SERVER_H
