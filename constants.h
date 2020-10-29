// Constants
#define pb // pushbutton pin
#define jx // Joystic x
#define jy // Joystick y
#define sizex // screen size
#define sizey // Screen size
#define jthreshold 100 // Threshold for joystick
#define speed // Speed

// Vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int mc; // Speed var auxiliar, counter
int[sizex][sizey] apple;
int[] snake; // list array, pendent array dinamic de touples coords

// funtions
void drawBackground();