#include <ncurses.h>
#include <iostream>
#ifndef _GAME_H
#define _GAME_H

#define BOXC 1
#define WALL 2
#define PLAYER 3
#define FLOOR 4
#define STORAGE 5
#define BOXS 6
// ######################CLASSES####################
class game_object
{
	public:
	game_object();
	char sign;
	short color;
	char x;
	char y;
	virtual bool move(char, game_object***&) = 0;
	game_object* attached_object = NULL;
};

class board_object : public game_object
/*! \brief Nieaktywne elementy planszy
*/
{
	public:
	board_object();
	game_object* attached_object;
	bool move(char, game_object***&);
};

class wall : public board_object
{
	public:
	wall();

};

class floor : public board_object
{
	public:
	floor();

};

class storage : public board_object
{
	public:
	storage();

};

class active_object : public game_object
/*! \brief Obiekty aktywne
*/
{
	public:
	active_object();
	bool move(char direction, game_object***&);
};

class pudlo : public active_object
/*! \brief Klasa pudeł
*/
{
	public:
	pudlo(char a, char b);
};

class player : public active_object
/*! \brief Klasa gracza
*/
{
	public:
	player(char a, char b);
};

// ######################FUNCTIONS####################
void buff2board(char* buffer, game_object***& board, game_object**& storages, game_object*& _player,FILE* logg);
/*! \brief Konwertuje bufor na tablice obiektów gry
*/
bool map_solved(game_object**& storages, int* nos);
/*! \brief Sprawdza czy plansza została rozwiązana
*/
bool load_map(char* filename, game_object**& storages, int* nos, char* mapbuff);
/*! \brief Ładuje mapę z pliku do zmiennej
*/
//char* read_progress();
#endif
