/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on November 16, 2021 at 6:32 PM
 * Purpose: TestScores Class - Exercise 13.7 - Assignment 5
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "TestScores.h"

using namespace std;

int main(int argc, char** argv) {
    
    TestScores TestScores;       
    string line;        
    
    cout << "Insert Test Score #1: ";
    getline(cin, line);        
    TestScores.setTestScore1(stod(line));
    cin.clear();
    line = "";
    cout << "Insert Test Score #2: ";
    getline(cin, line);    
    TestScores.setTestScore2(stod(line));
    cin.clear();
    line = "";
    cout << "Insert Test Score #3: ";
    getline(cin, line);    
    TestScores.setTestScore3(stod(line));
    cin.clear();
    line = "";
    cout << endl << "The Average of the Scores is: " << TestScores.getAverage() << endl;
    
    return 0;
}

