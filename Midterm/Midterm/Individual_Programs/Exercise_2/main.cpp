/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE 2

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

using namespace std;

//EXERCISE 2 STRUCTURE
struct EmployeesPay {
    string employeeName;
    float hoursWorked;
    float payRate;
};
const int MAXSIZE = 100;
//EXERCISE 2 STRUCTURE

//EXERCISE 2
void printPayStub(EmployeesPay[], int, long, string[], string[]);
string convertToWords(long, string[], string[]);
string numToWords(int, string, string[], string[]);
bool setHoursWorked(int, string);
bool setPayRate(int, string);
int menuExercise2();
//EXERCISE 2

//EXERCISE #2 - MAIN
int main(int argc, char** argv) {

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
            cout << "All Done... Bye Bye..." << endl;
            Sleep(4000);
            break;

        }
        else {
            option = 3;
            cout << endl;
            cout << "Bye Bye..." << endl;
            break;
        }
    }
    
    return 0;
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