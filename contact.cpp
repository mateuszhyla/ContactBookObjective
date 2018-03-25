#include <iostream>
#include "contact.h"

using namespace std;

Contact::Contact(int contactNumber, int userNumber, string contactName, string contactSurname, string contactPhone, string contactEmail, string contactAddress)
{
    contactId = contactNumber;
    userId = userNumber;
    name = contactName;
    surname = contactSurname;
    phoneNumber = contactPhone;
    mailAddress = contactEmail;
    address = contactAddress;

}

void Contact::setContactId(int id)
{
    contactId = id;
}
int Contact::getContactId()
{
    return contactId;
}
void Contact::setUserId(int id)
{
    userId = id;
}
int Contact::getUserId()
{
    return userId;
}
void Contact::setName(string contactName)
{
    name = contactName;
}
string Contact::getName()
{
    return name;
}
void Contact::setSurname(string contactSurname)
{
    surname = contactSurname;
}
string Contact::getSurname()
{
    return surname;
}
void Contact::setPhoneNumber(string contactPhone)
{
    phoneNumber = contactPhone;
}
string Contact::getPhoneNumber()
{
    return phoneNumber;
}
void Contact::setEmail(string contactEmail)
{
    mailAddress = contactEmail;
}
string Contact::getEmail()
{
    return mailAddress;
}
void Contact::setAddress(string contactAddress)
{
    address = contactAddress;
}
string Contact::getAddress()
{
    return address;
}
