#include <iostream>
#include "user.h"

using namespace std;

User::User(int number, string nick, string pass)
{
    id = number;
    nickname = nick;
    password = pass;
}

void User::setNickname(string nick)
{
    nickname = nick;
}

string User::getNickname()
{
    return nickname;
}

void User::setPassword(string pass)
{
    password = pass;
}


string User::getPassword()
{
    return password;
}

void User::setId(int number)
{
    id = number;
}


int User::getId()
{
    return id;
}
