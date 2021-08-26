
#include "Board.h"


int* Board::transformcoords(int _coords) {
	int* coords = new int[2];
	coords[0]= abs((_coords % 10) - 8);
	coords[1]= (_coords / 10) - 1;
	return coords;
}


bool Board::movePawn(int* beg, int* end, Colors _color) {

	
	Colors targetColor;
	bool firstMove = false;
	bool result;
	targetColor = board[end[0]][end[1]].getColor();

	
	if (_color == white) {
		if (beg[0] == 6) { firstMove = true; }
		else firstMove = false;

		if (board[beg[0] - 1][beg[1]].getPiece() != emptyPiece && end[1]==beg[1]) { result = false; }
		else if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == 1 || beg[0] - end[0] == 2)) { result= true; }
		else if (firstMove == false && beg[1] == end[1] && (beg[0] - end[0]) == 1) { result = true; }
		else if (targetColor == black && (beg[0] - end[0] == 1) && (abs(beg[1] - end[1]) == 1)) { result = true; }
		else { result = false; }

	}
	else if (_color == black) {
		if (beg[0] == 1) { firstMove = true; }
		else firstMove = false;

		if (board[beg[0] + 1][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == -1 || beg[0] - end[0] == -2)) { result = true; }
		else if (firstMove == false && beg[1] == end[1] && (beg[0] - end[0]) == -1) { result = true; }
		else if (targetColor == white && (beg[0] - end[0] == -1) && (abs(beg[1] - end[1]) == 1)) { result = true; }
		else { result = false; }
	}
	else result = false;
	return result;
	
}

bool Board::moveRook(int* _beg, int* _end, Colors _color) {

	Colors targetColor;
	bool clearTarget = true;
	targetColor = board[_end[0]][_end[1]].getColor();
	int counter=0;

	if (_beg[0] != _end[0]) counter = abs(_beg[0] - _end[0])-1;
	if (_beg[1] != _end[1]) counter = abs(_beg[1] - _end[1])-1;
	
	//ruch w góre
	//cout << "poczatek " << _beg[0] << " koniec " << _end[0] << " counter is " << counter << endl;
	if (_beg[0] > _end[0]) {
		for (int i = counter; i > 0; i--) {
			
			if (board[_beg[0] - i][_beg[1]].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}

	//ruch w dó³
	if (_beg[0] < _end[0]) {
		for (int i = counter; i > 0; i--) {

			if (board[_beg[0] + i][_beg[1]].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}
	//ruch w prawo

	if (_beg[1] < _end[1]) {

		for (int i = counter; i > 0; i--) {
			
			if (board[_beg[0]][_beg[1]+i].getPiece() != emptyPiece) {
				clearTarget = false;
				
				break;
			}
		}
	}
	//ruch w lewo
	if (_beg[1] > _end[1]) {
		for (int i = counter; i > 0; i--) {

			if (board[_beg[0]][_beg[1]-i].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}
	//cout << "color to " << _color << " a target color " << targetColor << " cleartarget " << clearTarget << endl;
	if ((clearTarget && _color != targetColor)) {

		if (_beg[0] != _end[0] && _beg[1] == _end[1]) return true;
		else if (_beg[0] == _end[0] && _beg[1] != _end[1]) return true;
		else {
			
			return false;
		}

	}
	else return false;


}

bool Board::moveKnight(int* _beg, int* _end, Colors _color) {

	Colors targetColor;
	targetColor = board[_end[0]][_end[1]].getColor();
	int yDiff = abs(_beg[0] - _end[0]);
	int xDiff = abs(_beg[1] - _end[1]);

	if (_color != targetColor) {
		if ((yDiff == 2 && xDiff == 1) || (yDiff == 1 && xDiff == 2)) return true;
		else return false;

	}
	else return false;

}

bool Board::moveBishop(int* _beg, int* _end, Colors _color) {

	Colors targetColor;
	bool clearTarget = true;
	targetColor = board[_end[0]][_end[1]].getColor();
	int yDiff = abs(_beg[0] - _end[0])-1;
	int xDiff = abs(_beg[1] - _end[1])-1;
	cout << "y1 " << _beg[0] << " y2 " << _end[0] << " yDiff is " << yDiff << endl;
	cout << "x1 " << _beg[1] << " x2 " << _end[1] << " xDiff is " << xDiff << endl;
	//cout << "color to " << _color << " a target color " << targetColor << " cleartarget " << clearTarget << endl;
	//cout << "poczatek " << _beg[0] << " koniec " << _end[0] << " counter is " << yDiff << endl;

	if (_beg[0] > _end[0] && _beg[1] > _end[1]) {
		for (int i = yDiff; i > 0; i--) {

			if (board[_beg[0] - i][_beg[1] - i].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}

	if (_beg[0] > _end[0] && _beg[1] < _end[1]) {
		for (int i = yDiff; i > 0; i--) {

			if (board[_beg[0] - i][_beg[1] + i].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}

	if (_beg[0] < _end[0] && _beg[1] > _end[1]) {
		for (int i = yDiff; i > 0; i--) {

			if (board[_beg[0] + i][_beg[1] - i].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}
	if (_beg[0] < _end[0] && _beg[1] < _end[1]) {
		for (int i = yDiff; i > 0; i--) {

			if (board[_beg[0] + i][_beg[1] + i].getPiece() != emptyPiece) {
				clearTarget = false;
				break;
			}
		}
	}


	if (_color != targetColor && yDiff == xDiff && clearTarget) return true;
	else return false;
}

bool Board::moveKing(int* _beg, int* _end, Colors _color) {

	Colors targetColor;
	targetColor = board[_end[0]][_end[1]].getColor();
	int yDiff = abs(_beg[0] - _end[0]);
	int xDiff = abs(_beg[1] - _end[1]);
	if (_color != targetColor && xDiff <= 1 && yDiff <= 1) return true;
	else return false;
}

bool Board::moveQueen(int* _beg, int* _end, Colors _color) {

	if(moveRook(_beg, _end, _color) || moveBishop(_beg, _end, _color )) return true;
	else return false;

}

//bool Board::Check(int* _king) {
//
//
//	Colors kingColor = board[_king[0]][_king[1]].getColor();
//	
//	bool result = false;
//	// look for pawn
//	for (int i = -1; i < 2; i += 2) {
//		for (int k = -1; i < 2; i += 2) {
//			if (board[_king[0] + i][_king[1] + k].getPiece() == pawn && board[_king[0] + i][_king[1] + k].getColor() != kingColor) {
//				result = true;
//				break;
//			}
//		}
//		if (result) break;
//	}
//
//	return result;
//}