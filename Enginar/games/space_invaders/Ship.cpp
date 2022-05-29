#include "Ship.h"
#include "../../io/InputManager.h"
#include "Bullet.h"
#include "../../common/Game.h"

void PlayerShip::update()
{
	GameObject::update();

	cooldown--;

	if (InputManager::getInstance()->isPressing(SDLK_d) || InputManager::getInstance()->isPressing("d"))
	{
		//Asound->PlaySound();
		getTransform()->setPositionX(getTransform()->getPositionX() + 1);
	}
	if (InputManager::getInstance()->isPressing(SDLK_a) || InputManager::getInstance()->isPressing("a"))
	{
		//Asound->PlaySound();
		getTransform()->setPositionX(getTransform()->getPositionX() - 1);
	}

	if (cooldown <= 0)
	{

		if (InputManager::getInstance()->isPressing(SDLK_SPACE))
		{
			Bullet* bull = new Bullet(myScene, true);
			bull->name = "bullet";

			float posy = getTransform()->getPosition()->y;
			bull->getTransform()->setPosition(new vector2(getTransform()->getPosition()->x, getTransform()->getPosition()->y));

			cooldown = 50;

		}
	}
	

}

void EnemyShip::update()
{
	GameObject::update();

	cooldown--;

	if (cooldown <= 0)
	{
		cooldown = 2;

		getTransform()->setPositionX(getTransform()->getPositionX() + 1);

		if (getTransform()->getPositionX() > Game::getInstance()->getWindow()->getWindowSize().x)
		{
			getTransform()->setPositionY(getTransform()->getPositionY() + 50);
			getTransform()->setPositionX(0);
		}
	}
}
