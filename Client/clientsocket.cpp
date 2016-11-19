#include "clientsocket.h"

ClientSocket::ClientSocket(QString hostname)
{
    this->host=sf::IpAddress(hostname);
}

bool ClientSocket::authenticate(QString username, QString passwd){
     if(!this->isConnected){
         sf::Socket::Status = socket->connect(host,portnumber,100);
         sf::TcpSocket socket;
         if (status != sf::Socket::Done)
         {
             return false;
             // some error handling here
         }else{
             socket->send("authenticate;"+username+","+password);
             QString results = waitForResponse();
             //check results here
             //set the session id etc.
             if(results != "FAILURE"){
                 this->sessionId = QString::number(results);
                 this->isConnected;
             }
             socket.close();
             return results;
         }
     }
}

QString ClientSocket::sendPayLoad(unsigned int port, QString payload){

    if(!this->isConnected){
        sf::TcpSocket socket;
        sf::Socket::Status = socket->connect(host,portnumber,100);
        if (status != sf::Socket::Done)
        {
            return false;
            // some error handling here
        }else{
            socket->send("authenticate;"+username+","+password);
            QString results = waitForResponse();
            return results;
        }
    }
}

QString ClientSocket::waitForResponse(){
   char buff[2048];
   std::size_t r;
   sf::TcpListener listen;
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


