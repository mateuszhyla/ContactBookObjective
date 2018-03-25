#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "contactsHandler.h"
#include <algorithm>
#include <conio.h>
#include <sstream>
using namespace std;

void ContactsHandler::updateContactsVector(int userId, int &newContactId)
{
    existingContacts = fileHandler.readContactsDataFromFile(userId, newContactId);
}

void ContactsHandler::addContactToContactsBook(int userId)
{
    updateContactsVector(userId, newContactId);
    Contact newContact;
    string tempInfo;
    system("cls");

    cout << "Fill contact informations:" << endl << endl;

    newContact.setContactId (newContactId);
    newContact.setUserId(userId);

    cout << "Name: ";
    cin >> tempInfo;
    newContact.setName(tempInfo);

    cout << "Surname: ";
    cin >> tempInfo;
    newContact.setSurname(tempInfo);

    cout << "Phone number: ";
    cin.sync();
    getline(cin, tempInfo);
    newContact.setPhoneNumber (tempInfo);

    cout << "Email address: ";
    cin >> tempInfo;
    newContact.setEmail(tempInfo);

    cout << "Address: ";
    cin.sync();
    getline(cin, tempInfo);
    newContact.setAddress (tempInfo);

    fileHandler.updateContactsDataBase(newContact, "add");

    cout << endl << "Contact has been added to contacts list" << endl;
    Sleep(1500);
}

void ContactsHandler::showAllContacts(int userId)
{
    updateContactsVector(userId, newContactId);
    string userSelection;
    vector <string> availableIDs;
    availableIDs.push_back("0");

    system("cls");
    cout << "Contacts: " << endl << endl;

    for (int i = 0; i < existingContacts.size(); i++)
    {
        availableIDs.push_back(convertIntToString(existingContacts[i].getContactId()));
        cout << existingContacts[i].getContactId() << ". " << existingContacts[i].getName() << " " << existingContacts[i].getSurname() << endl;
    }

    cout << endl << "Press ID No. to edit/see contact details"
         << endl << "Press 0 to go back to main menu" << endl;

    do
    {
        cin >> userSelection;
    }
    while ((find(availableIDs.begin(), availableIDs.end(), userSelection) == availableIDs.end()));

    if (userSelection != "0")
    {
        showDetailedInfo(userSelection, userId);
    }

}
void ContactsHandler::modifyContact (int contactId, int userId)
{
    Contact newContact;
    string tempInfo;
    system("cls");
    cout << "Update contact informations:" << endl << endl;

    for (int i = 0; i < existingContacts.size(); i++)

    {
        if ((existingContacts[i].getContactId() == contactId))
        {
            newContact.setContactId(contactId);
            newContact.setUserId(userId);

            cout << "Old name: " << existingContacts[i].getName() << endl << "New name: ";
            cin >> tempInfo;
            newContact.setName(tempInfo);
            cout << "Old surname: " << existingContacts[i].getSurname() << endl << "New surname: ";
            cin >> tempInfo;
            newContact.setSurname(tempInfo);

            cout << "Old phone number: " << existingContacts[i].getPhoneNumber() << endl << "New phone number: ";
            cin.sync();
            getline(cin, tempInfo);
            newContact.setPhoneNumber(tempInfo);

            cout << "Old email: " << existingContacts[i].getEmail() << endl << "New email address: ";
            cin >> tempInfo;
            newContact.setEmail(tempInfo);

            cout << "Old address: " << existingContacts[i].getAddress() << endl << "New address: ";
            cin.sync();
            getline(cin, tempInfo);
            newContact.setAddress(tempInfo);
            break;
        }
    }

    fileHandler.updateContactsDataBase(newContact, "modify");
    cout << endl << "Contact has been modified" << endl;
    Sleep(1500);
}

void ContactsHandler::removeContact (int id)

