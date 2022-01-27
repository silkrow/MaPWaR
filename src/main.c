#include <stdio.h>
#include <SDL2/SDL.h>

#include "con.h"
#include "main.h"
#include "types.h"
#include "display.h"

GlobalSDL* global = NULL;

void process_input(void);

int main(void){
	global = malloc(sizeof(GlobalSDL));

	if(!setup()) return 0; // Setting up the global variable.


	while(global->running){

	display_prepare();
		process_input();
	//	update();
	//	draw();
	}

	destroy_window();

	return 0;
}

////////////////////////////////////////////
int setup(void){
	if (SDL_Init(SDL_INIT_EVERYTHING)){
		fprintf(stderr, "Error initializing SDL>\n");
		return FALSE;
	}	
	global->fps = FPS;
	global->spf = FRAME_TARGET_TIME;
	global->window_width = WINDOW_WIDTH;
	global->window_height = WINDOW_HEIGHT;
	global->window = NULL;
	global->renderer = NULL;
	global->running = TRUE;
	global->state = GAME_PREPARE; 
	global->last_frame_time = 0;

	global->window = SDL_CreateWindow(
			"MaPWaR", 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			global->window_width,
			global->window_height,
			SDL_WINDOW_OPENGL
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

void process_input(void){
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch(event.type){
		case SDL_QUIT:
			global->running = FALSE;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE){
				global->running = FALSE;
			}
			break;
		default:
			break;
	}
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

void destroy_window(void){
	SDL_DestroyRenderer(global->renderer);
	SDL_DestroyWindow(global->window);
	SDL_Quit();
}
