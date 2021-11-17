/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 9:28 PM
 * Purpose: NumDays Class and TimeOff Class - Exercise 14.4 and 14.5 - Assignment 5
 */

#include<iostream>
#include<string>
#include "NumDays.h"
#include "TimeOff.h"

using namespace std;

int main(int argc, char** argv) {
    TimeOff TimeOff1("Domenico Venuti", 0001, 30, 6, 16, 26, 19, 3);
    TimeOff1.display();
    cout << endl;
    cout << "************************************************************************" << endl << endl;
    TimeOff TimeOff2;
    TimeOff2.setName("Teresa Venuti");
    TimeOff2.setID(0002);
    TimeOff2.setMaxSickDays(4);
    TimeOff2.setSickTaken(3);
    TimeOff2.setMaxUnpaid(2);
    TimeOff2.setUnpaidTaken(1);
    TimeOff2.setMaxVacation(48);
    TimeOff2.setVacTaken(11);
    TimeOff2.display();
    cout << endl;
    cout << "************************************************************************" << endl << endl;
    TimeOff TimeOff3(3, "Luz Monsalve", 0003, 4, 10, 11, 8);
    TimeOff3.display();
    cout << endl;
    
    return 0;
}

