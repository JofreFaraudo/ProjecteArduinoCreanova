// Constants
#define pb // pushbutton pin
#define jx // Joystic x
#define jy // Joystick y
#define sizex // screen size
#define sizey // Screen size
#define jthreshold 1000 // Threshold for joystick

// Vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int[sizex][sizey] apple;
int[] snake; // list array, pendent array dinamic de touples coords

// funtions
void moveSnake();
void drawBackground();