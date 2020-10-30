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
}

// Loop
void loop()
{
	if(digitalRead(pb)) // The push button toggles the game status
	{
		// Do some stuff
	}
	// Do some other stuff
}

// Other global functions
int convert(int x, int y, int sx)
{
  return y*sx+x;
}
