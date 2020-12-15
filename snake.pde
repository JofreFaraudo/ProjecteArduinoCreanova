
Jordi Villar Peidro
9:31 (fa 0 minuts)
per a mi

import processing.serial.*;
import cc.arduino.*;
import java.util.*;

Arduino arduino;
PImage pic;

// Constants
final static int pb = 10; // pushbutton pin
final static int jx = 14; // Joystic x
final static int jy = 15; // Joystick y
final static int sizex = 30; // screen size x
final static int sizey = 60; // Screen size y
final static int jthreshold = 100; // Threshold for joystick
final static int s = 1000; // Speed
final static int initialTailSize = 3; // The size of the tail when beginning the game
final static int initialApples = 4; // Apples when beginning the game
final static int d = 400;

// Global vars
int dir; // Dirs: 0 u, 1 r, 2 d, 3 l
int x; // Current pos x
int y; // current pos y
int p; // Current points
int mc; // Speed var auxiliar, counter
boolean playing; // Is the game running?
int[] apple = new int[initialApples];
List<Integer> snakeTail = new ArrayList<Integer>();

// Global functions
void endGame()
{
  playing = false;
  titleScreen();
}
void titleScreen(){
  image(pic,1,1);
}

void setup()
{
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(pb, Arduino.INPUT);
  arduino.pinMode(jx, Arduino.INPUT);
  arduino.pinMode(jy, Arduino.INPUT);
  playing = false;
  size(900, 900);
  pic = loadImage("deusTemporada_20172018.png");
}

void draw()
{
  /*if(arduino.digitalRead(pb) == 1){
    /*if(!playing)
      initGame();
    else ///
      endGame(); //
  }
  if(playing)
    //gameScreen();
    //play();
   println(playing);
   delay(d);*/
   titleScreen();
}
