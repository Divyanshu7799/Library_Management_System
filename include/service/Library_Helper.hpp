#ifndef LIBRARY_HELPER
#define LIBRARY_HELPER
#include"../models/Book.hpp"
#include"../models/User.hpp"
#include"../models/Log.hpp"
#include"../repository/Main_DB.hpp"
class Library_Helper{
 private:
     Main_DB* repo;
    vector<Book> books;
    vector<User> users;
 public:
  Library_Helper();
   Library_Helper(Main_DB* r);
    void loadData();
    void saveData();
    void addBook(Book b);
    bool removeBook(int id);
    bool updateBook( int id, string title, string author,string category);
    Book* searchByTitle(string title);
    vector<Book> searchByCategory( string category);
    bool issueBook( int bookId, int userId);
    bool returnBook( int bookId, int userId);
    bool checkAvailability(int id);
    void addUser(User u);
};
#endif
