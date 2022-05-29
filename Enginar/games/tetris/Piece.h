#pragma once

#include "../../common/EnginarMath.h"
#include "../../common/Matrix.h"
#include "Block.h"
#include <vector>
#include "Tetris.h"

using namespace std;

class Piece : public GameObject
{
public:
	Piece();

	void createShape(Matrix3x3& _shape);

	void update();

	void moveLeft();
	void moveRight();
	int frame = 0;

	Block* leftMostBlock;
	Block* rightMostBlock;
	Block* upMostBlock;
	Block* downMostBlock;

	void Place();
	bool placed = false;
private:
	int passedFrameCounter = 0;

	Matrix3x3* shape = nullptr;

	vector<Block*> blocks;
};