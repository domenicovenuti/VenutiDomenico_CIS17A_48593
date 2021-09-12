/* 
 * File: Chapter 4 - Exercise 10 - CIS-17A - Days in a Month
 * Author: Domenico Venuti
 * Created on September 27, 2021, 10:46 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int checkLeap(int year){
    
    int x;
    
    float leap1001;
    float leap1001f;
    float leap4001;
    float leap4001f;
    float leap41;
    float leap41f;
   
    x = 0;
    
    leap1001f = year / 100.00f;
    leap1001 = year / 100;
    
    leap4001f = year / 400.00f;
    leap4001 = year / 400;
    
    leap41f = year / 4.00f;
    leap41 = year / 4;
    
    if(leap1001 == leap1001f){
        if(leap4001f == leap4001){
            x = 1;
        }else{
            x = 0;
        }
    }else{
        if(leap41f == leap41){
            x = 1;
        }else{
            x = 0;
        }
    }
    
    return x;
}

int daysinMonth(int month, int leap){
    
    int days;
    
    days = 0;
    
    switch(month){
        case 1:
            days = 31;
            break;
        case 2:
            if(leap == 1){
                days = 29;
            }else{
                days = 28;
            }
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;       
    }
    
    return days;
}

int main(int argc, char** argv) {
    
    //variables
    int month;
    int year;
    int leap;    
    int days;
    
    //initiliaze
    month = 1;
    year = 1;    
    days = 0;
    leap = 0;
    
    //interface
    cout << "Enter a Month (1-12): ";
    cin >> month;
    cout << "Enter a Year: ";
    cin >> year;
    
    //calculations
    leap = checkLeap(year);
    days = daysinMonth(month, leap);
            
    //show results
    cout << "Days in the Month: " << days << " days. ";
        
    return 0;
}

