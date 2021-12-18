#include <random>
#include <iostream>
#include "Prob1Random.h"

using namespace std;

Prob1Random::Prob1Random(const char nset1, const char* set1) {
	nset = nset1;
	set = new char[nset1];
	numRand = 0;
	for (int x = 0; x < nset1; x++) {
		set[x] = set1[x];
	}
	freq = new int[nset1];
	for (int x = 0; x < nset1; x++) {
		freq[x] = 0;
	}        
}

Prob1Random::~Prob1Random(void) {
	delete[] set; 
	delete[] freq;
}

char Prob1Random::randFromSet(void) {
	int randNum = 0;
	randNum = rand() % nset;
	setFreq(randNum);
	setNumRand();
	return set[nset];
}

void Prob1Random::setFreq(int randNum){
    freq[randNum]++;
}

void Prob1Random::setNumRand(){
    numRand++;
}

int* Prob1Random::getFreq(void) const {
	return freq;
}

char* Prob1Random::getSet(void) const {
	return set;
}

int Prob1Random::getNumRand(void) const {
	return numRand;
}