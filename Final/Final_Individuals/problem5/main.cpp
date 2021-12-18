/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 17, 2021 at 8:00 AM
 * Purpose: Final - Problem 5
 */
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

int main(int argc, char** argv)
{    
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
    Mark.toString();
    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
    Mary.toString();

    return 0;
}