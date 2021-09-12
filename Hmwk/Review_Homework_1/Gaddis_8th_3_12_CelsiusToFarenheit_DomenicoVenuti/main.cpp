/* 
 * Project: Celsius to Farenheit (Chapter 3 Exercise 12)
 * Author: Domenico Venuti
 * Created on September 12, 2021, 10:43 AM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    
    //Variables Definition
    float C;
    float F;
    
    //Initialize Variables
    C = 0.00;
    F = 0.00;
    
    //Read from Keyboard
    cout << "Insert Temperature to Convert(C):\n";
    cin >> C;
    
    //Conversion
    F = 9.0f/5.0f * C + 32;
    
    //Show Result
    cout << "The Temperature in F is: " << F;
    
    //Return main
    return 0;
}

