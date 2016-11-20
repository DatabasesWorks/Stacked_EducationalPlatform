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
    payload="";
    command="";
}

Message::~Message(){

}

void Message::addSessionId(sf::String sess){
    sessionid=sess;
}

std::string Message::tostring(){
    return command + payload + (""+numerical);
}

//small utility class to clean up code.
sf::Packet& operator <<(sf::Packet& packet, Message& msg)
{
    return packet << msg.command << msg.payload << msg.numerical << msg.sessionid;
}

sf::Packet& operator >>(sf::Packet& packet, Message& msg){
   // return packet >> msg.command >> msg.payload >> msg.returnport;
    return packet >> msg.command >> msg.payload >> msg.numerical >> msg.sessionid;

}
