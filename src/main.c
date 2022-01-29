#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "con.h"
#include "main.h"
#include "types.h"
#include "display.h"

GlobalSDL* global = NULL;
Button wel_bt_0;

int main(void){
	global = malloc(sizeof(GlobalSDL));

	if(!setup()) return 0; // Setting up the global variable.
	if(!display_loadFiles()) return 0;

	display_prepare();
	while(global->running){
		SDL_Delay((int)global->spf);
		process_input(); // Grab the infomation for further updating.
//		update();
	//	draw();
	}

	destroy_window();
	free(global);
	return 0;
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
//		case SDL_MOUSEBUTTONUP:
//			if (global->state == GAME_PREPARE){
//				if(event.button.button == SDL_BUTTON_LEFT &&
  //              	event.button.x >= wel_bt_0.rect.x &&
    //            	event.button.x <= (wel_bt_0.rect.x + wel_bt_0.rect.w) &&
      //          	event.button.y >= wel_bt_0.rect.y &&
        //        	event.button.y <= (wel_bt_0.rect.y + wel_bt_0.rect.h)) 
		//		{
          //  		wel_bt_0.pressed = TRUE;
			//		global->state = GAME_PICK;
        	//	}
		//	}
		//	break;
		default:
			break;
	}
}

void update(void){
	if (!global->running) return;

	switch(global->state){
		case GAME_PREPARE:
			display_prepare();
			break;
		case GAME_PICK:
			display_picking();
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
