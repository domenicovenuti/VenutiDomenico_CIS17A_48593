/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE #4

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 4
const int MAXSIZE4 = 4;
//EXERCISE 4

//EXERCISE 4
bool validNumber(string);
int encrypt(string);
int decrypt(string);
void printNumber(int number, int help);
int menuExercise4();
void clearSwap(int[]);
int swapNumbers(int[]);
//EXERCISE 4

//EXERCISE 4
int main(int argc, char** argv) {

    int swap[MAXSIZE4] = { 0,0,0,0 };
    int option = 0;
    bool control = true;
    string read;
    stringstream ss, s2, s3;
    string character, char2;
    int control2 = 0;
    int x = 0;
    int encryptedN = 0;

    cout << "\033c";
    while (option < 3) {

        option = menuExercise4();

        if (option == 1) {

            clearSwap(swap);

            while (control == true) {
                cout << endl;
                cout << "Insert Number to Encrypt: ";
                getline(cin, read);
                if (read.length() > 4) {
                    cout << endl;
                    cout << "Max 4 Digits are Allowed... Please, Try Again..." << endl;
                    control2++;
                }
                else {
                    for (char& c : read) {
                        if (control == true) {
                            if (c == ' ') {
                                control2++;
                            }
                            else {
                                ss << c;
                                ss >> character;

                                control = validNumber(character);
                                if (control == false) {
                                    control2++;
                                }
                                else {
                                    s2 << encrypt(character);
                                }
                                ss.str("");
                                ss.clear();
                                ss.seekg(0);
                            }
                        }
                    }
                }
                if (control2 == 0) {
                    s2 >> char2;
                    for (char& c : char2) {
                        s3 << c;
                        s3 >> swap[x];
                        s3.str("");
                        s3.clear();
                        s3.seekg(0);
                        x++;
                    }

                    encryptedN = swapNumbers(swap);

                    printNumber(encryptedN, 1);

                    x = 0;
                    control = false;
                }
                else {
                    control = true;
                    control2 = 0;
                }
                s2.str("");
                s2.clear();
                s2.seekg(0);

            }

            cout << endl;
            cout << "Press Enter to Continue...";
            getchar();
            cout << endl;
            cout << "Bye Bye...";
            break;
        }
        else if (option == 2) {
            clearSwap(swap);

            while (control == true) {
                cout << endl;
                cout << "Insert Number to Decrypt: ";
                getline(cin, read);
                if (read.length() > 4) {
                    cout << endl;
                    cout << "Max 4 Digits are Allowed... Please, Try Again..." << endl;
                    control2++;
                }
                else {
                    for (char& c : read) {
                        if (control == true) {
                            if (c == ' ') {
                                control2++;
                            }
                            else {
                                ss << c;
                                ss >> character;

                                control = validNumber(character);
                                if (control == false) {
                                    control2++;
                                }
                                else {
                                    s2 << decrypt(character);
                                }
                                ss.str("");
                                ss.clear();
                                ss.seekg(0);
                            }
                        }
                    }
                }
                if (control2 == 0) {
                    s2 >> char2;
                    for (char& c : char2) {
                        s3 << c;
                        s3 >> swap[x];
                        s3.str("");
                        s3.clear();
                        s3.seekg(0);
                        x++;
                    }

                    encryptedN = swapNumbers(swap);

                    printNumber(encryptedN, 2);

                    x = 0;
                    control = false;
                }
                else {
                    control = true;
                    control2 = 0;
                }
                s2.str("");
                s2.clear();
                s2.seekg(0);

            }

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

//EXERCISE 4
void clearSwap(int swap[]) {
    for (int x = 0; x < MAXSIZE4; x++) {
        swap[x] = 0;
    }
}

//EXERCISE 4
int swapNumbers(int swap[]) {
    int number = 0;
    stringstream ss;
    int help = 0;

    help = swap[0];
    swap[0] = swap[2];
    swap[2] = help;

    help = swap[1];
    swap[1] = swap[3];
    swap[3] = help;

    for (int x = 0; x < MAXSIZE4; x++) {
        ss << swap[x];
    }

    ss >> number;

    return number;
}

//EXERCISE 4
int menuExercise4() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 4   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Encrypt Number." << endl;
    cout << "2.- Decrypt Number." << endl;
    cout << "3.- Exit Program." << endl;
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

            if (optionN > 0 && optionN < 4) {
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

//EXERCISE 4
bool validNumber(string number) {
    bool result = true;
    int value1 = 0;

    try {
        value1 = stoi(number);
        if (value1 < 0 || value1 > 7) {
            cout << endl;
            cout << "Wrong Number entered... Please, try Again..." << endl;
            result = false;
        }
        else {

        }
    }
    catch (exception e) {
        cout << endl;
        cout << "Wrong Number entered... Please, try Again..." << endl;
        result = false;
    }

    return result;
}

//EXERCISE 4
int encrypt(string character) {
    int x = stoi(character);

    x = x + 3;

    x = x % 8;

    return x;
}

//EXERCISE 4
int decrypt(string character) {
    int x = stoi(character);

    switch (x) {
    case 0:
        x = 5;
        break;
    case 1:
        x = 6;
        break;
    case 2:
        x = 7;
        break;
    case 3:
        x = 0;
        break;
    case 4:
        x = 1;
        break;
    case 5:
        x = 2;
        break;
    case 6:
        x = 3;
        break;
    case 7:
        x = 4;
        break;
    default:
        break;
    }

    return x;
}

//EXERCISE 4
void printNumber(int number, int help) {
    cout << endl;
    if (help == 1) {
        cout << "The Encrypted Number is: " << number << endl;
    }
    else {
        cout << "The Decrypted Number is: " << number << endl;
    }
}