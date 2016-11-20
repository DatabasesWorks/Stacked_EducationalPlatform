#include "server.h"

Server::Server(int portnumber)
{
    rport=portnumber;
    try{
        listener.bind(rport);
        std::cout << "bindingport at " << rport <<std::endl;
    }catch(socketexception ex){
        std::cout << "This usually means: " << std::endl;
                  << "Another process is using port:{ " << rport << " }" << std::endl
                  << "Please close this process and restart the server" << std::endl;
    }
}

Server::~Server(){

}

//http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c#440147
static std::string RandomString(unsigned int len)
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
    try{
       QPair<Message, sf::IpAddress> results = listener.waitForResponse();
       decode(results.first,results.second);
    }catch(timeoutexception){
       //try, try again.
    }catch(packetexception){
       //same here.
    }
}

bool Server::verifysid(sf::String sid){
    for(auto it = sessionids.begin(); it < sessionids.end(); it++){
       if(*it==sid){ //check sessionid
            return true;
           // do something with the payload. DB class?
       }
    }return false;
}

void Server::deleteSessionId(sf::String s){
    auto it = std::find(sessionids.begin(), sessionids.end(), s);
    if(it < sessionids.end()){
        sessionids.erase(it);
    }
}

void Server::tryToSend(unsigned int iteration, ServerSocket &sock, sf::String payload){
   for(unsigned int i = 0; i < iteration; i++){
       try{
           sock.sendPayload(payload);
           break;
       }catch(socketexception){
           //if we cant contact the client. Try again.
           continue;
       }catch(packetexception){
           continue;
       }
   }
}

//This is where you will decode packets from clients. ( or pass the input to a DB class )
void Server::decode(Message msg, sf::IpAddress ip){
    // do something with the client message
    if(msg.command=="authenticate"){
       QVector<QString> split = QString::fromStdString(msg.payload).split(",").toVector();
       if(split.size()==2)
       {
           //check the DB?
           if(split.front() == "test" && split.back() == "user"){
              ServerSocket sock(ip,msg.numerical);
              sf::String temp(RandomString(30));
              sessionids.push_back(temp);
              tryToSend(5,sock,temp);
              return;
           }
       }
    }else if(msg.command=="deauthenticate")
    {
        deleteSessionId(msg.sessionid);
        ServerSocket sock(ip,msg.numerical);
        tryToSend(5,sock,"SUCCESS");
        return;
    }else if(msg.command=="rawpayload"){// this is just an example command
        if(verifysid(msg.sessionid)){ //verify session id
            ServerSocket sock(ip,msg.numerical); // send a payload back
            tryToSend(5,sock,"No Commands Supported Yet");
            return;
        }else{
            ServerSocket sock(ip,msg.numerical);
            tryToSend(5,sock,"Authentication error");
            return;
        }
    }
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
       //QThread::sleep(1);
   }
   delete server;
   return 0;
}
