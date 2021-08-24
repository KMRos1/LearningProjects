
#include "Header.h"
#pragma once

enum Colors { white, black, emptyColor };
enum Pieces { pawn, knight, bishop, rook, queen, king, emptyPiece };
class Square {

	int xAxis, yAxis;
	Colors squareColor;
	Pieces squarePiece;
public:
	Colors getColor();
	void setColor(Colors _color);
	Pieces getPiece();
	void setPiece(Pieces _piece);
	void resetSquare();
	int getxAxis();
	int getyAxis();
	void setxAxis(int _xAxis);
	void setyAxis(int _yAxis);

};

