/*
 *
 * types.h
 *
 * Holds all the enum and structures.
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/////////////
//enums
/////////////
typedef enum
{
	GAME_PREPARE,
	GAME_PICK,
	GAME_START,
	GAME_END,
} gameState; 

typedef enum
{
	HUMAN,
	AI
} playerType;

typedef enum
{
	RED,
	BLUE
} armyType;

////////////
//structures
////////////

typedef struct globalSDL
{
    /* Game constants */
	int window_width;
	int window_height;
	float fps;
	float spf;

    /* global SDL objects */
    SDL_Window * window;
    SDL_Renderer * renderer;
	SDL_Surface * screenSur;

    /* Game running flag */
    int running;
	

    /* Game is state base */
    gameState state;

    /* Game timers */
    //uint32_t timer[TIMER_TYPE_SIZE];
	
	/* Timer */
	int last_frame_time;
} GlobalSDL;

typedef struct playerInfo
{
	playerType playertype;
	armyType armytype;
	int side; // 0 for right, 1 for left.
	int birth_x;
	int birth_y;
} Player;

typedef struct {
	SDL_Texture * figure; // The main part to be displayed.
    SDL_Rect box;    // The valid part of the button.
} Button;

