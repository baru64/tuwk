#include <ncurses.h>
#include <string.h>

#ifndef _DRAW_H
#define _DRAW_H

#include "game.h"

#define BOX_C 11
#define WALL_C 12
#define PLAYER_C 13
#define FLOOR_C 14
#define STORAGE_C 15

#define LOGO_H 13
#define LOGO_W 83

const char CTRLS[] =	"\t\t\t\t\t\t\tControls:\n"
						"\t\t\t\t\t\t\tMovement: W,A,S,D\n"
						"\t\t\t\t\t\t\tExit: q";

const char OPT_G[] = "Start / Continue";
const char OPT_L[] = "Load Custom Map";
const char OPT_C[] = "Controls";
const char OPT_E[] = "Exit";
const char LOGO[] = "              _   _                  _ _   _                 _                                  | | | |                | | | (_)               | |                                 | |_| |__   ___   _   _| | |_ _ _ __ ___   __ _| |_ ___                            | __| '_ \\ / _ \\ | | | | | __| | '_ ` _ \\ / _` | __/ _ \\                           | |_| | | |  __/ | |_| | | |_| | | | | | | (_| | ||  __/                            \\__|_| |_|\\___|  \\__,_|_|\\__|_|_| |_| |_|\\__,_|\\__\\___|                                     | |                          | |                            __      ____ _ _ __ ___| |__   ___  _   _ ___  ___  | | _____  ___ _ __   ___ _ __ \\ \\ /\\ / / _` | '__/ _ | '_ \\ / _ \\| | | / __|/ _ \\ | |/ / _ \\/ _ | '_ \\ / _ | '__| \\ V  V | (_| | | |  __| | | | (_) | |_| \\__ |  __/ |   |  __|  __| |_) |  __| |     \\_/\\_/ \\__,_|_|  \\___|_| |_|\\___/ \\__,_|___/\\___| |_|\\_\\___|\\___| .__/ \\___|_|                                                                     | |                                                                                |_|              ";

/*
              _   _                  _ _   _                 _                     
             | | | |                | | | (_)               | |                    
             | |_| |__   ___   _   _| | |_ _ _ __ ___   __ _| |_ ___               
             | __| '_ \ / _ \ | | | | | __| | '_ ` _ \ / _` | __/ _ \              
             | |_| | | |  __/ | |_| | | |_| | | | | | | (_| | ||  __/              
              \__|_| |_|\___|  \__,_|_|\__|_|_| |_| |_|\__,_|\__\___|              
                       | |                          | |                            
__      ____ _ _ __ ___| |__   ___  _   _ ___  ___  | | _____  ___ _ __   ___ _ __ 
\ \ /\ / / _` | '__/ _ | '_ \ / _ \| | | / __|/ _ \ | |/ / _ \/ _ | '_ \ / _ | '__|
 \ V  V | (_| | | |  __| | | | (_) | |_| \__ |  __/ |   |  __|  __| |_) |  __| |   
  \_/\_/ \__,_|_|  \___|_| |_|\___/ \__,_|___/\___| |_|\_\___|\___| .__/ \___|_|   
                                                                  | |              
                                                                  |_|              
*/

void display_init(int* row, int* col, int* xpoint, int* ypoint); //ustawianie ncurses
/*! \brief Ustawia opcje ncurses
*/
void display_draw_board(game_object***& board, int row,int col); //rysowanie planszy
/*! \brief Rysuje plansze
*/
void disp_menu(int curs_pos, int row, int col); //rysowanie menu
/*! \brief Rysuje menu
*/
void disp_controls(int row, int col); //rysowanie ekranu sterowania
/*! \brief Rysuje ekran z sterowaniem
*/
#endif

