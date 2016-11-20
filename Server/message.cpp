#include <message.h>

Message::Message(std::string cmd, std::string pl, unsigned short num) {
    command=cmd;
    payload=pl;
    numerical=num;
    sessionid="";
}

Message::Message(){
    sessionid="";
    numerical=0;
    sessionid="";
    command="";
}

Message::~Message(){

}

std::string Message::tostring(){
    return command + payload + (""+numerical);
}

void Message::addSessionId(sf::String sess){
    sessionid=sess;
}

//small utility class to clean up code.
sf::Packet& operator <<(sf::Packet& packet, Message& msg)
{
    return packet << msg.command << msg.payload << msg.numerical;
}

sf::Packet& operator >>(sf::Packet& packet, Message& msg){
   // return packet >> msg.command >> msg.payload >> msg.returnport;
    return packet >> msg.command >> msg.payload >> msg.numerical;

}
