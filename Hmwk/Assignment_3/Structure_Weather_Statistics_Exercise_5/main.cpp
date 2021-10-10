/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 5, 2021 at 9:05 PM
 * Purpose: Structure Weather Statistics - Exercise 5 - Code-E
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
    string month;
    int traingfall;
    int hightemp;
    int lowtemp;
    float averagetemp;
};

//Function Prototypes
void getData(WeatherStatistics[]);
void displayData(WeatherStatistics[], float[]);
void sortAndAverage(WeatherStatistics[], float[]);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    WeatherStatistics weather[12];
    float average[2] = { 0.00,0.00 };
    
    //Process or map Inputs to Outputs                 
    getData(weather);    

    sortAndAverage(weather, average);        

    //display results
    displayData(weather, average);

    //Exit stage right!
    return 0;
}

void displayData(WeatherStatistics weather1[], float average[]) {
    cout <<fixed<<setprecision(1)<< "Average Rainfall " << average[0] << " inches/month" << endl;
    cout << "Lowest  Temperature " << weather1[0].month << "  " << weather1[0].lowtemp << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << weather1[11].month << "  " << weather1[11].hightemp << " Degrees Fahrenheit" << endl;
    cout << fixed << setprecision(0) << "Average Temperature for the year " << average[1] << " Degrees Fahrenheit" << endl;
}

void getData(WeatherStatistics weather1[]) {
    stringstream text1;
    string s;
    string b;
    int b2 = 0;
    int p = 0;
    int z = 0;
    for (int aa = 0; aa < 12; aa++) {
        
        std::getline(cin, s);
        
        for (char c : s) {
            if (c == ' ') {
                if (p > 0) {
                    if (z == 0) {
                        text1 >> b;
                        weather1[aa].month = b;
                        text1.str("");
                        text1.clear();
                        text1.seekg(0);
                        b = "";
                        z++;
                        p = 0;
                    }
                    else if (z == 1) {
                        text1 >> b2;
                        weather1[aa].traingfall = b2;
                        text1.str("");
                        text1.clear();
                        text1.seekg(0);
                        b2 = 0;
                        z++;
                        p = 0;
                    }
                    else if (z == 2) {
                        text1 >> b2;
                        weather1[aa].lowtemp = b2;
                        text1.str("");
                        text1.clear();
                        text1.seekg(0);
                        b2 = 0;
                        z++;
                        p = 0;
                    }
                }
            }
            else {
                text1 << c;
                p++;
            }
        }
        text1 >> b2;
        weather1[aa].hightemp = b2;
        text1.str("");
        text1.clear();
        text1.seekg(0);
        b = "";
        b2 = 0;
        s = "";
        p = 0;
        z = 0;
        weather1[aa].averagetemp = ((float)weather1[aa].lowtemp + (float)weather1[aa].hightemp) / 2; 
        
        if(weather1[aa].lowtemp < -100 || weather1[aa].lowtemp > 140 || weather1[aa].hightemp < -100 || weather1[aa].hightemp > 140){
            cout<<"Range of Temperatures Allowed is between -100 to +140 Degrees Fahrenheit. Insert Data for this Month again...)"<<endl;
            aa = aa - 1;
        }
    }
}

void sortAndAverage(WeatherStatistics weather1[], float average[]) {
    int x = 0;

    WeatherStatistics weatherhelp;
    while (x == 0) {
        x = 1;
        for (int y = 0; y < 11; y++) {
            if (weather1[y + 1].lowtemp < weather1[y].lowtemp) {
                weatherhelp = weather1[y];
                weather1[y] = weather1[y + 1];
                weather1[y + 1] = weatherhelp;
                x = 0;
            }
        }
    }

    for (int y = 0; y < 12; y++) {
        average[0] = average[0] + weather1[y].traingfall;
        average[1] = average[1] + weather1[y].averagetemp;
    }
    average[0] = average[0] / 12;
    average[1] = average[1] / 12;
}