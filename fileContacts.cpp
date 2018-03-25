#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "fileContacts.h"
#include <sstream>


using namespace std;

vector <Contact> FileContacts::readContactsDataFromFile(int userId)
{
    fstream contactBook;
    contactBook.open("contactBook.txt", ios::in);
    vector <string> dividedContact;
    vector <Contact> allContacts;
    Contact contactInfo;
    string contact;
    int contactId = 1;

    while (getline(contactBook, contact))
    {
        stringstream ss(contact);
        dividedContact.clear();
        while( ss.good() )
        {
            string sub;
            getline( ss, sub, '|' );
            dividedContact.push_back(sub);
        }
        contactInfo.setContactId(atoi(dividedContact[0].c_str()));
        contactInfo.setUserId(atoi (dividedContact[1].c_str()));
        contactInfo.setName(dividedContact[2]);
        contactInfo.setSurname(dividedContact[3]);
        contactInfo.setPhoneNumber (dividedContact[4]);
        contactInfo.setEmail (dividedContact[5]);
        contactInfo.setAddress(dividedContact[6]);
        contactId = contactInfo.getContactId() + 1;
        if (contactInfo.getUserId() == userId)
        {
            allContacts.push_back(contactInfo);
        }
    }
    contactBook.close();
    return allContacts;
}

void FileContacts::updateContactsDataBase(Contact contactToModify, string action)
{

    string convertedContact = convertContactStructureToSingleLine(contactToModify);
    string tempLine;
    fstream contactBook;
    string contactId;
    contactBook.open("contactBook.txt", ios::in | ios::out | ios::app);

    if (action == "add")
    {
        contactBook << convertedContact << endl;
        contactBook.close();
    }
    else
    {
        contactId = convertIntToString(contactToModify.getContactId());
        convertedContact = convertContactStructureToSingleLine(contactToModify);
        ofstream tempContactBook("tempContactBook.txt");

        while(contactBook >> tempLine)
        {
            if(tempLine.substr(0, contactId.size()) != contactId)
            {
                tempContactBook << tempLine << endl;
            }
            else
            {
                if (action == "remove")
                {
                }
                else if (action == "modify")
                {
                    tempContactBook << convertedContact << endl;
                }
            }
        }
        contactBook.close();
        remove("contactBook.txt");
        tempContactBook.close();
        rename("tempContactBook.txt", "contactBook.txt");
    }

}



string FileContacts::convertContactStructureToSingleLine(Contact contactToConvert)
{
    string convertedContact;

    convertedContact = convertIntToString(contactToConvert.getContactId()) + "|";
    convertedContact += convertIntToString(contactToConvert.getUserId()) + "|";
    convertedContact += contactToConvert.getName() + "|";
    convertedContact += contactToConvert.getSurname() + "|";
    convertedContact += contactToConvert.getPhoneNumber() + "|";
    convertedContact += contactToConvert.getEmail() + "|";
    convertedContact += contactToConvert.getAddress() + "|";

    return convertedContact;
}

string FileContacts::convertIntToString (int id)
{
    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}
