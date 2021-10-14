/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 13, 2021 at 8:30 PM
 * Purpose: Chapter 12 - Exercise 11 - Corporate Sales Data Output
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip> 

using namespace std;

struct Quarters {
    string divisionName = "";
    float quarter[4] = { 0.00, 0.00, 0.00, 0.00 };
    float quarterlySales = 0.00;
};

float getSaleforQuater();
void saveToFile(string, Quarters[]);

const int MAX_SIZE = 4;
const string filename = "Corporate_Sales_Data_Output.csv";

int main()
{        
    Quarters quarter[MAX_SIZE];
    float sales;    

    cout << "-- Corporate Sales Data Output Program --" << endl; 
    cout << "-----------------------------------------";
    cout << endl;

    for (int x = 0; x < MAX_SIZE; x++) {
        switch (x) {
            case 0:
                sales = 0.00;
                cout << endl;
                cout << "****************************" << endl;
                cout << "Sales for Division East ----" << endl;
                quarter[x].divisionName = "East";
                for (int y = 0; y < MAX_SIZE; y++) {
                    cout << "Insert Sales for Quarter #"<<y + 1<<":" << endl;                    
                    quarter[x].quarter[y] = getSaleforQuater();
                    sales = sales + quarter[x].quarter[y];
                }
                quarter[x].quarterlySales = sales;
                break;
            case 1:
                sales = 0.00;
                cout << endl;
                cout << "****************************" << endl;
                cout << "Sales for Division West ----" << endl;
                quarter[x].divisionName = "West";
                for (int y = 0; y < MAX_SIZE; y++) {
                    cout << "Insert Sales for Quarter #" << y + 1 << ":" << endl;
                    quarter[x].quarter[y] = getSaleforQuater();
                    sales = sales + quarter[x].quarter[y];
                }
                quarter[x].quarterlySales = sales;
                break;
            case 2:
                sales = 0.00;
                cout << endl;
                cout << "****************************" << endl;
                cout << "Sales for Division North ----" << endl;
                quarter[x].divisionName = "North";
                for (int y = 0; y < MAX_SIZE; y++) {
                    cout << "Insert Sales for Quarter #" << y + 1 << ":" << endl;
                    quarter[x].quarter[y] = getSaleforQuater();
                    sales = sales + quarter[x].quarter[y];
                }
                quarter[x].quarterlySales = sales;
                break;      
            default:
                sales = 0.00;
                cout << endl;
                cout << "****************************" << endl;
                cout << "Sales for Division South ----" << endl;
                quarter[x].divisionName = "South";
                for (int y = 0; y < MAX_SIZE; y++) {
                    cout << "Insert Sales for Quarter #" << y + 1 << ":" << endl;
                    quarter[x].quarter[y] = getSaleforQuater();
                    sales = sales + quarter[x].quarter[y];
                }
                quarter[x].quarterlySales = sales;
                break;
        }
    }

    saveToFile(filename, quarter);
    
}

float getSaleforQuater() {
    string line;    
    float number;
    int control1 = 0;

    while (control1 == 0) {
        cout << "Insert Sales: ";
        getline(cin, line); 
        try {
            number = stof(line);                      
            if (number < 0) {
                cout << "Sale can't be Negative... Try Again..." << endl;
            }
            else {

                control1 = 1;
            }
        }
        catch (exception) {
            cout << "Only Numbers are allowed... Try Again..." << endl;
        }
    }
    return number;
}

void saveToFile(string filename, Quarters quarter[]) {
    stringstream ss;
    string line;
    ofstream outFile;

    outFile.open(filename, ios::out);

    if (outFile.is_open()) {
        for (int x = 0; x < MAX_SIZE; x++) {
            ss.str("");
            ss.clear();
            ss.seekg(0);
            ss <<"\"" << quarter[x].divisionName << "\",";
            for (int y = 0; y < MAX_SIZE; y++) {
                ss << fixed << setprecision(2) << quarter[x].quarter[y] << ",";
            }
            ss << fixed << setprecision(2) << quarter[x].quarterlySales;
            line = ss.str();
            outFile << line << endl;
        }
        cout << endl;
        cout << "All Data was Transferred to File Corporate_Sales_Data_Output.csv, you can open this file in Notepad or in Excel." << endl;
    }
    else {
        cout << endl;
        cout << "File was not Found.... Nothing was Transferred...";
    }
    cout << "The End...";
}
