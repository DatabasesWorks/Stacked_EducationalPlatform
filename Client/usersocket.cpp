#include "usersocket.h"

UserSocket::UserSocket(std::string hostname, unsigned int portnumber)
{
    this->host=sf::IpAddress(hostname);
    this->portnumber = portnumber;

}

UserSocket::UserSocket(sf::IpAddress hostname, unsigned int portnumber)
{
    this->host=hostname;
    this->portnumber = portnumber;
}

//you can use this to reuse a session id
UserSocket::UserSocket(sf::IpAddress hostname, unsigned int portnumber, sf::String sessionId)
{
    this->sessionId=sessionId;
    this->host=hostname;
    this->portnumber = portnumber;
    this->authenticated=true;
}

UserSocket::~UserSocket(){

}

sf::String UserSocket::sid(){
    return sessionId;
}

//sends an authentication packet to the sever. if this returns true, then we will have a valid session id
bool UserSocket::authenticate(std::string username, std::string passwd){
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
             Message msg("authenticate",username + "," + passwd, li.getLocalPort());
             pack << msg;
             socket.send(pack);
             Message results = waitForResponse(li);
             //check results here
             //set the session id etc.
             if(results.payload!=""){
                sessionId=results.payload;
                std::cout << sessionId.toAnsiString() << std::endl;
                this->authenticated = true;
                return true;
             }
         }
     }else{
         // we are already authenticated.
     }
     return false;

}

//payloads to the server will require a session id, I will integrate that when I get a chance.
//the packets from the server will follow this format: command; payload
Message UserSocket::sendPayload(std::string command, std::string payload){
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
            Message msg(command,payload,li.getLocalPort());
            msg.addSessionId(this->sessionId);
            sf::Packet pack;
            pack << msg;
            socket.send(pack);
            Message results = waitForResponse(li);
            return results;
        }
    }else{
        // if we are not authenticated anymore then we will need to reauth.
        authenticationexception ex;
        throw ex;
    }
    return empty;
}

Message UserSocket::waitForResponse(sf::TcpListener &listener){
   sf::Packet pack;
   sf::TcpSocket sock;
   listener.accept(sock);
   sock.receive(pack);
   Message msg;
   if(pack >> msg){
      return msg;
   }else {
       packetexception ex;
       throw ex;
   }
}


