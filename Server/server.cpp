#include "server.h"

Server::Server(int portnumber)
{
    rport=portnumber;
    std::cout << "bindingport at " << rport <<std::endl;
    listener.bind(rport);
}

Server::~Server(){

}

//http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c#440147
static std::string RandomString(int len)
{
   std::srand(time(0));
   std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   int pos;
   while(str.size() != len) {
    pos = ((rand() % (str.size() - 1)));
    str.erase (pos, 1);
   }
   return str;
}


void Server::listen(){
    QPair<Message, sf::IpAddress> results = listener.waitForResponse();
    decode(results.first,results.second);
}

void Server::decode(Message msg, sf::IpAddress ip){
    // do something with the client message

    //std::cout << msg.tostring() << std::endl;
    if(msg.command=="authenticate"){
       QVector<QString> split = QString::fromStdString(msg.payload).split(",").toVector();
       if(split.size()==2)
       {
           //check the DB?
           if(split.front() == "test" && split.back() == "user"){
              ServerSocket sock(ip,msg.numerical);
              QString temp(QString::fromStdString(RandomString(30)));
              this->sessionids.push_back(temp);
              sock.sendPayload(temp);
              return;
           }
       }
    }else if(msg.command=="payload"){
        //the rest of the server logic will go here.
        //in methods or encapsuted
        for(auto it = sessionids.begin(); it < sessionids.end(); it++){
           if(*it==QString::fromStdString(msg.sessionid.toAnsiString())){ //check sessionid
               // do something with the payload. DB class?
               ServerSocket sock(ip,msg.numerical);
               sock.sendPayload("No Commands Supported Yet");
           }
        }
    }
    ServerSocket sock(ip,msg.numerical);
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
