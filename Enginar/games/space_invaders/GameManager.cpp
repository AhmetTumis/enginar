#include "GameManager.h"
#include "../../io/InputManager.h"
#include <time.h>
#include <random>

void GameManager::spawnEnemyShip()
{
	EnemyShipA* ea = new EnemyShipA(myScene);
	ea->name = "ea";
	float offset = ea->getTransform()->getScaleY() + Game::getInstance()->getWindow()->getWindowSize().y * .1f;
	ea->getTransform()->setPosition(new vector2(Game::getInstance()->getWindow()->getWindowSize().x / 2, offset));

}

void GameManager::onSceneLoaded()
{
	PlayerShip* ps = new PlayerShip(myScene);
	ps->name = "playership";
	float offset = ps->getTransform()->getScaleY() + Game::getInstance()->getWindow()->getWindowSize().y * .1f;
	ps->getTransform()->setPosition(new vector2(Game::getInstance()->getWindow()->getWindowSize().x / 2, Game::getInstance()->getWindow()->getWindowSize().y - offset));

	createUI();
}

void GameManager::createUI()
{
	scoreText = new GameObject();
	scoreText->init(myScene);

	Text* t = new Text("test");
	t->init("Score: 0", "assets/Marker Felt.ttf", 24, SDL_Rect{ 0,0,100,50 });
	scoreText->addComponent(make_any<Text*>(dynamic_cast<Text*>(t)));

	healthText = new GameObject();
	healthText->init(myScene);

	Text* t2 = new Text("test");
	t2->init("Health: 5", "assets/Marker Felt.ttf", 24, SDL_Rect{ 0,50,100,50 });
	healthText->addComponent(make_any<Text*>(dynamic_cast<Text*>(t2)));
}

int GameManager::getRand()
{
	float v = rand();
	v /= RAND_MAX;
	return v > .5f ? 1 : 0;
}

void GameManager::update()
{
	GameObject::update();

	frame++;

	if (frame % 100 == 0)
	{
		spawnEnemyShip();
	}
}
