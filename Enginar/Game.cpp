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
	//Window'u eşitle
	window = _window;

#pragma region Test Texture Rendering
	SDL_Surface* t = IMG_Load("assets/char.png");
	player = SDL_CreateTextureFromSurface(_window->getRenderer(), t);
	SDL_FreeSurface(t);
	window->addTexture(player);
#pragma endregion

	loop();
}

//Gameloop
void Game::loop()
{
	int x = 0;
	while (true)
	{
		window->render();
	}
}
