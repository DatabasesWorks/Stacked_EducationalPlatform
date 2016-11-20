#include "server.h"


Server::Server(int portnumber)
{
    rport=portnumber;
    try{
        listener.bind(rport);
        std::cout << "Binding port number: { " << rport << " }" << std::endl;
    }catch(socketexception){
        std::cout << "Another process is using port: { " << rport << " }" << std::endl
                  << "Please close that process and restart the server" << std::endl;
    }
}

Server::~Server(){

}

void Server::tryToSend(unsigned int iteration, ServerSocket &sock, sf::String payload){
    for(unsigned int i = 0; i < iteration; i++){
       try{
           sock.sendPayload(payload);
           return;
       }catch(socketexception){
           //if we cant contact the client. Try again.
           continue;
       }catch(packetexception){
           continue;
       }
   }
   std::cout << "Failed to send pl: " << payload.toAnsiString() << std::endl
             << "To machine: " << sock.getHostname().toAnsiString() <<":"<<sock.getPortnumber()<<std::endl;
}

void Server::listen(){
    try{
       QPair<Message, sf::IpAddress> results = listener.waitForResponse();
       QFuture<void> futre = QtConcurrent::run(this,&Server::decode,results.first,results.second);
       // need to make the session ids data structure thread safe.
       //decode(results.first,results.second);
    }catch(timeoutexception){
       //let's use update stuff in the server instead of listening all the time.
    }catch(packetexception){
       //try to salvage packet? or send request to resend?
    }
}

//We shoud make migitate most of the logic in this method
//to a separate class so this one doesn't grow too large
//Also anything in here needs to be threadsafe for global variables ( the db is threadsafe )
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
              mute.lock();
              sessionids.push_back(temp);
              mute.unlock();
              tryToSend(5,sock,temp);
              return;
           }else{
              ServerSocket sock(ip,msg.numerical);
              tryToSend(2,sock,"FAILED");
           }
       }
    }else if(msg.command=="deauthenticate")
    {
        mute.lock();
        deleteSessionId(msg.sessionid);
        mute.unlock();
        ServerSocket sock(ip,msg.numerical);
        tryToSend(5,sock,"SUCCESS");
        return;
    }
    // push everything below to another class

    else if(msg.command=="rawpayload"){// this is just an example command
        if(verifysid(msg.sessionid)){ //verify session id
            ServerSocket sock(ip,msg.numerical); // send a payload back
            tryToSend(5,sock,"No Commands Supported Yet");
            return;
        }else{
            ServerSocket sock(ip,msg.numerical);
            tryToSend(5,sock,"Authentication error");
            return;
        }
    }else{
        std::cout << "Command: " << msg.command.toAnsiString() << " Not Recognized" << std::endl;
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

//http://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c#440147
std::string Server::RandomString(unsigned int len)
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

int main(int, const char* []){
   Server server(11777);

   while(true){//we could make this multithread later on if it becomes an issue.
       server.listen();
   }

   return 0;
}
