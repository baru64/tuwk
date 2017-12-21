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
	//bool move(char, game_object***);
};

class floor : public board_object
{
	public:
	floor();
	//bool move(char, game_object***);//ogarniac definicje te
};

class storage : public board_object
{
	public:
	storage();
	//bool move(char, game_object***);
};

class active_object : public game_object
{
	public:
	active_object();
	bool move(char direction, game_object***&);
};

class pudlo : public active_object //box
{
	public:
	pudlo(char a, char b);
};

class player : public active_object
{
	public:
	player(char a, char b);
};

// ######################FUNCTIONS####################
void buff2board(char* buffer, game_object***& board, game_object**& storages, game_object*& _player,FILE* logg);
bool map_solved(game_object**& storages, int* nos);
bool load_map(char* filename, game_object**& storages, int* nos, char* mapbuff);
//char* read_progress();
#endif
