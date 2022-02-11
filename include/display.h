/*
 *
 * display.h
 *
 * All the functions that handle the display.
 *
 */
void display_prepare(void);
void display_picking(void);
int display_loadFiles(void);
void destroy_window(void);
void draw_button(Button*);
void playlayout_basic(void);
void draw_land(void);
void draw_birth_place(int, int, int, int);
void draw_unit(Player *, Unit *);
void draw_unit_route(Unit*);
void draw_units(void);
void draw_unit_desk(Unit*, Player*);
