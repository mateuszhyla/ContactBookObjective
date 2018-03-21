#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "fileUsers.h"
#include <sstream>


using namespace std;

vector <User> FileUsers::readUsersDataFromFile()
  {
      vector <User> existingUsers;
    fstream usersDataBase;
    usersDataBase.open("usersDataBase.txt", ios::in);

    vector <string> dividedUser;
    User userInfo;
    string user;

    while (getline(usersDataBase, user))
    {
        stringstream ss(user);
        dividedUser.clear();
        while( ss.good() )
        {
            string sub;
            getline( ss, sub, '|' );
            dividedUser.push_back(sub);
        }
        userInfo.setId(atoi(dividedUser[0].c_str()));
        userInfo.setNickname(dividedUser[1]);
        userInfo.setPassword(dividedUser[2]);

        existingUsers.push_back(userInfo);
    }
    usersDataBase.close();
    return existingUsers;
}

void FileUsers::updateUsersDataBase(User userToUpdate, string action)
{
    string convertedUser = convertUserStructureToSingleLine(userToUpdate);
    string tempLine;
    fstream usersDataBase;
    string userId;
    usersDataBase.open("usersDataBase.txt", ios::in | ios::out | ios::app);

    if (action == "add")
    {
        usersDataBase << convertedUser << endl;
        usersDataBase.close();
    }
    else
    {
        userId = convertIntToString(userToUpdate.getId());
        ofstream tempUserDataBase("tempUserDataBase.txt");

        while(usersDataBase >> tempLine)
        {
            if(tempLine.substr(0, userId.size()) != userId)
            {
                tempUserDataBase << tempLine << endl;
            }
            else
            {
                tempUserDataBase << convertedUser << endl;
            }
        }
        usersDataBase.close();
        remove("usersDataBase.txt");
        tempUserDataBase.close();
        rename("tempUserDataBase.txt", "usersDataBase.txt");
    }
}

string FileUsers::convertUserStructureToSingleLine(User userToConvert)
{
    string convertedUser;

    convertedUser = convertIntToString(userToConvert.getId()) + "|";
    convertedUser += userToConvert.getNickname()+ "|";
    convertedUser += userToConvert.getPassword() + "|";

    return convertedUser;

}

string FileUsers::convertIntToString (int id)
{
    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}
