/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 17, 2021 at 12:00 PM
 * Purpose: Final - Problem 4
 */
#include <iostream>
#include <string>
#include "SavingsAccount.h"

using namespace std;

int main(int argc, char** argv)
{
    SavingsAccount mine(-300);    
    for (int i = 1; i <= 10; i++) {
        mine.Transaction((float)(rand() % 500) * (rand() % 3 - 1));
    }   
    mine.toString();    
        cout << "Balance after 7 years given 10% interest = " << mine.Total((float)(0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = " << mine.TotalRecursive((float)(0.10), 7) << " Recursive Calculation " << endl;

    return 0;
}