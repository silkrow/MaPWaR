/*
 *
 * types.h
 *
 * Holds all the enum and structures.
 */

#include <SDL2/SDL.h>

/////////////
//enums
/////////////
typedef enum
{
	GAME_PREPARE,
	GAME_PICK,
	GAME_START,
	GAME_END,
	GAME_EXIT
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

} Player;

typedef struct {
    SDL_Rect rect;    // dimensions of button
    int pressed;
} Button;
