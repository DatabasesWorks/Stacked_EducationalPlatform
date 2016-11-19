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

QString UserSocket::authenticate(QString username, QString passwd){
     if(!this->authenticated){
         sf::TcpSocket socket;
         sf::Socket::Status status = socket.connect(host,portnumber);
         if (status == sf::Socket::Status::Error)
         {
             return "FAILED";

             // some error handling here
         }else{
             sf::TcpListener li;
             li.listen(sf::TcpListener::AnyPort);
             std::stringstream stream;

             stream << "authenticate;";
             stream << username.toStdString() << "," << passwd.toStdString() << ";";
             stream << li.getLocalPort();


             char buffer[stream.str().length()];
             std::size_t r;
             strcpy(buffer,stream.str().c_str());
             socket.send(buffer, r);
             QString results = waitForResponse(li);
             //check results here
             //set the session id etc.

             if(results != "FAILURE"){
                 this->sessionId = results.toInt();
                 this->authenticated = true;
             }
             return results;
         }
     }
     return "FAILED";

}

QString UserSocket::sendPayload(QString payload){
    if(this->authenticated){
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(host,portnumber);
        if (status == sf::Socket::Status::Error)
        {
            return "FAILED";
            // some error handling here
        }else{
            sf::TcpListener li;
            li.listen(sf::TcpListener::AnyPort);
            std::string pl = ("payload;"+payload+";"+li.getLocalPort()).toStdString();
            char buffer[2048];
            std::size_t r;
            strcpy(buffer, pl.c_str());
            socket.send(buffer, r);
            QString results = waitForResponse(li);
            return results;
        }
    }
    return "FAILED";
}

QString UserSocket::waitForResponse(sf::TcpListener &listener){
   char buff[512];
   std::size_t r;
   sf::TcpSocket sock;
   listener.accept(sock);
   //sf::IpAddress ip = sock.getRemoteAddress();
   sock.receive(buff,512,r);
   QString str(buff);
   return str;
}


