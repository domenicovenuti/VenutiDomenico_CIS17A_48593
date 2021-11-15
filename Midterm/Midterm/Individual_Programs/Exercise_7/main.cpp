/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE #7

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 7 STRUCTURE
struct Prime {
    int prime;
    int power;
};
struct Primes {
    int nPrimes;
    Prime* prime;
};
//EXERCISE 7 STRUCTURE

//EXERCISE 7
int menuExercise7();
void primeFactors(int n);
Primes factor(int, int*); //Input an integer, return all prime factors
void prntPrm(Primes*, int*); //Output all prime factors
bool validNumber7(string);
//EXERCISE 7

//EXERCISE 7
int main(int argc, char** argv) {
    int number;
    int option = 0;
    int size = 0;
    bool control = false;
    string read;
    int value1 = 0;
    
    Prime numsPrime[999];
    Primes primeTFind = {0};    

    primeTFind.prime = numsPrime;    

    cout << "\033c";
    while (option < 3) {

        option = menuExercise7();

        if (option == 1) {            
            
            while (control == false) {
                cout << endl;
                cout << "Insert Number to Find the Prime Factors [Min 2 , Max 65000]: ";
                getline(cin, read);
                if (read.length() > 5) {
                    cout << "Max Value Allowed if 65000... Please, Try Again..." << endl;
                    control = validNumber7("a");
                }
                control = validNumber7(read);
            }
            
            value1 = stoi(read);

            primeTFind = factor(value1, &size);

            prntPrm(&primeTFind, &size);

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

//EXERCISE 7
int menuExercise7() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 7   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Find Prime Factors for a Number between 2 and 65000." << endl;
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

//EXERCISE 7
Primes factor(int n, int *size)
{
    int x = 0;
    int count = 0;

    Prime numsPrime[999];    
    Primes prime = { n };

    prime.prime = numsPrime;
        
    while (n % 2 == 0)
    {
        count++;    
        n = n / 2;
    }

    if (count > 0) {
        prime.prime[x].prime = 2;
        prime.prime[x].power = count;        
        x++;
    }
        
    count = 0;    
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {        
        while (n % i == 0)
        {   
            
            count++;     
            n = n / i;
        }
        if (count > 0) {
            prime.prime[x].prime = i;
            prime.prime[x].power = count;
            x++;
        }
        count = 0;
    }    
    count = 0;    
    if (n > 2) {
        prime.prime[x].prime = n;
        prime.prime[x].power = 1;
        x++;        
    }    
    
    *size = x;

    return prime;
}

//EXERCISE 7
void prntPrm(Primes* primeTFind, int *size) {    
    cout << endl;
    cout << "Prime Factors for Number " << primeTFind->nPrimes << " Are:" << endl;
    cout << endl;
    for (int x = 0; x < *size; x++) {
        cout << primeTFind->prime[x].prime << "^" << primeTFind->prime[x].power;
        if (x < *size - 1) {
            cout<< " * ";
        }
    }
}

//EXERCISE 7
bool validNumber7(string number) {
    bool result = true;
    int value1 = 0;

    try {
        value1 = stoi(number);
        if (value1 < 2 || value1 > 65000) {
            cout << "Min Value Allowed is 2 and Max Value Allowed is 65000... Please, try Again..." << endl;
            result = false;
        }
    }
    catch (exception e) {
        cout << endl;
        cout << "Wrong Number entered... Please, try Again..." << endl;
        result = false;
    }

    return result;
}
//EXERCISE 7