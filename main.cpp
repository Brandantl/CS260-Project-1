/* 
 * File:   main.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 7, 2014, 8:43 AM
 */
#include "main.h"
using namespace std;
list* wineries = new list;

int main(int argc, char** argv) {
    wineries->ReadFromDisk(); // Read everything from the disk.
    char command = 'a';

    displayMenu();
    command = getCommand();
    while (command != 'q') {
        executeCmd(command, *wineries);
        displayMenu();
        command = getCommand();
    }
    wineries->WriteToDisk(); // Write everything to the disk in a file called "launch-codes". 
	delete wineries;
    return 0;
}

void displayMenu() {
    cout << "\nImplemented by: Brandan Lasley" << endl;
    cout << "\nWelcome to CS Winery Management System! " << endl;
    cout << "\ta> add a winery" << endl
            << "\tr> remove a winery" << endl
            << "\ts> search for a winery" << endl
            << "\tl> list all the wineries" << endl
            << "\tq> quit the application" << endl << endl;
}

char getCommand() {
    char cmd;
    cout << "Please enter your choice (a, r, s, l or q):";
    cin >> cmd;
    cin.ignore(100, '\n');
    return tolower(cmd);
}

void executeCmd(char command, list& aList) {
    char key[MAX_LEN];
    Winery obj;
    switch (command) {
        case 'a':
            getWinery(obj);
            if (aList.insert(obj)) {
                cout << endl << "the winery has been saved in the database. " << endl; 
            } else {
                cout << endl << "Failed to add winery to database. " << endl;
            }
            break;
        case 'r':
            getString((char *)"\nPlease enter the name of the winery you want to remove: ", key);
            aList.remove(key);
            cout << endl << key << " has been removed from the database. " << endl;
            break;
        case 's':
            getString((char *)"\nPlease enter the name of the winery you want to search: ", key);
            if (aList.search(key)) {
                cout << endl << "Information about " << key << ": " << endl << '\t' << *aList.retrieve(key) << endl;
            } else {
                cout << "Not Found :(";
            }
            break;
        case 'l':
            display(aList);
            break;
        default: cout << "illegal command!" << endl;
            break;
    }
}

void display(const list& aList) {
    char choice;

    cout << "\n\tn: list ordered by name" << endl
            << "\tr: list ordered by rating" << endl << endl;

    choice = getCommand();
    switch (choice) {
        case 'n': aList.display((true));
            break;
        case 'r': aList.display(false);
            break;
        default:
            cout << "illegal command!" << endl;
            break;
    }
}

int getInt(char * prompt) {
    int temp;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Illegal input -- try again: ";
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}

float getFloat(char * prompt) {
    float temp;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Illegal input -- try again: ";
        cin >> temp;
    }
    cin.ignore(100, '\n');
    return temp;
}

void getString(char * prompt, char * input) {
    cout << prompt;
    cin.get(input, MAX_LEN, '\n');
    cin.ignore(100, '\n');
}

void getWinery(Winery& obj) {
    char name[MAX_LEN];
    char location[MAX_LEN];
    int year;
    float acres;
    float rating;

    cout << "\nPlease enter information about the winery: " << endl;
    getString((char *)"\tname: ", name);
    getString((char *)"\tlocation: ", location);
    year = getInt((char *)"\tyear: ");
    acres = getFloat((char *)"\tacres: ");
    rating = getFloat((char *)"\trating: ");


    obj.setAcre(acres);
    obj.setLocation(location);
    obj.setName(name);
    obj.setRating(rating);
    obj.setYear(year);
}