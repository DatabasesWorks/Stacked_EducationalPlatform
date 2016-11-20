#ifndef DB_H
#define DB_H
#include <string>

class DB
{
public:
    DB();
    std::string executeCommand(std::string command, std::string payload);
};

#endif // DB_H
