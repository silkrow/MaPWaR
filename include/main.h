/*
 * main.h 
 *
 * The main loop of the game, handling the build up and tear down process.
 */

int initialize_window(void);
void setup(void);
void destroy_window(void);

typedef struct globalSDL
{
    /* Game constants */
    uint16_t screenWidth;
    uint16_t screenHeight;
    float screenTop;
    float screenBottom;
    float screenLeft;
    float screenRight;
    float framesPerSecond;
    float gameTickRatio;

    /* Base path of game directory */
    char * basePath;

    /* global SDL objects */
    SDL_Window * window;
    SDL_Renderer * renderer;
    const uint8_t * keystates;

    /* Game running flag */
    uint8_t exit;

    /* Game is state base */
    gameState state;

    /* Game timers */
    uint32_t timer[TIMER_TYPE_SIZE];
} GlobalSDL;


