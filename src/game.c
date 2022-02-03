#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "con.h"
#include "extern.h"
#include "game.h"
#include "map.h"
#include "troop.h"
#include "display.h"

///////////
//variables
///////////
Player * p1;
Player * p2;

///////////
//functions
///////////
void set_game(armyType teamType){

	display_map();

}

void run_game(void){
	SDL_Event event;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			global->running = FALSE;
			return;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE){
				global->running = FALSE;
				return;
			}
			break;
		default:
			break;
	}
	SDL_Delay((int)global->spf);
}
