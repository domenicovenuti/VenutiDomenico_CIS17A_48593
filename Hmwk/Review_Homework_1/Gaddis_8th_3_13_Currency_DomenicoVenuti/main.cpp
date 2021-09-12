/* 
 * File: Chapter 3, Exercise 13 (Currency)
 * Author: Domenico Venuti
 * Created on September 12, 2021, 10:45 AM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    //Variables and Constants
    float usd, yen, eur;
    const float YEN_PER_DOLLAR = 110.71f;
    const float EUROS_PER_DOLLAR = 0.84f;
    
    //Initialize Variables
    usd = 0.00f;
    yen = 0.00f;
    eur = 0.00f;
    
    //Interface
    cout << "How Many (USD) do you want to Convert?:\n";
    cin >> usd; //Read from Keyboard
    
    //Conversions
    yen = usd * YEN_PER_DOLLAR;
    eur = usd * EUROS_PER_DOLLAR;
    
    //Show Results
    cout << "\nYou will Receive: " << setprecision(2) << fixed << yen << " Japanese Yen.\n";
    cout << "You will Receive: " << setprecision(2) << fixed << eur << " Euros.";
    
    return 0;
}

