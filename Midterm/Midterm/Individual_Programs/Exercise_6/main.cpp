/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE #6

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 6
void main6();
int menuExercise6();
//EXERCISE 6

//EXERCISE 6
int main(int argc, char** argv) {

    int number;
    int option = 0;
    
    cout << "\033c";
    while (option < 3) {

        option = menuExercise6();

        if (option == 1) {

            cout << endl;
            cout << "Course: CIS-17A" << endl;
            cout << "Section: 48593" << endl;
            cout << "Student: Domenico Venuti" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << "Exercise #6: (Convert to NASA Float Point Format IEEE 754)" << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "a) 49.1875(Base10) to Hex is Equal to 31.3(Base 16)" << endl;
            cout << "   49.1875(Base10) to Octal is Equal to 61.14(Base 8)" << endl;
            cout << "   49.1875(Base10) to NASA 32 Bits Single Precision is Equal to 0(+Sign) 10000100(Exp 2^5) 10001001100000000000000(Mantissa)" << endl;
            cout << "   NASA FORMAT: 0 10000100 10001001100000000000000 = 0x4244C000(NASA)" << endl;
            cout << "   NASA FORMAT NEGATIVE: 1 10000100 10001001100000000000000 = 0xC244C000(NASA)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "b) 3.07421875(Base10) to Hex is Equal to 3.13(Base 16)" << endl;
            cout << "   3.07421875(Base10) to Octal is Equal to 3.046(Base 8)" << endl;
            cout << "   3.07421875(Base10) to NASA 32 Bits Single Precision is Equal to 0(+Sign) 10000000(Exp 2^5) 10001001100000000000000(Mantissa)" << endl;
            cout << "   NASA FORMAT: 0 10000000 10001001100000000000000 = 0x4044C000(NASA)" << endl;
            cout << "   NASA FORMAT NEGATIVE: 1 10000000 10001001100000000000000 = 0xC044C000(NASA)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "c) 0.2(Base10) to Hex is Equal to 0.33333......333(Base 16)" << endl;
            cout << "   0.2(Base10) to Octal is Equal to 0.14631463...1463(Base 8)" << endl;
            cout << "   0.2(Base10) to NASA 32 Bits Single Precision is Equal to 0(+Sign) 01111100(Exp 2^5) 10011001100110011001100(Mantissa)" << endl;
            cout << "   NASA FORMAT: 0 01111100 10011001100110011001100 = 0x3E4CCCCD(NASA)" << endl;
            cout << "   NASA FORMAT NEGATIVE: 1 01111100 10011001100110011001100 = 0xBE4CCCCD(NASA)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "d) 69999902(NASA) to Binary is Equal to 011.010011001100110011001(Base 2)" << endl;
            cout << "   69999902(NASA) to Hex is Equal to 3.4CCCCC(Base 16)" << endl;
            cout << "   69999902(NASA) to Octal is Equal to 3.2314631(Base 8)" << endl;
            cout << "   69999902(NASA) to Decimal is Equal to 3.29999971389(Base 10)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "e) 69999903(NASA) to Binary is Equal to 0110.100110011001100110010(Base 2)" << endl;
            cout << "   69999903(NASA) to Hex is Equal to 6.99999(Base 16)" << endl;
            cout << "   69999903(NASA) to Octal is Equal to 6.4631463(Base 8)" << endl;
            cout << "   69999903(NASA) to Decimal is Equal to 6.5999999(Base 10)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;
            cout << endl;
            cout << "f) 966667FF(NASA) to Binary is Equal to 0100101100110011.00110011111111111(Base 2)" << endl;
            cout << "   966667FF(NASA) to Hex is Equal to 4B33.33FF(Base 16)" << endl;
            cout << "   966667FF(NASA) to Octal is Equal to 45463.147776(Base 8)" << endl;
            cout << "   966667FF(NASA) to Decimal is Equal to 19251.203117370605(Base 10)" << endl;
            cout << endl;
            cout << "************************************************************" << endl;

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

//EXERCISE 6
int menuExercise6() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 6   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Show all the Conversions Binary, Hexadecimal, Octal, NASA Float Point Format." << endl;
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