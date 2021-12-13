#include "SDL.h"
#include "Window.h"
#include "Game.h"
#include "TextureManager.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	Window* window = new Window();
	TextureManager::getInstance()->SetWindow(window);

	window->initializeWindow("Enginar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	game = new Game();
	game->initializeGame(window);

	return 0;
}