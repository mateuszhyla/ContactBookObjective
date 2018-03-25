#include <iostream>
#pragma once
using namespace std;

class Contact
{
    private:
    int contactId;
    int userId;
    string name;
    string surname;
    string phoneNumber;
    string mailAddress;
    string address;

    public:
     Contact (int = 0, int = 0, string = "Adam", string = "Nowak", string = "0000", string = "@", string = "Unknown");

     void setContactId(int);
     int getContactId();
     void setUserId(int);
     int getUserId();
     void setName(string);
     string getName();
     void setSurname(string);
     string getSurname();
     void setPhoneNumber(string);
     string getPhoneNumber();
     void setEmail(string);
     string getEmail();
     void setAddress(string);
     string getAddress();

};
