#include "serversocket.h"
#include <SFML/Network/Packet.hpp>

ServerSocket::ServerSocket(sf::IpAddress host, unsigned int portnumber)
{
    this->host=host;
    this->portnumber=portnumber;
}

ServerSocket::~ServerSocket(){


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
            pack << "payload;";
            pack << payload.toStdString();
            socket.send(pack);
            return true;
        }

    return false;
}

QString ServerSocket::listen(unsigned int port){
    char buff[2048];
    std::size_t r;
    sf::TcpSocket sock;
    sf::TcpListener listen;
    sf::IpAddress ip = sock.getRemoteAddress();
    listen.accept(sock);
    sf::Packet pack;
    sock.receive(pack);
    pack << ip.toString();
    // check the variables of the payload

}
