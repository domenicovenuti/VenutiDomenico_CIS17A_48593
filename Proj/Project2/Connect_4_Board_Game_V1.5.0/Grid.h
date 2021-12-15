#include "Position.h"

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