#ifndef FILE_DB_HPP
#define FILE_DB_HPP
#include<iostream>
#include <ctime>
#include<fstream>
#include<string>
#include<vector>
#include"Main_DB.hpp"
using namespace std;
class File_DB:public Main_DB{

    private:
    string bookFile;
    string userFile;
    string logFile;
    public:
   File_DB();
   vector<string> ReadBook() override;
   void appendBook(const string& data)override;
   void UpdateBooks(const vector<string>& lines)override;
   void UpdateUser(const vector<string>& lines)override;
   void appendUser(const string& data)override;
   vector<string> readUsers()override;
   void appendLog(const string& data)override;


};

#endif 