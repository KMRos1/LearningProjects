#include <iostream>
#include <string>
#include "Board.h"

int main() {

	bool loop = true;
	Board game;
	game.newGame();

	while (true) {
		game.movePiece();
	}
	return 0;
}