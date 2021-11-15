/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE #1

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 1 STRUCTURE
struct Customer {
    string accountNumber; //Account Numbers are always string because can be too big to be an int, long, longlong, etc....
    string name;
    string address;
    float startbalance;
    vector<float> checks;
    vector<float> deposits;
};
//EXERCISE 1 STRUCTURE

//EXERCISE 1
int chooseCustomer(vector<Customer>&);
int setAccountNumber(vector<Customer>&, string);
bool setStartbalance(vector<Customer>&, int&, string);
bool setChecks(vector<Customer>&, int&, string);
bool setDeposits(vector<Customer>&, int&, string);
float getBalance(vector<Customer>&, int&);
void printCustomer(vector<Customer>&, int&);
int createCustomer(vector<Customer>&, int&);
int menuExercise1();
//EXERCISE 1

//EXERCISE #1 - MAIN
int main(int argc, char** argv) {

    int position = -1;
    bool result = true;
    int option1 = 0;
    float balance = 0.00;
    vector<Customer> customer;
    int option2 = 0;

    while (option1 < 5) {

        cout << "\033c";
        option1 = menuExercise1();

        switch (option1) {

        case 1:
            option1 = createCustomer(customer, position);
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 2:
            if (customer.size() > 0) {
                option2 = chooseCustomer(customer);
                balance = getBalance(customer, option2);
                if (balance < 0) {
                    cout << "This Customer OverDraw the Account, the current Balance is: $" << balance << "\nA Fee of $25 was Applied to the Account for the OverDraw, the New Balance is: $" << balance - 25.00 << endl;
                }
                else {
                    cout << "\tFinal Balance: $" << balance << endl;
                }
            }
            else {
                cout << "No Customer was Registered Yet..." << endl;
            }
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 3:
            if (customer.size() > 0) {
                option2 = chooseCustomer(customer);
                printCustomer(customer, option2);
            }
            else {
                cout << "No Customer was Registered Yet..." << endl;
            }
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(6000);
            break;

        case 4:
            option1 = 5;
            cout << endl;
            cout << "Bye Bye..." << endl;
            break;

        default:
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        }

    }
    
    return 0;
}

//EXERCISE #1
int chooseCustomer(vector<Customer>& customer) {

    int position = 0;
    string option;
    bool control = false;
    int xx = 0;

    cout << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose a Customer *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    for (int x = 0; x < customer.size(); x++) {
        cout << "Customer #" << x + 1 << ": Name: " << customer.at(x).name << " - Account Number: " << customer.at(x).accountNumber << endl;
        xx++;
    }
    cout << endl;
    cout << "**************************************************" << endl;
    while (control == false) {
        cout << ">> ";
        try {
            getline(cin, option);
            position = stoi(option);
            if (position > 0 && position <= xx) {
                control = true;
            }
            else {
                cout << endl;
                cout << "Wrong Option... Try Again..." << endl;
            }
        }
        catch (exception e) {
            cout << endl;
            cout << "Wrong Option... Try Again..." << endl;
        }
    }

    position = position - 1;

    return position;
}

//EXERCISE #1
int setAccountNumber(vector<Customer>& customer, string account) {
    int result = 1;
    int x = 0;

    if (account.length() > 5 || account.length() < 5) {
        result = false;
    }
    else {
        try {
            for (char& c : account) {
                if (c == ' ' && result == 1) {
                    result = 0;
                }
                else if (result == 1 && c != ' ') {

                    if (c >= 48 && c <= 57) {

                    }
                    else {
                        result = 0;
                    }
                }
                else {
                    result = 0;
                }
            }

            if (result == 1) {
                for (int y = 0; y < customer.size(); y++) {
                    if (account == customer.at(y).accountNumber) {
                        result = 2;
                    }
                }
            }
        }
        catch (exception e) {
            result = 0;
        }
    }

    return result;
}

//EXERCISE #1
bool setStartbalance(vector<Customer>& customer, int& position, string balance) {
    bool result = true;
    float value1 = 0.00;

    try {
        value1 = stof(balance);

        customer.at(position).startbalance = value1;
    }
    catch (exception e) {
        result = false;
    }

    return result;
}

//EXERCISE #1
bool setChecks(vector<Customer>& customer, int& position, string check) {
    bool result = true;
    float value1 = 0.00;

    try {
        value1 = stof(check);
        if (value1 < 0) {
            cout << endl;
            cout << "No Negative Numbers Allowed... Try Again..." << endl;
            result = false;
        }
        else {
            customer.at(position).checks.push_back(value1);
        }
    }
    catch (exception e) {
        result = false;
    }

    return result;
}

//EXERCISE #1
bool setDeposits(vector<Customer>& customer, int& position, string deposit) {
    bool result = true;
    float value1 = 0.00;

    try {
        value1 = stof(deposit);

        if (value1 < 0) {
            cout << endl;
            cout << "No Negative Numbers Allowed... Try Again..." << endl;
            result = false;
        }
        else {
            customer.at(position).deposits.push_back(value1);
        }
    }
    catch (exception e) {
        result = false;
    }

    return result;
}

