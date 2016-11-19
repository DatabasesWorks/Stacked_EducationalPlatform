#include "server.h"
#include <signal.h>


Server::Server(int portnumber = 11777)
{

    std::cout << "Binding to Port " << portnumber << std::endl;
    bind.listen(portnumber);

    // if the database has not been created yet, create it.
    // else... we can store the connection for later or discard
}

Server::~Server(){
    bind.close();

}


void Server::listen(){

    char buff[2048];
    std::size_t r;
    sf::TcpSocket sock;

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
    std::cout << ": " << str.toStdString() << "  from: " << ip.toString() << std::endl;
    // use a class to decode messages from the client







}

void interrupt_handler(int){
    std::cout << "You have terminated the Server" << std::endl;
    exit(1);
}

int main(int, const char* []){
   Server * server = new Server; // loop to run server.
   struct sigaction signal_handler;
   signal_handler.sa_handler = interrupt_handler;//handle interrupts gracefully
   sigemptyset(&signal_handler.sa_mask);
   signal_handler.sa_flags = 0;
   sigaction(SIGINT, &signal_handler, NULL);
   while(true){
       server->listen();
       QThread::sleep(1);
   }
   delete server;
   return 0;
}
