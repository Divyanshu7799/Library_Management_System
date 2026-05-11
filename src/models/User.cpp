#include"../../include/models/User.hpp"

User::User(int user_id, string name){
    this->user_id=user_id;
    this->name=name;
    this->BookCount=0;
}

string User::get_name()const{
    return name;
}
int User::get_user_id()const{
    return user_id;
}
string User::add_to_file() const{
    return to_string(user_id)+","+name+","+to_string(BookCount);
}
int User::getcount()const{
    return BookCount;
}
void User::count(){
    this->BookCount++;
}
void User::countd_dec(){
    this->BookCount--;
}
User User::fromString(string line){
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

    return User(
        stoi(d[0]),
        d[1]
    );

}