
#include "Header.h"
#include "Figure.h"
#pragma once

/// <summary>
/// G��wna klasa Board przechowuj�ca pionki, ze wzgl�du na problemy z implementacj� klas przechowuje te� funkcje sprawdzaj�ce ruch pionk�w
/// </summary>
class Board

{
	public:		
	/// <summary>
	/// Tablica dwuwymiarowa zawieraj�ca wszystkie pionki na szachownicy
	/// </summary>
	Figure  board[8][8];
	/// <summary>
	///  Po�o�enie bia�ego kr�la
	/// </summary>
	int* whiteKing = transformcoords(41);
	/// <summary>
	///  po�o�enie czarnego kr�la
	/// </summary>
	int* blackKing = transformcoords(48);
	/// <summary>
	///  zmienna s�u��ca do zap�tlania pro�by o wybranie pionka
	/// </summary>
	bool checking; 
	/// <summary>
	/// Informacja, czy wykonanko Check na bia�ym kr�lu
	/// </summary>
	bool checkWhite = false;
	/// <summary>
	/// Informacja czy wykonano Check na czarnym kr�lu
	/// </summary>
	bool checkBlack = false;
	/// <summary>
	///  zmienna s�u��ca do zap�tlania gry
	/// </summary>
	bool continueGame = true;
	/// <summary>
	/// Zmienna przechowuj�ca wybrane wsp�rz�dne pocz�tkowe
	/// </summary>
	int* coordBegin = 0;
	/// <summary>
	/// Zmienna przechowuj�ca wybrane wsp�rz�dne ko�cowe
	/// </summary>
	int* coordend = 0;
	/// <summary>
	/// zmienna przecowuj�ca koordynaty w postaci XY
	/// </summary>
	int beginning, target;
	/// <summary>
	/// Zmienna przechowuj�ca wsp�rz�dne pionku kt�ry wykonac� Check
	/// </summary>
	int* attacker = new int[2]; 
	/// <summary>
	///  zmienna opisuj�ca kolor aktualnego gracza
	/// </summary>
	Colors actualPlayer = white;
	/// <summary>
	///  Informacja wy�wietlana po wykonaniu dzia�ania
	/// </summary>
	string playerMessage;

	/// <summary>
	/// Rodzaj wybranego pionka
	/// </summary>
	Pieces beginPiece;
	/// <summary>
	///  Kolor wybranego pionka
	/// </summary>
	Colors beginColor;
	/// <summary>
	///  Informacja wy�wietlana po wykonaniu dzia�ania
	/// </summary>
	string message;
	/// <summary>
	///  zmienna kt�ra pozostawia okienko po zakonczeniu gry
	/// </summary>
	char smth;
	/// <summary>
	/// string wy�wietlany w momencie kolejnego ruchu
	/// </summary>
	string correct = "Kolejna tura!";
	/// <summary>
	/// string wy�wietlany w momencie wykonania niepoprawnego ruchu
	/// </summary>
	string fault = "Niepoprawny ruch!";
	/// <summary>
	/// Funkcja rozdzielajaca podane wsp�rz�dne na dwie oddzielne cyfry
	/// </summary>
	/// <param name="_coords">Wsp�rz�dne podane w formacie XY</param>
	/// <returns></returns>
	int* transformcoords(int _coords);
	/// <summary>
	/// Funkcja tworz�ca now� szachownic� i wype�niaj�ca j� pionkami
	/// </summary>
	void newBoard();
	/// <summary>
	///  Funkcja rysuj�ca szachownic� oraz wy�wietlaj�ca wiadomo�� po wykonaniu ruchu
	/// </summary>
	void printBoard();
	/// <summary>
	///  Funkcja tworz�ca now� gr�, czyli tworz�ca i rysuj�ca szachownice
	/// </summary>
	void newGame();
	/// <summary>
	///  G��wna funkcja obs�uguj�ca gr�
	/// </summary>
	/// <returns></returns>
	bool theGame();
	/// <summary>
	/// Funkcja sprawdzaj�ca poprawno�� wykonywanego ruchu
	/// </summary>
	/// <param name="_piece">Pionek kt�rym zamierzamy wykona� ruch</param>
	void checkMove(Pieces _piece);
	/// <summary>
	/// Funkcja wykonuj�ca ruch pionkiem
	/// </summary>
	/// <param name="_beginning">Po�o�enie pocz�tkowe pionka</param>
	/// <param name="_target">Po�o�enie docelowe pionka</param>
	void move(int _beginning, int _target);
	/// <summary>
	/// Funkcja wykonuj�ca ruch pionkiem
	/// </summary>
	/// <param name="_beginning">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="_target">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	void move(int* _beginning, int* _target);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Pionkiem mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool movePawn(int* beg, int* end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Wie�� mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool moveRook(int* _beginning, int* _target, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Skoczkiem mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool moveKnight(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Go�cem mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool moveBishop(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Kr�lem mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool moveKing(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy ruch Kr�low� mo�e by� wykonany
	/// </summary>
	/// <param name="beg">Tablica z wsp�lrz�dnymi pocz�tkowymi pionka</param>
	/// <param name="end">Tablica z wsp�rz�dnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" je�li ruch mo�e by� wykonany </returns>
	bool moveQueen(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj�ca, czy kr�l znajduje si� w po�o�eniu Check
	/// </summary>
	/// <param name="_kingz">Po�o�enie kr�la</param>
	/// <returns>Zwraca "True" je�li kr�l znajduje si� w po�o�eniu Check</returns>
	bool Check(int* _kingz);
	/// <summary>
	/// Funkcja sprawdzaj�ca czy kr�l na pozycji Check ma opcj� ratunku
	/// </summary>
	/// <param name="_king">Po�o�enie kr�la</param>
	/// <param name="_kingColor">Kolor kr�la</param>
	/// <returns>Zwraca "True" je�li kr�l nie ma ucieczki</returns>
	bool EndGame(int* _king,Colors _kingColor);
	/// <summary>
	/// Funkcja s�u��ca do zapisu gry. Tworzy plik z u�o�eniem szachownicy i kolorem aktualnego gracza
	/// </summary>
	void saveGame();
	/// <summary>
	/// Funkcja wczytuj�ca stan zapisanej gry
	/// </summary>
	void loadGame();
};

