#include "SDL.h"
#include "graphics/Window.h"
#include "common/Game.h"
#include "graphics/TextureManager.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	Matrix m1 = Matrix(2, 2);

	(m1.Inverse()).printMatrix();

	return 0;

	Window* window = new Window();
	TextureManager::getInstance()->SetWindow(window);

	window->initializeWindow("Enginar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	game = new Game();
	game->initializeGame(window);

	return 0;
}