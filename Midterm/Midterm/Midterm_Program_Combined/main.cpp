/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

#include "Array.h"
#include "Stats.h"

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

//EXERCISE 2 STRUCTURE
struct EmployeesPay {
    string employeeName;
    float hoursWorked;
    float payRate;
};
const int MAXSIZE = 100;
//EXERCISE 2 STRUCTURE

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

//EXERCISE 4
const int MAXSIZE4 = 4;
//EXERCISE 4

//EXERCISE 1
void main1();
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

//EXERCISE 2
void main2();
void printPayStub(EmployeesPay[], int, long, string[], string[]);
string convertToWords(long, string[], string[]);
string numToWords(int, string, string[], string[]);
bool setHoursWorked(int, string);
bool setPayRate(int, string);
int menuExercise2();
//EXERCISE 2

//EXERCISE 8
int mainMenu();
//EXERCISE 8

//EXERCISE 4
void main4();
bool validNumber(string);
int encrypt(string);
int decrypt(string);
void printNumber(int number, int help);
int menuExercise4();
void clearSwap(int[]);
int swapNumbers(int[]);
//EXERCISE 4

//EXERCISE 5
void main5();
int menuExercise5();
//EXERCISE 5

//EXERCISE 6
void main6();
int menuExercise6();
//EXERCISE 6

//EXERCISE 7
void main7();
int menuExercise7();
void primeFactors(int n);
Primes factor(int, int*); //Input an integer, return all prime factors
void prntPrm(Primes*, int*); //Output all prime factors
bool validNumber7(string);
//EXERCISE 7

//EXERCISE 3
//Function Prototypes I supply
Array* fillAry(int, int);        //Fill an array and put into a structure
void prntAry(const Array*, int);//Print the array 
int* copy(const int*, int);     //Copy the array
void mrkSort(int*, int);        //Sort an array
void prtStat(const Stats*);    //Print the structure
void rcvrMem(Array*);          //Recover memory from the Array Structure
void rcvrMem(Stats*);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats* stat(const Array*);     //Find & store mean, median, & modes in structure
void main3();
//EXERCISE 3

