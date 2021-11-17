/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 15, 2021 at 7:00 PM
 * Purpose: RetailItem Class - Exercise 13.5 - Assignment 5
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "RetailItem.h"

using namespace std;

RetailItem::RetailItem(string desc, int units, double p1) {
    description = desc;
    unitsOnHand = units;
    price = p1;
}

void RetailItem::setDescription(string desc) {
    description = desc;
}

void RetailItem::setUnitOnHand(int units) {
    unitsOnHand = units;
}

void RetailItem::setPrice(double p1) {
    price = p1;
}

string RetailItem::getDescription() const{
    return description;
}

int RetailItem::getUnitOnHand() const{
    return unitsOnHand;
}

double RetailItem::getPrice() const{
    return price;
}

int main(int argc, char** argv) {
    RetailItem RetailItem1("Jacket",12,59.95);
    RetailItem RetailItem2("Designer Jeans",40,34.95);
    RetailItem RetailItem3("Shirt",20,24.95);

    cout << "Tablet with the 3 Objects Data:" << endl << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\t\tUnits"<<endl;
    cout << "\t\tDescription\t\tOn Hand\t\tPrice" << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "Item #1\t\t" << RetailItem1.getDescription() << "\t\t\t" << RetailItem1.getUnitOnHand() << "\t\t" << RetailItem1.getPrice() << endl;
    cout << "Item #1\t\t" << RetailItem2.getDescription() << "\t\t" << RetailItem2.getUnitOnHand() << "\t\t" << RetailItem2.getPrice() << endl;
    cout << "Item #1\t\t" << RetailItem3.getDescription() << "\t\t\t" << RetailItem3.getUnitOnHand() << "\t\t" << RetailItem3.getPrice() << endl;
    cout << "_________________________________________________________________________________________________" << endl;
    return 0;
}

