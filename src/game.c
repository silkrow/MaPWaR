#include <stdio.h>
#include <SDL2/SDL.h>


#include "con.h"
#include "main.h"


int game_is_running = FALSE;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int last_frame_time = 0;

void process_input(void);
void update(void);
void render(void);

struct ball{
	float x;
	float y;
	float width;
	float height;
} ball;

int main(void){

	printf("Working...\n");

	game_is_running = initialize_window();

	setup();
	while(game_is_running){
		process_input();
		update();
		render();
	}

	destroy_window();

	return 0;
}

int initialize_window(void){
	if (SDL_Init(SDL_INIT_EVERYTHING)){
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;
	}

	window = SDL_CreateWindow(
			"Hello World", 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			SDL_WINDOW_BORDERLESS
			);
	if (!window){
		fprintf(stderr, "Error initializing SDL window.\n");
		return FALSE;
	}
	
	renderer = SDL_CreateRenderer(
			window,
			-1, // Default.
			0 // No flags or anything special.
			);
	if (!renderer){
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
			game_is_running = FALSE;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE){
				game_is_running = FALSE;
			}
			break;
		default:
			break;
	}
}

void update(void){
	int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
	if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
		SDL_Delay(time_to_wait);

	float delta_time = (SDL_GetTicks() - last_frame_time)/1000.0f;
	last_frame_time = SDL_GetTicks();

	ball.x += 5 * delta_time;
	ball.y += 5 * delta_time;
}

void render(void){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // <R> <G> <B> <Alpha>
	SDL_RenderClear(renderer);

	SDL_Rect ball_rect = { 
		(int)ball.x, 
		(int)ball.y, 
		(int)ball.width, 
		(int)ball.height 
	};

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &ball_rect);

	SDL_RenderPresent(renderer); // The buffer swap.
}

void destroy_window(void){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void setup(void){
	ball.x = 400;
	ball.y = 300;
	ball.width = 15;
	ball.height = 15;
}
