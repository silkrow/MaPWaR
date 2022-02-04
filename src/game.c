#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "con.h"
#include "extern.h"
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

///////////
//functions
///////////
void set_game(armyType teamType){

	p1 = malloc(sizeof(Player));
	p2 = malloc(sizeof(Player));



	p1->playertype = HUMAN;
	p2->playertype = AI;

	p1->armytype = teamType;
	p2->armytype = (teamType == RED)? BLUE:RED;

	playlayout_basic();

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


