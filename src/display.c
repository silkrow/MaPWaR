#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "extern.h"
#include "display.h"
#include "con.h"
/////////////////////////////////////////////////////////////////////
/////variables
TTF_Font * font = NULL;

/////////////////////////////////////////////////////////////////////
/*
 * Set the preparing window.
 */
void display_prepare(void){
	SDL_Surface * background = NULL;

	background = IMG_Load("./resources/images/bg.bmp");
    if (background == NULL)
    {
        fprintf(stderr, "Unable to load image.\n");
       	return;
    }
	
   	SDL_BlitSurface(background, NULL, global->screenSur, NULL);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(global->renderer, global->screenSur);
	SDL_RenderCopy(global->renderer, texture, NULL, NULL);

	SDL_Color color = {140, 140, 140};
	SDL_Surface * surface = TTF_RenderText_Solid(font, "Start", color);
	bt_0.figure = SDL_CreateTextureFromSurface(global->renderer, surface);
	int txt_w = 0;
	int txt_h = 0;
	SDL_QueryTexture(bt_0.figure, NULL, NULL, &txt_w, &txt_h);
	SDL_Rect txtBox = { 
		WINDOW_WIDTH/2 - txt_w/2,
		WINDOW_HEIGHT/4*3 - 40,
		txt_w,
		txt_h
	};
	bt_0.box = txtBox;
	SDL_SetRenderDrawColor(global->renderer, 0, 150, 0, 205);

	display_button(&(bt_0));

	
	SDL_RenderPresent(global->renderer);

	
	SDL_FreeSurface(surface);
	SDL_FreeSurface(background);
}

void display_picking(void){
	SDL_SetRenderDrawColor(global->renderer, BG_R, BG_G, BG_B, BG_A);
	SDL_RenderClear(global->renderer);
	SDL_Rect temp;

	SDL_Surface * background = NULL;

	SDL_SetRenderDrawColor(global->renderer, RED_R, RED_G, RED_B, RED_A);
	background = IMG_Load("./resources/images/ts.png");
	bt_0.box.x = 360; 
	bt_0.box.y = 100;
	bt_0.box.w = 340;
	bt_0.box.h = 580;
	SDL_RenderFillRect(global->renderer, &(bt_0.box));	

	bt_0.figure = SDL_CreateTextureFromSurface(global->renderer, background);
	temp.x = 300; 
	temp.y = 0;
	temp.w = 500;
	temp.h = 700;

	SDL_RenderCopy(global->renderer, bt_0.figure, NULL, &(temp));
	/////
	
	SDL_SetRenderDrawColor(global->renderer, BLUE_R, BLUE_G, BLUE_B, BLUE_A);
	background = IMG_Load("./resources/images/jw.png");
	bt_1.box.x = 900; 
	bt_1.box.y = 100;
	bt_1.box.w = 340;
	bt_1.box.h = 580;
	SDL_RenderFillRect(global->renderer, &(bt_1.box));	

	bt_1.figure = SDL_CreateTextureFromSurface(global->renderer, background);
	temp.x = 840; 
	temp.y = 0;
	temp.w = 500;
	temp.h = 700;

	SDL_RenderCopy(global->renderer, bt_1.figure, NULL, &(temp));

	
	SDL_RenderPresent(global->renderer);
	SDL_FreeSurface(background);
}

void playlayout_basic(){ // Temporarily test.
	SDL_SetRenderDrawColor(global->renderer, BG_R, BG_G, BG_B, BG_A);
	SDL_RenderClear(global->renderer);
	
	// Display the grids of the map.
	SDL_SetRenderDrawColor(global->renderer, 0, 0, 0, 255);
	for (int i = 0; i < 15; i++)
		SDL_RenderDrawLine(global->renderer,
       		80 * (i + 1), 0, 80 * (i + 1), 800);
	for (int i = 0; i < 9; i++)
		SDL_RenderDrawLine(global->renderer,
        	0, 80 * (i + 1), 1200, 80 * (i + 1));
	
	// Display the operation area on the right side.
	SDL_SetRenderDrawColor(global->renderer, 180, 180, 50, 255);
	SDL_Rect desk = {
		1205,
		0,
		395,
		800
		};
	SDL_RenderFillRect(global->renderer, &desk);


	SDL_RenderPresent(global->renderer);

}






////////////////////////////////////
int display_loadFiles(void) {
    //Load all files necessary to display.
	
	// Font
	if (TTF_Init()){
		fprintf(stderr, "Error initializing SDL_ttf.\n");
		return FALSE;
	}
	font = TTF_OpenFont("./resources/font/CaviarDreams.ttf", 52);
	if (font == NULL){
		fprintf(stderr, "Error loading font.\n");
		return FALSE;
	}

	//Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if(!( IMG_Init(imgFlags) & imgFlags )){
		fprintf(stderr, "Error initializing SDL image.\n");
        return FALSE;
    }

	//Get window surface
    global->screenSur = SDL_GetWindowSurface(global->window);

	if (global->screenSur == NULL) {
		fprintf(stderr, "Error initializing surface.\n");
		return FALSE;
	}

    return TRUE;
}

void display_button(Button* bt){

	SDL_Rect theBox = {
		bt->box.x - 15,
		bt->box.y - 10,
		bt->box.w + 30,
		bt->box.h + 20
	};

	SDL_RenderFillRect(global->renderer, &(theBox)); // Display the box containing the symbol of the text with a colored rect.
	SDL_RenderCopy(global->renderer, bt->figure, NULL, &(bt->box));
	bt->box = theBox;
}

void destroy_window(void){
	SDL_DestroyRenderer(global->renderer);	
	SDL_DestroyWindow(global->window);
	TTF_CloseFont(font);
	TTF_Quit();	
	IMG_Quit();
	SDL_Quit();
}
