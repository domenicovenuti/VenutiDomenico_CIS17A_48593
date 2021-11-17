/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 10:00 PM
 * Purpose: Day of the Year Modification - Exercise 14.3 - Assignment 5
 */

#include <iostream>
#include <string>
#include "DayOfYear.h"

using namespace std;

int main(int argc, char** argv) {
    string line = "";

    cout << "Insert a Day of the Year: ";
    getline(cin, line);

    DayOfYear DayOfTheYear(stoi(line));

    if (stoi(line) >= 0 && stoi(line) <= 365)
    {
            DayOfTheYear.print();
    }	
    return 0;
}

