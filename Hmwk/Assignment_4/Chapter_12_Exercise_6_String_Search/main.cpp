/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 11, 2021 at 8:12 PM
 * Purpose: Chapter 12 - Exercise 6 - String Search
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void getfileName(string&, string&);
void getLines(string, string);

int main()
{
    string filename;
    string search;
    vector<string> lines;

    getfileName(filename, search);
    getLines(filename, search);
}

void getfileName(string& filename, string& search) {
    cout << "Insert the Name of the File you want to Read: ";
    getline(cin, filename);
    cout << "Insert the String you want to search: ";
    getline(cin, search);
}

void getLines(string filename, string search) {
    int x = 0;
    string line;
    ifstream infile;
    string word;
    stringstream ss;        
    int counts = 0;
    int control2 = 0;
    int control1 = 0;

    infile.open(filename, ios::in);        

    if (infile.is_open()) {
        cout << endl;
        while (getline(infile, line)) {                        

            for (char& c : line) {

                if ((c == ' ' || c == '\n') && control1 == 1) {
                    ss >> word;
                    ss.str("");
                    ss.clear();
                    ss.seekg(0);

                    if (word == search) {
                        control2 = 1;
                        counts++;

                    }

                    if (control2 == 1) {
                        cout << search << " was Found in Line " << x + 1 << ": " << line << endl;
                        control2 = 0;
                    }
                    control1 = 0;
                }
                else {
                    ss << c;
                    control1 = 1;
                }
                
            }
            
            ss >> word;
            ss.str("");
            ss.clear();
            ss.seekg(0);

            if (word == search) {
                control2 = 1;
                counts++;

            }

            if (control2 == 1) {
                cout << search << " was Found in Line " << x + 1 << ": " << line << endl;
                control2 = 0;
            }
            control1 = 0;

            x++;            
            
        }
        if (x == 0) {
            cout << "File is Empty..." << endl;
        }
        else {
            cout << endl;
            cout << "The String " << search << " Appeared " << counts << " times in the Whole File." << endl;
        }
    }
    else {
        cout << "File doesn't Exist...";
    }

}
