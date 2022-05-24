#pragma once

#include "../../common/Game.h"

class Tetris : public Game
{
public:
	Tetris();

	/*static Tetris* getInstance()
	{
		static Tetris instance;
		return &instance;
	}*/

	void initializeGame(Window* _window);
};