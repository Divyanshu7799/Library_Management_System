#include"../../include/repository/FILE_DB.hpp"

File_DB::File_DB(){
    this->bookFile="DataBase/Book.txt";
    this->userFile="DataBase/User.txt";
    this->logFile="DataBase/Log.txt";
}


vector<Book> File_DB::loadBooks(){

    vector<Book> books;

    ifstream file(bookFile);

    string line;

    while(getline(file,line)){

        if(line.empty())
            continue;

        books.push_back(
            Book::fromString(line)
        );
    }

    file.close();

    return books;
}

void File_DB::saveBooks(
    const vector<Book>& books
){

    ofstream file(bookFile);

    for(const auto& book : books){

        file << book.add_to_file()
             << endl;
    }

    file.close();
}

// ===== load users =====
vector<User> File_DB::loadUsers(){

    vector<User> users;

    ifstream file(userFile);

    string line;

    while(getline(file,line)){

        if(line.empty())
            continue;

        users.push_back(
            User::fromString(line)
        );
    }

    file.close();

    return users;
}

// ===== save users =====
void File_DB::saveUsers(
    const vector<User>& users
){

    ofstream file(userFile);

    for(const auto& user : users){

        file << user.add_to_file()
             << endl;
    }

    file.close();
}
vector<Log> File_DB::loadLogs(){
    vector<Log>lg;
     ifstream file(logFile);

    string line;

    while(getline(file,line)){

        if(line.empty())
            continue;

        lg.push_back(
            Log::fromString(line)
        );
    }

    file.close();

    return lg;
}

void File_DB::appendLog(const string& log){
    ofstream f(logFile,ios::app);
    f<<log<<endl;
    f.close();

}
void File_DB::saveLogs(const vector<Log>& Logs){

    ofstream file(logFile);

    for(const auto& log : Logs){

        file << log.toFileString()
             << endl;
    }

    file.close();
}
