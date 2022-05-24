#include "Tetris.h"
#include "Piece.h"
#include "GameManager.h"

Tetris::Tetris()
{


}

void Tetris::initializeGame(Window* _window)
{
	Game::initializeGame(_window);

	GameManager* gm = new GameManager();
	gm->init();

	printf("Welcome to tetris");

	loop();
}
