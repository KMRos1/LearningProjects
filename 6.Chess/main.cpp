#include <iostream>
#include <string>
#include "Board.h"

/// <summary>
/// G³ówna funkcja programu
/// </summary>
/// <returns></returns>
int main() {
	Board game;
	bool loop = false;
	char input;
	cout << "Hello! Wanna play a game?" << endl;
	cout << "If yes press Y, if no press N" << endl;
	cin >> input;
	input = toupper(input);
	if (input == 'Y') {
		system("cls");
		game.newGame();
		loop = true;
	}
	else {
		cout << "Maybe next time!" << endl;

	}
	while (loop) { 

		loop = game.theGame();
	}
	system("cls");

	cout << "That was a good game, wanna try again?" << endl;
	cout << "If yes press Y, if no press N" << endl;
	cin >> input;
	input = toupper(input);

	if (input == 'Y') {
		system("cls");
		return main();
	}
	else {
		system("cls");
		cout << "Have a nice day!" << endl;
		return 0;
	}
	

//	return 0;
}

