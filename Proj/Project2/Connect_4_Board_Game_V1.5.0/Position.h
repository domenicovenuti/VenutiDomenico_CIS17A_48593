#ifndef POSITION_H
#define POSITION_H

//CLASS
/// Each Position in the Array.
/// This Class Define Each Individual Spot in the Board Game
/// @param x Position x in the Array
/// @param y Position y in the Array
/// @param value Value of the Position (0 = Empty, 1 = Player 1 Played That Position, 2 = Player 2 Played That Position)
/// @param nSquares Total Positions in the Array
/// @attention This Class include a Static Member (Shared by all Objects) called Outside the Class "int Position::nSquares = 0;"
/// @attention Include also Inline Member Functions "getX(), getY(), getValue(), getnSquares()"
class Position {
private:	//PRIVATES
	int x;
	int y;
	int value;
	static int nSquares;
public:	//PUBLICS
	void setX(int);
	void setY(int);
	void setValue(int);
	Position();
	//INLINE MEMBER FUNCTIONS
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	int getValue() const {
		return value;
	}	
	int getnSquares() {
		return nSquares;
	}
};
#endif // !POSITION_H