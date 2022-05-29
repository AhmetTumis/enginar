#pragma once
#include "../../common/Game.h"
#include "../../common/GameObject.h"
#include "../../common/Matrix.h"
#include "Ship.h"

class Game;

class GameManager : public GameObject
{
public:
	GameManager() 
	{
		go = this;
	}

	inline static GameManager* go;
	inline static GameManager* getGO()
	{
		return go;
	}

	void onSceneLoaded() override;

	void createUI();

	int getRand();

	void spawnEnemyShip();

	void update();

	int frame;

	int score;
	int health = 5;

	GameObject* scoreText = nullptr;
	GameObject* healthText = nullptr;
private:
};

