#include "server.h"


Server::Server()
{
    bind.listen(11777);
   // if the database has not been created yet, create it.
   // else... we can store the connection for later or discard
}

Server::~Server(){
}


void Server::listen(){

    char buff[2048];
    sf::TcpSocket sock;
    std::size_t r;
    bind.accept(sock);

    sf::IpAddress ip = sock.getRemoteAddress();
    if(!(sock.receive(buff,2048,r)!=sf::Socket::Done)){
        QString str(buff);
        decode(str, ip);

    }else{
        // networking error
    }


}

void Server::decode(QString str, sf::IpAddress ip){
    // do something with the client message
    std::cout << "message: " << str.toStdString() << "  from: " << ip.toString() << std::endl;
}


int main(int, const char* []){
   Server * server = new Server; // loop to run server.
   while(true){
       server->listen();
       QThread::sleep(1);
   }
   return 0;
}
