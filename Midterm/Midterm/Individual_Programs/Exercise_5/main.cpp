/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE #5

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 5
int menuExercise5();
//EXERCISE 5

//EXERCISE 5
int main(int argc, char** argv) {

    int number;
    int option = 0;
    
    cout << "\033c";
    while (option < 3) {

        option = menuExercise5();

        if (option == 1) {

            cout << endl;
            cout << "***************************************************************************************************************************" << endl;
            cout << "Largest n where n! can be Calculated per Each Primitive Data Type in C++." << endl;
            cout << "***************************************************************************************************************************" << endl;
            cout << "Data type\t\t\tSize(bytes)\tRange\t\t\t\t\t\t\t\tLargest n" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "short int\t\t\t2\t\t-32,768 to 32767\t\t\t\t\t\t7" << endl;
            cout << "unsigned short int\t\t2\t\t0 to 65,535\t\t\t\t\t\t\t8" << endl;
            cout << "unsigned int\t\t\t4\t\t0 to 4,294,967,295\t\t\t\t\t\t12" << endl;
            cout << "int\t\t\t\t4\t\t-2,147,483,648 to 2,147,483,647\t\t\t\t\t12" << endl;
            cout << "long int\t\t\t4\t\t-2,147,483,648 to 2,147,483,647\t\t\t\t\t12" << endl;
            cout << "unsigned long int\t\t8\t\t0 to 4,294,967,295\t\t\t\t\t\t12" << endl;
            cout << "long long int\t\t\t8\t\t-9,223,372,036,854,775,807 to 9,223,372,036,854,775,807\t\t20" << endl;
            cout << "unsigned long long int\t\t8\t\t0 to 18,446,744,073,709,551,615\t\t\t\t\t20" << endl;
            cout << "signed char / signed byte\t1\t\t-128 to 127\t\t\t\t\t\t\t5" << endl;
            cout << "unsigned char / unsigned byte\t1\t\t0 to 255\t\t\t\t\t\t\t5" << endl;
            cout << "float\t\t\t\t4\t\t1.17549e-038 to 3.40282e+038\t\t\t\t\t34" << endl;
            cout << "double\t\t\t\t8\t\t2.22507e-308 to 1.79769e+308\t\t\t\t\t170" << endl;
            cout << "long double\t\t\t12\t\t2.22507e-308 to 1.79769e+308\t\t\t\t\t170" << endl;
            cout << "***************************************************************************************************************************" << endl;
            cout << endl;
            cout << "Press Enter to Continue...";
            getchar();
            cout << endl;
            cout << "Bye Bye...";
            break;
        }
        else {
            option = 3;
            cout << endl;
            cout << "Bye Bye...";
            break;
        }
    }
    return 0;
}

//EXERCISE 5
int menuExercise5() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 5   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Largest n where n! can be Calculated per Each Primitive Data Type in C++." << endl;
    cout << "2.- Exit Program." << endl;
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

            if (optionN > 0 && optionN < 3) {
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