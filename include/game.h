/*
 * game.h
 *
 * Store the information of one specific battle.
 *
 */






typedef struct landform
{
    objectType type;
    SDL_Texture * image;
    SDL_Rect clip;
    uint16_t subImage;
    uint16_t subImageNumber;
    int x;
    int y;
    int16_t lives;
    float scale;
    struct object * next;
} Landform;

typedef struct troop
{
    objectType type;
    SDL_Texture * image;
    SDL_Rect clip;
    uint16_t subImage;
    uint16_t subImageNumber;
    int x;
    int y;
    int16_t lives;
    float scale;
    struct object * next;
} Troop;