//MASTER - MAIN
int main(int argc, char** argv)
{
    int position = -1;
    bool result = true;
    int option1 = 0;
    float balance = 0.00;
    int option2 = 0;

    while (option1 < 9) {

        cout << "\033c";
        option1 = mainMenu();

        switch (option1) {

        case 1:

            main1();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 2:
            main2();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 3:

            main3();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 4:

            main4();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 5:

            main5();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 6:

            main6();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        case 7:

            main7();
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;

        case 8:
            option1 = 9;
            cout << endl;
            cout << "Exiting Software, Bye Bye..." << endl;
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

//EXERCISE #2 - MAIN
void main2() {

    string one[] = { "", "ONE ", "TWO ", "THREE ", "FOUR ",
                 "FIVE ", "SIX ", "SEVEN ", "EIGHT ",
                 "NINE ", "TEN ", "ELEVEN ", "TWELVE ",
                 "THIRTEEN ", "FOURTEEN ", "FIFTEEN ",
                 "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
                 "NINETEEN " };


    string ten[] = { "", "", "TWENTY ", "THIRTY ", "FORTY ",
                     "FIFTY ", "SIXTY ", "SEVENTY ", "EIGHTY ",
                     "NINETY " };

    EmployeesPay* employeespay;
    int option = 0;
    int size = 0;
    int controlcreatearray = 0;
    string semp;
    int controlemp = 0;
    string name;
    bool controlint = true;
    string shours;
    string srate;
    long c1 = 123456458;

    employeespay = new EmployeesPay[MAXSIZE];
    //system("CLS");
    cout << "\033c";
    while (option < 3) {

        option = menuExercise2();

        if (option == 1) {
            if (controlcreatearray == 0) {
                while (controlemp == 0) {
                    cout << endl;
                    cout << "How Many Employees you want to Process?: ";
                    try {
                        getline(cin, semp);
                        size = stoi(semp);
                        controlemp = 1;
                    }
                    catch (exception e) {
                        cout << endl;
                        cout << "Wrong Value.... Try again Please..." << endl;
                    }
                }

                controlcreatearray = 1;
            }
            else {
                cout << endl;
                cout << "Number of Employees Permitted by the System (" << size << " Employees)" << endl;
            }
            for (int x = 0; x < size; x++) {
                cout << endl;
                cout << "\tInsert Name of Employee #" << x + 1 << ": ";
                getline(cin, name);
                employeespay[x].employeeName = name;
                cout << endl;
                cout << "\tInsert Hours Worked for Employee #" << x + 1 << ": ";
                getline(cin, shours);
                controlint = setHoursWorked(x, shours);
                if (controlint == false) {
                    cout << endl;
                    cout << "Wrong Hours Inserted, default Value is 0.00 Hours." << endl;
                    employeespay[x].hoursWorked = 0.00;
                }
                else {
                    employeespay[x].hoursWorked = stof(shours);
                }
                cout << "\tInsert Hourly Rate for Employee #" << x + 1 << ": ";
                getline(cin, srate);
                controlint = setHoursWorked(x, srate);
                if (controlint == false) {
                    cout << endl;
                    cout << "Wrong Hourly Rate Inserted, default Value is $0.00." << endl;
                    employeespay[x].payRate = 0.00;
                }
                else {
                    employeespay[x].payRate = stof(srate);
                }
                cout << endl;
                cout << "**************************************************" << endl;
                cout << "Generating Pay stub..." << endl;
                cout << "**************************************************" << endl;
                cout << endl;
                printPayStub(employeespay, x, c1, one, ten);
                c1 = c1 + 1;
            }
            cout << endl;

            cout << endl;
            cout << "Press Enter to Continue...";
            getchar();
            cout << "Opening Main Menu..." << endl;
            Sleep(4000);
            break;

        }
        else {
            option = 3;
            cout << endl;
            cout << "Opening Main Menu..." << endl;
            break;
        }
    }
}

//EXERCISE #2
void printPayStub(EmployeesPay employeespay[], int position, long c1, string one[], string ten[]) {

    time_t rawtime;
    time(&rawtime);
    time_t t;
    struct tm timeinfo;
    localtime_r(&rawtime, &timeinfo);

    float rate1 = employeespay[position].payRate;
    float rate2 = rate1 * 2;
    float rate3 = rate1 * 3;
    int control = 0;
    float h1 = 0.00;
    float h2 = 0.00;
    float h3 = 0.00;
    float s1 = 0.00;
    float s2 = 0.00;
    float s3 = 0.00;
    float total = 0.00;
    string lname;
    string samount;
    long intp = 0;

    lname = employeespay[position].employeeName;

    if (employeespay[position].hoursWorked <= 40) {
        h1 = employeespay[position].hoursWorked;
        s1 = h1 * rate1;
        control = 1;
    }
    else if (employeespay[position].hoursWorked > 40 && employeespay[position].hoursWorked <= 60) {
        h1 = 40;
        h2 = employeespay[position].hoursWorked - 40;
        s1 = h1 * rate1;
        h2 = h2 * rate2;
        control = 2;
    }
    else {
        h1 = 40;
        h2 = 20;
        h3 = employeespay[position].hoursWorked - 60;
        s1 = h1 * rate1;
        s2 = h2 * rate2;
        s3 = h3 * rate3;
        control = 3;
    }

    total = s1 + s2 + s3;

    intp = (long)total;

    samount = convertToWords(intp, one, ten);

    cout << fixed << setprecision(2);
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << " D/T CARSON ENTERPRISES, INC." << endl;
    cout << " 42882 IVY ST." << endl;
    cout << " (951) 555-5555" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t" << timeinfo.tm_mon + 1 << "/" << timeinfo.tm_mday << "/" << timeinfo.tm_year - 100 << endl;
    cout << endl;
    cout << " " << lname;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << " Pay Rate\t\tHours Worked\t\tAmount" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << " " << rate1 << "\t\t\t" << h1 << "(Regular)" << "\t\t" << s1 << endl;
    if (control > 2) {
        cout << " " << rate2 << "\t\t\t" << h2 << "(Double)" << "\t\t" << s2 << endl;
        cout << " " << rate3 << "\t\t\t" << h3 << "(Triple)" << "\t\t" << s3 << endl;
    }
    else {
        cout << " " << rate2 << "\t\t\t" << h2 << "(Double)" << "\t\t" << s2 << endl;
    }
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << " GROSS INCOME FOR THIS PERIOD: $" << total << " ROUNDED VALUE: $" << intp << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << " CHECK:" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << " D/T CARSON ENTERPRISES, INC." << endl;
    cout << " 42882 IVY ST." << endl;
    cout << " (951) 555-5555\t\t\t\t\t\t" << "DATE: " << timeinfo.tm_mon + 1 << "/" << timeinfo.tm_mday << "/" << timeinfo.tm_year - 100 << endl;
    cout << endl;
    cout << " PAY TO THE ORDER OF: " << lname << "\t\t\tAmount: $" << intp;
    cout << endl;
    cout << " " << samount << "DOLLARS" << endl;
    cout << endl;
    cout << " BANK OF AMERICA" << endl;
    cout << endl;
    cout << " CHECK #" << c1 << "\t\t_________________________________ SIGN" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
}

//EXERCISE #2
string convertToWords(long n, string one[], string ten[])
{
    string out;
    out += numToWords((n / 10000000), "CRORE ", one, ten);
    out += numToWords(((n / 100000) % 100), "LAKH ", one, ten);
    out += numToWords(((n / 1000) % 100), "THOUSAND ", one, ten);
    out += numToWords(((n / 100) % 10), "HUNDRED ", one, ten);
    if (n > 100 && n % 100)
        out += "AND ";
    out += numToWords((n % 100), "", one, ten);
    return out;
}

//EXERCISE #2
string numToWords(int n, string s, string one[], string ten[])
{
    string str = "";
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];
    if (n)
        str += s;
    return str;
}

//EXERCISE #2
bool setHoursWorked(int position, string input) {
    bool result = true;
    float value1 = 0.00;

    try {
        value1 = stof(input);
        if (value1 < 0) {
            result = false;
        }
        else {

        }
    }
    catch (exception e) {
        result = false;
    }

    return result;
}

//EXERCISE #2
bool setPayRate(int position, string input) {
    bool result = true;
    float value1 = 0.00;

    try {
        value1 = stof(input);
        if (value1 < 0) {
            result = false;
        }
        else {

        }
    }
    catch (exception e) {
        result = false;
    }

    return result;
}

//EXERCISE #2
int menuExercise2() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*        ---   Midterm: Exercise 2   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Run Program." << endl;
    cout << "2.- Main Menu." << endl;
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

//EXERCISE #1 - MAIN
void main1() {

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
            cout << "Opening Main Menu..." << endl;
            break;

        default:
            cout << endl;
            cout << "Please Wait..." << endl;
            Sleep(4000);
            break;
        }

    }
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
    cout << "4.- Main Menu." << endl;
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

//EXERCISE #8
int mainMenu() {
    string optionS;
    int optionN = 0;
    stringstream ss;
    int x = 0;

    cout << "**************************************************" << endl;
    cout << "*         ---   Midterm: Main Menu   ---         *" << endl;
    cout << "*         Developed by Domenico Venuti           *" << endl;
    cout << "**************************************************" << endl;
    cout << "* Choose from Menu: *" << endl;
    cout << "*********************" << endl;
    cout << endl;
    cout << "1.- Exercise #1 (Exceeding Checking Account Balance):" << endl;
    cout << "2.- Exercise #2 (Gross Pay and Paystubs):" << endl;
    cout << "3.- Exercise #3 (Mean, Median, Mode):" << endl;
    cout << "4.- Exercise #4 (Encrypt Decrypt):" << endl;
    cout << "5.- Exercise #5 (Larger n! for Each Data Type in C++):" << endl;
    cout << "6.- Exercise #6 (Conversion to NASA 4 bytes Float Point Format):" << endl;
    cout << "7.- Exercise #7 (Prime Numbers):" << endl;
    cout << "8.- Quit." << endl;
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

            if (optionN > 0 && optionN < 9) {
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
void main4() {

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
            cout << "Opening Main Menu...";
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
            cout << "Opening Main Menu...";
            break;
        }
        else {
            option = 3;
            cout << endl;
            cout << "Opening Main Menu...";
            break;
        }
    }
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
    cout << "3.- Main Menu." << endl;
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

//EXERCISE 5
void main5() {

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
            cout << "Opening Main Menu...";
            break;
        }
        else {
            option = 3;
            cout << endl;
            cout << "Opening Main Menu...";
            break;
        }
    }
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
    cout << "2.- Main Menu." << endl;
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

//EXERCISE 6
void main6() {

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
            cout << "Opening Main Menu...";
            break;
        }
        else {
            option = 3;
            cout << endl;
            cout << "Opening Main Menu...";
            break;
        }
    }
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
    cout << "2.- Main Menu." << endl;
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

