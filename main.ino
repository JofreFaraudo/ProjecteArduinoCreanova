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
	playing = false;
	vga.begin();
	pinMode(pb,INPUT_PULLUP);
	pinMode(jx,INPUT);
	pinMode(jy,INPUT);
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
		titleScreen();
	else{
		play();
		gameScreen();
	}
}

// Other global functions
int convert(int x, int y, int sx)
{
  return y*sx+x;
}
