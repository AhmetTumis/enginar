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

void GameManager::createUI()
{
	scoreText = new GameObject();

	Text* t = new Text("test");
	t->init("Score: 0", "assets/Marker Felt.ttf", 24, SDL_Rect{ 0,0,100,50 });
	scoreText->addComponent(make_any<Text*>(dynamic_cast<Text*>(t)));
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
