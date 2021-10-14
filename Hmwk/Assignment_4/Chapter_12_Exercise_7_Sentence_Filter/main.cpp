/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 12, 2021 at 7:01 PM
 * Purpose: Chapter 12 - Exercise 7 - Sentence Filter
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
    string filename2;
    vector<string> lines;

    getfileName(filename, filename2);
    getLines(filename, filename2);
}

void getfileName(string& filename, string& filename2) {
    cout << "Insert the Name of the File you want to Read: ";
    getline(cin, filename);
    cout << "Insert the Name of the File you want to Write: ";
    getline(cin, filename2);    
}

void getLines(string filename, string filename2) {
    int x = 0;
    string line;
    ifstream infile;
    ofstream outfile;
    string word;
    stringstream ss;        
    int counts = 0;
    int control2 = 0;
    int control1 = 0;

    infile.open(filename, ios::in);    
    outfile.open(filename2, ios::out);

    if (infile.is_open() && outfile.is_open()) {        
        while (getline(infile, line)) {                        
            
            for (char& c : line) {

                if (c == '.') {
                    ss << c;
                    control1 = 0;
                }
                else {
                    if (control1 == 0 && c != ' ') {
                        ss << char(toupper(c));
                        control1 = 1;
                    }
                    else {
                        ss << char(tolower(c));                        
                    }                    
                    
                }
                
            }
            x++;
            word = ss.str();
            ss.str("");
            ss.clear();
            ss.seekg(0);                                    

            outfile << word << endl;                        
        }
        if (x == 0) {
            cout << "File is Empty... Nothing was Transferred." << endl;
        }        
        else {
            cout << "All data was transferred from File " << filename << " to File " << filename2;
        }
    }
    else {
        cout << "File In or File Out doesn't Exist...";
    }    
    cout << endl;
    cout << "The End...";

}