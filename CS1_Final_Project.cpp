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

struct Players {
	int Position = 0;
	string Name;
};

Players Player1, Player2, Player3, Player4;


int players[4], diceValues[1000], player_number, die1, die2, dice, index, enter, yes_no = 1;



void dice_values_list(int index) {
	index = 0;
	do {
		cout << "Here is a list of the numbers rolled during the game: " << endl;
	} while ((index < 1000) && (diceValues[index] > 0) && index++); {
		index = 0;
		cout << diceValues[index];

	};
}
// dice_values_list lists out the values of rolls that are stored up to 1000 rolls.

void rolling_Dice() {
	die1 = (rand() % 6) + 1;//This section generates simulated dice values and then adds them up.
	die2 = (rand() % 6) + 1;
	dice = die1 + die2;

	diceValues[index] = die1;//This section stores values of dice.
	index++;
	diceValues[index] = die2;
	index++;

	cout << "You rolled a " << die1 << " and a " << die2 << ", which comes up to a total of " << dice << "!" << endl;//This section outputs the dice values.
	
}
//rolling_Dice generates simulated dice, stores the values and outputs them.

void get_number_of_Players() {
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
}
//get_number_of_Players asks for the number of players, and asks for their names, and then produces a response.



int main() {
	while (yes_no == 1) {
			cout << "Welcome to the game Sorry! Please input how many players will be playing today(2-4): " << endl;
			get_number_of_Players();
			cout << endl;
			cout << player_number;
			cout << endl;

		while ((Player1.Position < 60) | (Player2.Position < 60) | (Player3.Position < 60) | (Player4.Position < 60)) {

			if (player_number == 2) {

				cout << "It is player 1's turn, please roll the dice.(Press 1, then hit enter.)" << endl;//player 1 intro
				cin >> enter;
				rolling_Dice();

				switch (dice) {
				case 2: cout << "You move two spaces ahead!" << endl;
					Player1.Position = Player1.Position + 2;
					diceValues[index] = dice;
					index++;
					break;

				case 3: cout << "You move 3 spaces ahead!" << endl;
					Player1.Position = Player1.Position + 3;

					diceValues[index] = dice;
					index++;
					break;

				case 4: if (Player1.Position == 0) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
				}
					  else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					Player1.Position = Player1.Position - 1;
				}
					  diceValues[index] = dice;
					  index++;
					  break;

				case 5: if (Player1.Position == 0) {
					cout << "Good news, you don't have to move back three spaces, bad news is, you're still at position 0!" << endl;
				}
					  else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					Player1.Position = Player1.Position - 3;
				}
					  diceValues[index] = dice;
					  index++;
					  break;

				case 6: cout << "You move 6 spaces ahead!" << endl;
					Player1.Position = Player1.Position + 6;

					diceValues[index] = dice;
					index++;
					break;

				case 7:if (Player1.Position > Player2.Position) {
					Player1.Position = Player2.Position;
				}
					  if (Player1.Position > Player3.Position) {
						  Player1.Position = Player3.Position;
					  }
					  if (Player1.Position > Player4.Position) {
						  Player1.Position = Player4.Position;
					  }
					  cout << "You get to swap spaces with the last player! SORRY!" << endl;
					  diceValues[index] = dice;
					  index++;
					  break;

				case 8: cout << "You don't move this turn!" << endl;
					diceValues[index] = dice;
					index++;
					break;

				case 9: cout << "You get to move 9 spaces!" << endl;
					Player1.Position = Player1.Position + 9;

					diceValues[index] = dice;
					index++;
					break;

				case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
					Player1.Position = Player1.Position + 10;

					diceValues[index] = dice;
					index++;
					break;

				case 11: if (Player1.Position < Player2.Position) {
					Player1.Position = Player2.Position;
				}
					   if (Player1.Position < Player3.Position) {
						   Player1.Position = Player3.Position;
					   }
					   if (Player1.Position < Player4.Position) {
						   Player1.Position = Player4.Position;
					   }
					   cout << "You get to swap spaces with the last player! SORRY!" << endl;
					   diceValues[index] = dice;
					   index++;
					   break;

				case 12: cout << "You get to start over! SORRY!" << endl;
					Player1.Position = 0;
					break;
				}
				//switch statement for player 1.

				if (Player1.Position = Player2.Position, Player1.Position = Player3.Position, Player1.Position = Player4.Position) {
					cout << Player1.Name << " landed on another players space! " << Player1.Name << " will start at the beginning! SORRY!" << endl;
					Player1.Position = 0;
				}
				else {
					cout << "Player 1 is on space number " << Player1.Position << "!" << endl;
				}
				//position and landing on other players space for player 1.

				cout << "It is player 2's turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
				cin >> enter;
				rolling_Dice();

				switch (dice) {
				case 2: cout << "You move two spaces ahead!" << endl;
					Player2.Position = Player2.Position + 2;

					diceValues[index] = dice;
					index++;
					break;

				case 3: cout << "You move 3 spaces ahead!" << endl;
					Player2.Position = Player2.Position + 3;

					diceValues[index] = dice;
					index++;
					break;

				case 4: if (Player2.Position == 0) {
					cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
				}
					  else {
					cout << "Uh-oh, you move back one space! SORRY!" << endl;
					Player2.Position = Player2.Position - 1;
				}
					  diceValues[index] = dice;
					  index++;
					  break;

				case 5: if (Player2.Position == 0) {
					cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
				}
					  else {
					cout << "Are running backwards!? You move back 3 spaces!" << endl;
					Player2.Position = Player2.Position - 3;
				}
					  diceValues[index] = dice;
					  index++;
					  break;

				case 6: cout << "You move 6 spaces ahead!" << endl;
					Player2.Position = Player2.Position + 6;


					diceValues[index] = dice;
					index++;
					break;

				case 7:if (Player2.Position > Player1.Position) {
					Player2.Position = Player1.Position;
				}
					  if (Player2.Position > Player3.Position) {
						  Player2.Position = Player3.Position;
					  }
					  if (Player2.Position > Player4.Position) {
						  Player2.Position = Player4.Position;
					  }
					  cout << "You get to swap spaces with the last player! SORRY!" << endl;
					  diceValues[index] = dice;
					  index++;
					  break;

				case 8: cout << "You don't move this turn!" << endl;
					diceValues[index] = dice;
					index++;
					break;

				case 9: cout << "You get to move 9 spaces!" << endl;
					Player2.Position = Player2.Position + 9;

					diceValues[index] = dice;
					index++;
					break;

				case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
					Player2.Position = Player2.Position + 10;

					diceValues[index] = dice;
					index++;
					break;

				case 11: if (Player2.Position < Player1.Position) {
					Player2.Position = Player1.Position;
				}
					   if (Player2.Position < Player3.Position) {
						   Player2.Position = Player3.Position;
					   }
					   if (Player2.Position < Player4.Position) {
						   Player2.Position = Player4.Position;
					   }
					   cout << "You get to swap spaces with the last player! SORRY!" << endl;
					   diceValues[index] = dice;
					   index++;
					   break;

				case 12: cout << "You get to start over! SORRY!" << endl;
					Player2.Position = 0;
					break;
				}
				//switch statement for player 2.

				if (Player2.Position = Player1.Position, Player2.Position = Player3.Position, Player2.Position = Player4.Position) {
					cout << Player2.Name << " landed on another players space! " << Player2.Name << " will start at the beginning! SORRY!" << endl;
					Player2.Position = 0;
				}
				else {
					cout << "Player 2 is on space number " << Player2.Position << "!" << endl;
				}
				//position and landing on other players space for player 2.
			}

			else if (player_number == 3) {
			cout << "It is player 1's turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 1 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player1.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player1.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player1.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player1.Position--;
				Player1.Position--;
				Player1.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player1.Position > Player2.Position) {
				Player1.Position = Player2.Position;
			}
				  if (Player1.Position > Player3.Position) {
					  Player1.Position = Player3.Position;
				  }
				  if (Player1.Position > Player4.Position) {
					  Player1.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player1.Position < Player2.Position) {
				Player1.Position = Player2.Position;
			}
				   if (Player1.Position < Player3.Position) {
					   Player1.Position = Player3.Position;
				   }
				   if (Player1.Position < Player4.Position) {
					   Player1.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player1.Position = 0;
				break;
			}
			//switch statement for player 1.

			if ((Player1.Position = Player2.Position) | (Player1.Position = Player3.Position) | (Player1.Position = Player4.Position)) {
				cout << Player1.Name << " landed on another players space! " << Player1.Name << " will start at the beginning! SORRY!" << endl;
				Player1.Position = 0;
			}else {
				cout << "Player 1 is on space number " << Player1.Position << "!" << endl;
			}
			//position and landing on other players space for player 1.

			cout << "It is player 2's turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player2.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player2.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player2.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player2.Position--;
				Player2.Position--;
				Player2.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player2.Position > Player1.Position) {
				Player2.Position = Player1.Position;
			}
				  if (Player2.Position > Player3.Position) {
					  Player2.Position = Player3.Position;
				  }
				  if (Player2.Position > Player4.Position) {
					  Player2.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player2.Position < Player1.Position) {
				Player2.Position = Player1.Position;
			}
				   if (Player2.Position < Player3.Position) {
					   Player2.Position = Player3.Position;
				   }
				   if (Player2.Position < Player4.Position) {
					   Player2.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player2.Position = 0;
				break;
			}
			//switch statement for player 2.

			if (Player2.Position = Player1.Position, Player2.Position = Player3.Position, Player2.Position = Player4.Position) {
				cout << Player2.Name << " landed on another players space! " << Player2.Name << " will start at the beginning! SORRY!" << endl;
				Player2.Position = 0;
			}
			else {
				cout << "Player 2 is on space number " << Player2.Position << "!" << endl;
			}
			//position and landing on other players space for player 2.


			cout << "It is player 3's turn, please roll the dice.(Press 3, then hit enter.)" << endl;//player 3 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player3.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player3.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player3.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player3.Position--;
				Player3.Position--;
				Player3.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player3.Position > Player1.Position) {
				Player3.Position = Player1.Position;
			}
				  if (Player3.Position > Player2.Position) {
					  Player3.Position = Player2.Position;
				  }
				  if (Player3.Position > Player4.Position) {
					  Player3.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player3.Position < Player1.Position) {
				Player3.Position = Player1.Position;
			}
				   if (Player3.Position < Player2.Position) {
					   Player3.Position = Player2.Position;
				   }
				   if (Player3.Position < Player4.Position) {
					   Player3.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player3.Position = 0;
				break;
			}
			//switch statement for player 3.

			if (Player3.Position = Player1.Position, Player3.Position = Player2.Position, Player3.Position = Player4.Position) {
				cout << Player3.Name << " landed on another players space! " << Player3.Name << " will start at the beginning! SORRY!" << endl;
				Player3.Position = 0;
			}
			else {
				cout << "Player 3 is on space number " << Player3.Position << "!" << endl;
			}
			//position and landing on other players space for player 3.
			}

			else (player_number = 4); {

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player1.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player1.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player1.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player1.Position--;
				Player1.Position--;
				Player1.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player1.Position > Player2.Position) {
				Player1.Position = Player2.Position;
			}
				  if (Player1.Position > Player3.Position) {
					  Player1.Position = Player3.Position;
				  }
				  if (Player1.Position > Player4.Position) {
					  Player1.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				Player1.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player1.Position < Player2.Position) {
				Player1.Position = Player2.Position;
			}
				   if (Player1.Position < Player3.Position) {
					   Player1.Position = Player3.Position;
				   }
				   if (Player1.Position < Player4.Position) {
					   Player1.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player1.Position = 0;
				break;
			}
			//switch statement for player 1.

			if (Player1.Position = Player2.Position, Player1.Position = Player3.Position, Player1.Position = Player4.Position) {
				cout << Player1.Name << " landed on another players space! " << Player1.Name << " will start at the beginning! SORRY!" << endl;
				Player1.Position = 0;
			}
			else {
				cout << "Player 1 is on space number " << Player1.Position << "!" << endl;
			}
			//position and landing on other players space for player 1.

			cout << "It is player 2's turn, please roll the dice.(Press 2, then hit enter.)" << endl;//player 2 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player2.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player2.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player2.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player2.Position--;
				Player2.Position--;
				Player2.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player2.Position > Player1.Position) {
				Player2.Position = Player1.Position;
			}
				  if (Player2.Position > Player3.Position) {
					  Player2.Position = Player3.Position;
				  }
				  if (Player2.Position > Player4.Position) {
					  Player2.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				Player2.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player2.Position < Player1.Position) {
				Player2.Position = Player1.Position;
			}
				   if (Player2.Position < Player3.Position) {
					   Player2.Position = Player3.Position;
				   }
				   if (Player2.Position < Player4.Position) {
					   Player2.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player2.Position = 0;
				break;
			}
			//switch statement for player 2.

			if (Player2.Position = Player1.Position, Player2.Position = Player3.Position, Player2.Position = Player4.Position) {
				cout << Player2.Name << " landed on another players space! " << Player2.Name << " will start at the beginning! SORRY!" << endl;
				Player2.Position = 0;
			}
			else {
				cout << "Player 2 is on space number " << Player2.Position << "!" << endl;
			}
			//position and landing on other players space for player 2.


			cout << "It is player 3's turn, please roll the dice.(Press 3, then hit enter.)" << endl;//player 3 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player3.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player3.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player3.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player3.Position--;
				Player3.Position--;
				Player3.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player3.Position > Player1.Position) {
				Player3.Position = Player1.Position;
			}
				  if (Player3.Position > Player2.Position) {
					  Player3.Position = Player2.Position;
				  }
				  if (Player3.Position > Player4.Position) {
					  Player3.Position = Player4.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				Player3.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player3.Position < Player1.Position) {
				Player3.Position = Player1.Position;
			}
				   if (Player3.Position < Player2.Position) {
					   Player3.Position = Player2.Position;
				   }
				   if (Player3.Position < Player4.Position) {
					   Player3.Position = Player4.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player3.Position = 0;
				break;
			}
			//switch statement for player 3.

			if (Player3.Position = Player1.Position, Player3.Position = Player2.Position, Player3.Position = Player4.Position) {
				cout << Player3.Name << " landed on another players space! " << Player3.Name << " will start at the beginning! SORRY!" << endl;
				Player3.Position = 0;
			}
			else {
				cout << "Player 3 is on space number " << Player3.Position << "!" << endl;
			}
			//position and landing on other players space for player 3.





			cout << "It is player 4's turn, please roll the dice.(Press 4, then hit enter.)" << endl;//player 4 intro
			cin >> enter;
			rolling_Dice();

			switch (dice) {
			case 2: cout << "You move two spaces ahead!" << endl;
				Player4.Position++;
				Player4.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 3: cout << "You move 3 spaces ahead!" << endl;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 4: if (Player4.Position == 0) {
				cout << "Good news, you don't have to move back one space, bad news is, you're still at position 0!" << endl;
			}
				  else {
				cout << "Uh-oh, you move back one space! SORRY!" << endl;
				Player4.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 5: if (Player4.Position == 0) {
				cout << "Good news, you don't have to move back three spaces, bad news is , you're still at position 01" << endl;
			}
				  else {
				cout << "Are running backwards!? You move back 3 spaces!" << endl;
				Player4.Position--;
				Player4.Position--;
				Player4.Position--;
			}
				  diceValues[index] = dice;
				  index++;
				  break;

			case 6: cout << "You move 6 spaces ahead!" << endl;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;

				diceValues[index] = dice;
				index++;
				break;

			case 7:if (Player4.Position > Player1.Position) {
				Player4.Position = Player1.Position;
			}
				  if (Player4.Position > Player2.Position) {
					  Player4.Position = Player2.Position;
				  }
				  if (Player4.Position > Player3.Position) {
					  Player4.Position = Player3.Position;
				  }
				  cout << "You get to swap spaces with the last player! SORRY!" << endl;
				  diceValues[index] = dice;
				  index++;
				  break;

			case 8: cout << "You don't move this turn!" << endl;
				diceValues[index] = dice;
				index++;
				break;

			case 9: cout << "You get to move 9 spaces!" << endl;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 10: cout << "Did you take a taxi cab? Move 10 spaces!" << endl;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				Player4.Position++;
				diceValues[index] = dice;
				index++;
				break;

			case 11: if (Player4.Position < Player1.Position) {
				Player4.Position = Player1.Position;
			}
				   if (Player4.Position < Player2.Position) {
					   Player4.Position = Player2.Position;
				   }
				   if (Player4.Position < Player3.Position) {
					   Player4.Position = Player3.Position;
				   }
				   cout << "You get to swap spaces with the last player! SORRY!" << endl;
				   diceValues[index] = dice;
				   index++;
				   break;

			case 12: cout << "You get to start over! SORRY!" << endl;
				Player4.Position = 0;
				break;
			}
			//switch statement for player 4

			if (Player4.Position = Player1.Position, Player4.Position = Player2.Position, Player4.Position = Player3.Position) {
				cout << Player4.Name << " landed on another players space! " << Player4.Name << " will start at the beginning! SORRY!" << endl;
				Player4.Position = 0;
			}
			else {
				cout << "Player 4 is on space number " << Player4.Position << "!" << endl;
			}
			//position and landing on other players space for player 4.
			}

			
			cout << "Player 1 is on space number " << Player1.Position << ", player 2 is on space number " << Player2.Position << ", player 3 is on\n space number "<< Player3.Position << " and player number 4 is on space number " << Player4.Position << "!" << endl;

		}
		if (Player1.Position == 60) {
			cout << "Congrats on winning the game " << Player1.Name << endl;
		}
		else if (Player2.Position == 60) {
			cout << "Congrats on winning the game, " << Player2.Name << endl;
		}
		else if (Player3.Position == 60) {
			cout << "Congrats on winning the game, " << Player3.Name << endl;
		}
		else (Player4.Position == 60); {
			cout << "Congrats on winning the game, " << Player4.Name << endl;
		}
		//the if else statement that gives the congratulations.
		
		cout << "Would you like to play again(Yes/No, 1/0): ";
		cin >> yes_no;
	}
}
