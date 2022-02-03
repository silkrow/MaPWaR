#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "con.h"
#include "types.h"
#include "main.h"
#include "game.h"
#include "display.h"

GlobalSDL* global = NULL;
Button bt_0;
Button bt_1;

int main(void){
	global = malloc(sizeof(GlobalSDL));

	if(!setup()) return 0; // Setting up the global variable.
	if(!display_loadFiles()) return 0;

	setup_prepare();
	while(global->running){
		switch (global->state){
			case GAME_PREPARE:
				process_prepare();
				break;
			case GAME_PICK:
				process_picking();
				break;
			case GAME_START:
				run_game();
				break;
			default:
				break;
		}
	}

	destroy_window();
	free(global);
	return 0;
}

void setup_prepare(void){
	display_prepare();
}

void setup_picking(void){
	display_picking();
}

void process_prepare(void){
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
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT &&
				clicked(&bt_0, event.button.x, event.button.y))
			{
				global->state = GAME_PICK;
				setup_picking();
				return;
        	}
			break;
		default:
			break;
	}
	SDL_Delay((int)global->spf);
}

void process_picking(void){
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
		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT &&
				clicked(&bt_0, event.button.x, event.button.y))
			{
				global->state = GAME_START;
				set_game(RED);
				return;
        	}
			if(event.button.button == SDL_BUTTON_LEFT &&
				clicked(&bt_1, event.button.x, event.button.y))
			{
				global->state = GAME_START;
				set_game(BLUE);
				return;
        	}

			break;

		default:
			break;
	}
	SDL_Delay((int)global->spf);
}


////////////////////////////////////////////
int setup(void){
	if (SDL_Init(SDL_INIT_EVERYTHING)){
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;
	}	

	global->fps = FPS;
	global->spf = FRAME_TARGET_TIME;
	global->window_width = WINDOW_WIDTH;
	global->window_height = WINDOW_HEIGHT;
	global->window = NULL;
	global->renderer = NULL;
	global->screenSur = NULL;
	global->running = TRUE;
	global->state = GAME_PREPARE; 
	global->last_frame_time = 0;

	global->window = SDL_CreateWindow(
			"MaPWaR", 
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			global->window_width,
			global->window_height,
			SDL_WINDOW_SHOWN
			);
	if (!global->window){
		fprintf(stderr, "Error initializing SDL window.\n");
		return FALSE;
	}

	global->renderer = SDL_CreateRenderer(
			global->window,
			-1, // Default.
			0 // No flags or anything special.
			);
	if (!global->renderer){
		fprintf(stderr, "Error initializing SDL renderer.\n");
		return FALSE;
	}

	return TRUE;
}

int clicked(Button * bt, float x, float y){
	if(	x >= bt->box.x &&
        x <= (bt->box.x + bt->box.w) &&
        y >= bt->box.y &&
        y <= (bt->box.y + bt->box.h)) return TRUE;
	return FALSE;
}


//void update(void){
//	int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
//	if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
//		SDL_Delay(time_to_wait);

//	float delta_time = (SDL_GetTicks() - last_frame_time)/1000.0f;
//	last_frame_time = SDL_GetTicks();

//	ball.x += 5 * delta_time;
//	ball.y += 5 * delta_time;
//}
