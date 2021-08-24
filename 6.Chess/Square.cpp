#include "Square.h"



Colors Square::getColor() {return squareColor;}

void Square::setColor(Colors _color) {squareColor = _color;}

Pieces  Square::getPiece() {return squarePiece;}

void  Square::setPiece(Pieces _piece) {squarePiece = _piece;}

void  Square::resetSquare() {
	squareColor = emptyColor;
	squarePiece = emptyPiece;
	}

int  Square::getxAxis() { return xAxis; }

int  Square::getyAxis() { return yAxis; }

void  Square::setxAxis(int _xAxis) { xAxis = _xAxis;}

void  Square::setyAxis(int _yAxis) { yAxis = _yAxis;}
