#ifndef USERSOCKET_H
#define USERSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <QObject>
#include <SFML/Network.hpp>
#include <time.h>
#include <QWidget>
#include <message.h>
#include <sstream>
#include <string>
#include <iostream>

class UserSocket
{
public:
    UserSocket(QString host, int portnumber);
    UserSocket(sf::IpAddress host, int portnumber);
    ~UserSocket();
    bool authenticate(QString username, QString payload);
    Message sendPayload(QString payload);
private:
    sf::String sessionId = "";
    unsigned int portnumber = 0;
    sf::IpAddress host;
    bool authenticated = false;
    Message waitForResponse(sf::TcpListener&);
};

#endif // userSOCKET_H

