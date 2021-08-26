
#include "Header.h"
#include "Square.h"
#pragma once



class Board

{
	public:		
	Square board[8][8];
	int* whiteKing = transformcoords(41);
	int* blackKing = transformcoords(48);
	bool checking, checkWhite = false, checkBlack = false;
	int* coordBegin = 0;
	int* coordend = 0;
	int beginning, target;

	Pieces beginPiece;
	Colors beginColor;
	string message;
	string correct = "Nastepna tura!";
	string fault = "Niepoprawny ruch!";

	void newBoard();
	void printBoard();
	void newGame();
	void movePiece();
	void move(int _beginning, int _target);
	bool movePawn(int* beg, int* end, Colors _color);
	int* transformcoords(int _coords);
	bool moveRook(int* _beginning, int* _target, Colors _color);
	bool moveKnight(int* _beg, int* _end, Colors _color);
	bool moveBishop(int* _beg, int* _end, Colors _color);
	bool moveKing(int* _beg, int* _end, Colors _color);
	bool moveQueen(int* _beg, int* _end, Colors _color);
	bool Check(int* _king);

};

