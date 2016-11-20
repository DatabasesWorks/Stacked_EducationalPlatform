#include "serversocket.h"

//use this constructor for sending data
ServerSocket::ServerSocket(sf::IpAddress host, unsigned int portnumber)
{
    this->host=host;
    this->portnumber=portnumber;
}

//if you use this constructor, don't try to send a payload.
//it will send a packet to a random port on your machine.
ServerSocket::ServerSocket(){
    host = sf::IpAddress::LocalHost;
    portnumber = sf::TcpSocket::AnyPort;
}

//You can only bind once. Then call wait for response to capture input on the port
void ServerSocket::bind(unsigned int port){
    listener.listen(port);
}

//clean up if the socket was used for listening on a port
ServerSocket::~ServerSocket(){
    listener.close();
}

bool ServerSocket::sendPayload(QString pl){
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(host,portnumber);
    if (status == sf::Socket::Error)
    {
        socketexception e(host.toString(),portnumber);
        throw e;
    }else{
        Message msg("payload",pl.toStdString(),0);
        sf::Packet pack;
        pack << msg;
        socket.send(pack);
        return true;
    }
    return false;
}
//The basic structure for our packets is : command; payload; returnport;
//The ip address in the qpair is from the requesting client
QPair<Message, sf::IpAddress> ServerSocket::waitForResponse(){
    sf::TcpSocket sock;
    sf::Packet pack;
    Message msg;
    if(listener.accept(sock)==sf::Socket::Error){
        std::cout << "Client Connection Failed" << std::endl;
    }
    sock.receive(pack); // need some error handling here?
    if(pack >> msg)
    {
        sf::IpAddress ip = sock.getRemoteAddress();
        return QPair<Message, sf::IpAddress>(msg,ip);
    }else {
        //packet extraction failed
        packetexception ex;
        throw ex;
    }
}
