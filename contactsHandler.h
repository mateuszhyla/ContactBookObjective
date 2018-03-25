#include <iostream>
#include <vector>
#include "contact.h"
#include "fileContacts.h"
#include "converters.h"

using namespace std;

class ContactsHandler : public Converters
{

public:

    vector <Contact> existingContacts;
    FileContacts fileHandler;

    void updateContactsVector(int);
    void addContactToContactsBook(int);
    void showAllContacts(int);
    void modifyContact (int, int);
    void removeContact (int);
    void searchByName(int);
    void searchBySurname(int);
    void showDetailedInfo(string, int);
    virtual string convertIntToString (int);

};
