#pragma once
#include "Figure.h"
/// <summary>
/// Klasa opisuj¹ca Wie¿ê
/// </summary>
class Rook :
    public Figure
{
public:
     /// <summary>
     /// Konstruktor przypisuj¹cy kolor i rodzaj figury
     /// </summary>
     /// <param name="_color">Kolor figury</param>
     /// <returns>Zwraca obiekt klasy</returns>
    Rook(Colors _color);
    /// <summary>
    /// Funkcja sprawdzaj¹ca poprawnoœæ ruchu (Niedzia³aj¹ca)
    /// </summary>
    /// <param name="_beg">Po³o¿enie pocz¹tkowe</param>
    /// <param name="_end">Po³o¿enie koñcowe</param>
    /// <param name="board">Szachownica</param>
    /// <returns>Zwraca true jeœli ruch moze byæ wykonany</returns>
    bool move(int* beg, int* end, Figure board[]);
};

