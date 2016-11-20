#ifndef USERSOCKET_H
#define USERSOCKET_H
#include <QString>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Network/SocketSelector.hpp>
#include <sstream>
#include <string>
#include <iostream>
#include <message.h>
#include <exceptions.h>

class UserSocket
{
    unsigned int portnumber = 0;
    sf::String sessionId = "";
    sf::IpAddress host;
    bool authenticated = false;
    Message waitForResponse(sf::TcpListener&);
    sf::Time timeout;

public:
    UserSocket(std::string, unsigned int portnumber);
    UserSocket(sf::IpAddress host, unsigned int portnumber);
    UserSocket(sf::IpAddress host, unsigned int portnumber, sf::String sessionId);
    ~UserSocket();
    bool authenticate(std::string username, std::string payload);
    bool deauthenticate();
    Message sendPayload(std::string command, std::string payload);
    sf::String sid();
};

#endif // userSOCKET_H

