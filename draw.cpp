#include <ncurses.h>
#include "draw.h"



void display_init(int* row, int* col, int* xpoint, int* ypoint) //ustawienia ncurses
{
	initscr();
	raw();
	noecho();
	start_color();
	curs_set(0);
	getmaxyx(stdscr,*row,*col);
	*ypoint = (*row-6) / 2;
	*xpoint = (*col-10) / 2;
	init_color(BOX_C, 153, 74, 6); //dodawanie kolorow
	init_color(WALL_C, 127, 117, 109);
	init_color(PLAYER_C, 92, 121, 249);
	init_color(FLOOR_C, 251, 255, 163);
	init_color(STORAGE_C, 255, 86, 86);
	
	init_pair(BOXC, BOX_C, FLOOR_C);
	init_pair(BOXS, BOX_C, STORAGE_C);
	init_pair(WALL, COLOR_WHITE, WALL_C);
	init_pair(PLAYER, PLAYER_C, FLOOR_C);
	init_pair(FLOOR, COLOR_BLACK, FLOOR_C);
	init_pair(STORAGE, COLOR_WHITE, STORAGE_C);
	

}
void display_draw_board(game_object***& board, int row,int col)
{ 
	for(int i = 0; i < 16; ++i)
	{
		move(((row/2)-(16/2))+i,(col/2)-(32/2));
		for(int j = 0; j < 16; ++j)
		{
			game_object* temp;
			if(board[i][j]->attached_object != NULL)
			{ temp = board[i][j]->attached_object; } 
			else 
			{ temp = board[i][j]; }

			attron(COLOR_PAIR(temp->color));
			addch(temp->sign);
			attroff(COLOR_PAIR(temp->color));
		}

	}
}
/*void display_draw_menu(char SELECTION)
{
	
}*/
void disp_menu(int curs_pos,int row, int col)
{
	//ustawienie znaku na poczatek
	//petla do wypisywania arraya z kolorami wg funkcji
	//po lini przejscie do next tak jak w planszy
	//move(row-1,(col/2)-LOGO_W);
	int temp = 0;
	for(int i = 0; i < LOGO_H; ++i) //LOGO WYSIWTLANIE
	{
	move(1+i,(col/2)-(LOGO_W/2));
		for(int j = 0; j < LOGO_W; ++j)
		{
			//attron(COLOR_PAIR((temp%6)+1));
			addch(LOGO[(i*83)+j]);
			//attroff(COLOR_PAIR((temp%6)+1));
			++temp;
		}

	}
	
	mvprintw((row/2)+LOGO_H+2,(col-strlen(OPT_G))/2,"%s",OPT_G);
	mvprintw((row/2)+LOGO_H+3,(col-strlen(OPT_L))/2,"%s",OPT_L); //chyba dziala
	mvprintw((row/2)+LOGO_H+4,(col-strlen(OPT_C))/2,"%s",OPT_C);
	mvprintw((row/2)+LOGO_H+5,(col-strlen(OPT_E))/2,"%s",OPT_E);
	//dodawanie ktopki przy kurs
	mvprintw((row/2)+LOGO_H+2+curs_pos,(col-strlen(OPT_G))/2-2,">");
}


void disp_controls(int row, int col)
{
	mvprintw(row/2,0,"%s",CTRLS);
	
	//tutaj nie wiem czy cos jeszcze?
	//pozniej uzupelnic main i dodac funkcje ktorych nie ma
	//sprawdzic czy poruszanie i kolizje sa ok
	//przeglad czy wszystko po kolei jest ok
	//dodac sprawdzanie czy wszystkie boxy sa na miejscach (jakas lista boxow i storageow, szukanie czy wszystkie sie zgadzaja)
	
}


