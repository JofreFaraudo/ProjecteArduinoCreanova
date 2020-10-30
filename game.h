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
		mc = speed;
		snakeTail.add(convert(y,x,sizex)); // Adding old head pos to the tail
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
		if(apple[y][x]) // If there's an apple, add a new one and update points
		{
			p++;
			apple[y][x] = false;
			newApple();
		}else // If there's not, the snake length does not increase. Removing the end of the tail
			snakeTail.removeLast();
	}
	else
		mc--;
}

void newApple()
{
	newApple(1);
}

void newApple(int q)
{
	List<int> pc;
	for(int i = 0; i < sizex*sizey; i++)
		if(!snakeTail.Contains(i) || i == convert(y,x,sizex) || !apple[i])
			pc.insert(i);
	for(; q > 0; q--;)
	{
		int g = random[pc.Count()];
		apple[pc[g]] = true;
		pc.Remove(g);
	}
	delete pc;
}

void endGame()
{
	playing = false;
}

void initGame()
{
	playing = true;
	mc = 0;
	newApple(initialApples);
	x = (int)sizex/2;
	y = (int)sizey/2;
	dir = 0;
	snakeTail.Clear();
	for(int i = 1; i <= initialTailSize; i++)
		snakeTail.add(convert(y-i,x,sizex));
}