#include "SpaceInvaders.h"
#include "MenuManager.h"
#include "GameManager.h"

SpaceInvaders::SpaceInvaders()
{
}

void SpaceInvaders::initializeGame(Window* _window)
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

	loop();
}
