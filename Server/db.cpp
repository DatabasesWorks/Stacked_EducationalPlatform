#include "db.h"

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

