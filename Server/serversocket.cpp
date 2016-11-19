#include "serversocket.h"

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
            std::string pl = ("payload;"+payload).toStdString();
            char buffer[pl.length()];
            std::size_t r;
            strcpy(buffer, pl.c_str());
            socket.send(buffer, r);
            return true;
        }

    return false;
}

QString ServerSocket::listen(unsigned int port){
    char buff[2048];
    std::size_t r;
    sf::TcpSocket sock;
    sf::TcpListener listen;
    listen.accept(sock);
    sf::IpAddress ip = sock.getRemoteAddress();
    if(!(sock.receive(buff,2048,r)!=sf::Socket::Done)){
        QString str(buff);
        return str+QString::fromStdString(";"+ip.toString());
    }else{
        // networking error
    }
}
