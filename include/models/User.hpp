#ifndef USER_H
#define USER_H
#include<string>
#include<vector>
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
    string add_to_file() const;
    static User fromString(string line);
    void count();
    void countd_dec();
    
};

#endif