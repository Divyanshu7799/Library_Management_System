#ifndef MAIN_DB_HPP
#define MAIN_DB_HPP
#include"../models/Book.hpp"
#include"../models/User.hpp"
#include"../models/Log.hpp"
#include <vector>
#include <string>
using namespace std;

class Main_DB {
public:
 
     virtual vector<Book> loadBooks() = 0;

    virtual void saveBooks( const vector<Book>& books  ) = 0;

    virtual vector<User> loadUsers() = 0;

    virtual void saveUsers( const vector<User>& users ) = 0;
    // virtual vector<Log>loadLogs() = 0;
    // virtual void saveLogs( const vector<Log>& logs) = 0;
    virtual void appendLog(const string& log) = 0;
};

#endif