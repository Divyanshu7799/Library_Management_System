#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User{
    private:
    int user_id;
    string name;
    int BookCount;
    public:
    User(int user_id, string name);
    int get_user_id();
    string get_name();
    string add_to_file();
    
    
};

#endif