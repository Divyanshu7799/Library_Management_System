#include"../../include/repository/FILE_DB.hpp"

File_DB::File_DB(){
    this->bookFile="DataBase/Book.txt";
    this->userFile="DataBase/User.txt";
    this->logFile="DataBase/Log.txt";
}
vector<string> File_DB::ReadBook(){
   vector<string>temp;
    ifstream f(bookFile);  
    string line;
    if(!f){
        cout<<"Error opening User file!\n";
        return temp;
    }
    while(getline(f,line)){
        temp.push_back(line);
    }
    f.close();
    return temp;
}
void File_DB::appendBook(const string &data){
   ofstream f(bookFile,ios::app);
   
    if(!f){
        cout<<"Error opening User file!\n";
        return;
    }
   f<<data<<"\n";
   f.close();
   
}
void File_DB::UpdateBooks(const vector<string>&data){
  ofstream f(bookFile);
  
    if(!f){
        cout<<"Error opening User file!\n";
        return;
    }
  for(auto &line:data ){
    f<<line<<"\n";
  }
  f.close();

}

void File_DB::appendUser(const string &data){
    ofstream f(userFile, ios::app);

    if(!f){
        cout<<"Error opening User file!\n";
        return;
    }

    f << data << "\n";
    f.close();

}
void File_DB::appendLog(const string &data){
   ofstream f(logFile, ios::app);

    if(!f){
        cout<<"Error opening Log file!\n";
        return;
    }

    f << data << "\n";
    f.close();
}
vector<string>File_DB::readUsers(){
 vector<string> temp;
    ifstream f(userFile);
    string line;

    if(!f){
        cout<<"Error reading User file!\n";
        return temp;
    }

    while(getline(f, line)){
        temp.push_back(line);
    }

    f.close();
    return temp;
}
void File_DB::UpdateUser(const vector<string>&data){
  ofstream f(userFile);
  
    if(!f){
        cout<<"Error opening User file!\n";
        return;
    }
  for(auto &line:data ){
    f<<line<<"\n";
  }
  f.close();
}