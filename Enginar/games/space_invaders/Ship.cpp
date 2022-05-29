#include "Ship.h"
#include "../../io/InputManager.h"
#include "Bullet.h"
#include "../../common/Game.h"
#include "GameManager.h"

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
	if (!isActive)
	{
		return;
	}

	GameObject::update();

	cooldown--;

	if (cooldown <= 0)
	{
		cooldown = 1;

		getTransform()->setPositionX(getTransform()->getPositionX() + 1);

		if (getTransform()->getPositionX() > Game::getInstance()->getWindow()->getWindowSize().x)
		{
			getTransform()->setPositionY(getTransform()->getPositionY() + 500);
			getTransform()->setPositionX(0);
		}

		if (getTransform()->getPositionY() > Game::getInstance()->getWindow()->getWindowSize().y)
		{
			GameManager::getGO()->health--;
			if (GameManager::getGO()->health <= 0)
			{
				Game::getInstance()->isWorking = false;
			}
			GameManager::getGO()->healthText->getText()->setText(("Health: " + std::to_string(GameManager::getGO()->health)).c_str());
			Destroy();
		}
	}
}
