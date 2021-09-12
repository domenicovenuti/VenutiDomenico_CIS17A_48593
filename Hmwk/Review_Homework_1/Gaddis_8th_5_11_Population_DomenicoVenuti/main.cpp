/* 
 * File:   Chapter 5, Exercise 11 - CIS-17A
 * Author: Domenico Venuti
 * Created on September 12, 2021, 10:48 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

float populationIncrease(int startNumber, int increasePercentage, int days){                
    
    float popul;
    
    popul = (float)startNumber;
    
    for(int i = 0; i < days; i++){
        
        popul = popul + ((float)increasePercentage * popul / 100.00f);
        
    }
    
    return popul;
}

int main(int argc, char** argv) {
    
    //variables
    int startNumber;
    int increasePercentage;
    int days;
    int control;
    float population;
    
    //initialize
    startNumber = 0;
    increasePercentage = 0;
    days = 0;
    control = 0;
    population = 0;
    
    cout << "Insert the Starting Number of Organisms: ";
    
    while(control == 0){        
        cin >> startNumber;
        if(startNumber < 2){
            cout << "Error... Can't be less than 2... Try Again.";
            control = 0;
        }else{
            control = 1;
        }
    }
    
    control = 0;
    
    cout << "Insert the Average Daily Population Increase(%): ";
    
    while(control == 0){
        cin >> increasePercentage;
        if(increasePercentage < 0){
            cout << "Error... Can't be Negative... Try Again.";
            control = 0;
        }else{
            control = 1;
        }
    }
    
    control = 0;
    
    cout << "How Many days?: ";
    
    while(control == 0){
        cin >> days;
        if(days < 1){
            cout << "Error... Can't be less than 1... Try Again.";
            control = 0;
        }else{
            control = 1;
        }
    }       
    
    //calculations
    population = populationIncrease(startNumber, increasePercentage, days);
    
    //Show Results
    cout << "The size of the Population Predicted is : " << population;    
    
    return 0;
}

