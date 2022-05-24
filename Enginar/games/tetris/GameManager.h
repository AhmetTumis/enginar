#pragma once
#include "../../common/GameObject.h"
#include "../../common/Matrix.h"
#include "Piece.h"

class GameManager : public GameObject
{
public:
	Piece* testPiece = nullptr;

	inline static GameManager* go;
	inline static GameManager* getGO()
	{
		return go;
	}

	GameManager()
	{
		go = this;

		//float spacingX = Game::getInstance()->getWindow()->getWindowSize().x / 10.0f;

		for (int i = 0; i < 10; i++)
		{
			//horizontalPositions.push_back(spacingX * i);
		}

		auto shape = new Matrix3x3();
		float shapeArray[3][3] =
		{
			{1,1,1},
			{1,1,1},
			{1,1,1}
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

	int getRand();

	void spawnPiece();

	void update();
private:
	int horizontalPositionIndex;
	vector<int> horizontalPositions;

	bool pressingLeft;
	bool pressingRight;
};

