#ifndef LOG_HPP
#define LOG_HPP

#include <string>
using namespace std;

class Log{

private:

    int bookId;
    int userId;

    string issueDate;
    string returnDate;

    string status;

public:

    Log();

    Log(
        int,
        int,
        string,
        string,
        string
    );

    // getters
    int getBookId() const;

    int getUserId() const;

    string getIssueDate() const;

    string getReturnDate() const;

    string getStatus() const;

   
    void setReturnDate(string);

    void setStatus(string);

  
    string toFileString() const;

    static Log fromString(
        string line
    );
};

#endif