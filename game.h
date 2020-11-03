void play()
{
	if(analogRead(jx) > 1023-jthreshold) // Whenever the joystick moves (pos > threshold, in each direction), update the direction
		dir = 1;
	if(analogRead(jy) > 1023-jthreshold)
		dir = 0;
	if(analogRead(jx) < jthreshold)
		dir = 3;
	if(analogRead(jy) < jthreshold)
		dir = 2;
	if(mc = 0)
	{
		mc = s;
		snakeTail.Add(convert(y,x,sizex)); // Adding old head pos to the tail
		switch(dir) // Moving the head to the new pos
		{
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
		if(snakeTail.Contains(convert(x,y,sizex)) // If the snake collides with iself (head -> tail), ...
			|| x < 0 || x >= sizex || y < 0 || y >= sizey)  // If the new pos is not within the game field (if the snakes collides with edges), ...
		{
			endGame(); // ...it dies. The game is over.
			return;
		}
		if(arrayContains(apple, initialApples, convert(y,x,sizex)) != -1) // If there's an apple, add a new one and update points
		{
			p++;
			apple[arrayContains(apple, initialApples, convert(y,x,sizex))] = newApple();
		}else // If there's not, the snake length does not increase. Removing the end of the tail
			snakeTail.RemoveLast();
		gameScreen(); // Creating graphics
	}
	else
		mc--;
}

int newApple()
{
	List<int> pc;
  for(int i = 0; i < sizex*sizey; i++)
    if(!snakeTail.Contains(i) || i == convert(y,x,sizex) || arrayContains(apple, initialApples, i) != -1)
      pc.Insert(i);
  int a = pc[random(pc.Count())];
  delete &pc[0];
  return a;
}

void newApples(int q)
{
	while(q > 0)
  {
    apple[q] = newApple();
    q--;
  }
}

void endGame()
{
	playing = false;
  titleScreen();
}
void initGame()
{
	playing = true;
	mc = 0;
	newApples(initialApples);
	x = (int)sizex/2;
	y = (int)sizey/2;
	dir = 0;
  gameScreen();
	//snakeTail.Clear();
	//for(int i = 1; i < initialTailSize; i++)
    //Serial.println(convert(y-i,x,sizex));
		//snakeTail.Add(convert(y-1,x,sizex));
}
