#define FALSE 0
#define TRUE 1

#define WINDOW_WIDTH 1800
#define WINDOW_HEIGHT 960

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

#define IMAGE_PATH "./resources/images/red/tank/l1.png"

// The color parameters of background. 
#define BG_R 120
#define BG_G 150
#define BG_B 120
#define BG_A 80

// Parameters for welcome buttons.
#define WB_W 200
#define WB_H 70
#define WB_R 40 
#define WB_G 40
#define WB_B 80
#define WB_A 160

// The color parameters of teams. 
#define RED_R 220
#define RED_G 0
#define RED_B 0
#define RED_A 255
#define BLUE_R 0
#define BLUE_G 0
#define BLUE_B 255
#define BLUE_A 255

#define GRID 20
#define MAP_HEIGHT WINDOW_HEIGHT
#define MAP_WIDTH MAP_HEIGHT/2*3
#define ROW MAP_HEIGHT/GRID
#define COL MAP_WIDTH/GRID
