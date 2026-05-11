#include"../../include/service/Library_Helper.hpp"
#include<iostream>
using namespace std;

#include <ctime>

string getCurrentDate(){

    time_t now = time(0);

    tm* ltm = localtime(&now);

    return
    to_string(1900 + ltm->tm_year)
    + "-"
    + to_string(1 + ltm->tm_mon)
    + "-"
    + to_string(ltm->tm_mday);
}
Library_Helper::Library_Helper(Main_DB* r){
    repo = r;
   loadData();
}

void Library_Helper::loadData(){
    books = repo->loadBooks();
    users = repo->loadUsers();
}
void Library_Helper::saveData(){
    repo->saveBooks(books);
    repo->saveUsers(users);
}
void Library_Helper::addBook(Book b){
    books.push_back(b);
    saveData();
}

void Library_Helper::addUser(User u){

    users.push_back(u);

    saveData();
}
bool Library_Helper::issueBook(
    int bookId,
    int userId
){

    Book* foundBook = nullptr;

    User* foundUser = nullptr;

    for(auto& book : books){

        if(book.get_id() == bookId){

            foundBook = &book;

            break;
        }
    }

    if(foundBook == nullptr){

        return false;
    }

    if(foundBook->get_status() == 0){

        return false;
    }

    for(auto& user : users){

        if(user.get_user_id() == userId){

            foundUser = &user;

            break;
        }
    }

    if(foundUser == nullptr){

        return false;
    }

 
    foundBook->update_status(0);

    foundUser->count();

    string log =
        to_string(bookId)+","+
        to_string(userId)+","+
        getCurrentDate()+","+
        "NOT_RETURNED,ISSUED";

    repo->appendLog(log);

    saveData();

    return true;
}
bool Library_Helper::returnBook(
    int bookId,
    int userId
){

    Book* foundBook = nullptr;

    User* foundUser = nullptr;

    for(auto& book : books){

        if(book.get_id() == bookId){

            foundBook = &book;

            break;
        }
    }

    if(foundBook == nullptr){

        return false;
    }

    if(foundBook->get_status() == 1){

        return false;
    }

    for(auto& user : users){

        if(user.get_user_id()== userId){

            foundUser = &user;

            break;
        }
    }

    if(foundUser == nullptr){

        return false;
    }

    foundBook->update_status(1);

    foundUser->countd_dec();

    string log =
        to_string(bookId)+","+
        to_string(userId)+","+
        getCurrentDate()+","+
        "RETURNED";

    repo->appendLog(log);

    saveData();

    return true;
}
Book* Library_Helper::searchByTitle(
    string title
){

    for(auto& book : books){

        if(
            book.get_title().find(title)
            != string::npos
        ){
            return &book;
        }
    }

    return nullptr;
}
vector<Book>
Library_Helper::searchByCategory(
    string category
){

    vector<Book> result;

    for(auto& book : books){

        if(
            book.get_category().find(category)
            != string::npos
        ){
            result.push_back(book);
        }
    }

    return result;
}
bool Library_Helper::removeBook(
    int id
){

    for(
        auto it = books.begin();
        it != books.end();
        it++
    ){

        if(it->get_id() == id){

            books.erase(it);

            saveData();

            return true;
        }
    }

    return false;
}
bool Library_Helper::updateBook(
    int id,
    string title,
    string author,
    string category
){

    for(auto& book : books){

        if(book.get_id() == id){
            book = Book(
                id,
                title,
                author,
                category
            );

            saveData();

            return true;
        }
    }

    return false;
}
bool Library_Helper::checkAvailability(
    int id
){

    for(auto& book : books){

        if(book.get_id() == id){

            return (
                book.get_status()
                == 1
            );
        }
    }

    return false;
}