#include "entrypoint.h"

static SpaceInvaders* game = nullptr;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));


	Window* window = new Window();
	TextureManager::getInstance()->SetWindow(window);

	window->initializeWindow("Enginar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	game = new SpaceInvaders();
	game->initializeGame(window);

	return 0;
}