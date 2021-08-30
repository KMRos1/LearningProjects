#include "Board.h"
#include <iostream>


void Board::newBoard() {

	board[0][0].setColor(black);
	board[0][0].setPiece(rook);

	board[0][1].setColor(black);
	board[0][1].setPiece(knight);

	board[0][2].setColor(black);
	board[0][2].setPiece(bishop);

	board[0][3].setColor(black);
	board[0][3].setPiece(king);

	board[0][4].setColor(black);
	board[0][4].setPiece(queen);

	board[0][5].setColor(black);
	board[0][5].setPiece(bishop);

	board[0][6].setColor(black);
	board[0][6].setPiece(knight);

	board[0][7].setColor(black);
	board[0][7].setPiece(rook);

	for (int i = 0; i < 8; i++) {
		board[1][i].setColor(black);
		board[1][i].setPiece(pawn);

		board[6][i].setColor(white);
		board[6][i].setPiece(pawn);
	}

	for (int i = 2; i < 6; i++) {

		for (int k = 0; k < 8; k++) {
			board[i][k].setPiece(emptyPiece);
			board[i][k].setColor(emptyColor);
		}

	}
		
	board[7][0].setColor(white);
	board[7][0].setPiece(rook);

	board[7][1].setColor(white);
	board[7][1].setPiece(knight);

	board[7][2].setColor(white);
	board[7][2].setPiece(bishop);

	board[7][3].setColor(white);
	board[7][3].setPiece(king);

	board[7][4].setColor(white);
	board[7][4].setPiece(queen);

	board[7][5].setColor(white);
	board[7][5].setPiece(bishop);

	board[7][6].setColor(white);
	board[7][6].setPiece(knight);

	board[7][7].setColor(white);
	board[7][7].setPiece(rook);

}

void Board::printBoard(){
	string Icolor;
	string Ipiece;

	//string textLine;
		
	cout << "      1    2    3    4    5    6    7    8  " << endl;
	for (int k = 0; k < 8; k++) {
		cout << "  "<<abs(k-8) << " ";
		for (int i = 0; i < 8; i++) {

			Pieces localPiece = board[k][i].getPiece();

			if (board[k][i].getColor() == white) { Icolor = 'W'; }
			else Icolor = 'B';

			if (localPiece == rook) { Ipiece = 'R'; }
			else if (localPiece == knight) { Ipiece = 'K'; }
			else if (localPiece == bishop) { Ipiece = 'B'; }
			else if (localPiece == queen) { Ipiece = 'Q'; }
			else if (localPiece == pawn) { Ipiece = 'P'; }
			else Ipiece = 'X';

			
			if (localPiece == emptyPiece) { cout << "|   |"; }
			else cout << "|" + Icolor + "-" + Ipiece + "|";;
				
		}
		cout << " " << abs(k - 8);
		cout << endl;

	}
	cout << "      1    2    3    4    5    6    7    8  " << endl;
	cout << endl;
}

