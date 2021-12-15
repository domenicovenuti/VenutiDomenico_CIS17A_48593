#include <iostream>
#ifndef BASE_H_GUARD
#define BASE_H_GUARD

using namespace std;

//CLASS
class Base {
private:	//PRIVATE
	int tGamesPlayed;
protected:	//PROTECTED
	int boardsize;
public:	//PUBLICS
	void settGamesPlayed(int);
	void setBoardSize(int);
	int gettGamesPlayes() const;
	int getBoardSize() const;
	virtual void getTextMenu() {
		cout << endl;
		cout << "\t\t1. Classic Connect 4 - Grid (6 X 7)." << endl;
		cout << "\t\t2. Connect 4 - Grid (4 X 5)." << endl;
		cout << "\t\t3. Connect 4 - Grid (5 X 6)." << endl;
		cout << "\t\t4. Connect 4 - Grid (7 X 8)." << endl;
		cout << "\t\t5. Connect 4 - Grid (7 X 9)." << endl;
		cout << "\t\t6. Scores." << endl;
		cout << "\t\t7. Exit Game." << endl;
	}
	Base() {	//CONSTRUCTOR
		tGamesPlayed = 0;
		boardsize = 0;
	}	
};
#endif