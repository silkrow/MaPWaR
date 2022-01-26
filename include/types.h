/*
 *
 * types.h
 *
 * Holds all the enum and structures.
 */

////////////
//structures
////////////

typedef struct globalSDL
{
    /* Game constants */
	uint16_t window_width;
	uint16_t window_height;
	float fps;
	float spf;

    /* global SDL objects */
    SDL_Window * window;
    SDL_Renderer * renderer;
    const uint8_t * keystates;

    /* Game running flag */
    uint8_t running;

    /* Game is state base */
    gameState state;

    /* Game timers */
    //uint32_t timer[TIMER_TYPE_SIZE];
	
	/* Timer */
	int last_frame_time;
} GlobalSDL;


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
} teamType;

