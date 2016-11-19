#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <SFML/Network/IpAddress.hpp>


class ServerSocket
{
public:
    ServerSocket(sf::IpAddress, unsigned int);
    ~ServerSocket();
    QString listen(unsigned int);
    bool sendPayload(QString);
private:
    unsigned int portnumber = 0;
    sf::IpAddress host;
};
#endif // userSOCKET_H

