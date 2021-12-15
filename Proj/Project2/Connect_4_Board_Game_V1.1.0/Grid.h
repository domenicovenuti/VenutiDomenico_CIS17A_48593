#include <string>
#include "Position.h"

using namespace std;

//DEFINE CONSTANTS
const int MAX_SIZE = 70;

//CLASS
class Grid {
private:	//PRIVATE
	int rows;
	int cols;
	Position* position;	//OBJECT ARRAY
public:	//PUBLIC
	void setRows(int);
	void setCols(int);
	void setPositionX(int, int);
	void setPositionY(int, int);
	void setPositionValue(int, int);
	void setPositionsNew(int);
	int getRows() const;
	int getCols() const;
	int getPositionX(int) const;
	int getPositionY(int) const;
	int getPositionValue(int) const;
	void printP();
	Grid(int, int);
	~Grid();
};

//METHODS
Grid::Grid(int rows1, int cols1) {	//CONSTRUCTOR
	rows = rows1;
	cols = cols1;
	position = nullptr;
	int pos = 0;
	position = new Position[MAX_SIZE];	
}
Grid::~Grid() {	//DESTRUCTOR	
}
//SET DATA FUNCTIONS
void Grid::setRows(int rows1) {
	rows = rows1;
}
void Grid::setCols(int cols1) {
	cols = cols1;
}
void Grid::setPositionX(int pos, int x1) {
	position[pos].setX(x1);
}
void Grid::setPositionY(int pos, int y1) {
	position[pos].setY(y1);
}
void Grid::setPositionValue(int pos, int value1) {	
	position[pos].setValue(value1);
}
void Grid::setPositionsNew(int pos) {		
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			position[pos].setX(x);
			position[pos].setY(y);
			position[pos].setValue(0);
			pos++;
		}
	}
}
//GET DATA FUNCTIONS
int Grid::getRows() const {
	return rows;
}
int Grid::getCols() const {
	return cols;
}
int Grid::getPositionX(int pos) const {
	return position[pos].getX();
}
int Grid::getPositionY(int pos) const {
	return position[pos].getY();
}
int Grid::getPositionValue(int pos) const {
	return position[pos].getValue();
}
void Grid::printP() {	//PRINT POSITION ARRAY FOR TESTING PURPOSE
	int pos = 0;
	cout << endl;
	for (int x = 0; x < 7; x++) {
		for (int y = 0; y < 9; y++) {
			cout << "POS: " << pos << " / X: " << position[pos].getX() << " / Y: " << position[pos].getY() << " / VALUE: " << position[pos].getValue() << endl;
			pos++;
		}
	}
}

