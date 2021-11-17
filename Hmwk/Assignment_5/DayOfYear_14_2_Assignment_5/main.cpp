/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 8:49 PM
 * Purpose: Day Of Year - Exercise 14.2 - Assignment 5
 */

#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>

using namespace std;

class DayOfYear
{
private:
    int day;
    static string months[];
public:    
    DayOfYear(int day1) {
        day = day1;
    }
    void print(void)
    {        
        if (day < 1) {
            cout << endl;
            cout << "Wrong Day...";
        }

        else if (day >= 1 && day <= 31)
        {
            cout << endl;
            cout << "January" << " " << (day) << endl;
        }

        else if (day >= 32 && day <= 59)
        {
            cout << "February" << " " << (day - 31) << endl;
        }

        else if (day >= 60 && day <= 90)
        {
            cout << "March" << " " << (day - 59) << endl;
        }

        else if (day >= 91 && day <= 120)
        {
            cout << "April" << " " << (day - 90) << endl;
        }

        else if (day >= 121 && day <= 151)
        {
            cout << "May" << " " << (day - 120) << endl;
        }

        else if (day >= 152 && day <= 181)
        {
            cout << "June" << " " << (day - 151) << endl;
        }

        else if (day >= 182 && day <= 212)
        {
            cout << "July" << " " << (day - 181) << endl;
        }

        else if (day >= 213 && day <= 243)
        {
            cout << "August" << " " << (day - 212) << endl;
        }

        else if (day >= 244 && day <= 273)
        {
            cout << "September" << " " << (day - 243) << endl;
        }

        else if (day >= 274 && day <= 304)
        {
            cout << "October" << " " << (day - 273) << endl;
        }

        else if (day >= 305 && day <= 334)
        {
            cout << "November" << " " << (day - 304) << endl;
        }

        else if (day >= 335 && day <= 365)
        {
            cout << "December" << " " << (day - 334) << endl;
        }
        else {
            cout << endl;
            cout << "Wrong Day...";
        }
    }
};

string DayOfYear::months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "Decemeber" };

int main(int argc, char** argv) {
    string line = "";
    
    cout << "Insert Day of the Year: ";
    getline(cin, line);
    DayOfYear DayOfYear(stoi(line));
    DayOfYear.print();
    cin.clear();
    line = "";
    return 0;
}

