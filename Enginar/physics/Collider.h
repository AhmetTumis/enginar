#include <SDL.h>

#pragma once
class Collider
{
public:

	SDL_Rect colliderRect;
	char* tag;

	Collider(const char* _tag, SDL_Rect _rect) {
		tag = const_cast<char*>(_tag);

		colliderRect = _rect;
	}

	Collider(char* _tag, int x, int y, int width, int height) {
		tag = _tag;

		colliderRect.x = x;
		colliderRect.y = y;
		colliderRect.w = width;
		colliderRect.h = height;
	}
};

