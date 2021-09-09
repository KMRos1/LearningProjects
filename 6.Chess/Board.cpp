#include "Board.h"

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
	playerMessage = (actualPlayer == white) ? "Bialy" : "Czarny";
		
	cout << "      1    2    3    4    5    6    7    8  " << endl;
	for (int k = 0; k < 8; k++) {
		cout << "  "<<abs(k-8) << " ";
		for (int i = 0; i < 8; i++) {

			Pieces localPiece = board[k][i].getPiece();

			if (board[k][i].getColor() == white) { Icolor = 'W'; }
			else if (board[k][i].getColor() == black) { Icolor = 'B'; }
			else Icolor = 'E';

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
	cout << " Jesli chcesz zapisac gre, wpisz 0" << endl;
	cout << " Jesli chcesz wczytac gre, wpisz 1" << endl << endl;
	cout << "Aktualny gracz: " << playerMessage << endl;
	cout << message << endl;
	
}

bool Board::theGame() {
	
	checking = true;

	while (checking) {
		while (checking) {
			std::cout << "Podaj wspolrzedne pionka [XY]" << endl;
			cin >> beginning;
			if (beginning == 0) {
				saveGame();
			}
			else if (beginning == 1) {

				loadGame();
			}
			else {
				coordBegin = transformcoords(beginning);
				beginPiece = board[coordBegin[0]][coordBegin[1]].getPiece();
				beginColor = board[coordBegin[0]][coordBegin[1]].getColor();
				if (coordBegin[0] < 0 || coordBegin[0] > 7 || coordBegin[1] < 0 || coordBegin[1] > 7) {
					system("cls");
					printBoard();
					std::cout << "niepoprawne wspolrzedne, sprobuj ponownie" << endl;
				}
				else if (beginPiece == emptyPiece) {

					system("cls");
					printBoard();
					std::cout << "na tym polu nie ma bierki!" << endl;
				}
				else if (beginColor != actualPlayer) {
					system("cls");
					printBoard();
					std::cout << " Nie twoj ruch!" << endl;
				}

				else checking = false;
			}
			if (checkWhite || checkBlack) {

				switch (beginPiece)
				{
				case pawn:
					if (!movePawn(coordBegin, attacker, beginColor)) {
						checking = true;
						std::cout << "Musisz uciec krolem" << endl;
					}
					break;
				case knight:
					if (!moveKnight(coordBegin, attacker, beginColor)) {
						checking = true;
						std::cout << "Musisz uciec krolem" << endl;
					}
					break;
				case rook:
					if (!moveRook(coordBegin, attacker, beginColor)) {
						checking = true;
						std::cout << "Musisz uciec krolem" << endl;
					}
					break;
				case bishop:
					if (!moveBishop(coordBegin, attacker, beginColor)) {
						checking = true;
						std::cout << "Musisz uciec krolem" << endl;
					}
					break;
				case queen:
					if (!moveQueen(coordBegin, attacker, beginColor)) {
						checking = true;
						std::cout << "Musisz uciec krolem" << endl;
					}
					break;
				default:
					checking = false;
					break;
				}
			}
		}
		checking = true;

		std::cout << "Podaj wspolrzedne docelowe [XY]" << endl;
		cin >> target;
		coordend = transformcoords(target);

		if (coordend[0] < 0 || coordend[0] > 7 || coordend[1] < 0 || coordend[1] > 7) std::cout << "niepoprawne wspolrzedne, sprobuj ponownie" << endl;
		else checking = false;
		if ((checkWhite || checkBlack) && beginPiece != king && (*coordend != *attacker)) {
			checking = true;
			system("cls");
			std::cout << "Musisz uciec krolem" << endl;
		}

		
	}

	checkMove(beginPiece);
	
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
	

	if (continueGame) return true;
	else {
		std::cout << "Game ended! Press smtg to leave" << endl;
		cin >> smth;
		return false;

	}


}
void Board::checkMove(Pieces _piece) {
	Pieces temPiece;
	Colors temColor;
	switch (_piece) {

	case pawn:
		if (movePawn(coordBegin, coordend, beginColor)) {
			move(beginning, target);
			actualPlayer = (actualPlayer == white) ? black : white;
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
				if (beginColor == white) whiteKing = coordend;
				if (beginColor == black) blackKing = coordend;
				actualPlayer = (actualPlayer == white) ? black : white;
			}

			else {
				message = fault;
				move(target, beginning);
				board[coordend[0]][coordend[1]].setColor(temColor);
				board[coordend[0]][coordend[1]].setPiece(temPiece);
			}



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

void Board::saveGame() {
	string file;

	std::cout << " Podaj nazwê pliku do zapisania" << endl;
	cin >> file;

	ofstream output(file);

	if (output.is_open()) {
		for (int i = 0; i < 8; i++) {

			for (int k = 0; k < 8; k++) {
				output << board[i][k].getPiece() << " - " << board[i][k].getColor() << "\n";

		}
		
		}

		output << actualPlayer <<" - " <<"-1" << "\n";
		output << message << "\n";
		output.close();
		std::cout << " Pli zapisany" << endl;



	}
	else {

		std::cout << " error " << endl;
	}

}

void Board::loadGame() {
	string file, line;
	int counter = 0;
	int arr[65][2];
	int size;

	std::cout << "podaj nazwe pliku do odczytania" << endl;
	cin >> file;


	ifstream input(file);
	if (input) {
		while (getline(input, line)) {
			if (counter < 65) {
				size_t sep = line.find(" -");
				arr[counter][0] = stoi(line.substr(0, sep));
				arr[counter][1] = stoi(line.substr(line.find("-") + 2));
			}
			else {
				message = line;
			}
			counter++;
		}
		counter = 0;
		for (int i = 0; i < 8; i++) {

			for (int k = 0; k < 8; k++) {
				board[i][k].setPiece(arr[counter][0]);
				board[i][k].setColor(arr[counter][1]);
				counter++;
			}
		}
		if (arr[counter][0] == 0) {
			actualPlayer = white;
		}
		else {
			actualPlayer = black;
		}
	}

	else {

		std::cout << " brak pliku" << endl;
	}
	input.close();
	system("cls");
	printBoard();
}