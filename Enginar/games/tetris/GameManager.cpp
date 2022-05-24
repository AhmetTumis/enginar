#include "GameManager.h"
#include "../../io/InputManager.h"
#include <time.h>
#include <random>

void GameManager::spawnPiece()
{
	auto shape = new Matrix3x3();

	float shapeArray[3][3] =
	{
		{getRand(),getRand(),getRand()},
		{getRand(),getRand(),getRand()},
		{getRand(),getRand(),getRand()}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			shape->data[i][j] = shapeArray[i][j];
		}
	}

	testPiece = new Piece(*shape);
	testPiece->init();
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

	if (InputManager::getInstance()->isDown(SDLK_d) || InputManager::getInstance()->isDown("d"))
	{
		//Asound->PlaySound();
		testPiece->moveRight();
	}
	if (InputManager::getInstance()->isDown(SDLK_a) || InputManager::getInstance()->isDown("a"))
	{
		//Asound->PlaySound();
		testPiece->moveLeft();
	}
}
