
#include "Header.h"
#include "Figure.h"
#pragma once

/// <summary>
/// G³ówna klasa Board przechowuj¹ca pionki, ze wzglêdu na problemy z implementacj¹ klas przechowuje te¿ funkcje sprawdzaj¹ce ruch pionków
/// </summary>
class Board

{
	public:		
	/// <summary>
	/// Tablica dwuwymiarowa zawieraj¹ca wszystkie pionki na szachownicy
	/// </summary>
	Figure  board[8][8];
	/// <summary>
	///  Po³o¿enie bia³ego króla
	/// </summary>
	int* whiteKing = transformcoords(41);
	/// <summary>
	///  po³o¿enie czarnego króla
	/// </summary>
	int* blackKing = transformcoords(48);
	/// <summary>
	///  zmienna s³u¿¹ca do zapêtlania proŸby o wybranie pionka
	/// </summary>
	bool checking; 
	/// <summary>
	/// Informacja, czy wykonanko Check na bia³ym królu
	/// </summary>
	bool checkWhite = false;
	/// <summary>
	/// Informacja czy wykonano Check na czarnym królu
	/// </summary>
	bool checkBlack = false;
	/// <summary>
	///  zmienna s³u¿¹ca do zapêtlania gry
	/// </summary>
	bool continueGame = true;
	/// <summary>
	/// Zmienna przechowuj¹ca wybrane wspó³rzêdne pocz¹tkowe
	/// </summary>
	int* coordBegin = 0;
	/// <summary>
	/// Zmienna przechowuj¹ca wybrane wspó³rzêdne koñcowe
	/// </summary>
	int* coordend = 0;
	/// <summary>
	/// zmienna przecowuj¹ca koordynaty w postaci XY
	/// </summary>
	int beginning, target;
	/// <summary>
	/// Zmienna przechowuj¹ca wspó³rzêdne pionku który wykonac³ Check
	/// </summary>
	int* attacker = new int[2]; 
	/// <summary>
	///  zmienna opisuj¹ca kolor aktualnego gracza
	/// </summary>
	Colors actualPlayer = white;
	/// <summary>
	///  Informacja wyœwietlana po wykonaniu dzia³ania
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
	///  Informacja wyœwietlana po wykonaniu dzia³ania
	/// </summary>
	string message;
	/// <summary>
	///  zmienna która pozostawia okienko po zakonczeniu gry
	/// </summary>
	char smth;
	/// <summary>
	/// string wyœwietlany w momencie kolejnego ruchu
	/// </summary>
	string correct = "Kolejna tura!";
	/// <summary>
	/// string wyœwietlany w momencie wykonania niepoprawnego ruchu
	/// </summary>
	string fault = "Niepoprawny ruch!";
	/// <summary>
	/// Funkcja rozdzielajaca podane wspó³rzêdne na dwie oddzielne cyfry
	/// </summary>
	/// <param name="_coords">Wspó³rzêdne podane w formacie XY</param>
	/// <returns></returns>
	int* transformcoords(int _coords);
	/// <summary>
	/// Funkcja tworz¹ca now¹ szachownicê i wype³niaj¹ca j¹ pionkami
	/// </summary>
	void newBoard();
	/// <summary>
	///  Funkcja rysuj¹ca szachownicê oraz wyœwietlaj¹ca wiadomoœæ po wykonaniu ruchu
	/// </summary>
	void printBoard();
	/// <summary>
	///  Funkcja tworz¹ca now¹ grê, czyli tworz¹ca i rysuj¹ca szachownice
	/// </summary>
	void newGame();
	/// <summary>
	///  G³ówna funkcja obs³uguj¹ca grê
	/// </summary>
	/// <returns></returns>
	bool theGame();
	/// <summary>
	/// Funkcja sprawdzaj¹ca poprawnoœæ wykonywanego ruchu
	/// </summary>
	/// <param name="_piece">Pionek którym zamierzamy wykonaæ ruch</param>
	void checkMove(Pieces _piece);
	/// <summary>
	/// Funkcja wykonuj¹ca ruch pionkiem
	/// </summary>
	/// <param name="_beginning">Po³o¿enie pocz¹tkowe pionka</param>
	/// <param name="_target">Po³o¿enie docelowe pionka</param>
	void move(int _beginning, int _target);
	/// <summary>
	/// Funkcja wykonuj¹ca ruch pionkiem
	/// </summary>
	/// <param name="_beginning">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="_target">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	void move(int* _beginning, int* _target);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Pionkiem mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool movePawn(int* beg, int* end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Wie¿¹ mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool moveRook(int* _beginning, int* _target, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Skoczkiem mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool moveKnight(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Goñcem mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool moveBishop(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Królem mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool moveKing(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy ruch Królow¹ mo¿e byæ wykonany
	/// </summary>
	/// <param name="beg">Tablica z wspólrzêdnymi pocz¹tkowymi pionka</param>
	/// <param name="end">Tablica z wspó³rzêdnymi docelowymi pionka</param>
	/// <param name="_color">Informacja o kolorze pionka</param>
	/// <returns>Zwraca "True" jeœli ruch mo¿e byæ wykonany </returns>
	bool moveQueen(int* _beg, int* _end, Colors _color);
	/// <summary>
	/// Funkcja sprawdzaj¹ca, czy król znajduje siê w po³o¿eniu Check
	/// </summary>
	/// <param name="_kingz">Po³o¿enie króla</param>
	/// <returns>Zwraca "True" jeœli król znajduje siê w po³o¿eniu Check</returns>
	bool Check(int* _kingz);
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy król na pozycji Check ma opcjê ratunku
	/// </summary>
	/// <param name="_king">Po³o¿enie króla</param>
	/// <param name="_kingColor">Kolor króla</param>
	/// <returns>Zwraca "True" jeœli król nie ma ucieczki</returns>
	bool EndGame(int* _king,Colors _kingColor);
	/// <summary>
	/// Funkcja s³u¿¹ca do zapisu gry. Tworzy plik z u³o¿eniem szachownicy i kolorem aktualnego gracza
	/// </summary>
	void saveGame();
	/// <summary>
	/// Funkcja wczytuj¹ca stan zapisanej gry
	/// </summary>
	void loadGame();
};

