// External libraries
#include "VGAX.h"
#include "ListLib.h"
// Auxiliar files
#include "constants.h"
#include "game.h"
#include "screen.h"

// Setup
void setup()
{
	vga.begin();
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
		if(playing)
			endGame();
		else
			initGame();
	}
	if(playing)
		play();
}

// Other global functions
int convert(int x, int y, int sx)
{
  return y*sx+x;
}
