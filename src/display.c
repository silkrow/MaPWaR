#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "display.h"
#include "con.h"
#include "extern.h"
/////////////////////////////////////////////////////////////////////
/////variables

/////////////////////////////////////////////////////////////////////
/*
 * Set the preparing window.
 */
void display_prepare(void){

	SDL_Surface * background = NULL;

	background = SDL_Load("./resources/images/bg.bmp");
    if (background == NULL)
    {
        fprintf(stderr, "Unable to load image.\n");
       	return;
    }
	//Apply the image
    SDL_BlitSurface(background, NULL, global->screenSur, NULL);

    //Update the surface
    SDL_UpdateWindowSurface(global->window);
}

void display_picking(void){}

int display_load_files(void) {
    //Load all files necessary to display.
	
	// Font
	if (TTF_Init()){
		fprintf(stderr, "Error initializing SDL_ttf.\n");
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
    	



    //background = load_image( "background.png" );

    //If there was a problem in loading the background
    //if( background == NULL )
    //{
    //    return FALSE;
    //}

    //If everything loaded fine
    return TRUE;
}
