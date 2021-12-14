#pragma once

#include "Window.h"
#include "SDL_image.h"
#include "GameObject.h"

class Game
{
public:
	Game();
	~Game();

	void initializeGame(Window* _window);

	//gameloop
	void loop();

private:
	Window* window;
	vector<GameObject*> gameObjects;
};