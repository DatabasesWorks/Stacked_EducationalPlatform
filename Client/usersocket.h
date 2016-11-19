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

class UserSocket
{
public:
    UserSocket(QString host, int portnumber);
    ~UserSocket();
    bool authenticate(QString username, QString payload);
    sf::Packet sendPayload(QString payload);
private:
    unsigned int sessionId = 0;
    unsigned int portnumber = 0;
    sf::IpAddress host;
    bool authenticated = false;
    sf::Packet waitForResponse(sf::TcpListener&);
};

#endif // userSOCKET_H

