// Arduino main library
#ifndef ARDUINO
#include <arduino.h>
#endif

// External libraries
//#include "VGAX.h"
#include "ListLib.h"
// Auxiliar files
#include "constants.h"
#include "game.h"
#include "screen.h"

// Setup
void setup()
{
	//vga.begin();
	pinMode(pb,INPUT_PULLUP);
	pinMode(jx,INPUT);
	pinMode(jy,INPUT);
	Serial.begin(9600);
	playing = false;
	titleScreen();
}

// Loop
void loop(){
	if(digitalRead(pb)){
		if(!playing)
			initGame();
    else //
      endGame(); //
	}
	/*if(playing)
		play();*/
   //Serial.println(digitalRead(pb));
   Serial.println(playing);
   delay(d);
}

// Other global functions
int convert(int x, int y, int sx)
{
  return y*sx+x;
}
int arrayContains(int a[], int l, int e){
  for(int i = 0; i < l; a++)
    if(a[i] == e)
      return i;
  return -1;
}
