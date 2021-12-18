/*
 * File: main.cpp
 * Author: Domenico Venuti
 * Created on December 16, 2021 at 7:01 PM
 * Purpose: Final - Problem 1
 */
#include <iostream>
#include "Prob1Random.h"

using namespace std;

int main(int argc, char** argv)
{
	char n = 5;
	char rndseq[] = { 29,34,57,89,126 };
	int ntimes = 100000;
	Prob1Random a(n, rndseq);
	for (int i = 1; i <= ntimes; i++) {
		a.randFromSet();
	}
	int* x = a.getFreq();
	char* y = a.getSet();
	for (int i = 0; i < n; i++) {
		cout << int(y[i]) << " occurred " << x[i] << " times" << endl;
	}
	cout << "The total number of random numbers is " << a.getNumRand() << endl;	
    return 0;
}
