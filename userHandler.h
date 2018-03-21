#include <iostream>
#include <vector>
#include "user.h"
#include "fileUsers.h"

using namespace std;

class UserHandler
{

    public:

    vector <User> existingUsers;
    FileUsers fileHandler;
    UserHandler ();
    void registerNewUser();
    void logIn ();

};
