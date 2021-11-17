/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 6:32 PM
 * Purpose: Inventory Class - Exercise 13.6 - Assignment 5
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "InventoryClass.h"

using namespace std;

int main(int argc, char** argv) {    
    string line;
    int i1 = 0;
    int q1 = 0;
    double c1 = 0.00;
    int control1 = 0;

    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Item Number: ";
        getline(cin, line);
        i1 = stoi(line);
        cin.clear();
        line = "";
        if (i1 < 0) {
            control1 = 0;
            cout << "Value can't be less that 0... Try Again..." << endl;
        }
    }
    control1 = 0;
    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Quantity: ";
        getline(cin, line);
        q1 = stoi(line);
        cin.clear();
        line = "";
        if (q1 < 0) {
            control1 = 0;
            cout << "Value can't be less that 0... Try Again..." << endl;
        }
    }
    control1 = 0;
    while (control1 == 0) {
        control1 = 1;
        cout << "Insert Cost: ";
        getline(cin, line);
        c1 = stod(line);
        cin.clear();
        line = "";
        if (c1 < 0) {
            control1 = 0;
            cout << "Value can't be less that 0... Try Again..." << endl;
        }
    }
    InventoryClass InventoryClass(i1, q1, c1);

    cout << endl << "The Data Inserted for the Item in Inventory is: " << endl;
    cout << endl;
    cout << "Item Number: " << InventoryClass.getItemNumber() << endl;
    cout << "Item Quantity: " << InventoryClass.getQuantity() << endl;
    cout << "Item Cost: " << InventoryClass.getCost() << endl;
    cout << "Item Total: " << InventoryClass.getTotalCost() << endl;
    
    return 0;
}

