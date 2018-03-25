#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "contactsBook.h"
#include "contact.h"



using namespace std;


void ContactsBook::manageContactBook()
{
mainMenuWindow:

	mainMenuUserSelection = displayMainMenu();

	switch (mainMenuUserSelection)
	{

	case '1':
		userHandler.registerNewUser();
		goto mainMenuWindow;
		break;

	case '2':

		loggedUser = userHandler.logIn();
		if (loggedUser.getId() != 0)
		{
			contactsMenuUserSelection = manageContactsMenu();
		}
		goto mainMenuWindow;
		break;

	case '0':
		exit(0);
	}
}

char ContactsBook::displayMainMenu()
{
	char userSelection;

	system("cls");

	showConsoleTextInRed(".:Contacts book application:.");
	cout << endl << endl;
	cout << "1. Register" << endl;
	cout << "2. Log in" << endl;
	cout << "0. Close application" << endl << endl;
	cout << "Select a number to start an action..." << endl;

	do
	{
		userSelection = _getch();
	} while ((userSelection != '1') && (userSelection != '2') && (userSelection != '0'));

	return userSelection;
}

char ContactsBook::manageContactsMenu()
{
	char contactsWindowUserSelection;
	char searchWindowUserSelection;
	int contactId;

contactsWindow:
	//contactId = readContactsDataFromFile(currentUserInfo.id, allContacts);
	contactsWindowUserSelection = displayContactsMenu();

	switch (contactsWindowUserSelection)
	{

	case '1':
		searchWindowUserSelection = displaySearchMenu();

		switch (searchWindowUserSelection)
		{
		case '1':
			contactHandler.searchByName(loggedUser.getId());
			break;

		case '2':
			contactHandler.searchBySurname(loggedUser.getId());
			break;

		default:
			break;
		}
		goto contactsWindow;
		break;

	case '2':
		contactHandler.addContactToContactsBook(loggedUser.getId());
		goto contactsWindow;
		break;

	case '3':
		contactHandler.showAllContacts(loggedUser.getId());
		goto contactsWindow;
		break;

	case '4':
		userHandler.changePassword(loggedUser);
		goto contactsWindow;

	case '0':
		return contactsWindowUserSelection;
	}
}

char ContactsBook::displayContactsMenu()
{
	char userSelection;
	system("cls");

	showConsoleTextInRed(".:Manage contacts:.");
	cout << "  User: " << loggedUser.getNickname();
	cout << endl << endl;
	cout << "1. Search for contact" << endl;
	cout << "2. Add new contact to your contact list" << endl;
	cout << "3. Show all contacts from your contact list" << endl;
	cout << "4. Change password" << endl;
	cout << "0. Log off" << endl << endl;

	cout << "Select a number to start an action..." << endl;

	do
	{
		userSelection = getch();
	} while ((userSelection != '1') && (userSelection != '2') && (userSelection != '3') && (userSelection != '4') && (userSelection != '0'));

	return userSelection;
}

char ContactsBook::displaySearchMenu()
{
	char userSelection;

	system("cls");
	showConsoleTextInRed(".:Search contact:.");
	cout << endl << endl;
	cout << "1. By name..." << endl;
	cout << "2. By surname..." << endl;
	cout << "0. Back" << endl << endl;
	cout << "Select a number to start an action..." << endl;

	do
	{
		userSelection = getch();
	} while ((userSelection != '1') && (userSelection != '2') && (userSelection != '0'));

	return userSelection;
}

void ContactsBook::showConsoleTextInRed(string header)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 12);
	cout << header;
	SetConsoleTextAttribute(console, 15);

}
