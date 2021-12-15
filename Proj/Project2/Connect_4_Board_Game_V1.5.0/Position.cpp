#include "Position.h"

using namespace std;

//DEFINITION STATIC MEMBER VARIABLE OUTSIDE THE CLASS;
int Position::nSquares = 0;

//METHODS
Position::Position() {	//CONSTRUCTOR
	x = 0;
	y = 0;
	value = 0;
	nSquares++;
}
//SET DATA FUNCTIONS
void Position::setX(int x1) {
	x = x1;
}
void Position::setY(int y1) {
	y = y1;
}
void Position::setValue(int value1) {
	value = value1;
}