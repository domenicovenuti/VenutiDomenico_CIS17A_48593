/* 
 * File: Chapter 8 - Exercise 7 - CIS-17A
 * Author: Domenico Venuti
 * Created on September 12, 2021, 10:54 AM
 */

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(string names[], int size, string value)
{
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}

int main(){

//variables    
int result;
string nameP;    
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };
// Insert your code to complete this program

int z = sizeof(names)/sizeof(names[0]); //Get the array size

//sort
sort(names,names + z); //Use the start and end like this

//interface
cout << "Insert Name to Search:\n";
getline(cin, nameP);

//search
result = binarySearch(names, z, nameP);

//showresults
if(result == -1){
    cout << "Name not Found in the Array.";
}else{
    cout << "Name: " << names[result] << " was Found in Position: " << result;
}
        
return 0;
}