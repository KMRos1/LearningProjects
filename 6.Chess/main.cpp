#include <iostream>
#include <string>
#include "Board.h"

int main() {

	bool loop = false;
	Board game;
	char input;
	cout << "Hello! Wanna play a game?" << endl;
	cout << "If yes press Y, if no press N" << endl;
	cin >> input;
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