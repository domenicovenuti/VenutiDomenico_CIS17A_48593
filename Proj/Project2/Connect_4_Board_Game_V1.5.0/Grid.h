#include "Position.h"

//DEFINE CONSTANTS
const int MAX_SIZE = 63;

//CLASS
/// Board Game.
/// This Class Define the Board Game as an Array of Positions
/// @param rows Number of Rows in the Current Game
/// @param cols Number of Columns in the Current Game  
/// @param position Array of Class Position
/// @see Position
/// @attention This class Include a friend class gridsFriend()
/// @attention This class have 2 Constructors and a Destructor, the code can be found in Grid.cpp
class Grid {
private:	//PRIVATE MEMBER
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