#include "Bishop.h"

Bishop::Bishop(Colors _color) {
	squareColor = _color;
	squarePiece = bishop;

}

//bool Bishop::Move(int* _beg, int* _end, Figure board[]) {
//
//	Colors targetColor;
//	bool clearTarget = true;
//	targetColor = board[_end[0]][_end[1]].getColor();
//	int yDiff = abs(_beg[0] - _end[0]) - 1;
//	int xDiff = abs(_beg[1] - _end[1]) - 1;
//
//	if (_beg[0] > _end[0] && _beg[1] > _end[1]) {
//		for (int i = yDiff; i > 0; i--) {
//
//			if (board[_beg[0] - i][_beg[1] - i].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//
//	if (_beg[0] > _end[0] && _beg[1] < _end[1]) {
//		for (int i = yDiff; i > 0; i--) {
//
//			if (board[_beg[0] - i][_beg[1] + i].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//
//	if (_beg[0] < _end[0] && _beg[1] > _end[1]) {
//		for (int i = yDiff; i > 0; i--) {
//
//			if (board[_beg[0] + i][_beg[1] - i].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//	if (_beg[0] < _end[0] && _beg[1] < _end[1]) {
//		for (int i = yDiff; i > 0; i--) {
//
//			if (board[_beg[0] + i][_beg[1] + i].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//
//
//	if (_color != targetColor && yDiff == xDiff && clearTarget) return true;
//	else return false;
//}