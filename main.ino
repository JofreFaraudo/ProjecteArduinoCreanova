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
}

// Other global functions
int convert(int x, int y, int sx)
{
  return y*sx+x;
}
