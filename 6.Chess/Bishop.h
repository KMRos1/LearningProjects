#pragma once
#include "Figure.h"
/// <summary>
/// Klasa opisuj�ca Go�ca
/// </summary>
class Bishop :
    public Figure
{
    /// <summary>
    /// Konstruktor przypisuj�cy kolor i rodzaj figury
    /// </summary>
    /// <param name="_color">Kolor figury</param>
    /// <returns>Zwraca obiekt klasy</returns>
    Bishop(Colors _color);
    /// <summary>
    /// Funkcja sprawdzaj�ca poprawno�� ruchu (Niedzia�aj�ca)
    /// </summary>
    /// <param name="_beg">Po�o�enie pocz�tkowe</param>
    /// <param name="_end">Po�o�enie ko�cowe</param>
    /// <param name="board">Szachownica</param>
    /// <returns>Zwraca true je�li ruch moze by� wykonany</returns>
    bool Move(int* _beg, int* _end, Figure board[]);
};

