#include <iostream>
#include <vector>
#include "contact.h"
#include "converters.h"

using namespace std;

class FileContacts : public Converters
{

    public:

    vector <Contact> readContactsDataFromFile(int, int&);
    void updateContactsDataBase(Contact, string);

    private:

    string convertContactStructureToSingleLine(Contact);
    virtual string convertIntToString (int);
};
