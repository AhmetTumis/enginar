#include "SceneManager.h"

SceneManager::SceneManager()
{
	instance = this;
	gameInstance = Game::getInstance();
}

void SceneManager::loadScene(Scene* scene)
{
	Game::getInstance()->getActiveScene()->unload();
	Game::getInstance()->setActiveScene(scene);
}
