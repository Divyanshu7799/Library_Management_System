#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;
class Book{
    private:
    string  Author_Name,Title,Category;
    bool status;
    int id;
    public:
    Book(int id,string Title,string Author_Name,string Category);
    string get_title();
    string get_category();
    int get_id();
    bool get_status();
    void update_status(bool s);
    string add_to_file();
};

#endif