#include <ncurses.h>
#include "game.h" 

game_object :: game_object()
{
	
}

board_object :: board_object()
{
	attached_object = NULL;
}

wall :: wall()
{
	color = WALL;
	sign = 'H';
}

floor :: floor()
{
	color = FLOOR;
	sign = ' ';
}

storage :: storage()
{
	color = STORAGE;
	sign = 'X';
	//x = 0;
	//y = 0;
	//bool move(char);
	//game_object* attached_object = NULL;
}

active_object :: active_object()
{
	
}

bool active_object :: move(char direction, game_object***& board)
{
	switch(direction)
	{
		case 'r': 
		if( board[x][y+1]->sign == 'H' ) return false;
		if( board[x][y+1]->attached_object == NULL ||
		board[x][y+1]->attached_object->move(direction,board) )
		{
			board[x][y]->attached_object = NULL;
			y+=1;
			board[x][y]->attached_object = this;
			return true;
		}
		break;
		case 'l':
		if( board[x][y-1]->sign == 'H' ) return false;
		if( board[x][y-1]->attached_object == NULL ||
		board[x][y-1]->attached_object->move(direction,board) )
		{
			board[x][y]->attached_object = NULL;
			y-=1;
			board[x][y]->attached_object = this;
			return true;
		}
		break;
		case 'u':
		if( board[x-1][y]->sign == 'H' ) return false;
		if( board[x-1][y]->attached_object == NULL ||
		board[x-1][y]->attached_object->move(direction,board) )
		{
			board[x][y]->attached_object = NULL;
			x-=1;
			board[x][y]->attached_object = this;
			return true;
		}
		break;
		case 'd':
		if( board[x+1][y]->sign == 'H' ) return false;
		if( board[x+1][y]->attached_object == NULL ||
		board[x+1][y]->attached_object->move(direction,board) )
		{
			board[x][y]->attached_object = NULL;
			x+=1;
			board[x][y]->attached_object = this;
			return true;
		}
		break;
	}
}

bool board_object :: move(char direction, game_object***& board)
{}

player :: player(char a, char b)
{
	x = a; y = b;
	color = PLAYER;
	sign = '0';
}

pudlo :: pudlo(char a, char b)
{
	x = a; y = b;
	color = BOXC;
	sign = '#';
}
//rozmiar staly mapy: 16x16
void buff2board(char* buffer, game_object***& board, game_object**& storages, game_object*& _player,FILE* logg)
{ 
	board = new game_object**[16];
	int temp = 0;
	for(int i = 0; i < 16; ++i)
	{
		board[i] = new game_object*[16];
		for(int j = 0; j < 16; ++j)
		{
		fprintf(logg," %d %d ",i,j);
			switch(buffer[i*16+j])
			{
				case 'w':
				board[i][j] = new wall();
				fprintf(logg,"w");
				break;
				case 'f':
				board[i][j] = new floor();
				fprintf(logg,"f");
				break;
				case 'p':
				fprintf(logg,"p");
				board[i][j] = new floor();
				board[i][j]->attached_object = new player(i,j);
				_player = board[i][j]->attached_object;
				fprintf(logg,"player: %d %d ",_player->x,_player->y);
				break;
				
				case 'b':
				fprintf(logg,"b");
				board[i][j] = new floor();
				board[i][j]->attached_object = new pudlo(i,j);
				break;
				
				case 's':
				fprintf(logg,"s");
				board[i][j] = new storage();
				storages[temp++] = board[i][j];
				break;
			}
		}
	}
}

bool map_solved(game_object**& storages, int* nos)
{
	int t = 0;
	for(int i = 0; i < *nos;++i) //NOS - NUMBER OF STORAGES
		if(!((storages[i]->attached_object != NULL) && storages[i]->attached_object->sign == '#'))
			return false;
			
	return true;
}

bool load_map(char* filename, game_object**& storages, int* nos, char* mapbuff)
{
	FILE* c_map;
	c_map = fopen(filename,"r");
	if(c_map != NULL)
	{
		char t;
		fscanf(c_map,"%c %s",&t,mapbuff);
		fclose(c_map);
		*nos = atoi(&t);
		storages = new game_object*[*nos];			
	} else { throw 20; return false;}
    return true;
}

/*char* read_progress()
{
	char buff;
	FILE *prg;
	if ((prg = fopen("game.save", "r")) != NULL) {
        return 0;
    }
    fscanf(prg,"%c",buff);
    fclose(prg);
    switch(buff)
    {
    	case '1': return "map1";
    	case '2': return "map2";
    }
}
bool save_progress(char lvl)
{
	FILE *prg;
	if ((prg = fopen("game.save", "w")) == NULL) {
        return false;
    }
    fprintf(prg,"%c", lvl);
    fclose(prg);
    return true;
}*/
