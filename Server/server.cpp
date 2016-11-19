#include "server.h"
#include <signal.h>
#include <QVector>
#include <serversocket.h>


Server::Server(int portnumber)
{
    rport=portnumber;
    std::cout << "bindingport at " << rport <<std::endl;
    listener.bind(rport);
}

Server::~Server(){

}

void Server::listen(){
    QPair<sf::Packet, sf::IpAddress> results = listener.waitForResponse();
    decode(results.first,results.second);
}

void Server::decode(sf::Packet pack, sf::IpAddress ip){
    // do something with the client message
    std::cout << ": " << pack.getData() << "  from: " << ip.toString() << std::endl;
    unsigned short returnport;
    std::string command;
    std::string payload;
    if(pack >> command >> payload >> returnport){
        if(command == "authenticate"){
            QVector<QString> split = QString::fromStdString(payload).split(",").toVector();
            if(split.size()==2)
            {
                QString username(split.front());
                QString password(split.back());
                if(username == "test" && password == "user"){
                    ServerSocket sock(ip,returnport);
                    sock.sendPayload("199");
                    return;
                }
            }
        }

    }
    ServerSocket sock(ip,returnport);
    sock.sendPayload("0");

}

void interrupt_handler(int){
    std::cout << "You have terminated the Server" << std::endl;
    exit(1);
}

int main(int, const char* []){
   // I need to look at the interrupt code a bit more
   Server * server = new Server(11777); // loop to run server.
   //  struct sigaction signal_handler;
   // signal_handler.sa_handler = interrupt_handler;//handle interrupts gracefully
   //   sigemptyset(&signal_handler.sa_mask);
   //  signal_handler.sa_flags = 0;
   //  sigaction(SIGINT, &signal_handler, NULL);
   while(true){
       server->listen();
       QThread::sleep(1);
   }
   delete server;
   return 0;
}