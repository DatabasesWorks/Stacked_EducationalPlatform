#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <SFML/Network/IpAddress.hpp>
#include <QPair>

class ServerSocket
{
public:
    ServerSocket(sf::IpAddress, unsigned int);
    ServerSocket();
    ~ServerSocket();
    QPair<sf::Packet,sf::IpAddress> waitForResponse();
    bool sendPayload(QString);
    void bind(unsigned int);
private:
    unsigned int portnumber = 0;
    sf::IpAddress host;
    sf::TcpListener listener;
};
#endif // userSOCKET_H

