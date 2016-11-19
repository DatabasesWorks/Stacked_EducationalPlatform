#include "clientsocket.h"

ClientSocket::ClientSocket(sf::IpAddress hostname, int portnumber)
{
    this->host=sf::IpAddress(hostname);
    this->portnumber = portnumber;
}

QString ClientSocket::authenticate(QString username, QString password){
     if(!this->authenticated){
         sf::TcpSocket* socket;
         sf::Socket::Status status = socket->connect(host,portnumber,sf::milliseconds(100));
         if (status != sf::Socket::Done)
         {
             return NULL;
             //return false;
             // some error handling here
         }else{
             socket->send("authenticate;"+username+","+password);
             QString results = waitForResponse();
             //check results here
             //set the session id etc.
             if(results != "FAILURE"){
                 this->sessionId = results.toInt();

                 this->authenticated = true;
             }
//             socket->close();
             return results;
         }
     }
}

QString ClientSocket::sendPayload(QString payload){

    if(!this->authenticated){
        sf::TcpSocket* socket;
        sf::Socket::Status status = socket->connect(host,portnumber,sf::milliseconds(100));
        if (status != sf::Socket::Done)
        {
            return NULL;
//            return false;
            // some error handling here
        }else{
            socket->send("payload;"+payload);
            QString results = waitForResponse();
            return results;
        }
    }
}

QString ClientSocket::waitForResponse(){
   char buff[2048];
   std::size_t r;
   sf::TcpListener listener;
   sf::TcpSocket sock;
   listener.listen(11777);
   listener.accept(sock);
   sf::IpAddress ip = sock.getRemoteAddress();
   if(!(sock.receive(buff,2048,r)!=sf::Socket::Done)){
       QString str(buff);
       return str;

   }else{
       return "garbage";
       // networking error
   }
}


