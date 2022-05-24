#include "Piece.h"
#include "../../graphics/Window.h"
#include "../../entrypoint.h"
#include "GameManager.h"
#include "../../physics/Collision.h"

Piece::Piece(Matrix3x3& _shape)
{
	shape = &_shape;
	int minY = 2, maxY = 0, minX = 2, maxX = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_shape.data[i][j] == 1)
			{
				auto* block = new Block(i, j);
				blocks.push_back(block);
				block->parent = this;
				children.push_back(block);

				if (upMostBlock == nullptr)
				{
					upMostBlock = block;
				}

				if (downMostBlock == nullptr)
				{
					downMostBlock = block;
				}

				if (leftMostBlock == nullptr)
				{
					leftMostBlock = block;
				}

				if (rightMostBlock == nullptr)
				{
					rightMostBlock = block;
				}

				if ((2 - i) <= maxX)
				{
					maxX = 2 - i;
					rightMostBlock = block;
				}

				if ((2 - i) >= minX)
				{
					minX = 2 - i;
					leftMostBlock = block;
				}

				if ((2 - j) >= maxY)
				{
					maxY = 2 - j;
					upMostBlock = block;
				}

				if ((2 - j) <= minY)
				{
					minY = 2 - j;
					downMostBlock = block;
				}
			}
		}
	}
}

void Piece::update()
{
	GameObject::update();
	passedFrameCounter++;

	if (!placed)
	{
		willUpdateTexture = false;

		if (passedFrameCounter % 50 == 0)
		{
			willUpdateTexture = true;
		}

		getTransform()->setPositionY(getTransform()->getPositionY() + 1);

		float winY = getTetris()->getWindow()->getWindowSize().y;
		if (downMostBlock->getTransform()->getPositionY() + 50 >= winY)
		{
			Place();
		}
		
	}
}
void Piece::moveLeft()
{
	if (leftMostBlock->getTransform()->getPositionX() < 10)
	{
		return;
	}
	getTransform()->setPositionX(getTransform()->getPositionX() - 50);
	willUpdateTexture = true;
}

void Piece::moveRight()
{
	float winX = getTetris()->getWindow()->getWindowSize().x;

	if (rightMostBlock->getTransform()->getPositionX() > winX - 60)
	{
		return;
	}
	getTransform()->setPositionX(getTransform()->getPositionX() + 50);
	willUpdateTexture = true;
}

void Piece::Place()
{
	placed = true;
	GameManager::getGO()->spawnPiece();
}
