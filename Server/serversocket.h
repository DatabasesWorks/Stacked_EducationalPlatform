#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network.hpp>
#include <QPair>
#include <message.h>

class ServerSocket
{
public:
    ServerSocket(sf::IpAddress, unsigned int);
    ServerSocket();
    ~ServerSocket();
    QPair<Message,sf::IpAddress> waitForResponse();
    bool sendPayload(QString);
    void bind(unsigned int);
private:
    unsigned int portnumber = 0;
    sf::IpAddress host;
    sf::TcpListener listener;
};

#endif // SERVERSOCKET_H

