/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 8:29 PM
 * Purpose: Numbers Class - Exercise 14.1 - Assignment 5
 */
#include <iostream>
#include <string>
#include "NumbersClass.h"

using namespace std;

int main(int argc, char** argv) {

    int number;

    cout << "Enter a number from 0 to 9999: ";
    cin >> number;		

    NumbersClass NumbersClass(number);

    if (number >= 0 && number <= 9999)
    {
            NumbersClass.print();
    }

    return 0;
}

