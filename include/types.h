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

typedef struct unit{
	struct unit * forward; // Used in the linked list.
	struct unit * backward;

	SDL_Rect box;
	SDL_Rect grid;

	int x;
	int y; // The location of this unit.

	playerType playertype;
	char * name;
	int walking; // A 0/1 value, indicating whether the unit has a series of pictures for moving animation.
	int sight; // The range of sight, 0 for none.
	float d1;
	float d2; // In case of there're multiple kinds of damage.
	float speed; // The regular moving speed of the unit. 
} Unit;

typedef struct playerInfo
{
	playerType playertype;
	armyType armytype;
	int side; // 0 for right, 1 for left.
	int birth_x;
	int birth_y;
	char * image;
	int army_num;
	Unit * Army; // A double-linked list to hold the units for player.

	int next_round;
	int round;
} Player;

typedef struct {
	SDL_Texture * figure; // The main part to be displayed.
    SDL_Rect box;    // The valid part of the button.
} Button;

