#include "Base.h"

using namespace std;

//SET DATA FUNCTIONS
void Base::settGamesPlayed(int tGamesPlayed) {
	this->tGamesPlayed = tGamesPlayed;
}
void Base::setBoardSize(int boardsize) {
	this->boardsize = boardsize;
}
int Base::getBoardSize() const {
	return boardsize;
}
int Base::gettGamesPlayes() const {
	return tGamesPlayed;
}