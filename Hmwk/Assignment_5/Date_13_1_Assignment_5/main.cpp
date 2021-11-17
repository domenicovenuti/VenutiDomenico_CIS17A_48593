/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 6:12 PM
 * Purpose: Date - Exercise 13.3 - Assignment 5
 */

#include <iostream>
#include "Date.h"

using namespace std;

int main(int argc, char** argv) {
    Date date;
    string text1 = "";
    int value;
    int control1 = 0;

    cout << "****************************************" << endl;
    cout << "Show Dates in Different Formats Program:" << endl;
    cout << "****************************************" << endl;
    cout << endl;    
    //Set Month
    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Month Number (Between 1 - 12):" << endl;
        cout << "-> ";
        getline(cin, text1);
        cin.clear();
        cin.sync();
        try {
            if (text1.length() > 0 && stoi(text1)) {
                value = stoi(text1);
                if (value > 0 && value < 13) {
                    date.setMonth(value);
                }
                else {
                    cout << endl;
                    cout << "Month can't be less than 1 or greater than 12... Try Again..." << endl;
                    control1 = 0;
                }
            }
            else {
                control1 = 0;
            }
        }
        catch (exception e) {
            cout << endl;
            cout << "Only Numbers are Allowed... Try Again..." << endl;
            control1 = 0;
        }
        text1 = "";
    }
    control1 = 0;
    //Set Day
    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Day Number (Between 1 - 31):" << endl;
        cout << "-> ";
        getline(cin, text1);
        cin.clear();
        cin.sync();
        try {
            if (text1.length() > 0 && stoi(text1)) {
                value = stoi(text1);
                if (value > 0 && value < 32) {
                    date.setDay(value);
                }
                else {
                    cout << endl;
                    cout << "Day can't be less than 1 or greater than 31... Try Again..." << endl;
                    control1 = 0;
                }
            }
            else {
                control1 = 0;
            }
        }
        catch (exception e) {
            cout << endl;
            cout << "Only Numbers are Allowed... Try Again..." << endl;
            control1 = 0;
        }
        text1 = "";
    }
    control1 = 0;
    //Set Year
    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Year Number:" << endl;
        cout << "-> ";
        getline(cin, text1);
        cin.clear();
        cin.sync();
        try {
            if (text1.length() > 0 && stoi(text1)) {
                value = stoi(text1);
                if (value > 0) {
                    date.setYear(value);
                }
                else {
                    cout << endl;
                    cout << "Year can't be less than 1... Try Again..." << endl;
                    control1 = 0;
                }
            }    
            else {
                control1 = 0;
            }
        }
        catch (exception e) {
            cout << endl;
            cout << "Only Numbers are Allowed... Try Again..." << endl;
            control1 = 0;
        }
        text1 = "";
    }
    control1 = 0;
    //Dates Menu
    while (control1 == 0) {
        control1 = 1;
        cout << endl;
        cout << "How Do you Want your Date?:" << endl;
        cout << "1. 12/25/2014" << endl;
        cout << "2. December 25, 2014" << endl;
        cout << "3. 25 December 2014" << endl;
        cout << "-> ";
        getline(cin, text1);
        cin.clear();
        cin.sync();
        try {
            if (text1.length() > 0 && stoi(text1)) {
                value = stoi(text1);
                if (value > 0 && value < 4) {
                    switch (value)
                    {
                    case 1:
                        cout << endl;
                        cout << "The Date's Format Requested is: " << date.getDateN() << endl << endl;
                        cout << "The End.";
                        break;
                    case 2:
                        cout << endl;
                        cout << "The Date's Format Requested is: " << date.getDateT1() << endl << endl;
                        cout << "The End.";
                        break;
                    default:
                        cout << endl;
                        cout << "The Date's Format Requested is: " << date.getDateT2() << endl << endl;
                        cout << "The End.";
                        break;
                    }
                }
                else {
                    cout << endl;
                    cout << "Wrong Option... Try Again..." << endl;
                    control1 = 0;
                }
            }
            else {
                control1 = 0;
            }
        }
        catch (exception e) {
            cout << endl;
            cout << "Only Numbers are Allowed... Try Again..." << endl;
            control1 = 0;
        }
    }
    return 0;
}

