#include <message.h>

Message::Message(std::string cmd, std::string pl, unsigned short port) {
    command=cmd;
    payload=pl;
    returnport = port;
}

Message::Message(){

}

Message::~Message(){

}

//small utility class to clean up code.
sf::Packet& operator <<(sf::Packet& packet, Message& msg)
{
    return packet << msg.command << msg.payload << msg.returnport;
}

sf::Packet& operator >>(sf::Packet& packet, Message& msg){
   // return packet >> msg.command >> msg.payload >> msg.returnport;
    return packet >> msg.command >> msg.payload >> msg.returnport;

}