bool Board::theGame() {
	
	checking = true;
	Pieces temPiece;
	Colors temColor;
	playerMessage = (actualPlayer == white) ? "Bialy" : "Czarny";
	while (checking) {
		
		cout << "Aktualny gracz: " << playerMessage << endl;
		cout << "Podaj wspolrzedne pionka [XY]" << endl;
		cin >> beginning;
		coordBegin = transformcoords(beginning);
		beginPiece = board[coordBegin[0]][coordBegin[1]].getPiece();
		beginColor= board[coordBegin[0]][coordBegin[1]].getColor();
		if (coordBegin[0] < 0 || coordBegin[0] > 7 || coordBegin[1] < 0 || coordBegin[1] > 7)  cout << "niepoprawne wspolrzedne, sprobuj ponownie" << endl;
		else if(beginPiece==emptyPiece)  cout << "na tym polu nie ma bierki!" << endl; 
		else if (beginColor != actualPlayer) cout<< " Nie twoj ruch!" << endl;
		else checking = false;
		
	}
	checking = true;
		
	while (checking) {
		cout << "Podaj wspolrzedne docelowe [XY]" << endl;
		cin >> target;
		coordend = transformcoords(target);
		if (coordend[0] < 0 || coordend[0] > 7 || coordend[1] < 0 || coordend[1] > 7) cout << "niepoprawne wspolrzedne, sprobuj ponownie" << endl;
		else checking = false;
	}
	//cout << "black king y " << blackKing[0] << " black king x " << blackKing[1] << endl;
	switch (beginPiece) {

	case pawn:
		if (movePawn(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
			//cout << "pawn y " << coordend[0] << " pawn x " << coordend[1] << endl;
			if (beginColor == white && movePawn(coordend, blackKing, beginColor)) {
				checkWhite = true;
				attacker = coordend;
				message = "Check!";
			}
			else if (beginColor == black && movePawn(coordend, whiteKing, beginColor)) {
				checkBlack = true;
				attacker = coordend;
				message = "Check!";
			}
			
			else message = correct;
		}
		else message = fault;
		break;

	case rook:
		if (moveRook(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
			if (beginColor == white && moveRook(coordend, blackKing, beginColor)) {
				checkWhite = true;
				attacker = coordend;
				message = "Check!";
			}
			else if (beginColor == black && moveRook(coordend, whiteKing, beginColor)) {
				checkBlack = true;
				attacker = coordend;
				message = "Check!";
			}

			else message = correct;
		}
		else message = fault;

		break;

	case knight:
		if (moveKnight(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
			if (beginColor == white && moveKnight(coordend, blackKing, beginColor)) {
				checkWhite = true;
				attacker = coordend;
				message = "Check!";
			}
			else if (beginColor == black && moveKnight(coordend, whiteKing, beginColor)) {
				checkBlack = true;
				attacker = coordend;
				message = "Check!";
			}

			else message = correct;
		}
		else message = fault;

		break;

	case bishop:
		if (moveBishop(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
			if (beginColor == white && moveBishop(coordend, blackKing, beginColor)) {
				checkWhite = true;
				attacker = coordend;
				message = "Check!";
			}
			else if (beginColor == black && moveBishop(coordend, whiteKing, beginColor)) {
				checkBlack = true;
				attacker = coordend;
				message = "Check!";
			}

			else message = correct;
		}
		else message = fault;

		break;


	case king:
		if (moveKing(coordBegin, coordend, beginColor)) {
			temPiece = board[coordend[0]][coordend[1]].getPiece();
			temColor = board[coordend[0]][coordend[1]].getColor();
		
			move(beginning, target);
			if (!Check(coordend)) {
				message = correct;
				actualPlayer = (actualPlayer == white) ? black : white;
			}

			else {
				message = fault;
				move(target, beginning);
				board[coordend[0]][coordend[1]].setColor(temColor);
				board[coordend[0]][coordend[1]].setPiece(temPiece);
			}
			if (beginColor == white) whiteKing = coordend;
			if (beginColor == black) blackKing = coordend;


		}
		else message = fault;

		break;

	case queen:
		if (moveQueen(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
			if (beginColor == white && moveQueen(coordend, blackKing, beginColor)) {
				checkWhite = true;
				attacker = coordend;
				message = "Check!";

			}
			else if (beginColor == black && moveQueen(coordend, whiteKing, beginColor)) {
				checkBlack = true;
				attacker = coordend;
				message = "Check!";
			}

			else message = correct;
		}
		else message = fault;

		break;
	default:
		move(beginning, target);

	}
	if (Check(whiteKing)) {
		checkWhite = true;
		message = "Check White!";
	}
	else checkWhite = false;

	if (Check(blackKing)) {
		checkBlack = true;
		message = "Check Black!";
	}
	else checkBlack = false;

	if (checkWhite) {
		if (EndGame(whiteKing, white) && !Check(attacker)) {
			continueGame = false;
			message = "Good job, White win! ";
		}
		if (EndGame(whiteKing, white) && Check(attacker)) message = "Check!";
	}
	if (checkBlack) {
		if (EndGame(blackKing, black) && !Check(attacker)) {
			continueGame = false;
			message = "Good job!, Black Win!";
	}
		if (EndGame(blackKing, black) && Check(attacker)) message = "Check!";

	}
	
	system("cls");
	printBoard();
	cout << message << endl;
	if (continueGame) return true;
	else {
		cout << "Game ended! Press smtg to leave" << endl;
		cin >> smth;
		return false;

	}
	//return continueGame;

}
void Board::move(int _beginning, int _target) {
	Pieces oldPiece;
	Colors oldColor;
	int* beg = transformcoords(_beginning);
	int* end = transformcoords(_target);
	oldPiece = board[beg[0]][beg[1]].getPiece();
	oldColor = board[beg[0]][beg[1]].getColor();
	board[beg[0]][beg[1]].resetSquare();
	board[end[0]][end[1]].setColor(oldColor);
	board[end[0]][end[1]].setPiece(oldPiece);

}
void Board::move(int* _beginning, int* _target) {
	Pieces oldPiece;
	Colors oldColor;
	oldPiece = board[_beginning[0]][_beginning[1]].getPiece();
	oldColor = board[_beginning[0]][_beginning[1]].getColor();
	board[_beginning[0]][_beginning[1]].resetSquare();
	board[_target[0]][_target[1]].setColor(oldColor);
	board[_target[0]][_target[1]].setPiece(oldPiece);

}

void Board::newGame() {
	continueGame = true;
	newBoard();
	printBoard();
	
}

