/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 16, 2021 at 10:50 PM
 * Purpose: Final - Problem 3
 */
#include <iostream>
#include "Prob3Table.h"
#include "Prob3TableInherited.h"

using namespace std;

int main(int argc, char** argv)
{	
    cout << "Entering problem number 3" << endl;
	int rows = 5;
	int cols = 6;		
	Prob3TableInherited<int> tab("Problem3.txt", rows, cols);	//CHANGED TO MAKE IT WORK BY DVENUTI
	const int* naugT = tab.getTable();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << naugT[i * cols + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	const int* augT = tab.getAugTable();
	for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << augT[i * cols + j] << " ";
		}
		cout << endl;
	}
        
    return 0;
}
