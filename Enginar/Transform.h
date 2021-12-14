#pragma once
#include "EnginarMath.h"
#include <SDL_video.h>

class Transform
{
public:
	void setPositionX();
	void setScale(int size);
	void setScale(vector2& newScale);
	void setScaleX(int x);
	void setScaleY(int y);
	int xx;
	SDL_Rect rect1;
};

