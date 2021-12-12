#include "SDL.h"
#include "Window.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	Window* window = new Window();
	window->initializeWindow("Enginar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	game = new Game();
	game->initializeGame(window);

	return 0;
}