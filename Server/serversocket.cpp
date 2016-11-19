#include "serversocket.h"
#include <SFML/Network/Packet.hpp>
#include <QPair>

ServerSocket::ServerSocket(sf::IpAddress host, unsigned int portnumber)
{
    this->host=host;
    this->portnumber=portnumber;
}

ServerSocket::ServerSocket(){
    this->host = sf::IpAddress::LocalHost;
    this->portnumber = sf::TcpSocket::AnyPort;
}

void ServerSocket::bind(unsigned int port){
    listener.listen(port);
}

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

QPair<sf::Packet, sf::IpAddress> ServerSocket::waitForResponse(){
    sf::TcpSocket sock;
    sf::Packet pack;
    listener.accept(sock);
    sf::IpAddress ip = sock.getRemoteAddress();
    sock.receive(pack); // need some error handling here?
    QPair<sf::Packet, sf::IpAddress> results(pack,ip);
    return results;
}
