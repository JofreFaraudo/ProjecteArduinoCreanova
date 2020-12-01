// Constants
#define pb 10 // pushbutton pin
#define jx A0 // Joystic x
#define jy A1 // Joystick y
#define sizex 30 // screen size x
#define sizey 60 // Screen size y
#define jthreshold 100 // Threshold for joystick
#define s 1000 // Speed
#define initialTailSize 3 // The size of the tail when beginning the game
#define initialApples 4 // Apples when beginning the game
#define d 400

// Global vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int mc; // Speed var auxiliar, counter
bool playing; // Is the game running?
int apple[initialApples];
List<int> snakeTail;
//VGAX vga;

// Global functions
int convert(int x, int y, int sx);
//int arrayContains(int &a, int l, int e);
void play();
int newApple();
void gameScreen();
void titleScreen();
void endGame();
void initGame();
