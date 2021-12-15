@mainpage Connect 4 - Board Game (V1.5.0)

<b>Author:</b> Domenico Venuti<br>
<b>First Version Created on December 5, 2021 at 6:00 PM<br></b>
<b>Purpose:</b> Project 2 - CIS-17A - C++ Objects - Board Game - Connect 4<br>
<b>Section#:</b> 48593<br>
<b>Current Version:</b> V1.5.0<br>
<br>
Revision Table:<br>
-----------------------------------------------------------------------<br>
V1.0.0 <Original Project 1 Submitted><br>
V1.1.0 <Convert Structures to Objects(Classes) - Requirements For Chapter 13 - Grid.h | Position.h><br>
V1.2.0 <Requirements For Chapter 14 - PlayersScore.h><br>
V1.3.0 <Requirements For Chapter 15 - Base.h | Derived.h><br>
V1.4.0 <Separate Specification vs Implementation - Base.h | Base.cpp | Grid.cpp | PlayersScore.cpp | Position.cpp | Derived.h><br>
V1.5.0 <Requirements For Chapter 16 - Exceptions, Template and STL><br>
-----------------------------------------------------------------------<br>

@tableofcontents <u><b>Table of Contents</b></u>

@section mainpagesection1 Introduction
<p>Connect 4 is a 47-year-old Board Game that I enjoyed a lot when I was a child, I always played with my sister, she usually won, well, she is 3 years older than me, it is understandable when I was only 7 years old.</p>
<p>The Classic board was made by Hasbro, it has 6 rows and 7 columns but you can find different variations in the market. For the project, the program allows you to choose between 5 different board sizes.</p>
![](img1.png)
<p>The game is simple, there are 2 players, each player chooses a color (for the project this was modified and you only choose to be player 1 or 2 when writing your name), player 1 starts the game by choosing the column where he/she wants to place his/her piece (player 1's pieces are identified with number 1 and player 2's with number 2, empty spaces are identified with number 0).</p>
<p>1. The Program Allow you to Choose between 5 Different Board Sizes (6 X 7,4 X 5,5 X 6,7 X 8 and 7 X 9).</p>
![](img2.png)
<p>Beside from being able to choose 5 different board sizes, to add more complexity I decided for this project to give the user the freedom to choose 3 Game Types:</p>
- Player Vs Player.<br>
- Player VS PC.<br>
- PC VS PC.<br>
![](img3.png)
<p>The piece must fall to the lowest place on the board corresponding to that column, in the case of a 6 x 7 board, the first piece will fall to row 6, if later a player chooses to place his/her piece on the same row, the new piece will fall to row 5 and so on, after player 1 does drop a piece, it is the turn of player 2 and so on.</p>
1. Pieces from Player 1 are Identified with Number 1.<br>
2. Pieces from Player 2 are Identified with Number 2.<br>
![](img4.png)
<p>To win the game, you must have at least 4 pieces of the same player in line, it can be a horizontal, vertical, or diagonal line (in the project, every time someone wins, the winner earns 30.25 points). If after filling all the empty spaces with pieces, it has not been possible to obtain 4 pieces from the same player in line, is a Draw.</p>
![](img5.png)

@section mainpagesection2 Description
<p>I am going to define the complexity of this program in 3 main areas. How to define winner. When is a Draw. How to make the computer play Automatically without having to create a separate code just for that.</p>
<br>
<b>a. Define a Winner:</b>
<p>To define a winner, I decided to create 4 functions that will review the 4 closest positions to each position on the board and determine if there are at least 4 in a horizontal, vertical, 45-degree diagonal or 135-degree diagonal with the same value, if player 1 wins it is because at least 4 have value 1, if player 2 wins it is because at least 4 have value 2.</p>
![](img6.png) 
<b>The 3 Functions to define a winner are:</b><br>
//EVALUATE HORIZONTAL<br>
horizontal = evaluateHorizontal(positions, grid, option);<br>
//EVALUATE VERTICAL<br>
vertical = evaluateVertical(positions, grid, option);	<br>
//EVALUATE DIAGONAL 45 DEGREES<br>
d45d = evaluate45Degrees(positions, grid, option);	<br>
//EVALUATE DIAGONAL 135 DEGREES<br>
d135d = evaluate135Degrees(positions, grid, option);<br>

<b>The Basic of the Logic for Each Function is this (All 4 Function use the same logic with small changes):</b><br>
for (int pos1 = 0; pos1 < positions; pos1++) {<br>
	col = grid.position[pos1].y;<br>
	row = grid.position[pos1].x;<br>
	value = grid.position[pos1].value;<br>
	if (value > 0) {<br>
		for (int x = row; x > row - 4; x--) {<br>
			for (int pos2 = 0; pos2 < positions; pos2++) {<br>
if (grid.position[pos2].x == x && grid.position[pos2].y == col && grid.position[pos2].value == value) {<br>
					control1++;<br>
				}<br>
			}<br>
		}<br>
	}<br>
	if (control1 >= 4) {<br>
		pos1 = positions;<br>
		won = true;<br>
	}<br>
	else {<br>
		control1 = 0;<br>
	}<br>
}<br>
<br>
<b>b. Draw:</b><br>
To know when a Draw occurred, I used 2 variables and a Function: <br>
-	Int positions: Total Positions available in a Board.<br>
-	int movements: Counts how many positions were played already in the Board<br>
-	int winLogic(int positions, Grid grid, int option): If someone Won, return 1, if nobody won Return 0.<br>
<br>
If (movements >= positions && won == 0): It is a Draw.<br>
<b>c. Computer Plays by Itself:</b><br>
When the option Player VS PC or PC Vs PC is chosen, the first thing the program does is assign the name of the player or players that are PCs as COMPUTER.<br>
For the Computer to play by itself, it use the same functions created for a human player but, if the name of the current player is COMPUTER the program ignores the keyboard input and uses a random number between 1 and the maximum columns of the board, if the move is valid it processes it, if it is not valid, it tries again until the move is valid, so the computer plays randomly.<br>
<br>
int randNum = 0; //Integer that will Generate a Random Number	<br>
stringstream ss;<br>
while (control == 0) {<br>
	control2 = 0;<br>
	control3 = 0;<br>
	control = 1;<br>
	cout << endl;<br>
	cout << "\t\t-> ";<br>
	randNum = rand() % (cols - 1 + 1) + 1; //Generates a Random int Between 1 and Max Columns.<br>
	if (playername == "COMPUTER") { //Decide if use the Random number or Read from Keyboard<br>
		ss << randNum;<br>
		n = ss.str(); //Assign Random Number to Variable n<br>
		ss.str("");<br>
		ss.clear();<br>
		cout << n << endl;<br>
		cout << "\t\tPress Enter Process COMPUTER SELECTION...";<br>
		getchar();<br>
	}<br>
	else {<br>
		getline(cin, n); //Read from Keyboard if the Player is Human<br>
	}<br>
<br>
<b>c. Sample In/Out.</b><br>
<p>Player 1 (Ray Romano) win game with a Vertical Line of 4 in Column 3 on a 4 X 5 Board Size Game. Because of that, earns 30.25 Points and Show the New Score in the Scores Table.<p>
![](img7.png)
Ray Won 30.24 Points<br>
![](img8.png)
Ray is un the Score Board as 5 with 30.25 Points<br>
![](img9.png)
Ray’s Name is the Last one in File names.csv<br>
![](img10.png)
Ray’s Score is the Last one in File scores.csv<br>

@section mainpagesection3 FlowCharts
![](flow1.png)<br><br>
![](flow1.png)<br><br>
![](flow1.png)<br><br>
![](flow3.png)<br><br>
