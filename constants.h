// Constants
#define pb // pushbutton pin
#define jx // Joystic x
#define jy // Joystick y
#define sizex 30 // screen size x
#define sizey 60 // Screen size y
#define jthreshold 100 // Threshold for joystick
#define speed 1000 // Speed
#define initialTailSize 3 // The size of the tail when beginning the game
#define initialApples 2 // Apples when beginning the game

// Global vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int mc; // Speed var auxiliar, counter
int apple[sizey][sizex];
List<int> snakeTail;

// Global functions
int convert(int x, int y, int sx);
void play();
void newApple();
void newApple(int q);
void gameScreen();
void titleScreen();
void endGame();
void initGame();
