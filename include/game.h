/*
 * game.h
 *
 * Store the information of one specific battle.
 *
 */

//////////
//typedefs
//////////
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

///////////
//functions
///////////

void run_game(void);
