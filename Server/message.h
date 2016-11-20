#ifndef MESSAGE_H
#define MESSAGE_H
#include <SFML/Network/Packet.hpp>
#include <SFML/System/String.hpp>
#include <string>

class Message{

public:
    sf::String command;
    sf::String payload;
    sf::Uint8 returnport;
    Message(std::string cmd, std::string pl, unsigned short);
    Message();
    ~Message();
    //small utility class to clean up code.
    friend sf::Packet& operator <<(sf::Packet& packet, Message& msg);
    friend sf::Packet& operator >>(sf::Packet& packet, Message& msg);
};


#endif
