// Arduino main library
#ifndef ARDUINO
#include <arduino.h>
#endif

// External libraries
//#include "VGAX.h"
#include "ListLib.h"
// Auxiliar files
#include "constants.h"
//#include "screen.h"
#include "game.h"

// Setup
void setup(){
	//vga.begin();
	pinMode(pb,INPUT_PULLUP);
	pinMode(jx,INPUT);
	pinMode(jy,INPUT);
	Serial.begin(115200);
	playing = false;
	//titleScreen();
}

// Loop
void loop(){
	if(digitalRead(pb)){
		if(!playing)
			initGame();
    else //
      endGame(); //
	}
	if(playing)
    //gameScreen();
		play();
   Serial.println(playing);
   delay(d);
}

// Other global functions
int convert(int x, int y, int sx){
  return y*sx+x;
}
int arrayContains(int a[], int l, int e){
  for(int i = 0; i < l; a++)
    if(a[i] == e)
      return i;
  return -1;
}

void titleScreen(){
  Serial.println("Benvolgut al Snake de l\'ousmane i al Snake d\'en Viviano Espero que gaudeixis del teu Snake, merit de Juffrrenfa, pero idea de\'n Vivano");
}

void gameScreen(){
  Serial.print("hola");
  Serial.println("Tu no jugaras mai, jaja es broma xddd");
  Serial.println("playing: "+String(playing)+", x: "+ String(x)+", y: "+ String(y)+", mc: "+ String(mc)+", pts: "+ String(p)+", apples:");
  for(int i = 0; i < initialApples; i++)
    Serial.print(String(i)+':'+String(apple[i])+' ');
  Serial.println("tail");
  for(int i = 0; i < snakeTail.Count(); i++)
    Serial.print(i+':'+snakeTail[i]+' ');
}
