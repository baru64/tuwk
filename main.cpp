#include <iostream>
#include <cmath>
#include <ncurses.h>
#include "draw.h"
#include "game.h"
using namespace std;
int ROW, COL = 0;
int YPOINT;
int XPOINT;

game_object*** BOARD;
game_object* __PLAYER;
char** BOARD_BUFF;
int MAPWIDTH;
int MAPHEIGHT;
game_object** STORAGES;
int NOS;
FILE* LOG_F;
unsigned short CURS_POS = 0;
int main()
{
	display_init(&ROW,&COL,&XPOINT,&YPOINT);
	LOG_F = fopen("log.txt","w"); //logi do debugowania
	fprintf(LOG_F, "--START--\nROW=%d COL=%d XPOINT=%d YPOINT=%d\n",ROW,COL,XPOINT,YPOINT);
	char c;
	char game_mode = 'M'; // tryb gry
	char map_file[32];
	
	while(true) //main loop
	{
		switch(game_mode)
		{
			case 'M':
				clear();
				disp_menu(CURS_POS, ROW,COL);

				fprintf(LOG_F, "DISPLAY. CURS_POS:%d\n",CURS_POS);
				switch(c)
				{
					case 'w': CURS_POS == 0 ? CURS_POS = 3 : CURS_POS = (CURS_POS-1)%4;
					fprintf(LOG_F, "w case\n");
					clear();
					disp_menu(CURS_POS, ROW,COL);
					break;
					case 's': CURS_POS = (CURS_POS+1)%4;
					fprintf(LOG_F, "s case\n");
					clear();
					disp_menu(CURS_POS, ROW,COL);
					break;
					case 'e':
						switch( CURS_POS )
						{
							case 0:
								char map_buff[256];
								if(load_map("map1", STORAGES, &NOS, map_buff))
								{
									buff2board(map_buff, BOARD, STORAGES, __PLAYER,LOG_F);
									game_mode = 'G';
									fprintf(LOG_F, "map buffer loaded into board\n");
									clear();
									display_draw_board(BOARD,ROW,COL);
								}
							break;
							case 1:
								game_mode = 'L';
								clear();
								echo();
								mvprintw(ROW/2,(COL-18)/2,"Enter file name:");
								mvscanw((ROW/2)+1,(COL-18)/2, "%s", map_file);
								noecho();
							break;
							case 2:
								game_mode = 'C';
								clear();
								disp_controls(ROW,COL);
							break;
							case 3:
							endwin();
							fclose(LOG_F);
							return 0;
						}
					
					break;
				}
			break;
			
			case 'L':
				fprintf(LOG_F,"Entered loading screen\n");
				char custom_map[256];
				fprintf(LOG_F,"map file: %s\n",map_file);
				
				try
				{
					if(load_map(map_file, STORAGES,&NOS,custom_map))
					{
						game_mode = 'G';
						buff2board(custom_map, BOARD, STORAGES, __PLAYER,LOG_F);
						fprintf(LOG_F, "custom map buffer loaded into board\n");
						clear();
						display_draw_board(BOARD,ROW,COL);
					}
				}
				catch(...)
				{
					fprintf(LOG_F,"Exception - can't open map file\n");
					clear();
					game_mode = 'M';
					disp_menu(CURS_POS, ROW,COL);
				}
			break;
			
			case 'G':
				fprintf(LOG_F,"Entered game mode\n");
				fprintf(LOG_F,"player: %d %d\n",__PLAYER->x,__PLAYER->y);
				
				switch( c )
				{
					case 'w': __PLAYER->move('u',BOARD);
					break;
					case 'a': __PLAYER->move('l',BOARD);
					break;
					case 's': __PLAYER->move('d',BOARD);
					break;
					case 'd': __PLAYER->move('r',BOARD);
					break;
				}
				display_draw_board(BOARD,ROW,COL);
				if(c == 'q')
				{
					clear();
					game_mode = 'M';
					disp_menu(CURS_POS, ROW,COL);
				}
				if(map_solved(STORAGES, &NOS)) 
				{
					clear(); 
					delete[] BOARD;
					mvprintw(ROW/2,(COL-34)/2,"Solved! Press q to return to menu");
					game_mode = 'M';
					fprintf(LOG_F,"Game solved\n");
				}
			break;
			
			case 'C':
				fprintf(LOG_F,"Entered controls screen\n");
				disp_controls(ROW,COL);
				if(c == 'q')
				{
					clear();
					game_mode = 'M';
					disp_menu(CURS_POS, ROW,COL);
				}
			break;
		}
		c = getch();
		fprintf(LOG_F, "input:%c\n",c);
		if(c == 'l')
		{
			fprintf(LOG_F, "---closing:%c---\n",c);
			endwin();
			fclose(LOG_F);
			return 0;
		}
	}
	endwin();
	fclose(LOG_F);
	return 0;
}