//EXERCISE #1
float getBalance(vector<Customer>& customer, int& position) {
    float balance = 0.00;
    float checks = 0.00;
    float deposits = 0.00;

    if (customer.at(position).checks.size() == 0) {
        checks = 0.00;
    }
    else {
        for (int x = 0; x < customer.at(position).checks.size(); x++) {
            checks = checks + customer.at(position).checks.at(x);
        }
    }

    if (customer.at(position).deposits.size() == 0) {
        deposits = 0.00;
    }
    else {
        for (int x = 0; x < customer.at(position).deposits.size(); x++) {
            deposits = deposits + customer.at(position).deposits.at(x);
        }
    }
    balance = customer.at(position).startbalance + deposits - checks;

    return balance;
}

//EXERCISE #1
void printCustomer(vector<Customer>& customer, int& position) {
    int x = 1;
    float finalbalance = 0.00;

    cout << endl;
    cout << "**************************************************" << endl;
    cout << "* Customer Info *" << endl;
    cout << "*****************" << endl;
    cout << endl;
    cout << "Account Number: " << customer.at(position).accountNumber << endl;
    cout << "Customer's Name: " << customer.at(position).name << endl;
    cout << "Customer's Address : " << customer.at(position).address << endl;
    cout << "Balance at the Beginning of the month: " << customer.at(position).startbalance << endl;
    cout << "Checks Issued: " << endl;
    for (int y = 0; y < customer.at(position).checks.size(); y++) {
        cout << "\tCheck #" << x << " $" << customer.at(position).checks.at(y) << endl;;
        x++;
    }
    x = 0;
    cout << "Deposits Received: " << endl;
    for (int y = 0; y < customer.at(position).deposits.size(); y++) {
        cout << "\tDeposit #" << x << " $" << customer.at(position).deposits.at(y) << endl;;
        x++;
    }

    finalbalance = getBalance(customer, position);

    if (finalbalance < 0) {
        cout << "This Customer OverDraw the Account, the current Balance is: $" << finalbalance << "\nA Fee of $25 was Applied to the Account for the OverDraw, the New Balance is: $" << finalbalance - 25.00 << endl;
    }
    else {
        cout << "\tFinal Balance: $" << finalbalance << endl;
    }

}

//EXERCISE #1
int createCustomer(vector<Customer>& customer, int& position) {
    int result = 0;
    string account;
    string name;
    string address;
    float startBalance = 0.00;
    string sbalance;
    float checks = 0.00;
    string schecks;
    float deposits = 0.00;
    string sdeposits;
    bool balancecontrol = false;
    bool tcontrol = false;
    cout << endl;
    cout << "**************************************************" << endl;
    cout << "Insert the Account Number (Only 5 Numeric Digits are Allowed): ";
    try {
        getline(cin, account);
        result = setAccountNumber(customer, account);
        if (result == 1) {
            cout << "Insert Customer's Name: ";
            getline(cin, name);
            cout << "Insert Customer's Address: ";
            getline(cin, address);
            customer.push_back({ account, name, address });
            position++;
            while (balancecontrol == false) {
                cout << "Insert Balance at the beginning of the Month: ";
                getline(cin, sbalance);
                balancecontrol = setStartbalance(customer, position, sbalance);
            }
            startBalance = stof(sbalance);
            customer.at(position).startbalance = startBalance;
            while (tcontrol == false) {
                cout << "Insert Amount of Check Issued (Type 'finish' to end the Input of Checks): ";
                getline(cin, schecks);
                if (schecks != "finish") {
                    tcontrol = setChecks(customer, position, schecks);
                    tcontrol = false;
                }
                else {
                    tcontrol = true;
                }
            }
            tcontrol = false;
            while (tcontrol == false) {
                cout << "Insert Amount of Deposit Received (Type 'finish' to end the Input of Deposits): ";
                getline(cin, sdeposits);
                if (sdeposits != "finish") {
                    tcontrol = setDeposits(customer, position, sdeposits);
                    tcontrol = false;
                }
                else {
                    tcontrol = true;
                }
            }
            cout << endl;
            cout << "Customer Created successfully..." << endl;

        }
        else if (result == 2) {
            cout << "You Can't Create this Account Number because is Duplicated..." << endl;
        }
        else {
            cout << "Wrong Account Number.... Only 5 Numeric Digits are Allowed (e.g. 12345)" << endl;
        }
    }
    catch (exception e) {
        cout << "An Error was Found.... Check with IT and Try Again..." << endl;
    }

    return result;
}

//EXERCISE #1
int menuExercise1() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 1   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Create a Customer." << endl;
    cout << "2.- Print Customer's Balance." << endl;
    cout << "3.- Print All Customer's Info." << endl;
    cout << "4.- Exit Program." << endl;
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

            if (optionN > 0 && optionN < 5) {
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