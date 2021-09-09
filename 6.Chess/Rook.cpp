#include "Rook.h"
Rook::Rook(Colors _color) {

	squareColor = _color;
	squarePiece = rook;
}
//
//bool Rook::move(int* beg, int* end, Figure board[]) {
//
//	Colors targetColor;
//	bool clearTarget = true;
//	targetColor = board[_end[0]][_end[1]].getColor();
//	int counter = 0;
//
//	if (_beg[0] != _end[0]) counter = abs(_beg[0] - _end[0]) - 1;
//	if (_beg[1] != _end[1]) counter = abs(_beg[1] - _end[1]) - 1;
//
//	if (_beg[0] > _end[0]) {
//		for (int i = counter; i > 0; i--) {
//
//			if (board[_beg[0] - i][_beg[1]].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//
//	//ruch w dó³
//	if (_beg[0] < _end[0]) {
//		for (int i = counter; i > 0; i--) {
//
//			if (board[_beg[0] + i][_beg[1]].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//	//ruch w prawo
//
//	if (_beg[1] < _end[1]) {
//
//		for (int i = counter; i > 0; i--) {
//
//			if (board[_beg[0]][_beg[1] + i].getPiece() != emptyPiece) {
//				clearTarget = false;
//
//				break;
//			}
//		}
//	}
//	//ruch w lewo
//	if (_beg[1] > _end[1]) {
//		for (int i = counter; i > 0; i--) {
//
//			if (board[_beg[0]][_beg[1] - i].getPiece() != emptyPiece) {
//				clearTarget = false;
//				break;
//			}
//		}
//	}
//	if ((clearTarget && _color != targetColor)) {
//
//		if (_beg[0] != _end[0] && _beg[1] == _end[1]) return true;
//		else if (_beg[0] == _end[0] && _beg[1] != _end[1]) return true;
//		else {
//
//			return false;
//		}
//
//	}
//	else return false;
//
//
//}