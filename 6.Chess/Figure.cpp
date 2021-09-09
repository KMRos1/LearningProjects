#include "Figure.h"



Colors Figure::getColor() {return squareColor;}

void Figure::setColor(Colors _color) {squareColor = _color;}
void Figure::setColor(int _color) {
	Colors color;

	switch (_color) {

	case 0: 
		color = white;
		break;
	case 1:
		color = black;
		break;
	case 2:
		color = emptyColor;
		break;
	default:
		color = emptyColor;
	}
	squareColor = color;


}

Pieces Figure::getPiece() {return squarePiece;}

void  Figure::setPiece(Pieces _piece) {squarePiece = _piece;}

void  Figure::setPiece(int _piece) {
	Pieces piece;
	switch (_piece) {
	case 0:
		piece = pawn;
		break;

	case 1:
		piece = knight;
		break;
	case 2:
		piece = bishop;
		break;
	case 3:
		piece = rook;
		break;
	case 4:
		piece = queen;
		break;
	case 5:
		piece = king;
		break;
	case 6:
		piece = emptyPiece;
		break;
	default: 
		piece = emptyPiece;
	}

	squarePiece = piece;


}

void  Figure::resetSquare() {
	squareColor = emptyColor;
	squarePiece = emptyPiece;
	}

bool Figure::move() { return true; }