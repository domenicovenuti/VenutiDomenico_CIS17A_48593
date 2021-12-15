#include <string>
#include "PlayersScore.h"

using namespace std;

//SET DATA FUNCTIONS
void PlayersScore::setPlayer1n(string name1) {
	player1 = name1;
}
void PlayersScore::setScore1() {
	this->score1 = score1 + winn;
}
string PlayersScore::getPlayer1n() {
	return player1;
}
void PlayersScore::setP1(float p1) {
	this->p1 = p1;
}
void PlayersScore::setP2(float p2) {
	this->p2 = p2;
}
float PlayersScore::getScore1() const {
	return score1;
}
float PlayersScore::getWinn() const {
	return winn;
}
float PlayersScore::getP1() const {
	return p1;
}
float PlayersScore::getP2() const {
	return p2;
}