#include <iostream>
#pragma once
using namespace std;

class User
{
    private:
    int id;
    string nickname;
    string password;

    public:
     User (int = 0, string = "Adam", string = "Nowak");
     void setNickname(string);
     string getNickname();
     void setPassword(string);
     string getPassword();
     void setId(int);
     int getId();
};
