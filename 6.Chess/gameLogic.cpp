
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
		else if (firstMove == true && beg[0] - end[0] == 2 &&  board[beg[0] - 2][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == 1 || beg[0] - end[0] == 2)) { result= true; }
		else if (firstMove == false && beg[1] == end[1] && (beg[0] - end[0]) == 1) { result = true; }
		else if (targetColor == black && (beg[0] - end[0] == 1) && (abs(beg[1] - end[1]) == 1)) { result = true; }
		else { result = false; }

	}
	else if (_color == black) {
		if (beg[0] == 1) { firstMove = true; }
		else firstMove = false;

		if (board[beg[0] + 1][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[0]-end[0] == -2 && board[beg[0] + 2][beg[1]].getPiece() != emptyPiece && end[1] == beg[1]) { result = false; }
		else if (firstMove == true && beg[1] == end[1] && (beg[0] - end[0] == -1 || beg[0] - end[0] == -2)) { result = true; }
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


bool Board::Check(int* _king) {
	
	bool result = false;
	Colors kingColor = board[_king[0]][_king[1]].getColor();
	Pieces checkPiece;
	int array[2];
	Colors tempColor;
	for (int i = 0; i < 8; i++) {

		for (int k = 0; k < 8; k++) {

			if (board[i][k].getColor() != kingColor && (board[i][k].getColor() != emptyColor)) {
				tempColor = (kingColor==white)? black : white;
				checkPiece = board[i][k].getPiece();
				array[0] = i;
				array[1] = k;
				switch (checkPiece) {
				case pawn: 
					if (movePawn(array, _king, tempColor)) {
						result = true;
					}
					break;
				case knight:
					if (moveKnight(array, _king, tempColor)) {
						result = true;
					}
					break;
				case rook:
					if (moveRook(array, _king, tempColor)) {
						result = true;
					}
					break;
				case queen:
					if (moveQueen(array, _king, tempColor)) {
						result = true;
					}
					break;
				case bishop:
					if (moveBishop(array, _king, tempColor)) {
						result = true;
					}
					break;
				default: 
					result = false;
				}
			}
			if (result) break;
		}
		if (result) break;

	}
	return result;
}

bool Board::EndGame(int* _king, Colors _kingColor) {
	bool end = true;
	Pieces temPiece;
	Colors temColor;
	int* TempCoords = new int[2];
	for (int i = -1; i < 2; i++) {
		for (int k = -1; k < 2; k++) {
		
			TempCoords[0] = (_king[0] + i) > 7 ? abs(_king[0] - i) : abs(_king[0] + i);
			TempCoords[1] = (_king[1] + k) > 7 ? abs(_king[1] - k) : abs(_king[1] + k);
			if(moveKing(_king,TempCoords, _kingColor)) {
				temPiece = board[TempCoords[0]][TempCoords[1]].getPiece();
				temColor = board[TempCoords[0]][TempCoords[1]].getColor();
				move(_king,TempCoords);
				if (!Check(TempCoords)) {
					end = false;
				}
				move(TempCoords, _king);
				board[TempCoords[0]][TempCoords[1]].setColor(temColor);
				board[TempCoords[0]][TempCoords[1]].setPiece(temPiece);
			}
			if (!end) break;

		}
		if (!end) break;
	}

	return end;

}
