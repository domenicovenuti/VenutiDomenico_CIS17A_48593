#include <string>
#include "Position.h"

using namespace std;

//DEFINE CONSTANTS
const int MAX_SIZE = 63;

//CLASS
class Grid {
private:	//PRIVATE
	int rows;
	int cols;
	Position* position;	//AGGREGATION AND OBJECT ARRAY	
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
	int getnSquares() const;
	void printP();
	Grid(int, int);
	Grid();
	~Grid();
	friend void gridsFriend(int, int, Grid&);	//FRIEND FUNCTION OF Grid Class
};

//METHODS
Grid::Grid() {	//CONSTRUCTOR
	rows = 0;
	cols = 0;
	position = nullptr;	
}
Grid::Grid(int rows1, int cols1) {	//OVERLOADED CONSTRUCTOR
	rows = rows1;
	cols = cols1;	
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
int Grid::getnSquares() const{
	return position->getnSquares();
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

