#include <string>
#include <iostream>
#include "Base.h"

using namespace std;

//CLASS
class Derived:public Base {
public:	//PUBLIC
	Derived() {	//CONSTRUCTOR
		boardsize = 0;
	}
	//UPDATED VIRTUAL FUNCTION
	void getTextMenu() {
		cout << endl;
		cout << "\t--------------------------------------------------------------------------------------------" << endl;
		cout << "\t--------------------------------------------------------------------------------------------" << endl;
		cout << "\t\tChoose a Game Type:" << endl;
		cout << "\t--------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "\t\t1. Player VS Player." << endl;
		cout << "\t\t2. Player VS PC." << endl;
		cout << "\t\t3. PC VS PC." << endl;
		cout << "\t\t4. Back." << endl;
	}
};