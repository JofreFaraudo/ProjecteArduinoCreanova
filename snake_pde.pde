import processing.serial.*;
import cc.arduino.*;
import java.util.*;
import java.util.Arrays;

Arduino arduino;
PImage pic; // Title screen image
PImage pgo; // Game over screen image

// Constants
final static int pb = 10; // pushbutton pin
final static int jx = 1; // Joystic x
final static int jy = 0; // Joystick y
final static int sizex = 20; // screen size x
final static int sizey = 20; // Screen size y
final static int jthreshold = 100; // Threshold for joystick
final static int is = 6; // Initial speed
final static int initialTailSize = 3; // The size of the tail when beginning the game
final static int initialApples = 330; // Num of apples when beginning the game
final static int sd = 15;
final static int d = 30;
final static int size = 40;
final static int margin = 50;

// Global vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int s; // Speed
int mc; // Speed var auxiliar, counter
int tdir; // Dir var auxiliar
boolean playing; // Is the game running?
int[] apple = new int[initialApples];
List<Integer> snakeTail = new ArrayList<Integer>();

// Global functions
int convert(int x, int y, int sx){
  return y*sx+x;
}
void endGame(){
  endGame(false);
}
void endGame(boolean nd)
{
  playing = false;
  if(nd)
  {
    clear(); // Clearing the game screen
    // Showing points to player
    textSize(18);
    text("Score: "+p, 10, 30);
    //image(pgo, 0, 0); // Showing the game over image...
    //delay(2000); // for 2 seconds
  }
  else
    delay(50);
  titleScreen(); // Returning to title
}
void titleScreen(){
  clear();
  image(pic, 0, 0);
}
int indexOf(int arr[], int obj){
  for(int i = 0; i < arr.length; i++)
    if(arr[i] == obj)
      return i;
  return -1;
}
int newApple(){
  ArrayList<Integer> t = new ArrayList();
  for(int i = 0; i < sizex*sizey; i++){
    if(!snakeTail.contains(i) && indexOf(apple, i) == -1)
      t.add(i);
  }
  if(t.size() > 0)
    return t.get((int)random(t.size()));
  return -1;
}
void initGame()
{
  playing = true;
  s = is;
  p = 0;
  mc = 0;
  for(int i = 0; i < initialApples; i++)
    apple[i]=newApple();
  x = (int)sizex/2;
  y = (int)sizey/2;
  dir = 0;
  snakeTail.removeAll(snakeTail);
  for(int i = 1; i < initialTailSize; i++)
    snakeTail.add(convert(y-1,x,sizex));
}
void gameScreen(){
  clear();
  background(color(150, 150, 150));
  fill(color(10,10,10));
  noStroke();
  square(margin, margin, 800);
  stroke(color(109, 201, 147));
  fill(0, 135, 56);
  square(x*size+margin, y*size+margin, size);
  fill(20, 240, 170);
  for(Integer j : snakeTail)
    square(j%sizex*size+margin, (int)(j/sizex)*size+margin, size);
  fill(250, 50, 50);
  stroke(253, 10, 10);
  for(int j : apple)
    square(j%sizex*size+margin, (int)(j/sizex)*size+margin, size);
  textSize(30);
  fill(61, 51, 51);
  text("Score: " + p, 300, 40);
}
void play(){
  if(dir%2 == 0){
    if(arduino.analogRead(jx) > 1023-jthreshold) // Whenever the joystick moves (pos > threshold, in each direction), update the direction
      tdir = 1;
    if(arduino.analogRead(jx) < jthreshold)
      tdir = 3;
  }else{
    if(arduino.analogRead(jy) > 1023-jthreshold)
      tdir = 0;
    if(arduino.analogRead(jy) < jthreshold)
      tdir = 2;
  }
  if(s < 0)
    s = 0;
  if(mc > s){
    mc = 0;
    dir = tdir;
  snakeTail.add(convert(x,y,sizex)); // Adding old head pos to the tail
  switch(dir) // Moving the head to the new pos
  {
    case 0:
      y++;
      break;
    case 1:
      x++;
      break;
    case 2:
      y--;
      break;
    case 3:
      x--;
      break;
  }
  if(snakeTail.contains(convert(x,y,sizex)) // If the snake collides with iself (head -> tail), ...
    || x < 0 || x >= sizex || y < 0 || y >= sizey)  // If the new pos is not within the game field (if the snakes collides with edges), ...
  {
    endGame(true); // ...it dies. The game is over.
    return;
  }
  int index = indexOf(apple, convert(x, y, sizex));
  if(index != -1) // If there's an apple, add a new one and update points
  {
    p++;
    s = is-int(p/sd);
    apple[index] = newApple();
    if(apple[index] == -1)
      endGame();
  }else // If there's not, the snake length does not increase. Removing the end of the tail
    snakeTail.remove(0);
  gameScreen(); // Creating graphics
  }else{
    mc++;
  }
}

void setup()
{
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(pb, Arduino.INPUT);
  arduino.pinMode(jx, Arduino.INPUT);
  arduino.pinMode(jy, Arduino.INPUT);
  playing = false;
  size(900, 900);
  pic = loadImage("title.png");
  pgo = loadImage("gameover.png");
  titleScreen();
}

void draw()
{
  /*if(arduino.digitalRead(pb) == 1){
    if(!playing)
      initGame();
    else 
      endGame();
  }*/
  if(playing){
    play();
  }else{
    if(arduino.digitalRead(pb) == 1){
      delay(500);
      initGame();
    }
  }
  delay(d);
}
