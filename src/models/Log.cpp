#include "../../include/models/Log.hpp"

#include <vector>

Log::Log(){}

Log::Log(
    int b,
    int u,
    string i,
    string r,
    string s
){
    bookId=b;
    userId=u;
    issueDate=i;
    returnDate=r;
    status=s;
}

// ===== getters =====
int Log::getBookId() const{
    return bookId;
}

int Log::getUserId() const{
    return userId;
}

string Log::getIssueDate() const{
    return issueDate;
}

string Log::getReturnDate() const{
    return returnDate;
}

string Log::getStatus() const{
    return status;
}

// ===== setters =====
void Log::setReturnDate(
    string d
){
    returnDate=d;
}

void Log::setStatus(
    string s
){
    status=s;
}

// ===== to file =====
string Log::toFileString() const{

    return
    to_string(bookId)+","+
    to_string(userId)+","+
    issueDate+","+
    returnDate+","+
    status;
}

// ===== from file =====
Log Log::fromString(
    string line
){

    vector<string> d;

    string temp="";

    for(char c : line){

        if(c==','){
            d.push_back(temp);
            temp="";
        }
        else{
            temp+=c;
        }
    }

    d.push_back(temp);

    return Log(
        stoi(d[0]),
        stoi(d[1]),
        d[2],
        d[3],
        d[4]
    );
}