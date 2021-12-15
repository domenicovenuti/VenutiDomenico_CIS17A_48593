/*
* File: main.cpp
* Author: Domenico Venuti
* First Version Created on December 5, 2021 at 6:00 PM
* Purpose: Project 2 - CIS-17A - C++ Objects - Board Game - Connect 4
* Current Version: V1.5.0
*
* Revision Table:
* -----------------------------------------------------------------------
* V1.0.0 <Original Project 1 Submitted>
* V1.1.0 <Convert Structures to Objects(Classes) - Requirements For Chapter 13 - Grid.h | Position.h>
* V1.2.0 <Requirements For Chapter 14 - PlayersScore.h>
* V1.3.0 <Requirements For Chapter 15 - Base.h | Derived.h>
* V1.4.0 <Separate Specification vs Implementation - Base.h | Base.cpp | Grid.cpp | PlayersScore.cpp | Position.cpp | Derived.h>
* V1.5.0 <Requirements For Chapter 16 - Exceptions, Template and STL>
* -----------------------------------------------------------------------
*/

//LIBRARIES
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include "Grid.h"
#include "PlayersScore.h"
#include "Base.h"
#include "Derived.h"
#include "ReadFromKeyboard.h"

//NAMESPACE STD
using namespace std;

//DEFINE CONSTANTS
const int MAX_ROWS = 10;
const int MAX_COLS = 7;
const int MAX_ARRAY = 50;

//DEFINE ENUMERATION
enum Games { PLAYERVSPLAYER, PLAYERVSCOMPUTER, RANDOM } games;
enum Boardsize { CLASSIC7X6, X54, X65, X87, X97 } boardsize;
enum Player { NONE, PLAYER1, PLAYER2 } player;

//FUNCTIONS
string* playerName();
PlayersScore player1;	//FOR USING OF OVERLOADING OPERATOR
PlayersScore player2;	//FOR USING OF OVERLOADING OPERATOR
void printPlayerOptions(Grid*);
void printGrid(int*, Grid*, string*, int);
void mainMenu(Base);
int readOptionfromKeyboard(int, int*, int, string);
void gameTypeMenu(Derived);
int gameLogic(int, Grid, int*);
bool evaluateHorizontal(int, Grid, int);
bool evaluateVertical(int, Grid, int);
bool evaluate45Degrees(int, Grid, int);
bool evaluate135Degrees(int, Grid, int);
int winLogic(int, Grid, int);
void someoneWon(string*, int, float);
void nobodyWon(int);
void writeBinaryFile(float);
float readBinaryFile();
void showScores(int, float, int, string);
void overloadOperators(Base, Derived);
string trim(const string&);	//CUSTOM TRIM FUNCTION
//FRIEND FUNCTION CLASS Grid
void gridsFriend(int, int, Grid&);

