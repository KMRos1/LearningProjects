
#include "Header.h"
#include "Square.h"
#pragma once



class Board

{
	public:		
	Square board[8][8];
	int* whiteKing = transformcoords(41);
	int* blackKing = transformcoords(48);
	bool checking, checkWhite = false, checkBlack = false, continueGame = true;
	int* coordBegin = 0;
	int* coordend = 0;
	int beginning, target;
	int* attacker = new int[2]; 
	Colors actualPlayer = white;
	string playerMessage;


	Pieces beginPiece;
	Colors beginColor;
	string message;
	char smth;
	string correct = "Next turn!";
	string fault = "Incorrect move!";

	void newBoard();
	void printBoard();
	void newGame();
	bool theGame();
	void move(int _beginning, int _target);
	void move(int* _beginning, int* _target);
	bool movePawn(int* beg, int* end, Colors _color);
	int* transformcoords(int _coords);
	bool moveRook(int* _beginning, int* _target, Colors _color);
	bool moveKnight(int* _beg, int* _end, Colors _color);
	bool moveBishop(int* _beg, int* _end, Colors _color);
	bool moveKing(int* _beg, int* _end, Colors _color);
	bool moveQueen(int* _beg, int* _end, Colors _color);
	bool Check(int* _kingz);
	bool EndGame(int* _king,Colors _kingColor);
	void SaveGame();
	void LoadGame();
};

