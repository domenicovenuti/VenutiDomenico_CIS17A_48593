#include <string>

using namespace std;

//CLASS
class Position {
private:	//PRIVATES
	int x;
	int y;
	int value;
public:	//PUBLICS
	void setX(int);
	void setY(int);
	void setValue(int);
	int getX() const;
	int getY() const;
	int getValue() const;	
	Position();
};

//METHODS
Position::Position() {	//CONSTRUCTOR
	x = 0;
	y = 0;
	value = 0;
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
//GET DATA FUNCTIONS
int Position::getX() const {
	return x;
}
int Position::getY() const {
	return y;
}
int Position::getValue() const {
	return value;
}