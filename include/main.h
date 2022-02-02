/*
 * main.h 
 *
 * The main loop of the game, handling the build up and tear down process.
 */
////////////
//functions
////////////
int initialize_window(void);
int setup(void);
void setup_prepare(void);
void process_prepare(void);
void setup_picking(void);
void process_picking(void);
int clicked(Button *, float, float);
