#include <iostream>
#include <vector>
#include "contact.h"
#include "fileContacts.h"
#include "converters.h"

using namespace std;

class ContactsHandler : public Converters
{

private:

    vector <Contact> existingContacts;
    FileContacts fileHandler;
    int newContactId;

    void updateContactsVector(int, int&);
    void modifyContact (int, int);
    void removeContact (int);
    void showDetailedInfo(string, int);
    virtual string convertIntToString (int);

public:
    void addContactToContactsBook(int);
    void showAllContacts(int);
    void searchByName(int);
    void searchBySurname(int);

};
