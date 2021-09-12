/* 
 * File: Chapter 6, Exercise 7 - CIS-17A
 * Author: Domenico Venuti
 *
 * Created on September 12, 2021, 10:50 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float celsius(float tempF){
    
    float tempC;
    
    tempC = 0;
    
    tempC = 5.00f / 9.00f * (tempF - 32.00f);
    
    return tempC;
    
}

int main(int argc, char** argv) {
    
    //variables
    float tempC;
    float tempF;
    
    //initialize
    tempC = 0.00f;
    tempF = 0.00f;
    
    //interface
    cout << "Insert a Temperature in F to Convert to C: ";
    cin >> tempF; 
    
    //calculations
    tempC = celsius(tempF);
    
    //show results
    cout << "Temp (F): " << setprecision(2) << fixed << tempF << " is Equivalent to Temp(C): " << setprecision(2) << fixed << tempC;
    tempC = 0.00f;
    
    cout << "\n\n Celsius Temperature Table:\n\n";
    
    for(int i = 0; i < 21; i++){
        tempC = celsius(i);
        cout << "Temp (F): " << setprecision(2) << fixed << i << " is Equivalent to Temp(C): " << setprecision(2) << fixed << tempC << "\n";
    }
    
    return 0;
}

