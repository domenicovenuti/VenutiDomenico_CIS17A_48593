/*
* File: main.cpp
* Author: Domenico Venuti
* Created on October 22, 2021 at 8:00 PM
* Purpose: Midterm - CIS-17A - C++ Objects
*/

//EXERCISE 3

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <vector>
#include <windows.h>
#include <ctime>
#include <math.h>

#include "Array.h"
#include "Stats.h"

using namespace std;

//EXERCISE 3
//Function Prototypes I supply
Array* fillAry(int, int);        //Fill an array and put into a structure
void prntAry(const Array*, int);//Print the array 
int* copy(const int*, int);     //Copy the array
void mrkSort(int*, int);        //Sort an array
void prtStat(const Stats*);    //Print the structure
void rcvrMem(Array*);          //Recover memory from the Array Structure
void rcvrMem(Stats*);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats* stat(const Array*);     //Find & store mean, median, & modes in structure
//EXERCISE 3

//*************************************************************************************************************
//Exercise #3

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array* array;
    string press;

    //Input the size and mod number
    cout << "This program develops an array to be analyzed" << endl;
    cout << "Array size from mod number to 100" << endl;
    cout << "Mod number from 2 to 10" << endl;
    cout << "Input the Array Size and the mod number to be used." << endl;
    cin >> arySize >> modNum;
    cout << endl << endl;

    //Fill the array
    array = fillAry(arySize, modNum);

    //Print the initial array
    cout << "Original Array before sorting" << endl;
    prntAry(array, 10);

    //Sort the array
    mrkSort(array->data, array->size);
    cout << "Sorted Array to be utilize for the stat function" << endl;
    prntAry(array, 10);

    //Calculate some of the statistics
    Stats* stats = stat(array);

    //Print the statistics
    prtStat(stats);

    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);

    //Exit stage right 
    //system("pause");
    cout << endl;
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.clear();
    cin.sync();
    getline(cin, press);
    cout << "Bye Bye..." << endl;
    Sleep(4000);
    
    return 0;
}

int* copy(const int* a, int n) {
    //Declare and allocate an array
    //that is a c
    int* b = new int[n];
    //Fill
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats* ary) {
    cout << endl;
    cout << "The average of the array = " << ary->avg << endl;
    cout << "The median of the array  = " << ary->median << endl;
    cout << "The number of modes      = " <<
        ary->mode->size << endl;
    cout << "The max Frequency        = " <<
        ary->modFreq << endl;
    if (ary->mode->size == 0) {
        cout << "The mode set             = {null}" << endl;
        return;
    }
    cout << "The mode set             = {";
    for (int i = 0; i < ary->mode->size - 1; i++) {
        cout << ary->mode->data[i] << ",";
    }
    cout << ary->mode->data[ary->mode->size - 1] << "}" << endl;
}

void mrkSort(int* array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void rcvrMem(Stats* stats) {
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array* array) {
    delete[]array->data;
    delete array;
}

void prntAry(const Array* array, int perLine) {
    //Output the array
    for (int i = 0; i < array->size; i++) {
        cout << array->data[i] << " ";
        if (i % perLine == (perLine - 1))cout << endl;
    }
    cout << endl;
}

Array* fillAry(int n, int modNum) {
    //Allocate memory
    Array* array = new Array;
    array->size = n;
    array->data = new int[array->size];

    //Fill the array with mod numbers
    for (int i = 0; i < n; i++) {
        array->data[i] = i % modNum;
    }

    //Exit function
    return array;
}

Stats* stat(const Array* array) {
    //Non-working stub to be completed by the student
    cout << endl << "Stat function to be completed by the student" << endl;
    Stats* stats = new Stats;
    stats->mode = new Array;
    int sum = 0;
    float mean = 0.00;

    //MEAN
    for (int x = 0; x < array->size; x++) {
        sum = sum + array->data[x];
    }
    mean = sum / (float)array->size;
    stats->avg = mean;

    //MEDIAN
    float median = 0.00;
    if (array->size % 2 != 0) {
        median = (float)array->data[array->size / 2];
    }
    else {
        median = (float)(array->data[(array->size - 1) / 2] + array->data[array->size / 2]) / 2.0;
    }

    //MODE
    int** maxf = nullptr;
    maxf = new int* [array->size];
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;

    for (a1 = 0; a1 < 2; a1++) {
        maxf[a1] = new int[array->size];
    }

    for (a1 = 0; a1 < 2; a1++) {
        for (b1 = 0; b1 < array->size; b1++) {
            maxf[a1][b1] = -999;
        }
    }

    //Copy the array
    int* ary = copy(array->data, array->size);

    //Sort the copy
    mrkSort(ary, array->size);

    //Find the max Frequency
    int aa = 0;
    for (c1 = 0; c1 < array->size; c1++) {
        if (c1 == 0) {
            maxf[0][aa] = ary[c1];
            maxf[1][aa] = 1;
        }
        else {
            if (ary[c1] == ary[c1 - 1]) {
                maxf[1][aa] = maxf[1][aa] + 1;
            }
            else {
                aa++;
                maxf[0][aa] = ary[c1];
                maxf[1][aa] = 1;
            }
        }
    }
    int f1 = 0;
    for (c1 = 0; c1 < array->size - 1; c1++) {
        if (maxf[0][c1 + 1] != -999) {
            f1 = f1 + 1;
        }
    }

    f1 = f1 + 1;

    //Find the number of modes
    int sum1 = 0;
    int control2 = 0;
    int nmodes = 0;
    int freq = 0;

    freq = maxf[1][0];

    for (int zz = 0; zz < array->size; zz++) {
        if (control2 == 0) {
            if (maxf[1][zz + 1] == maxf[1][zz] && maxf[1][zz + 1] != -999) {
                sum1 = sum1 + 1;
            }
            else {
                sum1 = sum1 + 1;
                control2 = 1;
            }
        }
    }

    nmodes = sum1;

    if (nmodes == f1) {
        nmodes = 0;
    }

    //Allocate the mode array
    int* modeAry = new int[nmodes + 2];

    //Again this is just a stub.        
    if (nmodes == 0) {
        modeAry[0] = 0;//Stub returns no modes
        modeAry[1] = 1;//Stub returns Frequency 1            
    }
    else {
        modeAry[0] = nmodes;
        modeAry[1] = freq;
    }

    //Fill the mode array
    for (int zz3 = 2; zz3 < nmodes + 2; zz3++) {
        modeAry[zz3] = maxf[0][zz3 - 2];
    }

    //ORIGINAL CODE
    stats->mode->size = nmodes;
    int nModes = nmodes;
    if (nModes != 0)stats->mode->data = new int[nModes];
    stats->modFreq = freq;
    stats->median = median;

    for (int zz3 = 2; zz3 < nmodes + 2; zz3++) {
        stats->mode->data[zz3 - 2] = modeAry[zz3];
    }

    return stats;

    //Delete the allocated copy and return
    delete[]ary;
    for (int z4 = 0; z4 < array->size; z4++) {
        delete[]maxf[z4];
    }
    delete[]maxf;
}
//Exercise #3
//*************************************************************************************************************
