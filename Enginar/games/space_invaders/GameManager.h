#pragma once
#include "../../common/Game.h"
#include "../../common/GameObject.h"
#include "../../common/Matrix.h"
#include "Ship.h"

class Game;

class GameManager : public GameObject
{
public:
	inline static GameManager* go;
	inline static GameManager* getGO()
	{
		return go;
	}

	GameManager(Scene* scene)
	{
		init(scene);

		go = this;

		/*Texture* shipTexture = new Texture("assets/test.png");
		addComponent(make_any<Texture*>(dynamic_cast<Texture*>(shipTexture)));
		getTransform()->setScale(1);*/

		PlayerShip* ps = new PlayerShip(scene);
		ps->name = "playership";
		float offset = ps->getTransform()->getScaleY() + Game::getInstance()->getWindow()->getWindowSize().y * .1f;
		ps->getTransform()->setPosition(new vector2(Game::getInstance()->getWindow()->getWindowSize().x / 2, Game::getInstance()->getWindow()->getWindowSize().y - offset));

		createUI();
	}

	void createUI();

	int getRand();

	void spawnEnemyShip();

	void update();

	int frame;

	int score;

	GameObject* scoreText = nullptr;
private:
};

