/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on October 12, 2021 at 8:10 PM
 * Purpose: Chapter 12 - Exercise 8 - Array/File functions
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip> 

using namespace std;

const int SIZE = 5;

void arrayToFile(string, int*, int);
void fileToArray(string, int*, int);
void printArray(int*, int*, int);

int main()
{        
    int array[SIZE] = { 1, 2, 3, 4, 666 };    

    int array2[SIZE] = { 0, 0, 0, 0, 0 };

    string name = "arrayToFile.dat";    

    cout << "Chapter 12 - Exercise 8:" << endl;
    cout << "Author: Domenico Venuti" << endl;
    cout << "************************************************" << endl;
    cout << endl;
    cout << "The Array 1 will be save in the binary file 'arrayToFile.dat' and then the same data will be read from 'arrayToFile.dat' to the Array 2 and both array's will be display..." << endl;
    cout << "************************************************" << endl;

    arrayToFile(name, array, SIZE);

    fileToArray(name, array2, SIZE);
    
    printArray(array, array2, SIZE);
}

void arrayToFile(string name, int*array, int size) {
    ofstream outFile;

    outFile.open(name, ios::out | ios::binary);

    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char *>(array), sizeof(int) * size);
    }
    else {
        cout << "File was not Found or can't be opened...";
    }

    outFile.close();
}

void fileToArray(string name, int *array, int size) {
    ifstream outFile;

    outFile.open(name, ios::out | ios::binary);

    if (outFile.is_open()) {        
        outFile.read(reinterpret_cast<char *>(array), sizeof(int) * size);
    }
    else {
        cout << "File was not Found or can't be opened...";
    }

    outFile.close();
}

void printArray(int *array, int *array2, int size) {
    cout << endl;
    cout << endl;

    cout << "Arrays Content:" << endl;
    cout << "************************************************" << endl;
    cout << endl;
    for (int x = 0; x < size; x++) {
        cout << "Array 1 - Position [" << x << "]: " << array[x] << "\t\t|" << "\t\t" << "Array 2 - Position [" << x << "]: " << array2[x] << endl;
    }
}