/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 6, 2021 at 7:37 PM
 * Purpose: Ga9EdC11P5 - Exercise 2 - Code-E
 */

 //System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include <iomanip>
#include <vector>
#include <sstream>

//Global Constants - No Global Variables

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structures
struct WeatherStatistics {    
    float traingfall;
    float hightemp;
    float lowtemp;
    float averagetemp;
};

enum Months { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

//Function Prototypes
int getData(WeatherStatistics[], Months);
void displayData(WeatherStatistics[], float[], int);
void sortAndAverage(WeatherStatistics[], float[], int, Months);
int lastm;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    WeatherStatistics weather[12];
    float average[2] = { 0.00,0.00 };
    Months month = Months::JANUARY;

    //Process or map Inputs to Outputs                 
    lastm = getData(weather, month);

    sortAndAverage(weather, average, lastm, month);

    //display results
    displayData(weather, average, lastm);

    //Exit stage right!
    return 0;
}

void displayData(WeatherStatistics weather1[], float average[], int lastm) {
    cout << fixed << setprecision(2) << "Average monthly rainfall:" << average[0] << endl;
    cout << fixed << setprecision(0) << "High Temp:" << weather1[lastm].hightemp << endl;
    cout << fixed << setprecision(0) << "Low Temp:" << weather1[0].lowtemp << endl;
    cout << fixed << setprecision(1) << "Average Temp:" << average[1];
}

int getData(WeatherStatistics weather1[], Months month1) {
    
    stringstream text1;
    string s;
    string b;
    float b2 = 0.00;
    int p = 0;
    int z = 0;

    std::getline(cin, s);

    for (char c : s) {
        if (c == ' ') {
            if (p > 0) {
                if (z == 0) {
                    text1 >> b2;
                    weather1[month1].traingfall = b2;
                    text1.str("");
                    text1.clear();
                    text1.seekg(0);
                    b2 = 0.00;
                    z++;
                    p = 0;
                }
                else if (z == 1) {
                    text1 >> b2;
                    weather1[month1].hightemp = b2;
                    text1.str("");
                    text1.clear();
                    text1.seekg(0);
                    b2 = 0.00;
                    z++;
                    p = 0;
                }
                else if (z == 2) {
                    text1 >> b2;
                    weather1[month1].lowtemp = b2;
                    text1.str("");
                    text1.clear();
                    text1.seekg(0);
                    weather1[month1].averagetemp = (weather1[month1].lowtemp + weather1[month1].hightemp) / 2;
                    if (weather1[month1].lowtemp < -100 || weather1[month1].lowtemp > 140 || weather1[month1].hightemp < -100 || weather1[month1].hightemp > 140) {
                        cout << "Range of Temperatures Allowed is between -100 to +140 Degrees Fahrenheit. Insert Data for this Month again...)" << endl;
                        month1 = static_cast<Months>(month1 - 1);
                    }
                    month1 = static_cast<Months>(month1 + 1);
                    cout << "Enter the total rainfall for the month:" << endl;
                    cout << "Enter the high temp:" << endl;
                    cout << "Enter the low temp:" << endl;
                    b2 = 0.00;
                    z = 0;
                    p = 0;
                }
            }
        }
        else {
            text1 << c;
            p++;
        }
    }
    b = "";
    b2 = 0.00;
    s = "";
    p = 0;

    if (z == 2) {
        text1 >> b2;
        weather1[month1].lowtemp = b2;
        text1.str("");
        text1.clear();
        text1.seekg(0);
        weather1[month1].averagetemp = (weather1[month1].lowtemp + weather1[month1].hightemp) / 2;
        if (weather1[month1].lowtemp < -100 || weather1[month1].lowtemp > 140 || weather1[month1].hightemp < -100 || weather1[month1].hightemp > 140) {
            cout << "Range of Temperatures Allowed is between -100 to +140 Degrees Fahrenheit. Insert Data for this Month again...)" << endl;
            month1 = static_cast<Months>(month1 - 1);
        }
        month1 = static_cast<Months>(month1 + 1);
        cout << "Enter the total rainfall for the month:" << endl;
        cout << "Enter the high temp:" << endl;
        cout << "Enter the low temp:" << endl;
    }
    z = 0;        

    return static_cast<Months>(month1 - 1);
}

void sortAndAverage(WeatherStatistics weather1[], float average[], int lastm, Months month) {
    int x = 0;    
    WeatherStatistics weatherhelp;
    float a;
    float b;
    while (x == 0) {
        x = 1;
        for (month = JANUARY; month < lastm; month = static_cast<Months>(month + 1)) {
            a = weather1[month].lowtemp;
            b = weather1[static_cast<Months>(month + 1)].lowtemp;
            if (weather1[static_cast<Months>(month + 1)].lowtemp < weather1[month].lowtemp) {
                weatherhelp = weather1[month];
                weather1[month] = weather1[static_cast<Months>(month + 1)];
                weather1[static_cast<Months>(month + 1)] = weatherhelp;
                x = 0;
            }
        }
    }

    month = JANUARY;

    for (month = JANUARY; month < lastm + 1; month = static_cast<Months>(month + 1)) {
        average[0] = average[0] + weather1[month].traingfall;
        average[1] = average[1] + weather1[month].averagetemp;
    }
    average[0] = average[0] / (lastm + 1);
    average[1] = average[1] / (lastm + 1);
}

