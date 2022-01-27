#include <SDL2/SDL.h>

#include "display.h"
#include "con.h"
#include "extern.h"

/*
 * Set the preparing window.
 */
void display_prepare(void){
	SDL_SetRenderDrawColor(global->renderer, BG_R, BG_G, BG_B, BG_A);
	SDL_RenderClear(global->renderer);

	SDL_RenderPresent(global->renderer);
}

