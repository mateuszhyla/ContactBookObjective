#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "contactBook.h"



using namespace std;

char ContactBook::displayMainMenu()
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
        userSelection = getch();
    }
    while ((userSelection != '1') && (userSelection != '2') && (userSelection != '0'));

    return userSelection;
}

void ContactBook::showConsoleTextInRed(string header)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, 12);
    cout << header;
    SetConsoleTextAttribute(console, 15);

}
