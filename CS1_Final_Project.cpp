/*
Program name: CS1_Final_Project
Author: Gabriel Dennett
Date: 12/16/19
Purpose: game of Sorry
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Player {
	int Position = 1;
	string Name;
};

Player Player1, Player2, Player3, Player4;
//struct and struct variables for players.

int diceValues[1000], player_number, die1, die2, dice, index, enter, yes_no = 1, x, y, position1 = 0, position2 = 0, position3 = 0, position4 = 0, z;
int players[4] = { Player1.Position, Player2.Position, Player3.Position, Player4.Position };
// integer lists

void Debug_output() {
	cout << "Player1.Position " << players[0] << endl;
	cout << "Player2.Position " << players[1] << endl;
	cout << "Player3.Position " << players[2] << endl;
	cout << "Player4.Position " << players[3] << endl;
	cout << "dice " << dice << endl;
	cout << "die1 " << die1 << endl;
	cout << "die2 " << die2 << endl;
	cout << "player_number " << player_number << endl;
	cout << "index " << index << endl;
	cout << endl;
}
//Debugging function that shows values of variables that I wanted to see were being tracked.



void winning_Space() {
	if (players[0] > 60) {
		players[0] = 50;
		cout << "Uh-oh, you have to roll the exact number of spaces to get on 60! You'll be sent back to space 50 to try again! SORRY!" << endl;
	}
	if (players[1] > 60) {
		players[1] = 50;
		cout << "Uh-oh, you have to roll the exact number of spaces to get on 60! You'll be sent back to space 50 to try again! SORRY!" << endl;
	}
	if (players[2] > 60) {
		players[2] = 50;
		cout << "Uh-oh, you have to roll the exact number of spaces to get on 60! You'll be sent back to space 50 to try again! SORRY!" << endl;
	}
	if (players[3] > 60) {
		players[3] = 50;
		cout << "Uh-oh, you have to roll the exact number of spaces to get on 60! You'll be sent back to space 50 to try again! SORRY!" << endl;
	}
}
//winning_Space function determines if someone over rolled getting to space 60.

void dice_values_list(int diceValues[]) {
	index = 0;
	do {
		cout << "Here is a list of the numbers rolled during the game: " << endl;
		diceValues[0] = 1;
	} while ((index < 1000) && (diceValues[index] >= 0) && index++); {
		index = 1;
		cout << diceValues[index];
	};
}
// dice_values_list lists out the values of rolls that are stored up to 1000 rolls.

void rolling_Dice(int diceValues[]) {
	die1 = (rand() % 6) + 1;//This section generates simulated dice values and then adds them up.
	die2 = (rand() % 6) + 1;
	dice = die1 + die2;
	index = 1;
	diceValues[index] = dice;//This section stores values of dice.
	index++;
	
	cout << "You rolled a " << die1 << " and a " << die2 << ", which comes up to a total of " << dice << "!" << endl;//This section outputs the dice values.
}
//rolling_Dice generates simulated dice, stores the values and outputs them.

int mainGame() {
	while (players[0] < 60 && players[1] < 60 && players[2] < 60 && players[3] < 60) {
		switch (player_number) {
		case 1:
			cout << "Please select 2-4 players: " << endl;
			cin >> player_number;
			break;
		case 2:
			cout << "It is " << Player1.Name << "'s turn, please roll the dice.(Press 1, then hit enter.)" << endl;//player 1 intro
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 1.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[0] = players[0] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[0] = players[0] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[0] = players[0] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[0] = players[0] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[0] = players[0] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				if (players[0] > players[1]) {
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				/*if (players[0] > players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if (players[0] > players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[0] = players[0];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[0] = players[0] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[0] = players[0] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				if (players[0] < players[1]) {
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				/*if (players[0] < players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if (players[0] < players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[0] = 1;
				break;
			}
			if (players[0] == players[1]) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[0] = 1;
			}
			cout << Player1.Name << " is on space number " << players[0] << endl;

			//position and landing on other players space for player 1.
			//checkpoint
			//Debug_output();

			cout << "It is " << Player2.Name << "'s turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
			cin >> enter;
			rolling_Dice(diceValues);

			//else if statement for dice roll- player 2.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[1] = players[1] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[1] = players[1] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[1] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[1] = players[1] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (Player2.Position == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[1] = players[1] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[1] = players[1] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				if (players[1] > players[0]) {
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				/*if (players[1] > players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if (players[1] > players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[1] = players[1];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[1] = players[1] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[1] = players[1] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				if (players[1] < players[0]) {
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				/*if (players[1] < players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if (players[1] < players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[1] = 1;
				break;
			}
			//else if statement for dice roll- player 2.
			if (players[1] == players[0]) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[1] = 1;
			}
			cout << Player2.Name << " is on space number " << players[1] << endl;
			//Debug_output();
			winning_Space();
			cout << Player1.Name << " is on space number " << players[0] << ", and " << Player2.Name << " is on space number " << players[1] << "!" << endl;
			
			break;
			//case 2 end.
		case 3://case 3 start.
			cout << "It is " << Player1.Name << "'s turn, please roll the dice.(Press 1, then hit enter.)" << endl;//player 1 intro
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 1.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[0] = players[0] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[0] = players[0] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[0] = players[0] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[0] = players[0] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[0] = players[0] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				if (players[0] > players[1]) {
					x = players[1];
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				if (players[0] > players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if ((players[0] < players[1]) && (players[0] < players[2])) {
					if (x == players[2]) {
						z = players[1];
					players[1] = players[2];
					players[2] = z;
						}
				}
				/*if (players[0] > players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[0] = players[0];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[0] = players[0] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[0] = players[0] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				if (players[0] < players[1]) {
					x = players[1];
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				if (players[0] < players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if ((players[0] > players[1]) && (players[0] > players[2])) {
					if (x == players[2]) {
						z = players[1];
						players[1] = players[2];
						players[2] = z;
					}
				}
				/*if (players[0] < players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[0] = 1;
				break;
			}
			Debug_output();
			if ((players[0] == players[1]) || (players[0])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[0] = 1;
			}

			cout << Player1.Name << " is on space number " << players[0] << endl;
			//position and landing on other players space for player 1.
			//checkpoint
			//Debug_output();

			cout << "It is " << Player2.Name << "'s turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
			cin >> enter;
			rolling_Dice(diceValues);

			//else if statement for dice roll- player 2.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[1] = players[1] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[1] = players[1] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[1] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[1] = players[1] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[1] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[1] = players[1] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[1] = players[1] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				if (players[1] > players[0]) {
					x = players[0];
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				if (players[1] > players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if ((players[1] < players[0]) && (players[1] < players[2])) {
					if (x == players[2]) {
						z = players[1];
						players[1] = players[2];
						players[2] = z;
					}
				}
				/*if (players[1] > players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[1] = players[1];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[1] = players[1] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[1] = players[1] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				if (players[1] < players[0]) {
					x = players[0];
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				if (players[1] < players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if ((players[1] > players[0]) && (players[1] > players[2])) {
					if (x == players[2]) {
						z = players[1];
						players[1] = players[2];
						players[2] = z;
					}
				}
				/*if (players[1] < players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[1] = 1;
				break;
			}
			//else if statement for dice roll- player 2.
			if ((players[1] == players[0]) || (players[1] == players[2])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[1] = 1;
			}
			Debug_output();
			cout << Player2.Name << " is on space number " << players[1] << endl;

			//player 3 turn.
			cout << "It is " << Player3.Name << "'s turn, please roll the dice.(Press 3, then hit enter.)" << endl;
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 3.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[2] = players[2] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[2] = players[2] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[2] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[2] = players[2] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[2] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[2] = players[2] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[2] = players[2] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				if (players[2] > players[0]) {
					x = players[0];
					z = players[2];
					players[2] = players[0];
					players[0] = z;
				}
				if (players[2] > players[1]) {
					z = players[2];
					players[2] = players[1];
					players[1] = z;
				}
				if ((players[2] < players[0]) && (players[2] < players[1])) {
					if (x == players[1]) {
						z = players[1];
						players[1] = players[2];
						players[2] = z;
					}
				}
				/*if (players[2] > players[3]) {
					z = players[2];
					players[2] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[2] = players[2];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[2] = players[2] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[2] = players[2] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				if (players[2] < players[0]) {
					x = players[0];
					z = players[2];
					players[2] = players[0];
					players[0] = z;
				}
				if (players[2] < players[1]) {
					z = players[2];
					players[2] = players[1];
					players[1] = z;
				}
				if ((players[2] > players[0]) && (players[0] > players[1])) {
					if (x == players[0]) {
						z = players[1];
						players[1] = players[2];
						players[2] = z;
					}
				}
				/*if (players[2] < players[3]) {
					z = players[2];
					players[2] = players[3];
					players[3] = z;
				}*/
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[2] = 1;
				break;
			}
			Debug_output();
			if ((players[2] == players[0]) || (players[2] == players[1])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[2] = 1;
			}
			cout << Player3.Name << " is on space number " << players[2] << endl;
			//position and landing on other players space for player 1.
			//checkpoint
			winning_Space();
			cout << Player1.Name << " is on space number " << players[0] << ", " << Player2.Name << " is on space number " << players[1] << ", and " << Player3.Name << " is on space number " << players[2] << "!" << endl;
			//Debug_output();
			
			break;
			//case 3 end.
		case 4://case 4 start.
			cout << "It is " << Player1.Name << "'s turn, please roll the dice.(Press 1, then hit enter.)" << endl;//player 1 intro
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 1.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[0] = players[0] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[0] = players[0] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[0] = players[0] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[0] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[0] = players[0] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[0] = players[0] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				x = players[1];
				if (players[0] > players[1]) {
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				y = players[2];
				if (players[0] > players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if (players[0] > players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}
				if ((players[0] < players[1]) && (players[0] < players[2]) && (players[0] < players[3])) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[2];
						players[2] = z;
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[0] = players[0];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[0] = players[0] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[0] = players[0] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				x = players[1];
				if (players[0] < players[1]) {
					z = players[0];
					players[0] = players[1];
					players[1] = z;
				}
				y = players[2];
				if (players[0] < players[2]) {
					z = players[0];
					players[0] = players[2];
					players[2] = z;
				}
				if (players[0] < players[3]) {
					z = players[0];
					players[0] = players[3];
					players[3] = z;
				}
				if ((players[0] > players[1]) && (players[0] > players[2]) && (players[0] > players[3])) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[2];
						players[2] = z;
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[0] = 1;
				break;
			}
			if ((players[0] == players[1]) || (players[0] == players[2]) || (players[0] == players[3])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[0] = 1;
			}
			cout << Player1.Name << " is on space number " << players[0] << endl;
			//position and landing on other players space for player 1.
			//checkpoint
			//Debug_output();

			cout << "It is " << Player2.Name << "'s turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
			cin >> enter;
			rolling_Dice(diceValues);

			//else if statement for dice roll- player 2.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[1] = players[1] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[1] = players[1] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[1] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[1] = players[1] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (Player2.Position == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[1] = players[1] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[1] = players[1] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				x = players[0];
				if (players[1] > players[0]) {
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				y = players[2];
				if (players[1] > players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if (players[1] > players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}
				if ((players[1] < players[0]) && (players[1] < players[2]) && (players[1] < players[3])) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[2];
						players[2] = z;
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[1] = players[1];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[1] = players[1] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[1] = players[1] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				x = players[0];
				if (players[1] < players[0]) {
					z = players[1];
					players[1] = players[0];
					players[0] = z;
				}
				players[2];
				if (players[1] < players[2]) {
					z = players[1];
					players[1] = players[2];
					players[2] = z;
				}
				if (players[1] < players[3]) {
					z = players[1];
					players[1] = players[3];
					players[3] = z;
				}
				if ((players[1] > players[0]) && (players[1] > players[2]) && (players[1] > players[3])) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[2];
						players[2] = z;
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[1] = 1;
				break;
			}
			//else if statement for dice roll- player 2.
			if ((players[1] == players[0]) || (players[1] == players[2]) || (players[1] == players[3])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[1] = 1;
			}
			cout << Player2.Name << " is on space number " << players[1] << endl;
			//Debug_output();

			//player 3 turn.
			cout << "It is " << Player3.Name << "'s turn, please roll the dice.(Press 3, then hit enter.)" << endl;
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 3.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[2] = players[2] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[2] = players[2] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[2] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[2] = players[2] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[2] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[2] = players[2] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[2] = players[2] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				x = players[0];
				if (players[2] > players[0]) {
					z = players[2];
					players[2] = players[0];
					players[0] = z;
				}
				y = players[1];
				if (players[2] > players[1]) {
					z = players[2];
					players[2] = players[1];
					players[1] = z;
				}
				if (players[2] > players[3]) {
					z = players[2];
					players[2] = players[3];
					players[3] = z;
				}
				if ((players[2] < players[0]) && (players[2] < players[1]) && players[2] < players[3]) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[1];
						players[1] = z;
					}
					if (x == players[1]) {
						z = players[0];
						players[0] = players[1];
						z = players[1];
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[2] = players[2];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[2] = players[2] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[2] = players[2] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				x = players[0];
				if (players[2] < players[0]) {
					z = players[2];
					players[2] = players[0];
					players[0] = z;
				}
				players[1];
				if (players[2] < players[1]) {
					z = players[2];
					players[2] = players[1];
					players[1] = z;
				}
				if (players[2] < players[3]) {
					z = players[2];
					players[2] = players[3];
					players[3] = z;
				}
				if ((players[2] > players[0]) && (players[2] > players[1]) && (players[2] > players[3])) {
					if (y == players[3]) {
						z = players[3];
						players[3] = players[1];
						players[1] = z;
					}
					if (x == players[1]) {
						z = players[0];
						players[0] = players[1];
						z = players[1];
					}
					if (x == players[3]) {
						z = players[3];
						players[3] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[2] = 1;
				break;
			}
			if ((players[2] == players[0]) || (players[2] == players[1]) || (players[2] == players[3])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[2] = 1;
			}
			cout << Player3.Name << " is on space number " << players[2] << endl;
			//position and landing on other players space for player 3.
			//checkpoint

			//Debug_output();

			//player 4 turn.
			cout << "It is " << Player4.Name << "'s turn, please roll the dice.(Press 4, then hit enter.)" << endl;
			cin >> enter;
			rolling_Dice(diceValues);

			// if else statement for dice roll- player 4.
			switch (dice) {
			case 2:
				cout << "You move two spaces ahead!" << endl;
				players[3] = players[3] + 2;
				diceValues[index] = dice;
				index++;
				break;
			case 3:
				cout << "You move 3 spaces ahead!" << endl;
				players[3] = players[3] + 3;
				diceValues[index] = dice;
				index++;
				break;
			case 4:
				if (players[3] == 1) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					players[3] = players[3] - 1;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 5:
				if (players[3] == 1) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 1!" << endl;
				}
				else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					players[3] = players[3] - 3;
				}
				diceValues[index] = dice;
				index++;
				break;
			case 6:
				cout << "You move 6 spaces ahead!" << endl;
				players[3] = players[3] + 6;
				diceValues[index] = dice;
				index++;
				break;
			case 7:
				x = players[0];
				if (players[3] > players[0]) {
					z = players[3];
					players[3] = players[0];
					players[0] = z;
				}
				y = players[1];
				if (players[3] > players[1]) {
					z = players[3];
					players[3] = players[1];
					players[1] = z;
				}
				if (players[3] > players[2]) {
					z = players[3];
					players[3] = players[2];
					players[2] = z;
				}
				if ((players[3] < players[0]) && (players[3] < players[1]) && players[3] < players[2]) {
					if (y == players[2]) {
						z = players[2];
						players[2] = players[1];
						players[1] = z;
					}
					if (x == players[1]) {
						z = players[0];
						players[0] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the last player! SORRY!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 8:
				cout << "You don't move this turn!" << endl;
				players[3] = players[3];
				diceValues[index] = dice;
				index++;
				break;
			case 9:
				cout << "You get to move 9 spaces!" << endl;
				players[3] = players[3] + 9;
				diceValues[index] = dice;
				index++;
				break;
			case 10:
				cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				players[3] = players[3] + 10;
				diceValues[index] = dice;
				index++;
				break;
			case 11:
				players[0];
				if (players[3] < players[0]) {
					z = players[3];
					players[3] = players[0];
					players[0] = z;
				}
				players[1];
				if (players[3] < players[1]) {
					z = players[3];
					players[3] = players[1];
					players[1] = z;
				}
				if (players[3] < players[2]) {
					z = players[3];
					players[3] = players[2];
					players[2] = z;
				}
				if ((players[3] > players[0]) && (players[3] > players[1]) && players[3] > players[2]) {
					if (y == players[2]) {
						z = players[2];
						players[2] = players[1];
						players[1] = z;
					}
					if (x == players[1]) {
						z = players[0];
						players[0] = players[1];
						z = players[1];
					}
					if (x == players[2]) {
						z = players[2];
						players[2] = players[1];
						z = players[1];
					}
				}
				cout << "You get to swap spaces with the leading player!" << endl;
				diceValues[index] = dice;
				index++;
				break;
			case 12:
				cout << "You get to start over! SORRY!" << endl;
				players[3] = 1;
				break;
			}
			if ((players[3] == players[0]) || (players[3] == players[1]) || (players[3] == players[2])) {//player landing on same space if statement!
				cout << "You landed on another players space, you get to go back to the beginning!" << endl;
				players[3] = 1;
			}
			cout << Player4.Name << " is on space number " << players[3] << endl;
			//position and landing on other players space for player 4.
			//checkpoint
			winning_Space();
			cout << Player1.Name << " is on space number " << players[0] << ", " << Player2.Name << " is on space number " << players[1] << ", " << Player3.Name << " is on\nspace number " << players[2] << " and " << Player4.Name << " is on space number " << players[3] << "!" << endl;
			//Debug_output();
			
			break;
		}
	}
		return 0;
}
//this is the mainGame function where most of the game takes place.




