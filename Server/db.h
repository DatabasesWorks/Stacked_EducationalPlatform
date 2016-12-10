#ifndef DB_H
#define DB_H
#include <string>
#include <mysql.h>


class DB
{
    std::string regUser(MYSQL* connection, std::string payload);
    std::string getStudents(MYSQL* connection, std::string payload);
    std::string authenticate(MYSQL* connection, std::string payload);
    std::string puzzleSolved(MYSQL* connection, std::string payload);
    std::string studentlist(MYSQL* connection, std::string payload);
public:
    DB();
    std::string executeCommand(std::string command, std::string payload);
};

#endif // DB_H
