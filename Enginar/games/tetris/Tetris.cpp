#include "Tetris.h"
#include "Piece.h"
#include "GameManager.h"
#include "../../common/Scene.h"
#include "../../games/tetris/MenuManager.h"

Tetris::Tetris()
{


}

void Tetris::initializeGame(Window* _window)
{
	Game::initializeGame(_window);

	Scene* mainMenu = new Scene();
	Game::getInstance()->setActiveScene(mainMenu);

	Scene* gameScene = new Scene();
	GameManager* gm = new GameManager(gameScene);

	MenuManager* mm = new MenuManager();
	mm->init(mainMenu);
	mm->createUI(gameScene);

	//gm->init(mainMenu);

	printf("Welcome to tetris");

	loop();
}
