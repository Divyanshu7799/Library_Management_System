#include"../../include/models/User.hpp"

User::User(int user_id, string name){
    this->user_id=user_id;
    this->name=name;
    this->BookCount=0;
}

string User::get_name(){
    return name;
}
int User::get_user_id(){
    return user_id;
}
string User::add_to_file(){
    return to_string(user_id)+","+name+","+to_string(BookCount);
}