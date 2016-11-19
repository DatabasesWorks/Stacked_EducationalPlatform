#include "clientsocket.h"

ClientSocket::ClientSocket(QString hostname, int portnumber)
{
    this->host=sf::IpAddress(hostname.toStdString());
    this->portnumber = portnumber;
}

ClientSocket::~ClientSocket(){

}

QString ClientSocket::authenticate(QString username, QString passwd){
     if(!this->authenticated){
         sf::TcpSocket socket;
         sf::Socket::Status status = socket.connect(host,portnumber);
         if (status != sf::Socket::Done)
         {
             return "FAILED";
             // some error handling here
         }else{
             std::string pl = ("authenticate;"+username+","+passwd).toStdString();
             char buffer[2048];
             std::size_t r;
             strcpy(buffer, pl.c_str());
             socket.send(buffer, r);
             QString results = waitForResponse();
             //check results here
             //set the session id etc.
             if(results != QString("FAILURE")){
                 this->sessionId = results.toInt();
                 this->authenticated = true;
             }
             return results;
         }
     }
     return "FAILED";

}

QString ClientSocket::sendPayload(QString payload){

    if(!this->authenticated){
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect(host,portnumber);
        if (status != sf::Socket::Done)
        {
            return "FAILED";
            // some error handling here
        }else{
            std::string pl = ("payload;"+payload).toStdString();
            char buffer[2048];
            std::size_t r;
            strcpy(buffer, pl.c_str());
            socket.send(buffer, r);
            QString results = waitForResponse();
            return results;
        }
    }
    return "FAILED";
}

QString ClientSocket::waitForResponse(){
   char buff[2048];
   std::size_t r;
   sf::TcpListener listen;
   sf::TcpSocket sock;
   listen.listen(11777);
   listen.accept(sock);
   //sf::IpAddress ip = sock.getRemoteAddress();
   if(!(sock.receive(buff,2048,r)!=sf::Socket::Done)){
       QString str(buff);
       return str;

   }else{
       return "garbage";
       // networking error
   }
}


