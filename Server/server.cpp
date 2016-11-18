#include "server.h"


Server::Server()
{

   // if the database has not been created yet, create it.
   // else... we can store the connection for later or discard
}

void Server::listen(){
    char buff[2048];
    sf::TcpListener binding;
    sf::TcpSocket sock;
    std::size_t r;
    binding.listen(11777);
    binding.accept(sock);
    if(!(sock.receive(buff,2048,r)!=sf::Socket::Done)){
        QString str(buff);
        std::cout << str.toStdString() << std::endl;
    }else{
        // networking error
    }

}

int main(int argc, const char* []){
   Server * server = new Server;
   while(true){
       server->listen();
       QThread::sleep(100);
   }
   return 0;
}