{
    char userSelection;
    Contact contactToRemove;
    cout << endl << "Are you sure? (y/n)" << endl;
    do
    {
        userSelection = getch();
    }
    while ((userSelection != 'y') && (userSelection != 'n'));


    if (userSelection == 'y')
    {
        for (int i = 0; i < existingContacts.size(); i++)
        {
            if ((existingContacts[i].getContactId() == id))
            {
                contactToRemove = existingContacts[i];
                break;
            }
        }

        fileHandler.updateContactsDataBase(contactToRemove, "remove");
        cout << endl << "Contact has been removed from contacts list" << endl;
        Sleep(1500);
    }

}

void ContactsHandler::searchByName(int userId)
{
    updateContactsVector(userId, newContactId);
    string searchedName;
    string userSelection;
    bool matchesFound = false;
    vector <string> availableIDs;
    availableIDs.push_back("0");

    system("cls");
    cout << "Please type a name: ";
    cin >> searchedName;

    for (int i = 0; i < existingContacts.size(); i++)
    {
        if ((existingContacts[i].getName() == searchedName))
        {
            availableIDs.push_back(convertIntToString(existingContacts[i].getContactId()));
            matchesFound = true;
            cout << existingContacts[i].getContactId() << ". " << existingContacts[i].getName() << " " << existingContacts[i].getSurname() << endl;
        }
    }
    if(!matchesFound)
    {
        cout << endl << "There is no match. Press 0 to go back to main menu" << endl;
    }
    else
    {
        cout << endl << "Press ID No. to edit/see contact details"
             << endl << "Press 0 to go back to main menu" << endl;
    }

    do
    {
        cin >> userSelection;
    }
    while ((find(availableIDs.begin(), availableIDs.end(), userSelection) == availableIDs.end()));

    if (userSelection != "0")
    {
        showDetailedInfo(userSelection, userId);
    }
}

void ContactsHandler::searchBySurname(int userId)
{
    updateContactsVector(userId, newContactId);
    string searchedSurname;
    string userSelection;
    bool matchesFound = false;
    vector <string> availableIDs;
    availableIDs.push_back("0");

    system("cls");
    cout << "Please type a surname: ";
    cin >> searchedSurname;

    for (int i = 0; i < existingContacts.size(); i++)
    {
        if ((existingContacts[i].getSurname() == searchedSurname))
        {
            availableIDs.push_back(convertIntToString(existingContacts[i].getContactId()));
            matchesFound = true;
            cout << existingContacts[i].getContactId() << ". " << existingContacts[i].getName() << " " << existingContacts[i].getSurname() << endl;
        }
    }

    if(!matchesFound)
    {
        cout << endl << "There is no match. Press 0 to go back to main menu" << endl;
    }
    else
    {
        cout << endl << "Press ID No. to edit/see contact details"
             << endl << "Press 0 to go back to main menu" << endl;
    }

    do
    {
        cin >> userSelection;
    }
    while ((find(availableIDs.begin(), availableIDs.end(), userSelection) == availableIDs.end()));

    if (userSelection != "0")
    {
        showDetailedInfo(userSelection, userId);
    }

}

void ContactsHandler::showDetailedInfo (string contactId, int userId)
{
    char userSelection;
    int convertedId = atoi(contactId.c_str());

    system("cls");
    cout << "Contact details:" << endl << endl;

    for (int i = 0; i < existingContacts.size(); i++)
    {
        if ((existingContacts[i].getContactId() == convertedId))
        {
            cout << existingContacts[i].getName() << " " << existingContacts[i].getSurname() << ", " << existingContacts[i].getPhoneNumber()
                 << ", " << existingContacts[i].getEmail() << ", " << existingContacts[i].getAddress() << endl;
        }
    }
    cout << endl << "Press 1 to edit contact" << endl
         << "Press 2 to remove contact" << endl
         << "Press 0 to go back to main menu" << endl;

    do
    {
        userSelection = getch();
    }
    while ((userSelection != '0') && (userSelection != '1') && (userSelection != '2'));

    if (userSelection == '1')
    {
        modifyContact(convertedId, userId);
    }
    else if (userSelection == '2')
    {
        removeContact(convertedId);
    }
}

string ContactsHandler::convertIntToString (int id)
{
    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}
