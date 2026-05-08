#include"../../include/models/Book.hpp"

Book::Book(int id,string Title,string Author_Name,string Category){
    this->id =id;
    this->Title=Title;
    this->Author_Name=Author_Name;
    this->Category=Category;
    this->status=true;

}

string Book::get_title(){
    return Title;
}
string Book::get_category(){
    return Category;
}
int Book::get_id(){
    return id;
}
bool Book::get_status(){
    return status;
}

void Book::update_status(bool s){
    status=s;
}

string Book::add_to_file(){
    string sta;
    if(status==1){
      sta="Available";
    }
    else{
        sta="Issued";
    }
    string s= to_string(id)+","+Title+","+Author_Name+","+Category+","+sta;
    return s;
    
}

