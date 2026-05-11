#include"../../include/models/Book.hpp"
#include <sstream>
Book::Book(int id,string Title,string Author_Name,string Category){
    this->id =id;
    this->Title=Title;
    this->Author_Name=Author_Name;
    this->Category=Category;
    this->status=true;

}

string Book::get_title()const {
    return Title;
}
string Book::get_category()const {
    return Category;
}
int Book::get_id()const {
    return id;
}
bool Book::get_status() const {
    return status;
}

void Book::update_status(bool s) {
    status=s;
}
string Book::get_Author()const {
    return Author_Name;
}

string Book::add_to_file()const {
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

Book Book::fromString(string line){

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

    return Book(
        stoi(d[0]),
        d[1],
        d[2],
        d[3]
    );
}