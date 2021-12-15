#include <string>

using namespace std;

//CLASS
class PlayersScore {
private:	//PRIVATES
	string player1;
	float score1;	
	float p1;
	float p2;
	float winn = 30.25;
public:	//PUBLICS
	void setPlayer1n(string);	
	void setScore1();	
	void setP1(float);
	void setP2(float);
	string getPlayer1n();
	float getScore1() const;
	float getWinn() const;
	float getP1() const;
	float getP2() const;
	PlayersScore() {	//CONSTRUCTOR
		player1 = "";
		score1 = 0.00;
		p1 = 0.00;
		p1 = 0.00;
	}
	PlayersScore operator + (PlayersScore const& obj) {	//Overload Operator +
		PlayersScore player;
		player.score1 = score1 + obj.score1;
		return player;
	}
	PlayersScore operator - (PlayersScore const& obj) {	//Overload Operator -
		PlayersScore player;
		player.score1 = abs(score1 - obj.score1);
		return player;
	}
	PlayersScore operator / (PlayersScore const& obj) {	//Overload Operator /
		PlayersScore player;
		player.p1 = score1 / (score1 + obj.score1) * 100;
		player.p2 = obj.score1 / (score1 + obj.score1) * 100;
		return player;
	}
};

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
float PlayersScore::getScore1() const{
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