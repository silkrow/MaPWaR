/*
 * game.h
 *
 * Store the information of one specific battle.
 *
 */
void run_game(void);
void set_game(armyType);
void destroy_game(void);
void set_map(void);
void random_mountain(int);
void h_down(int, int);
void generate_birth_place(Player *);
void free_units(Player *);
