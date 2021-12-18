/*
* File: main.cpp
* Author: Domenico Venuti
* Created on December 17, 2021 at 9:20 PM
* Purpose: Final - CIS-17A - C++ Objects
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

int mainMenu() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*         ---   Final: Main Menu   ---           *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Exercise #1 (Random Sequence):" << endl;
    cout << "2.- Exercise #2 (All Kinds of Sorting) - DIDN'T FINISH:" << endl;
    cout << "3.- Exercise #3 (Spreadsheet Stu):" << endl;
    cout << "4.- Exercise #4 (Savings Account Class):" << endl;
    cout << "5.- Exercise #5 (Employee Class):" << endl;
    cout << "6.- Exercise #6 (Conversions):" << endl;
    cout << "7.- Quit." << endl;
    cout << endl;
    cout << "**************************************************" << endl;
    while (x == 0) {
        try {
            cout << ">> ";
            getline(cin, optionS);
            ss << optionS;
            ss >> optionN;

            ss.str("");
            ss.clear();
            ss.seekg(0);

            if (optionN > 0 && optionN < 8) {
                x = 1;
            }
            else {
                cout << "Wrong Option, please, try again..." << endl;
            }
        }
        catch (exception e) {
            cout << "Wrong Option, please, try again..." << endl;
        }
    }

    return optionN;
}

int main(int argc, char** argv) {
    int n = mainMenu();
    cout << "Option: " << n;
    return 0;
}

