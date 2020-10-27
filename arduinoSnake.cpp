void main(){
	if(analogRead(pb))
		return;
	// Joystick
	switch(dir){
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
	moveSnake();
	if(apple[x][y]){
		p++;
		apple[x][y] = false;
		apple[random[sizex]][random[sizey]] = true;
	}
	}