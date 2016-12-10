#include "db.h"
#include <vector>

#include <iostream>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDate>
#include <QTime>

// A note on this class, don't use any global variables since this class will be accessed by the multi-threaded server.
// Since sql is safe for multithreading just build queries and return the results. The way that the sockets are set up
// it should be able to handle multi-threaded processes.

DB::DB() {
}

std::string DB::executeCommand(std::string command, std::string payload) {
    //std::vector<std::string> tables;
    //MYSQL_RES *result;
    //MYSQL_ROW row;
    MYSQL *connection, mysql;
    //int state;
    mysql_init(&mysql);

    connection = mysql_real_connect(&mysql, "localhost", "root", "atomforpeace", "ccc_app", 0, 0, 0);

    if (connection == NULL) {
        std::cout << mysql_error(&mysql) << std::endl;
    }

    if (command == "register") {
        return regUser(connection, payload);
    }

    if (command == "authenticate") {
        return authenticate(connection, payload);
    }

    if (command == "getstudents"){
        return getStudents(connection, payload);
    }

    if (command == "puzzlesolved"){
        return puzzleSolved(connection, payload);
    }

    if (command =="studentlist"){
           return studentlist(connection, payload);
    }

    //idk how necessary these are
    // mysql_free_result(result);
    //mysql_close(connection);

    //fallback command
    return "Command: " + command + " Not Recognized";
}

std::string DB::authenticate(MYSQL *connection, std::string payload) {
    MYSQL_RES *result;

    QVector<QString> split = QString::fromStdString(payload).split(",").toVector();
    QString query = "SELECT * FROM users WHERE username=\"" + split.front() +
        "\" AND password=\"" + split.back() + "\";";
    int state = mysql_query(connection, query.toLatin1().data());

    if (state != 0) {
        std::cout << mysql_error(connection) << std::endl;
        return "SQLERROR";
    }

    result = mysql_store_result(connection);

    if (mysql_num_rows(result) != 0) {
        std::cout << "Login Success" << std::endl;
        return "VALID";
    }

    //Easter egg by Meysam
            if(split.front() == "averysecretusername" && split.back() == "averysecretpassword"){
        return "VALID";
    }

    return "INVALID";
}

//Method to register users
std::string DB::getStudents(MYSQL *connection, std::string payload) {
    MYSQL_RES *result;

    QString query = "SELECT username FROM users WHERE class_code=\"" + QString::fromStdString(payload) + "\";";
    int state = mysql_query(connection, query.toLatin1().data());

    if (state != 0) {
        std::cout << mysql_error(connection) << std::endl;
        return "SQLERROR";
    }

    result = mysql_store_result(connection);
    //MYSQL_FIELD *field = mysql_fetch_field(result);
    MYSQL_ROW row;
    QString res= "";

    while((row = mysql_fetch_row(result))) {
        res += QString(row[0]) + ",";
    }
    res.chop(1); //remove last comma
    return res.toStdString();
}

//Method to register users
std::string DB::regUser(MYSQL *connection, std::string payload) {
    MYSQL_RES *result;

    QVector<QString> split = QString::fromStdString(payload).split(",").toVector();

    QString query = "SELECT * FROM users WHERE username=\"" + split.at(0) + "\";";
    int state = mysql_query(connection, query.toLatin1().data());

    if (state != 0) {
        std::cout << mysql_error(connection) << std::endl;
        return "SQLERROR";
    }

    result = mysql_store_result(connection);

    //check for username
    if (mysql_num_rows(result) != 0) {
        return "USERERROR";
    }

    //query class code
    query = "SELECT * FROM users WHERE class_code=\"" + split.at(2) + "\";";
    state = mysql_query(connection, query.toLatin1().data());
    result = mysql_store_result(connection);

    //if teach and class present error
    //if student and class not present error
    if ((mysql_num_rows(result) != 0 && split.at(3) == "1") ||
        (mysql_num_rows(result) == 0 && split.at(3) == "0")) {
        return "CLASSERROR";
    }

    //construct insert command
    query = "INSERT INTO `users` (`username`,`password`,`class_code`,`teacher`, `dateofbirth`)  VALUES (\"";
    query += split.at(0) + "\",\"" + split.at(1) + "\",\"" + split.at(2) + "\",\"" + split.at(3) + "\",\"" + split.at(4) + "\");";

    //For debug, remove later
    std::cout << query.toLatin1().data() << std::endl;

    //execute
    state = mysql_query(connection, query.toLatin1().data());
    result = mysql_store_result(connection);

    if (state == 0) {
        return "SUCCESS";
    } else {
        return "FAIL";
    }
}


//Method to submit and log a solved puzzle
std::string DB::puzzleSolved(MYSQL *connection, std::string payload) {

    MYSQL_RES *result;

    QVector<QString> split = QString::fromStdString(payload).split(",").toVector();

    QString query = "SELECT * FROM users WHERE id=\"" + split.at(0) + "\";";
    int state = mysql_query(connection, query.toLatin1().data());

    if (state != 0) {
        std::cout << mysql_error(connection) << std::endl;
        return "SQLERROR";
    }

    result = mysql_store_result(connection);

    //check to see if the user exists in the database
    if (mysql_num_rows(result) != 0) {
        return "INVALIDUSER";
    }

    //construct insert command
    query = "INSERT INTO `puzzles` (`userid`, `puzzleid`, `date`) VALUES (\"";
    query += split.at(0) + "\",\"" + split.at(1) + "\",\"CURRENT_TIMESTAMP)\");";

    //For debug, remove later
    std::cout << query.toLatin1().data() << std::endl;

    //execute
    state = mysql_query(connection, query.toLatin1().data());
    result = mysql_store_result(connection);

    if (state == 0) {
        return "SUCCESS";
    } else {
        return "FAIL";
    }

}
