#include <iostream>
#include <vector>
#include "usersHandler.h"
#include "contactsHandler.h"

using namespace std;

class ContactsBook
{

public:
	char mainMenuUserSelection;
	char contactsMenuUserSelection;
	char searchMenuUserSelection;
	UsersHandler userHandler;
	ContactsHandler contactHandler;
	User loggedUser;

	void manageContactBook();

private:
	char displayMainMenu();
	char displayContactsMenu();
	char manageContactsMenu();
	char displaySearchMenu();
	void showConsoleTextInRed(string);

};
