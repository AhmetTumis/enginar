#pragma once

#include "Window.h"
#include "SDL_image.h"

class Game
{
public:
	Game();
	~Game();

	void initializeGame(Window* _window);

	void loop();

private:
	Window* window;
};