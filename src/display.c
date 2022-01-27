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

	wel_bt_0.rect.x = global->window_width/2 - WB_W/2;
	wel_bt_0.rect.y = global->window_height/4*3;
	wel_bt_0.rect.w = WB_W;
	wel_bt_0.rect.h = WB_H;
	wel_bt_0.pressed = FALSE;	

	SDL_SetRenderDrawColor(global->renderer, WB_R, WB_G, WB_B, WB_A);
	SDL_RenderFillRect(global->renderer, &(wel_bt_0.rect));

	SDL_RenderPresent(global->renderer);
}

