
#include "Header.h"
#pragma once

/// <summary>
/// Klasa Figura zawieraj¹ca informacje o danym pionku na szachownicy
/// </summary>
class Figure {
public:
	/// <summary>
	/// Pole przechowuj¹ce kolor pionka
	/// </summary>
	Colors squareColor; 
	/// <summary>
	/// Pole przechowuj¹ce rodzaj pionka
	/// </summary>
	Pieces squarePiece; 

	/// <summary>
	/// Funkcja zwaracaj¹ca kolor figury
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
	/// <param name="_color">Liczba przyporz¹dkowana do koloru</param>
	void setColor(int _color);
	/// <summary>
	/// Funcja zwracaj¹ca rodzaj pionka
	/// </summary>
	/// <returns>Rodzaj pionka</returns>
	Pieces getPiece();
	/// <summary>
	/// Funkcja przypisuj¹ca rodzaj do danego pionka
	/// </summary>
	/// <param name="_piece">Rodzaj pionka</param>
	void setPiece(Pieces _piece);
	/// <summary>
	/// Funkcja przypisuj¹ca rodzaj do danego pionka
	/// </summary>
	/// <param name="_piece">Liczba przypisana do rodzaju pionka</param>
	void setPiece(int _piece);
	/// <summary>
	/// Funkcja która "czyœci" pole wstawiaj¹c tam pionek o kolorze i rodzaju "empty"
	/// </summary>
	void resetSquare();
	/// <summary>
	/// Funkcja ktora sprawdza czy dany ruch pionkiem moze byc wykonany
	/// </summary>
	/// <returns>zwraca "True" jeœli ruch mo¿e byœ wykonany, zaœ "False" jeœli nie</returns>
	bool move();
};

