#include "db.h"

// A note on this class, don't use any global variables since this class will be accessed by the multi-threaded server.
// Since sql is safe for multithreading just build queries and return the results. The way that the sockets are set up
// it should be able to handle multi-threaded processes.

DB::DB()
{

}

std::string DB::executeCommand(std::string command, std::string payload){
    if(command=="rawpayload"){// this is just an example command, in reality we will be contacting the database
        return "No Commands Supported Yet";
    }else{
        return "Command: " + command + " Not Recognized";
    }
}

