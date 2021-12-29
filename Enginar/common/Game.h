#pragma once

#include "../graphics/Window.h"
#include "SDL_image.h"
#include "../common/GameObject.h"

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