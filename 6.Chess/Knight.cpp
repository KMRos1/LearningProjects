#include "Knight.h"
Knight::Knight(Colors _color) {
	squareColor = _color;
	squarePiece = knight;

}


//bool Knight::move(int* _beg, int* _end, Figure board[]) {
//
//	Colors targetColor;
//	targetColor = board[_end[0]][_end[1]].getColor();
//	int yDiff = abs(_beg[0] - _end[0]);
//	int xDiff = abs(_beg[1] - _end[1]);
//
//	if (_color != targetColor) {
//		if ((yDiff == 2 && xDiff == 1) || (yDiff == 1 && xDiff == 2)) return true;
//		else return false;
//
//	}
//	else return false;
//
//}