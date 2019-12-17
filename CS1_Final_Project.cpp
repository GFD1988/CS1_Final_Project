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
	int Position[60];
	string Name;
};

Players Player1, Player2, Player3, Player4;
int players[4], player_number, y, x, die1, die2, dice;


int dice_values_list(int index = 0) {
	int diceValues[1000];
	do {
		cout << "Here is a list of the numbers rolled during the game: " << endl;
	} while (index < 1000, diceValues[index] > 0, index++); {
		cout << diceValues[index];

	}
	return 0;
}

int rolling_Dice(int diceValues[1000]) {
	die1 = (rand() % 6) + 1;
	die2 = (rand() % 6) + 1;
	dice = die1 + die2;

	cout << "You rolled a " << die1 << " and a " << die2 << ", which comes up to a total of " << dice << " moves!" << endl;
	return 0;
}

int get_number_of_Players() {
	int player_number;
	cin >> player_number;
	cout << "There are " << player_number << " players in this game." << endl;
	switch (player_number) {
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
		cout << "It's the full house showdown here, where " << Player1.Name << ", " << Player2.Name << ", " << Player3.Name << " and " << Player4.Name << "race to the finish line!" << endl;
		break;
		return 0;
	}

}




int main() {
	while (Player1.Position[60] != 59, Player2.Position[60] != 59, Player3.Position[60] != 59, Player4.Position[60] != 59) {
		cout << "Welcome to the game Sorry! Please input how many players will be playing today(2-4): " << endl;
		cout << get_number_of_Players();



























	}





}