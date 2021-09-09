#include "King.h"


King::King(Colors _color) {
	squareColor = _color;
	squarePiece = king;

}
//bool King::move(int* _beg, int* _end, Figure board[]) {
//
//	Colors targetColor, _color;
//	_color = board[_beg[0]][_beg[1]].getColor();
//	targetColor = board[_end[0]][_end[1]].getColor();
//	int yDiff = abs(_beg[0] - _end[0]);
//	int xDiff = abs(_beg[1] - _end[1]);
//	if (_color != targetColor && xDiff <= 1 && yDiff <= 1) return true;
//	else return false;
//}