#ifndef MAIN_DB_HPP
#define MAIN_DB_HPP

#include <vector>
#include <string>
using namespace std;

class Main_DB {
public:
 
    virtual void appendBook(const string& data) = 0;
    virtual vector<string> ReadBook() = 0;
    virtual void UpdateBooks(const vector<string>& lines) = 0;
    virtual void appendUser(const string& data) = 0;
    virtual void UpdateUser(const vector<string>& lines) = 0;
    virtual vector<string> readUsers() = 0;
    virtual void appendLog(const string& data) = 0;
    virtual ~Main_DB() {}
};

#endif