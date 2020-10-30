// Constants
#define pb // pushbutton pin
#define jx // Joystic x
#define jy // Joystick y
#define sizex 30 // screen size
#define sizey 60 // Screen size
#define jthreshold 100 // Threshold for joystick
#define speed 1000 // Speed

// Global vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int mc; // Speed var auxiliar, counter
int apple[sizey][sizex];
List<int> snakeTail;

// Global auxiliar functions
int convert(int x, int y, int sx){
  return y*sx+x;
}
