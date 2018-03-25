#include <iostream>
#include <vector>
#include "user.h"
#include "fileUsers.h"

using namespace std;

class UsersHandler
{

    public:

    vector <User> existingUsers;
    FileUsers fileHandler;
    UsersHandler ();
    void registerNewUser();
    User logIn ();
    void changePassword (User);

};
