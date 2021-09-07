#include "Square.h"



Colors Square::getColor() {return squareColor;}

void Square::setColor(Colors _color) {squareColor = _color;}
void Square::setColor(int _color) {
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

Pieces Square::getPiece() {return squarePiece;}

void  Square::setPiece(Pieces _piece) {squarePiece = _piece;}

void  Square::setPiece(int _piece) {
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

void  Square::resetSquare() {
	squareColor = emptyColor;
	squarePiece = emptyPiece;
	}

int  Square::getxAxis() { return xAxis; }

int  Square::getyAxis() { return yAxis; }

void  Square::setxAxis(int _xAxis) { xAxis = _xAxis;}

void  Square::setyAxis(int _yAxis) { yAxis = _yAxis;}
