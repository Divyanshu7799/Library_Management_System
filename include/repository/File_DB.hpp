#ifndef FILE_DB_HPP
#define FILE_DB_HPP
#include<iostream>
#include <ctime>
#include<fstream>
#include<string>
#include<vector>
#include"Main_DB.hpp"
#include"../../include/models/Book.hpp"
#include"../../include/models/User.hpp"
using namespace std;
class File_DB:public Main_DB{

    private:
    string bookFile;
    string userFile;
    string logFile;
    public:
   File_DB();
    vector<Book> loadBooks() override;
    void saveBooks( const vector<Book>& books) override;
    vector<User> loadUsers() override;
    void saveUsers( const vector<User>& users ) override;
    vector<Log> loadLogs() override;
    void saveLogs(const vector<Log>& logs) override;
    void appendLog(const string& log) override;

};

#endif 