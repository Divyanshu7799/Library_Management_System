#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<vector>
using namespace std;
class Book{
    private:
    string  Author_Name,Title,Category;
    bool status;
    int id;
    public:
    Book(int id,string Title,string Author_Name,string Category);
    string get_title()const ;
    string get_category()const ;
    int get_id()const ;
    bool get_status()const ;
    string get_Author()const ;
    void update_status(bool s);
    string add_to_file() const;
     static Book fromString(string line);
};

#endif