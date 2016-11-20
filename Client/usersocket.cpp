#include "usersocket.h"

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
             Message msg("authenticate",username.toStdString() + "," + passwd.toStdString(), li.getLocalPort());
             pack << msg;
             socket.send(pack);
             Message results = waitForResponse(li);
             //check results here
             //set the session id etc.

             if(msg.payload!="0"){
                QString t = QString::fromStdString(msg.payload);
                bool ok;
                int sid = t.toInt(&ok);
                if(ok){
                   sessionId=sid;
                   this->authenticated = true;
                   return true;
                }

             }
         }
     }
     return false;

}

//payloads to the server will require a session id, I will integrate that when I get a chance.
//the packets from the server will follow this format: command; payload
Message UserSocket::sendPayload(QString payload){
    Message empty;
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
            Message msg("payload",payload.toStdString(),li.getLocalPort());
            sf::Packet pack;
            pack << msg;
            socket.send(pack);
            Message results = waitForResponse(li);
            return results;
        }
    }
    return empty;
}


//responses from the server will come in the form: command; payload, use a 0 last port
Message UserSocket::waitForResponse(sf::TcpListener &listener){
   sf::Packet pack;
   sf::TcpSocket sock;
   listener.accept(sock);
   sock.receive(pack);
   Message msg;
   pack >> msg;
   return msg;
}


