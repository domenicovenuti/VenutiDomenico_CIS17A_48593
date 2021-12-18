/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 16, 2021 at 9:28 PM
 * Purpose: Final - All Problems Merged
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

#include <iostream>
#include "Prob1Random.h"
#include "Prob3Table.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"

using namespace std;

void problem4(){
    SavingsAccount mine(-300);    
    for (int i = 1; i <= 10; i++) {
        mine.Transaction((float)(rand() % 500) * (rand() % 3 - 1));
    }   
    mine.toString();    
        cout << "Balance after 7 years given 10% interest = " << mine.Total((float)(0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = " << mine.TotalRecursive((float)(0.10), 7) << " Recursive Calculation " << endl;
}

void problem5(){
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
}

void problem3()
{	
	cout << "Entering problem number 3" << endl;
	int rows = 5;
	int cols = 6;		
	Prob3TableInherited<int> tab("Problem3.txt", rows, cols);	//CHANGED TO MAKE IT WORK BY DVENUTI
	const int* naugT = tab.getTable();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << naugT[i * cols + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	const int* augT = tab.getAugTable();
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << augT[i * cols + j] << " ";
		}
		cout << endl;
	}
	
}

void problem1()
{
	char n = 5;
	char rndseq[] = { 29,34,57,89,126 };
	int ntimes = 100000;
	Prob1Random a(n, rndseq);
	for (int i = 1; i <= ntimes; i++) {
		a.randFromSet();
	}
	int* x = a.getFreq();
	char* y = a.getSet();
	for (int i = 0; i < n; i++) {
		cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
	}
	cout << "The total number of random numbers is " << a.getNumRand() << endl;	    
}

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
    int option = 1;
    
    while(option < 7){
        cout << "OPENING MAIN MENU..." << endl;
        cout << endl;
        option = mainMenu();
        switch(option){
            case 1:
                cout << endl;
                cout << "Problem 1:" << endl << endl;
                problem1();
                cout << endl;
                //mainMenu();
                break;
            case 2:
                cout << endl;
                cout << "Problem 2:" << endl << endl;
                cout << "I Apologize... I didn't Finish this Problem..." << endl;
                cout << endl;
                //mainMenu();
                break;
            case 3:cout << endl;
                cout << "Problem 3:" << endl << endl;
                problem3();
                cout << endl;
                //mainMenu();
                break;
            case 4:
                cout << endl;
                cout << "Problem 4:" << endl << endl;
                problem4();
                cout << endl;
                //mainMenu();
                break;
            case 5:
                cout << endl;
                cout << "Problem 5:" << endl << endl;
                problem5();
                cout << endl;
                //mainMenu();
                break;
            case 6:
                cout << endl;
                cout << "Problem 6:" << endl << endl;
                cout << "I Apologize... I didn't Finish this Problem..." << endl;
                cout << endl;
                //mainMenu();
                break;
            case 7:
                cout << endl;
                cout << "Exiting Software, Bye Bye..." << endl;
                break;
        }    
    }
    return 0;
}

