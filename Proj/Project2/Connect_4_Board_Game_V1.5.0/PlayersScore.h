#ifndef PLAYERSSCORE_H
#define PLAYERSSCORE_H

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
#endif // !PLAYERSSCORE_H