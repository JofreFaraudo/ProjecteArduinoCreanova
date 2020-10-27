void main(){
	if(digitalRead(pb))
		return;
	if(analogRead(jx)>1023-jthreshold )
		dir = 1;
	if((analogRead(jy)>1023-jthreshold )
		dir = 0;
	if(analogRead(jx)<jthreshold )
		dir = 3;
	if((analogRead(jy)<jthreshold )
		dir = 2;
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
	   if(mc = 0){
	   mc = speed;
		   moveSnake();
	   }
	   else mc--;3
	if(apple[x][y]){
		p++;
		apple[x][y] = false;
		apple[random[sizex]][random[sizey]] = true;
	}
	}