int main() {
	while (yes_no == 1) {
		cout << "Welcome to the game Sorry! Please input how many players will be playing today(2-4): " << endl;
		cin >> player_number;
		cout << "There are " << player_number << " players in this game." << endl;
		switch (player_number) { //switch statement for each 2, 3, or 4 players.
		case 2: cout << "Player 1, please input your name: " << endl;
			cin >> Player1.Name;
			cout << "Player 2, please input your name: " << endl;
			cin >> Player2.Name;
			cout << "It's gametime, where " << Player1.Name << " goes head to head with " << Player2.Name << " in a classic game of Sorry!" << endl;
			break;
		case 3: cout << "Player 1, please input your name: " << endl;
			cin >> Player1.Name;
			cout << "Player 2, please input your name: " << endl;
			cin >> Player2.Name;
			cout << "Player 3, please input your name: " << endl;
			cin >> Player3.Name;
			cout << "It's gametime, where " << Player1.Name << ", " << Player2.Name << " and " << Player3.Name << " duke out who's going to say sorry!" << endl;
			break;
		case 4: cout << "Player 1, please input your name: " << endl;
			cin >> Player1.Name;
			cout << "Player 2, please input your name: " << endl;
			cin >> Player2.Name;
			cout << "Player 3, please input your name: " << endl;
			cin >> Player3.Name;
			cout << "Player 4, please input your name: " << endl;
			cin >> Player4.Name;
			cout << "It's the full house showdown here, where " << Player1.Name << ", " << Player2.Name << ", " << Player3.Name << " and " << Player4.Name << " race to the finish line!" << endl;
			break;
		}
		
		mainGame();
		
		if (players[0] == 60) {
			cout << "Congrats on winning the game, player 1!" << endl;
		}
		else if (players[1] == 60) {
			cout << "Congrats on winning the game, player 2!" << endl;
		}
		else if (players[2] == 60) {
			cout << "Congrats on winning the game, player 3!" << endl;
		}
		else if (players[3] == 60) {
			cout << "Congrats on winning the game, player 4!" << endl;
		}
		//the if else statement that gives the congratulations.
		dice_values_list(diceValues);
		cout << endl;
		cout << "Would you like to play again(Yes/No, 1/0): ";
		cin >> yes_no;
		//input whether you want to play again or not.
		players[0] = 0;
		players[1] = 0;
		players[2] = 0;
		players[3] = 0;
	}
}




//code that might useful.
/*if (players[1] = players[0], players[1] = players[2], players[1] = players[3]) {
cout << Player2.Name << " landed on another players space! " << Player2.Name << " will start at the beginning! SORRY!" << endl;
players[1] = 0;
			}
			else {
			cout << Player2.Name << " is on space number " << players[1] << "!" << endl;
			}
*/