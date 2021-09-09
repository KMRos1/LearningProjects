#include "Pawn.h"


Pawn::Pawn(Colors _color) {

	squareColor = _color;
	squarePiece = pawn;
}
/*
bool Pawn::move(int* beg, int* end, Figure board[]) {

	Colors targetColor = board[end[0]][end[1]].getColor();
	bool firstMove = false;
	bool result;

	if (squareColor == white) {
		if (beg[0] == 6) { firstMove = true; }
		else firstMove = false;

		if (board[beg[0] - 1][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[0] - end[0] == 2 && board[beg[0] - 2][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == 1 || beg[0] - end[0] == 2)) { result = true; }
		else if (firstMove == false && beg[1] == end[1] && (beg[0] - end[0]) == 1) { result = true; }
		else if (targetColor == black && (beg[0] - end[0] == 1) && (abs(beg[1] - end[1]) == 1)) { result = true; }
		else { result = false; }

	}
	else if (squareColor == black) {
		if (beg[0] == 1) { firstMove = true; }
		else firstMove = false;

		if (board[beg[0] + 1][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[0] - end[0] == -2 && board[beg[0] + 2][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == -1 || beg[0] - end[0] == -2)) { result = true; }
		else if (firstMove == false && beg[1] == end[1] && (beg[0] - end[0]) == -1) { result = true; }
		else if (targetColor == white && (beg[0] - end[0] == -1) && (abs(beg[1] - end[1]) == 1)) { result = true; }
		else { result = false; }
	}
	else result = false;
	return result;

	

}
*/