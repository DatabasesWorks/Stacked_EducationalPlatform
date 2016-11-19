#include "usersocket.h"
#include <sstream>
#include <string>
#include <iostream>

UserSocket::UserSocket(QString hostname, int portnumber)
{
    this->host=sf::IpAddress(hostname.toStdString());
    this->portnumber = portnumber;
}

UserSocket::~UserSocket(){

}

//sends an authentication packet to the sever. if this returns true, then we will have a valid session id
bool UserSocket::authenticate(QString username, QString passwd){
     if(!this->authenticated){
         sf::TcpSocket socket;
         sf::Socket::Status status = socket.connect(host,portnumber);
         if (status == sf::Socket::Status::Error)
         {
             return false;

             // some error handling here
         }else{
             sf::TcpListener li;
             li.listen(sf::TcpListener::AnyPort);
             sf::Packet pack;
             pack << "authenticate";
             pack << username.toStdString() + "," + passwd.toStdString();
             pack << li.getLocalPort();
             socket.send(pack);
             sf::Packet results = waitForResponse(li);
             //check results here
             //set the session id etc.
             std::string command;
             std::string payload;

             if(results >> command >> payload){
                 if(payload!="0"){
                      QString t = QString::fromStdString(payload);
                      bool ok;
                      int sid = t.toInt(&ok);
                      if(ok){
                          sessionId=sid;
                          return true;
                      }
                 }
                 this->authenticated = true;
             }


         }
     }
     return false;

}

//payloads to the server will require a session id, I will integrate that when I get a chance.
//the packets from the server will follow this format: command; payload
sf::Packet UserSocket::sendPayload(QString payload){
    sf::Packet empty;
    if(this->authenticated){
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(host,portnumber);
        if (status == sf::Socket::Status::Error)
        {
            return empty;
            // some error handling here
        }else{
            sf::TcpListener li;
            li.listen(sf::TcpListener::AnyPort);
            sf::Packet pack;
            pack << "payload";
            pack << payload.toStdString();
            pack << li.getLocalPort();
            socket.send(pack);
            sf::Packet results = waitForResponse(li);
            return results;
        }
    }
    return empty;
}


//responses from the server will come in the form: command; payload.
sf::Packet UserSocket::waitForResponse(sf::TcpListener &listener){
   sf::Packet pack;
   sf::TcpSocket sock;
   listener.accept(sock);
   sock.receive(pack);
   return pack;
}