//*************************************************************************************************************
//Exercise #3

//Execution begins here
void main3() {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array* array;
    string press;

    //Input the size and mod number
    cout << "This program develops an array to be analyzed" << endl;
    cout << "Array size from mod number to 100" << endl;
    cout << "Mod number from 2 to 10" << endl;
    cout << "Input the Array Size and the mod number to be used." << endl;
    cin >> arySize >> modNum;
    cout << endl << endl;

    //Fill the array
    array = fillAry(arySize, modNum);

    //Print the initial array
    cout << "Original Array before sorting" << endl;
    prntAry(array, 10);

    //Sort the array
    mrkSort(array->data, array->size);
    cout << "Sorted Array to be utilize for the stat function" << endl;
    prntAry(array, 10);

    //Calculate some of the statistics
    Stats* stats = stat(array);

    //Print the statistics
    prtStat(stats);

    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);

    //Exit stage right 
    //system("pause");
    cout << endl;
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.clear();
    cin.sync();
    getline(cin, press);
    cout<<endl;
    cout << "Opening Main Menu..." << endl;
    Sleep(4000);
}

int* copy(const int* a, int n) {
    //Declare and allocate an array
    //that is a c
    int* b = new int[n];
    //Fill
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats* ary) {
    cout << endl;
    cout << "The average of the array = " << ary->avg << endl;
    cout << "The median of the array  = " << ary->median << endl;
    cout << "The number of modes      = " <<
        ary->mode->size << endl;
    cout << "The max Frequency        = " <<
        ary->modFreq << endl;
    if (ary->mode->size == 0) {
        cout << "The mode set             = {null}" << endl;
        return;
    }
    cout << "The mode set             = {";
    for (int i = 0; i < ary->mode->size - 1; i++) {
        cout << ary->mode->data[i] << ",";
    }
    cout << ary->mode->data[ary->mode->size - 1] << "}" << endl;
}

