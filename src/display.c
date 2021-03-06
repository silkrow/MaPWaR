#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "extern_game.h"
#include "extern.h"
#include "display.h"
#include "con.h"

extern Player* p1;
extern Player* p2;
/////////////////////////////////////////////////////////////////////
/////variables
TTF_Font * font = NULL;

/////////////////////////////////////////////////////////////////////
/*
 * Set the preparing window.
 */
void display_prepare(void){

	SDL_SetRenderDrawColor(global->renderer, BG_R, BG_G, BG_B, BG_A);
	SDL_RenderClear(global->renderer);
	SDL_Surface * background = NULL;

	background = IMG_Load("./resources/images/basic/bg.bmp");
    if (background == NULL)
    {
        fprintf(stderr, "Unable to load image.\n");
       	return;
    }
	
	SDL_Texture * texture = SDL_CreateTextureFromSurface(global->renderer, background);
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

	draw_button(&(bt_0));

	
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
	background = IMG_Load("./resources/images/basic/ts.png");
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
	background = IMG_Load("./resources/images/basic/jw.png");
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
	
	// Display the operation area on the right side.
	SDL_SetRenderDrawColor(global->renderer, 130, 130, 50, 255);
	SDL_Rect desk = {
		MAP_WIDTH,
		0,
		WINDOW_WIDTH - MAP_WIDTH,
		MAP_HEIGHT
		};
	SDL_RenderFillRect(global->renderer, &desk);

	// Display the window for the unit picture.
	SDL_Surface * s = NULL;
	s = IMG_Load("./resources/images/basic/unit_pic.png");
	SDL_Texture * t = SDL_CreateTextureFromSurface(global->renderer, s);
	SDL_Rect box = {
		DESK_UNIT_X,
		DESK_UNIT_Y,
		DESK_UNIT_LENGTH,
		DESK_UNIT_LENGTH
	}; 

	SDL_RenderCopy(global->renderer, t, NULL, &box);


	// Display the 'next round' button.
	SDL_Color color = {240, 240, 240};
	SDL_Surface * surface = TTF_RenderText_Solid(font, "Next Round", color);
	bt_0.figure = SDL_CreateTextureFromSurface(global->renderer, surface);
	int txt_w = 0;
	int txt_h = 0;
	SDL_QueryTexture(bt_0.figure, NULL, NULL, &txt_w, &txt_h);
	SDL_Rect txtBox = { 
		WINDOW_WIDTH/2 + MAP_WIDTH/2 - txt_w/2,
		WINDOW_HEIGHT - txt_h - 60,
		txt_w,
		txt_h
	};
	bt_0.box = txtBox;
	SDL_SetRenderDrawColor(global->renderer, 0, 150, 0, 205);
	draw_button(&(bt_0));

	SDL_FreeSurface(s);
	SDL_FreeSurface(surface);
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

void draw_button(Button* bt){

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

void draw_land(void) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
		{
			SDL_SetRenderDrawColor(global->renderer,
					BG_R - land[i][j].h*20, 
					BG_G - land[i][j].h*20,
					BG_B - land[i][j].h*20, 
					BG_A);
			SDL_RenderFillRect(global->renderer, &(land[i][j].box));
		}
}

void draw_birth_place(int x1, int y1, int x2, int y2){
	SDL_SetRenderDrawColor(global->renderer, 0, 0, 0, 255);
	SDL_Rect rect = {
		y1 * GRID,
		x1 * GRID,
		GRID,
		GRID
	};
	SDL_RenderDrawRect(global->renderer, &rect);
	
	rect.x = y2*GRID;
	rect.y = x2*GRID;

	SDL_RenderDrawRect(global->renderer, &rect);
}

void draw_unit(Player* p, Unit* u){
	SDL_Surface * s = NULL;
	char image_path[50];
	image_path[0] = '\0';
	strcat(image_path, p->image);
	strcat(image_path, u->name);

	if (p->side == 0)
		strcat(image_path, "r");
	else 
		strcat(image_path, "l");

	if (u->walkable)
	{
		if (u->walking)
		{
			switch (u->n_png){
				case 1:	
					strcat(image_path, "1");
					break;
				case 2:	
					strcat(image_path, "2");
					break;
				case 3:	
					strcat(image_path, "3");
					break;
				case 4:	
					strcat(image_path, "4");
					break;
				default:
					break;
			}
			u->n_png = (u->n_png + 1) % 4 + 1;
		}
		else strcat(image_path, "1");
	}
	else {
		strcat(image_path, "0");	
	}

	strcat(image_path, ".png");

	s = IMG_Load(image_path);
	SDL_Texture * t = SDL_CreateTextureFromSurface(global->renderer, s);
	SDL_RenderCopy(global->renderer, t, NULL, &(u->box));

	SDL_FreeSurface(s);
}

void draw_unit_route(Unit* u){
	/* If there's a destination, draw the point and the route. */
	if (u->to_x != -1)
	{
		SDL_SetRenderDrawColor(global->renderer, 0, 0, 0, 255);
		SDL_RenderDrawPoint(global->renderer, u->to_x, u->to_y);
		SDL_RenderDrawLine(global->renderer, u->to_x, u->to_y, u->x, u->y);
	}

}

void draw_units(void){
	Unit* ptr;
	ptr = p1->Army;
	while(ptr->forward != NULL){
		draw_unit(p1, ptr->forward);
		ptr = ptr->forward;
	}

	ptr = p2->Army;
	while(ptr->forward != NULL){
		draw_unit(p2, ptr->forward);
		ptr = ptr->forward;
	}

	/* Now draw the cover(for sight)*/

	/* Now draw the routes. */

	if (p1->next_round == FALSE){ // p1's round.
		ptr = p1->Army;
		while(ptr->forward != NULL){
			draw_unit_route(ptr->forward);
			ptr = ptr->forward;
		}
	}
	else{ // p2's round.
		ptr = p2->Army;
		while(ptr->forward != NULL){
			draw_unit_route(ptr->forward);
			ptr = ptr->forward;
		}
	}
}

void draw_unit_desk(Unit* u, Player* p){
	SDL_Surface * s = NULL;
	char image_path[50];
	image_path[0] = '\0';
	strcat(image_path, p->image);
	strcat(image_path, u->name);

	if (p->side == 0)
		strcat(image_path, "r");
	else
		strcat(image_path, "l");

	if (u->walkable){
		strcat(image_path, "1");
	}
	else strcat(image_path, "0");

	strcat(image_path, ".png");

	s = IMG_Load(image_path);
	SDL_Texture * t = SDL_CreateTextureFromSurface(global->renderer, s);

	SDL_Rect box = {
		DESK_UNIT_X + 20,
		DESK_UNIT_Y + 20,
		265,
		265
	};
	SDL_RenderCopy(global->renderer, t, NULL, &box);

	SDL_FreeSurface(s);
}
