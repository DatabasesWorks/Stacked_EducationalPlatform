#include "serversocket.h"
#include <SFML/Network/Packet.hpp>
#include <QPair>

//use this constructor for sending data
ServerSocket::ServerSocket(sf::IpAddress host, unsigned int portnumber)
{
    this->host=host;
    this->portnumber=portnumber;
}

//if you use this constructor, don't try to send a payload.
//it will send a packet to a random port on your machine.
ServerSocket::ServerSocket(){
    this->host = sf::IpAddress::LocalHost;
    this->portnumber = sf::TcpSocket::AnyPort;
}

//You can only bind once. Then call wait for response to capture input on the port
void ServerSocket::bind(unsigned int port){
    listener.listen(port);
}

//clean up if the socket was used for listening on a port
ServerSocket::~ServerSocket(){
    listener.close();
}

bool ServerSocket::sendPayload(QString payload){
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(host,portnumber);
        if (status == sf::Socket::Error)
        {
            return false;
            // some error handling here
        }else{
            sf::Packet pack;
            pack << "payload";
            pack << payload.toStdString();
            socket.send(pack);
            return true;
        }

    return false;
}
//The basic structure for our packets is : command; payload; returnport;
//The ip address in the qpair is from the requesting client
QPair<sf::Packet, sf::IpAddress> ServerSocket::waitForResponse(){
    sf::TcpSocket sock;
    sf::Packet pack;
    listener.accept(sock);
    sf::IpAddress ip = sock.getRemoteAddress();
    sock.receive(pack); // need some error handling here?
    QPair<sf::Packet, sf::IpAddress> results(pack,ip);
    return results;
}
