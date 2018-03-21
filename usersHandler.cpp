#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "userHandler.h"


using namespace std;

UserHandler::UserHandler()
{
    existingUsers = fileHandler.readUsersDataFromFile();
}

void UserHandler::registerNewUser()
{

    string nickName, password;
    User newUser;
    int i = 0, contactId = 1;

    cout << endl << "Type new username: ";
    cin >> nickName;

    while (i < existingUsers.size())
    {
        if (existingUsers[i].getNickname() == nickName)
        {
            cout << "Username already exists. Type different username: ";
            cin >> nickName;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    cout << "Type a password: ";
    cin >> password;


    if (existingUsers.size()>0)
    {
        contactId = existingUsers.back().getId() + 1;
    }
    newUser.setId (contactId);
    newUser.setNickname (nickName);
    newUser.setPassword (password);

    existingUsers.push_back(newUser);
    fileHandler.updateUsersDataBase(newUser, "add");

    cout << endl << "User's account has been created!" << endl;
    Sleep(1500);
}
   // void logIn ();
