#include "server.h"

Server::Server(int portnumber)
{
    rport=portnumber;
    std::cout << "bindingport at " << rport <<std::endl;
    listener.bind(rport);
}

Server::~Server(){

}

void Server::listen(){
    QPair<Message, sf::IpAddress> results = listener.waitForResponse();
    decode(results.first,results.second);
}

void Server::decode(Message msg, sf::IpAddress ip){
    // do something with the client message
    std::stringstream ss;
    ss << ": ";
    ss << msg.command.toAnsiString();
    ss << "; " << msg.payload.toAnsiString();
    ss << "; " << msg.returnport;
    std::cout << ss.str() << std::endl;
    if(msg.command=="authenticate"){
       QVector<QString> split = QString::fromStdString(msg.payload).split(",").toVector();
       if(split.size()==2)
       {
           if(split.front() == "test" && split.back() == "user"){
              ServerSocket sock(ip,msg.returnport);
              sock.sendPayload("199");
              return;
           }
       }
    }else if(msg.command=="payload"){


    }
    ServerSocket sock(ip,msg.returnport);
    sock.sendPayload("0");
}

void interrupt_handler(int){
    std::cout << "You have terminated the Server" << std::endl;
    exit(1);
}

int main(int, const char* []){
   // I need to look at the interrupt code a bit more
   Server * server = new Server(11701); // loop to run server.
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