//MAIN
int main(int argc, char** argv)
{
	int gamesp = 0;
	Base baseh;	//Base Class
	Derived derivedh; //Derived Class from Base
	Grid grid(7,9);
	string* players;
	float score = 0.00;
	int rows = 6;
	int cols = 7;
	int positions;
	int boards = 0;
	int gamess = 0;
	int control1 = 0;
	int control2 = 0;
	int control3 = 0;
	int lastposchoice = 0;
	int won = 0;
	int playing = 0;
	players = new string[2];
	int movements = 0;

	writeBinaryFile(0.00);
	while (control1 == 0) {
		movements = 0;
		control2 = 0;
		control3 = 0;
		player = NONE;
		mainMenu(baseh);
		control1 = readOptionfromKeyboard(0, &boards, cols, "NONE");
		switch (boards)
		{
		case 1:
			boardsize = CLASSIC7X6;
			rows = 6;
			cols = 7;
			break;
		case 2:
			boardsize = X54;
			rows = 4;
			cols = 5;
			break;
		case 3:
			boardsize = X65;
			rows = 5;
			cols = 6;
			break;
		case 4:
			boardsize = X87;
			rows = 7;
			cols = 8;
			break;
		case 5:
			boardsize = X97;
			rows = 7;
			cols = 9;
			break;
		case 6:
			showScores(0, 0, 7, "");
			cout << endl;
			cout << "\t\tPress Enter to Go to the Main Menu...";
			getchar();
			cout << endl;
			cout << endl;
			break;
		default:
			break;
		}
		if (boards != 6) {						
			gridsFriend(rows, cols, grid);			
			positions = grid.getRows() * grid.getCols();	
			baseh.setBoardSize(positions);
			derivedh.setBoardSize(baseh.getBoardSize());
			if (control1 == 0) {
				if (playing == 0) {
					gameTypeMenu(derivedh);
					control2 = readOptionfromKeyboard(1, &gamess, cols, "NONE");
					switch (gamess)
					{
					case 1:
						games = PLAYERVSPLAYER;
						break;
					case 2:
						games = PLAYERVSCOMPUTER;
						break;
					case 3:
						games = RANDOM;
						break;
					default:
						break;
					}
				}
				if (control2 == 0) {
					if (playing == 0) {
						players = playerName();
						player1.setPlayer1n(players[0]); //FOR USE OF OVERLOADING OPERATOR
						player2.setPlayer1n(players[1]); //FOR USE OF OVERLOADING OPERATOR
					}
					playing = 1;
					while (control2 == 0) {
						if (player == NONE) {
							player = PLAYER1;
						}
						else if (player == PLAYER1) {
							player = PLAYER2;
						}
						else {
							player = PLAYER1;
						}
						if (control3 == 0) {
							printGrid(&positions, &grid, players, won);
							control3 = 2;
							while (control3 > 0) {
								control3 = readOptionfromKeyboard(2, &lastposchoice, cols, players[player - 1]);
								control3 = gameLogic(positions, grid, &lastposchoice);
								won = winLogic(positions, grid, lastposchoice);
								if (control3 == 0) {
									movements++;
								}
								if (won > 0) {
									score = readBinaryFile(); //READ CUMULATIVE SCORE TO BE READY FOR A NEW
									if (player == PLAYER1) {
										player1.setScore1();
									}
									else if (player == PLAYER2) {
										player2.setScore1();
									}
									score = score + player1.getWinn();	//Code before: score = score + 30.25;									
									writeBinaryFile(score);	//WRITE SCORE IN A BINARY FILE								
									printGrid(&positions, &grid, players, won);									
									control3 = 0;
									control2 = 1;
									control1 = 0;									
									someoneWon(players, grid.getCols(), score);					
									gamesp++;
									baseh.settGamesPlayed(gamesp);
									overloadOperators(baseh, derivedh);
									showScores(1, score, grid.getCols(), players[player - 1]);									
									won = 0;
									cout << endl;
									cout << "\t\tPress Enter to Go to the Main Menu...";
									getchar();
									cout << endl;
									cout << endl;
								}
								else {
									if (movements >= positions) {										
										nobodyWon(grid.getCols());
										control3 = 0;
										control2 = 1;
										control1 = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << endl;
	cout << "\t\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\t\tSee Your Later!!!... Thanks for Play Connect 4... Come Back Soon." << endl;
	cout << "\t\t--------------------------------------------------------------------------------------------" << endl;
	return 0;
}

//Define Player Names
string* playerName() {
	ReadFromKeyboard<string> skey("");	//USE OF EXCEPTION CLASS AND TEMPLATE
	static string name[2];
	string n;
	int control = 0;
	int control2 = 0;
	int control3 = 0;

	if (games != RANDOM) {
		while (control == 0) {
			control = 1;
			control2 = 0;
			control3 = 0;
			cout << endl;
			cout << "\t\tPlease, Insert the Name for Player #1:" << endl;
			cout << "\t\t-> ";
			getline(cin, n);			
			if (trim(n).length() > 0) {
				try {
					skey.setString(trim(n));
					name[0] = skey.getString();
					control = 1;
					control2 = 1;
				}
				catch (ReadFromKeyboard<string>::ThrowExceptionDouble e) {	//EXCEPTION CLASS
					control = 0;
				}

			}
			if (control == 1 && control2 == 1) { //At least 1 Character was type
				name[0] = n;
			}
			else {
				cout << "\t\tYou must Type At Least 1 Character, no Special Characters Allowed... Please, try Again." << endl;
				control = 0;
			}
			cin.clear();
			cin.sync();
			n = "";
		}
		control = 0;
		control2 = 0;
		control3 = 0;
	}
	else {
		name[0] = "COMPUTER";
	}
	if (games == PLAYERVSPLAYER) {
		while (control == 0) {
			control = 1;
			control2 = 0;
			control3 = 0;
			cout << endl;
			cout << "\t\tPlease, Insert the Name for Player #2:" << endl;
			cout << "\t\t-> ";
			getline(cin, n);			
			if (trim(n).length() > 0) {
				try {
					skey.setString(trim(n));
					name[1] = skey.getString();
					control = 1;
					control2 = 1;
				}
				catch (ReadFromKeyboard<string>::ThrowExceptionDouble e) {	//EXCEPTION CLASS
					control = 0;
				}

			}
			if (control == 1 && control2 == 1) { //At least 1 Character was type
				name[1] = n;
			}
			else {
				cout << "\t\tYou must Type At Least 1 Character, no Special Characters Allowed... Please, try Again." << endl;
				control = 0;
			}
			cin.clear();
			cin.sync();
			n = "";
		}
	}
	else {
		name[1] = "COMPUTER";
	}
	return name; //Return Player Name
}

//FUNCTION TO PRINT OPTIONS FOR CURRENT PLAYER
void printPlayerOptions(Grid* grid) {	
	int cols = grid->getCols();
	int colhelp = cols;
	string printChar[2] = { "11111","22222" };

	cout << endl;
	for (int x = 0; x < 3; x++) {
		cout << "\t\t       ";
		for (int y = 0; y < colhelp; y++) {
			if (player == PLAYER1) {
				cout << " " << printChar[0] << "  ";
			}
			else {
				cout << " " << printChar[1] << "  ";
			}
		}
		cout << endl;
	}
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
}

//FUNCTION TO PRINT THE BOARD GRID
void printGrid(int* positions, Grid* grid, string* players, int won) {
	Grid copyConstructor = *grid;	//Using Copy Constructor
	stringstream ss; //Concatenate all Characters to Show the Grid simulatinga a Graphic Interface.
	string coutstring; //Each line to Print in Screen	
	int rows = copyConstructor.getRows();	//Using Copy Constructor, original code was grid->getRows();
	int cols = copyConstructor.getCols();	//Using Copy Constructor, original code was grid->getCols();
	int pos = 0;
	int colhelp = cols;
	string printChar[3] = { "00000","11111","22222" };
	string boardstring = "";
	string gametypestring = "";

	//BOAR SIZE TITLE
	switch (boardsize)
	{
	case CLASSIC7X6:
		boardstring = "6 X 7";
		break;
	case X54:
		boardstring = "4 X 5";
		break;
	case X65:
		boardstring = "5 X 6";
		break;
	case X87:
		boardstring = "7 X 8";
		break;
	case X97:
		boardstring = "7 X 9";
		break;
	default:
		boardstring = "NONE";
		break;
	}
	//TYPE GAME TITLE
	switch (games)
	{
	case PLAYERVSPLAYER:
		gametypestring = "Player VS Player";
		break;
	case PLAYERVSCOMPUTER:
		gametypestring = "Player VS PC";
		break;
	case RANDOM:
		gametypestring = "PC VS PC";
		break;
	default:
		gametypestring = "NONE";
		break;
	}
	ss.str("");
	ss.clear();
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << "\t\tBOARD SIZE: " << boardstring << "\tGAME TYPE: " << gametypestring;
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << "\t\tCURRENT BOARD GAME STATUS:\t" << "PLAYER #" << player << ": " << players[(int)player - 1] << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << "\t\t       ";
	for (int x = 0; x < colhelp; x++) {
		cout << "|POS:" << x + 1 << "| ";
	}
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	printPlayerOptions(&copyConstructor);	//printPlayerOptions(grid);
	cout << endl;
	cout << endl;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {			
			if (copyConstructor.getPositionValue(pos) == 0) {	//if (grid->getPositionValue(pos) == 0) {
				ss << "\t" << printChar[0];
			}			
			else if (copyConstructor.getPositionValue(pos) == 1) {	//else if (grid->getPositionValue(pos) == 1) {
				ss << "\t" << printChar[1];
			}
			else {
				ss << "\t" << printChar[2];
			}

			if (y == cols - 1) {
				cout << "\t\t       ";
				cout << ss.str() << endl;
				cout << "\t\t       ";
				cout << ss.str() << endl;
				cout << "\t\t       ";
				cout << ss.str() << endl;
				cout << "\t";
				ss.str("");
				ss.clear();
			}
			pos++;
		}
		cout << endl;
	}
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	if (won == 0) {
		cout << endl;
		cout << "\t\tChoose a Position to Play:";
	}
}

//MAIN MENU
void mainMenu(Base baseh) {
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\t     ----------  Connect 4 - Board Game - by Domenico Venuti, Version V1.0  ----------      " << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t  ******   *******   *****   ***  *****   ***  *********    ******  *********         ******" << endl;
	cout << "\t ******   *********  ******  ***  ******  ***  *********   ******   *********        *******" << endl;
	cout << "\t***       ***   ***  *** *** ***  *** *** ***  ***        ***          ***          ***  ***" << endl;
	cout << "\t***       ***   ***  ***  ******  ***  ******  ******     ***          ***         *********" << endl;
	cout << "\t***       ***   ***  ***   *****  ***   *****  ***        ***          ***         *********" << endl;
	cout << "\t ******   *********  ***    ****  ***    ****  *********   ******      ***               ***" << endl;
	cout << "\t  ******   *******   ***     ***  ***     ***  *********    ******     ***               ***" << endl;
	cout << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\tMAIN MENU:" << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\t\tChoose a Board Size:" << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	baseh.getTextMenu();	
}

//OPTIONS FROM KEYBOARD
int readOptionfromKeyboard(int menuoption, int* option, int cols, string playername) {
	ReadFromKeyboard<int> ikey(0);	//USE OF EXCEPTION CLASS AND TEMPLATE
	string n;
	int control = 0;
	int control2 = 0;
	int control3 = 0;
	int value = 0;
	int randNum = 0;
	int numberclass = 0;
	stringstream ss;
	int c5;

	while (control == 0) {
		c5 = 0;
		control2 = 0;
		control3 = 0;
		control = 1;
		cout << endl;
		cout << "\t\t-> ";
		randNum = rand() % (cols - 1 + 1) + 1;
		if (playername == "COMPUTER") {
			ss << randNum;
			n = ss.str();
			ss.str("");
			ss.clear();
			cout << n << endl;
			cout << "\t\tPress Enter Process COMPUTER SELECTION...";
			getchar();
		}
		else {
			getline(cin, n);
		}
		try {
			numberclass = stoi(n);
			ikey.setInt(numberclass);
			n = to_string(ikey.getInt());			
		}
		catch (ReadFromKeyboard<int>::ThrowExceptionDouble e) {	//EXCEPTION CLASS
			c5 = 1;
			control3 = 0;
		}
		catch (exception e) {
			c5 = 1;
			control3 = 0;
		}
		if (c5 == 0) {
			if (n.length() < 2 && n.length() > 0) {
				for (char& c : n) {
					control2 = 1;
					if (isdigit(c) && control == 1) {
						*option = (int)c - 48;
						if (menuoption == 0 && *option < 8 && *option > 0) {
							control3 = 1;
						}
						else if (menuoption == 1 && *option < 5 && *option > 0) {
							control3 = 1;
						}
						else if (menuoption == 2 && *option <= cols && *option > 0) {
							control3 = 1;
						}
					}
					else {
						if (control3 != 1) {
							control = 0;
						}
					}
				}
			}
		}
		if (control3 == 0) {
			cout << "\t\tWrong Option Typed, no Special Characters Allowed... Please, try Again." << endl;
			control = 0;
		}
		cin.clear();
		cin.sync();
		n = "";
	}
	if (menuoption == 0) {
		if (*option == 7) {
			value = 7;
		}
		else {
			value = 0;
		}
	}
	else if (menuoption == 1) {
		if (*option == 4) {
			value = 4;
		}
		else {
			value = 0;
		}
	}
	else {
		value = 0;
	}
	return value;
}

//GAME TYPE OPTIONS
void gameTypeMenu(Derived derivedh) {
	derivedh.getTextMenu();	
}

//GAME LOGIC
int gameLogic(int positions, Grid grid, int* option) {
	int value = 0;
	int counter = 0;
	int lastx = 0;
	int playervalue = 1;
	int column = *option - 1;
	
	switch (player)
	{
	case PLAYER1:
		playervalue = 1;
		break;
	default:
		playervalue = 2;
		break;
	}
	if (positions <= grid.getnSquares()) {
		for (int x = 0; x < positions; x++) {
			if (grid.getPositionY(x) == column && grid.getPositionValue(x) == 0) {
				lastx = x;
				counter++;
			}
		}
	}
	else {
		counter = 0;
	}
	if (counter > 0) {		
		grid.setPositionValue(lastx, playervalue);
		*option = lastx;
		value = 0;
	}
	else {
		value = 1;
		cout << endl;
		cout << "\t\tYou can't make that Move, Please, Choose a Different Position." << endl;
	}	
	return value;
}

//EVALUATE HORIZONTAL
bool evaluateHorizontal(int positions, Grid grid, int option) {
	int col;
	int row;
	int value;
	int control1 = 0;
	bool won = false;

	for (int pos1 = 0; pos1 < positions; pos1++) {		
		col = grid.getPositionY(pos1);
		row = grid.getPositionX(pos1);
		value = grid.getPositionValue(pos1);
		if (value > 0) {
			for (int y = col; y < col + 4; y++) {
				for (int pos2 = 0; pos2 < positions; pos2++) {					
					if (grid.getPositionX(pos2) == row && grid.getPositionY(pos2) == y && grid.getPositionValue(pos2) == value) {
						control1++;
					}
				}
			}
		}
		if (control1 >= 4) {
			pos1 = positions;
			won = true;
		}
		else {
			control1 = 0;
		}
	}
	return won;
}

//EVALUATE VERTICAL
bool evaluateVertical(int positions, Grid grid, int option) {
	int col;
	int row;
	int value;
	int control1 = 0;
	bool won = false;

	for (int pos1 = 0; pos1 < positions; pos1++) {		
		col = grid.getPositionY(pos1);
		row = grid.getPositionX(pos1);
		value = grid.getPositionValue(pos1);
		if (value > 0) {
			for (int x = row; x > row - 4; x--) {
				for (int pos2 = 0; pos2 < positions; pos2++) {
					if (grid.getPositionX(pos2) == x && grid.getPositionY(pos2) == col && grid.getPositionValue(pos2) == value) {
						control1++;
					}
				}
			}
		}
		if (control1 >= 4) {
			pos1 = positions;
			won = true;
		}
		else {
			control1 = 0;
		}
	}
	return won;
}

//EVALUATE DIAGONAL 45 DEGREES
bool evaluate45Degrees(int positions, Grid grid, int option) {
	int col;
	int row;
	int value;
	int control1 = 0;
	bool won = false;
	int y = 0;

	for (int pos1 = 0; pos1 < positions; pos1++) {		
		col = grid.getPositionY(pos1);
		row = grid.getPositionX(pos1);
		value = grid.getPositionValue(pos1);
		if (value > 0) {
			y = col - 1;
			for (int x = row; x > row - 4; x--) {
				if (y < col + 4) {
					y = y + 1;
				}
				for (int pos2 = 0; pos2 < positions; pos2++) {
					if (grid.getPositionX(pos2) == x && grid.getPositionY(pos2) == y && grid.getPositionValue(pos2) == value) {
						control1++;
					}
				}
			}
		}
		if (control1 >= 4) {
			pos1 = positions;
			won = true;
		}
		else {
			control1 = 0;
		}
	}
	return won;
}

//EVALUATE DIAGONAL 135 DEGREES 
bool evaluate135Degrees(int positions, Grid grid, int option) {
	int col;
	int row;
	int value;
	int control1 = 0;
	bool won = false;
	int y = 0;

	for (int pos1 = 0; pos1 < positions; pos1++) {		
		col = grid.getPositionY(pos1);
		row = grid.getPositionX(pos1);
		value = grid.getPositionValue(pos1);
		if (value > 0) {
			y = col - 1;
			for (int x = row; x < row + 4; x++) {
				if (y < col + 4) {
					y = y + 1;
				}
				for (int pos2 = 0; pos2 < positions; pos2++) {
					if (grid.getPositionX(pos2) == x && grid.getPositionY(pos2) == y && grid.getPositionValue(pos2) == value) {
						control1++;
					}
				}
			}
		}
		if (control1 >= 4) {
			pos1 = positions;
			won = true;
		}
		else {
			control1 = 0;
		}
	}
	return won;
}

//MAIN GAME LOGIC FUNCTION
int winLogic(int positions, Grid grid, int option) {
	int won = 0;
	bool horizontal = false;
	bool vertical = false;
	bool d45d = false;
	bool d135d = false;

	//EVALUATE HORIZONTAL
	horizontal = evaluateHorizontal(positions, grid, option);
	//EVALUATE VERTICAL
	vertical = evaluateVertical(positions, grid, option);
	//EVALUATE DIAGONAL 45 DEGREES
	d45d = evaluate45Degrees(positions, grid, option);
	//EVALUATE DIAGONAL 135 DEGREES
	d135d = evaluate135Degrees(positions, grid, option);
	if (player == PLAYER1 && (horizontal == true || vertical == true || d45d == true || d135d == true)) {
		won = 1;
	}
	else if (player == PLAYER2 && (horizontal == true || vertical == true || d45d == true || d135d == true)) {
		won = 2;
	}
	else {
		won = 0;
	}
	return won;
}

//SOMEBODY WON
void someoneWon(string* players, int cols, float score) {
	int colhelp = cols;

	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << endl;
	cout << "\t\tPLAYER #" << player << " WON!!!!!... " << players[player - 1] << " Congratulations!!!" << endl;
	cout << setprecision(2) << fixed << "\t\tCUMULATIVE SCORE: " << score << endl;
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
}

//DRAW
void nobodyWon(int cols) {
	int colhelp = cols;

	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
	cout << endl;
	cout << "\t\tNOBODY WON.... THE GAME ENDED IN DRAW!!..." << endl;
	cout << endl;
	cout << "\t\t***";
	for (int x = 0; x < colhelp + 2; x++) {
		cout << "*******";
	}
	cout << endl;
}

//WRITE CUMULATIVE IN A BINARY FILE
void writeBinaryFile(float cumulative) {
	string name = "cumulative.dat";
	ofstream outFile;
	string cumulativet = to_string(cumulative);
	int size1 = (cumulativet.size());

	outFile.open(name, ios::out | ios::binary);
	if (outFile.is_open()) {
		outFile.write(reinterpret_cast<char*>(&size1), sizeof(int));
		outFile.write(cumulativet.c_str(), size1);
	}
	else {
		cout << "File was not Found or can't be opened...";
	}
	outFile.close();
}

//READ CUMULATIVE FROM A BINARY FILE
float readBinaryFile() {
	string name = "cumulative.dat";
	string cumulativet = "00000000000000000000";
	ifstream outFile;
	float cumulative = 0.00;
	char* buf;
	int size1 = (cumulativet.size());

	outFile.open(name, ios::in | ios::binary);
	if (outFile.is_open()) {
		outFile.read(reinterpret_cast<char*>(&size1), sizeof(int));
		buf = new char[size1];
		outFile.read(buf, size1);
		cumulativet = "";
		cumulativet.append(buf, size1);
	}
	else {
		cout << "File was not Found or can't be opened...";
	}
	outFile.close();
	cumulative = stof(cumulativet);
	return cumulative;
}

//SHOW SCORES:
void showScores(int option, float cumulativescore, int cols, string playername) {
	vector<float> scorev;	//STL
	vector<string> namesv;	//STL
	float score = 0.00;
	string name = "";
	string filename = "scores.csv";
	string filename2 = "names.csv";
	int x = 0;
	int y = 0;
	string line;
	string line2;
	ifstream infile;
	ifstream infile2;
	ofstream outfile;
	ofstream outfile2;
	int colhelp = cols;
	int control1 = 0;

	if (option == 1) {
		outfile.open(filename, ios::app);
		outfile2.open(filename2, ios::app);
		if (outfile.is_open() && outfile2.is_open()) {
			outfile << endl;
			outfile2 << endl;
			outfile << fixed << setprecision(2) << cumulativescore;
			outfile2 << playername;
			y++;
		}
		if (y == 0) {
			cout << endl;
			cout << "\t\tFiles couldn't be Created, Data was not transfered..." << endl;
			cout << endl;
		}
		outfile.close();
		outfile2.close();
	}
	infile.open(filename, ios::in);
	infile2.open(filename2, ios::in);
	if (infile.is_open() && infile2.is_open()) {
		while (getline(infile, line)) {
			scorev.push_back(stof(line));
			x++;
		}
		infile.close();
		if (x > 0) {
			x = 0;
			while (getline(infile2, line2)) {
				namesv.push_back(line2);
				x++;
			}
		}
		infile2.close();
		if (x == 0 || (namesv.size() != scorev.size())) {
			cout << endl;
			cout << "\t\tFile is Empty or Corrupted... Can't Show Scores... Please, Fix Files and Try Again..." << endl;
		}
		else {
			while (control1 == 0) {
				control1 = 1;
				for (int x = 0; x < namesv.size() - 1; x++) {
					if (scorev.at(x + 1) > scorev.at(x)) {
						score = scorev.at(x + 1);
						name = namesv.at(x + 1);
						scorev.at(x + 1) = scorev.at(x);
						namesv.at(x + 1) = namesv.at(x);
						scorev.at(x) = score;
						namesv.at(x) = name;
						control1 = 0;
					}
				}
			}
			cout << "\t--------------------------------------------------------------------------------------------" << endl;
			cout << endl;
			cout << "\t  ******   *******   *****   ***  *****   ***  *********    ******  *********         ******" << endl;
			cout << "\t ******   *********  ******  ***  ******  ***  *********   ******   *********        *******" << endl;
			cout << "\t***       ***   ***  *** *** ***  *** *** ***  ***        ***          ***          ***  ***" << endl;
			cout << "\t***       ***   ***  ***  ******  ***  ******  ******     ***          ***         *********" << endl;
			cout << "\t***       ***   ***  ***   *****  ***   *****  ***        ***          ***         *********" << endl;
			cout << "\t ******   *********  ***    ****  ***    ****  *********   ******      ***               ***" << endl;
			cout << "\t  ******   *******   ***     ***  ***     ***  *********    ******     ***               ***" << endl;
			cout << endl;
			cout << "\t--------------------------------------------------------------------------------------------" << endl;
			cout << "\t--------------------------------------------------------------------------------------------" << endl;
			cout << endl;
			cout << "\t\t***";
			for (int x = 0; x < colhelp + 2; x++) {
				cout << "*******";
			}
			cout << endl;
			cout << "\t\t\tConnect 4 - HALL OF FAME:" << endl;
			cout << "\t\t***";
			for (int x = 0; x < colhelp + 2; x++) {
				cout << "*******";
			}
			cout << endl;

			cout << "\t\t\tRANK\t\tSCORE\t\t\tNAME" << endl;
			cout << "\t\t***";
			for (int x = 0; x < colhelp + 2; x++) {
				cout << "*******";
			}
			cout << endl;
			cout << endl;
			for (int x = 0; x < namesv.size(); x++) {
				cout << fixed << setprecision(2);
				cout << "\t\t\t " << x + 1 << "\t\t" << scorev.at(x) << "\t\t\t" << namesv.at(x) << endl;
			}
			cout << endl;
			cout << "\t\t***";
			for (int x = 0; x < colhelp + 2; x++) {
				cout << "*******";
			}
			cout << endl;
		}
	}
	else {
		cout << endl;
		cout << "\t\tFiles In didn't Exist...";
	}
	cout << endl;
}

//FRIEND FUNCTION TO Grid CLASS
void gridsFriend(int rows, int cols, Grid& gfriend) {
	gfriend.setRows(rows);
	gfriend.setCols(cols);
	gfriend.setPositionsNew(0);
}
//FUNCTION USING OVERLOADING OPERATORS
void overloadOperators(Base baseh, Derived derivedh) {
	PlayersScore ptp = player1 + player2;	//+ OPERATOR
	PlayersScore ptm = player1 - player2;	//- OPERATOR
	PlayersScore ptd = player1 / player2;	// / OPERATOR

	cout << endl;
	cout << "\t\tThe Current Total Points Won by All Players Are Equal to : " << ptp.getScore1() << " Points." << endl;
	cout << "\t\tThe Difference in Points Between All Players Are Equal to : " << ptm.getScore1() << " Points." << endl;
	cout << "\t\tPorcentage that Each Player Won from Total Point is Equal to : " << endl << "\t\tPLAYER 1: " << player1.getPlayer1n() << " = " << ptd.getP1() << "%" << "\t" << "PLAYER 2: " << player2.getPlayer1n() << " = " << ptd.getP2() << "%" << endl << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl;
	cout << "\t\tGames Played: " << baseh.gettGamesPlayes() << "\t\t--- " << "Maximum Positions Allowed in Last Game Played: " << derivedh.getBoardSize() << endl;
	cout << "\t--------------------------------------------------------------------------------------------" << endl << endl;

}

//CUSTOM FUNCTION TRIM
string trim(const string& s)
{
	auto start = s.begin();
	while (start != s.end() && std::isspace(*start)) {
		start++;
	}

	auto end = s.end();
	do {
		end--;
	} while (std::distance(start, end) > 0 && std::isspace(*end));

	return std::string(start, end + 1);
}