#include <VGAX.h>
#include "constants.h"
#include "game.h"
#include "screen.h"
VGAX vga;
void setup(){
	vga.begin();
	pinMode(pb,INPUT_PULLUP);
	pinMode(jx,INPUT);
	pinMode(jy,INPUT);
}
void loop(){}
