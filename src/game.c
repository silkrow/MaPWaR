#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "con.h"
#include "extern.h"
#include "types_game.h"
#include "game.h"
#include "map.h"
#include "troop.h"
#include "display.h"
#include "main.h"

///////////
//variables
///////////
Player * p1; // By default, human player uses p1.
Player * p2;

Grid land[80][120];
///////////
//functions
///////////
void set_game(armyType teamType){

	p1 = malloc(sizeof(Player));
	p2 = malloc(sizeof(Player));
//// Players' infomation.
	p1->playertype = HUMAN;
	p2->playertype = AI;

	p1->armytype = teamType;
	p2->armytype = (teamType == RED)? BLUE:RED;


//// Basic display setting up.
	playlayout_basic();

//// Calculate and generate the map.
	set_map();
}

void run_game(void){
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			global->running = FALSE;
			destroy_game();
			return;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE){ // Ask for confirm.
				global->state = GAME_PREPARE;
				destroy_game();

				setup_prepare();
				return;
			}
			break;
		default:
			break;
	}
	SDL_Delay((int)global->spf);
}

void destroy_game(void){
	free(p1);
	free(p2);
}

void set_map(void){
	for (int i = 0; i < 80; i++)
		for (int j = 0; j < 120; j++)
		{
			land[i][j].box.x = j*10;
			land[i][j].box.y = i*10;
			land[i][j].box.w = 10;
			land[i][j].box.h = 10;
			land[i][j].h = 0;
		}

	random_mountain(10 + rand() % 6);
	
	display_land();
}

void random_mountain(int n) { // Generate n mountains randomly.
	int H;
	for (int k = 0; k < n; k++){
		H = rand() % 3 + 2; // H from 2 to 4, representing the height.
		int x = rand() % 80;
		int y = rand() % 120;
		land[x][y].h = H;
		h_down(x, y); // Recursively arrange the other grids for the mountain.
	}

}

void h_down(int x, int y){ 
	/* 
	 * For a grid and the eight squares surronding it, the 4 squares that
	 * share a side with the grid will have 1/3 chance to keep the same 
	 * height, the remaining 4 on the corners will have 1/6 chance to 
	 * keep the same height. 
	 *
	 * Recursively, update the height to generate a mountain.
	 *
	 */

	int x_update[8];
	int y_update[8];

	int s = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 && j == 0) ||
				i + x < 0 ||
				i + x >= 80 ||
				j + y < 0 ||
				j + y >= 120) continue;
			
			if (land[x + i][y + j].h == 0){
				if (rand()% (4*abs(i) + 4*abs(j)) == 0) // Keep the same height.
				{	
					land[x + i][y + j].h = land[x][y].h;
				}
				else land[x + i][y + j].h = land[x][y].h - 1;
				
				if (land[x + i][y + j].h != 0){
					x_update[s] = x + i;
					y_update[s] = y + j;
					s++;
				}
			}

		}

	for (int i = 0; i < s; i++)
		h_down(x_update[i], y_update[i]);
}			
