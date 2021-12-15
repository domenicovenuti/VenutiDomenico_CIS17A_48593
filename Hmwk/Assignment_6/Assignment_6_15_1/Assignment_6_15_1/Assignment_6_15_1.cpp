/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 12, 2021 at 7:12 PM
 * Purpose: Chapter 15 Problem 1
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "Employee.h"
#include "ProductionWorker.h"

using namespace std;

int main(int argc, char** argv) {

    string line;
    ProductionWorker pworker;
    string shift;

    cout << "Insert All Info Required for the Worker." << endl;
    cout << endl;
    cout << "Employee Number: ";
    getline(cin, line);
    pworker.setEmployeeNumber(stoi(line));
    cout << "Employee Name: ";
    getline(cin, line);
    pworker.setEmployeeName(line);
    cout << "Hire Date: ";
    getline(cin, line);
    pworker.setHireDate(line);
    cout << "Shift Worked: ";
    getline(cin, line);
    pworker.setShift(stoi(line));
    cout << "Hourly Rate: ";
    getline(cin, line);
    pworker.setHourlyPayRate(stod(line));
    cout << endl;
    cout << "Here are all the Employee Data Saved:" << endl;
    cout << endl;
    cout << "Employee Number: " << pworker.getEmployeeNumber() << endl;
    cout << "Employee Name: " << pworker.getEmployeeName() << endl;
    cout << "Hire Date: " << pworker.getEmployeeHireDate() << endl;
    if (pworker.getShift() == 1) {
        shift = "Day";
    }
    else {
        shift = "Night";
    }
    cout << "Shift Worked: (" << pworker.getShift() << ") - " << shift << endl;
    cout << fixed << setprecision(2) << "Hourly Rate: $" << pworker.getHourlyPayRate() << endl;            

    return 0;
}