void mrkSort(int* array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void rcvrMem(Stats* stats) {
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array* array) {
    delete[]array->data;
    delete array;
}

void prntAry(const Array* array, int perLine) {
    //Output the array
    for (int i = 0; i < array->size; i++) {
        cout << array->data[i] << " ";
        if (i % perLine == (perLine - 1))cout << endl;
    }
    cout << endl;
}

Array* fillAry(int n, int modNum) {
    //Allocate memory
    Array* array = new Array;
    array->size = n;
    array->data = new int[array->size];

    //Fill the array with mod numbers
    for (int i = 0; i < n; i++) {
        array->data[i] = i % modNum;
    }

    //Exit function
    return array;
}

Stats* stat(const Array* array) {
    //Non-working stub to be completed by the student
    cout << endl << "Stat function to be completed by the student" << endl;
    Stats* stats = new Stats;
    stats->mode = new Array;
    int sum = 0;
    float mean = 0.00;

    //MEAN
    for (int x = 0; x < array->size; x++) {
        sum = sum + array->data[x];
    }
    mean = sum / (float)array->size;
    stats->avg = mean;

    //MEDIAN
    float median = 0.00;
    if (array->size % 2 != 0) {
        median = (float)array->data[array->size / 2];
    }
    else {
        median = (float)(array->data[(array->size - 1) / 2] + array->data[array->size / 2]) / 2.0;
    }

    //MODE
    int** maxf = nullptr;
    maxf = new int* [array->size];
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;

    for (a1 = 0; a1 < 2; a1++) {
        maxf[a1] = new int[array->size];
    }

    for (a1 = 0; a1 < 2; a1++) {
        for (b1 = 0; b1 < array->size; b1++) {
            maxf[a1][b1] = -999;
        }
    }

    //Copy the array
    int* ary = copy(array->data, array->size);

    //Sort the copy
    mrkSort(ary, array->size);

    //Find the max Frequency
    int aa = 0;
    for (c1 = 0; c1 < array->size; c1++) {
        if (c1 == 0) {
            maxf[0][aa] = ary[c1];
            maxf[1][aa] = 1;
        }
        else {
            if (ary[c1] == ary[c1 - 1]) {
                maxf[1][aa] = maxf[1][aa] + 1;
            }
            else {
                aa++;
                maxf[0][aa] = ary[c1];
                maxf[1][aa] = 1;
            }
        }
    }
    int f1 = 0;
    for (c1 = 0; c1 < array->size - 1; c1++) {
        if (maxf[0][c1 + 1] != -999) {
            f1 = f1 + 1;
        }
    }

    f1 = f1 + 1;

    //Find the number of modes
    int sum1 = 0;
    int control2 = 0;
    int nmodes = 0;
    int freq = 0;

    freq = maxf[1][0];

    for (int zz = 0; zz < array->size; zz++) {
        if (control2 == 0) {
            if (maxf[1][zz + 1] == maxf[1][zz] && maxf[1][zz + 1] != -999) {
                sum1 = sum1 + 1;
            }
            else {
                sum1 = sum1 + 1;
                control2 = 1;
            }
        }
    }

    nmodes = sum1;

    if (nmodes == f1) {
        nmodes = 0;
    }

    //Allocate the mode array
    int* modeAry = new int[nmodes + 2];

    //Again this is just a stub.        
    if (nmodes == 0) {
        modeAry[0] = 0;//Stub returns no modes
        modeAry[1] = 1;//Stub returns Frequency 1            
    }
    else {
        modeAry[0] = nmodes;
        modeAry[1] = freq;
    }

    //Fill the mode array
    for (int zz3 = 2; zz3 < nmodes + 2; zz3++) {
        modeAry[zz3] = maxf[0][zz3 - 2];
    }

    //ORIGINAL CODE
    stats->mode->size = nmodes;
    int nModes = nmodes;
    if (nModes != 0)stats->mode->data = new int[nModes];
    stats->modFreq = freq;
    stats->median = median;

    for (int zz3 = 2; zz3 < nmodes + 2; zz3++) {
        stats->mode->data[zz3 - 2] = modeAry[zz3];
    }

    return stats;

    //Delete the allocated copy and return
    delete[]ary;
    for (int z4 = 0; z4 < array->size; z4++) {
        delete[]maxf[z4];
    }
    delete[]maxf;
}
//Exercise #3
//*************************************************************************************************************

//EXERCISE 7
void main7() {
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
            cout << "Opening Main Menu...";
            break;
        }
        else {
            option = 3;
            cout << endl;
            cout << "Opening Main Menu...";
            break;
        }
    }
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
    cout << "2.- Main Menu." << endl;
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