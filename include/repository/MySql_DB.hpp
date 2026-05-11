#ifndef MYSQL_DB_HPP
#define MYSQL_DB_HPP
#include"Main_DB.hpp"
#include <mysql_driver.h>

#include <mysql_connection.h>

#include <cppconn/statement.h>

#include <cppconn/resultset.h>

class MySql_DB: public Main_DB{
    private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

 public:

   MySql_DB();

    vector<Book> loadBooks() override;

    void saveBooks(
        const vector<Book>& books
    ) override;

    vector<User> loadUsers() override;

    void saveUsers(
        const vector<User>& users
    ) override;

   
    void appendLog(
        const string& log
    ) override;
};


#endif