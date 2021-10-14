/* 
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 11, 2021 at 7:12 PM
 * Purpose: Chapter 12 - Exercise 4 - Tail Program
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void getfileName(string&);
void getLines(vector<string>, string);

int main()
{
    string filename;       
    vector<string> lines;    
    getfileName(filename);        
    getLines(lines, filename);    
}

void getfileName(string &filename) {
    cout << "Insert the Name of the File you want to Read: ";
    getline(cin, filename);
}

void getLines(vector<string> lines, string filename) {
    int x = 0;
    string line;
    ifstream infile;

    infile.open(filename, ios::in);

    if (infile.is_open()) {
        while (getline(infile, line)) {            
            lines.push_back(line);
            x++;
        }

        if (x == 0) {
            cout << "File is Empty..." << endl;
        }
        else if (x > 0 && x <= 10) {
            for (int y = 0; y < x; y++) {
                cout << "Line " << (y + 1) << ": " << lines.at(y) << endl;
            }
            cout<<"The Entire File has been Displayed.";
        }
        else {
            x = x - 10;
            for (int y = x; y < (x + 10); y++) {
                cout << "Line " << (y + 1) << ": " << lines.at(y) << endl;
            }
            cout<<"The Last 10 Lines have been Displayed.";
        }
    }
    else {
        cout << "File doesn't Exist...";
    }
    
}
