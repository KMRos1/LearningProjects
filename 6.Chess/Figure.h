
#include "Header.h"
#pragma once

/// <summary>
/// Klasa Figura zawieraj�ca informacje o danym pionku na szachownicy
/// </summary>
class Figure {
public:
	/// <summary>
	/// Pole przechowuj�ce kolor pionka
	/// </summary>
	Colors squareColor; 
	/// <summary>
	/// Pole przechowuj�ce rodzaj pionka
	/// </summary>
	Pieces squarePiece; 

	/// <summary>
	/// Funkcja zwaracaj�ca kolor figury
	/// </summary>
	/// <returns></returns>
	Colors getColor();
	/// <summary>
	/// Fukcja przypisujaca kolor do pionka
	/// </summary>
	/// <param name="_color">Kolor pionka</param>
	void setColor(Colors _color);
	/// <summary>
	/// Fukcja przypisujaca kolor do pionka
	/// </summary>
	/// <param name="_color">Liczba przyporz�dkowana do koloru</param>
	void setColor(int _color);
	/// <summary>
	/// Funcja zwracaj�ca rodzaj pionka
	/// </summary>
	/// <returns>Rodzaj pionka</returns>
	Pieces getPiece();
	/// <summary>
	/// Funkcja przypisuj�ca rodzaj do danego pionka
	/// </summary>
	/// <param name="_piece">Rodzaj pionka</param>
	void setPiece(Pieces _piece);
	/// <summary>
	/// Funkcja przypisuj�ca rodzaj do danego pionka
	/// </summary>
	/// <param name="_piece">Liczba przypisana do rodzaju pionka</param>
	void setPiece(int _piece);
	/// <summary>
	/// Funkcja kt�ra "czy�ci" pole wstawiaj�c tam pionek o kolorze i rodzaju "empty"
	/// </summary>
	void resetSquare();
	/// <summary>
	/// Funkcja ktora sprawdza czy dany ruch pionkiem moze byc wykonany
	/// </summary>
	/// <returns>zwraca "True" je�li ruch mo�e by� wykonany, za� "False" je�li nie</returns>
	bool move();
};

