#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

SDL_Texture* player = nullptr;

void Game::initializeGame(Window* _window)
{
	window = _window;

#pragma region Test Texture Rendering
	SDL_Surface* t = IMG_Load("assets/char.png");
	player = SDL_CreateTextureFromSurface(_window->getRenderer(), t);
	SDL_FreeSurface(t);
	window->addTexture(player);
#pragma endregion

	loop();
}

void Game::loop()
{
	int x = 0;
	while (true)
	{
		window->render();
	}
}
