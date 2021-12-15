#ifndef POSITION_H
#define POSITION_H

//CLASS
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