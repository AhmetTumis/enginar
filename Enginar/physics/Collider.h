#include <SDL.h>
#include "../graphics/Texture.h"
#include "../common/EnginarMath.h"
#include "../common/Vector.h"

#pragma once
class Collider
{
public:
	enum class ColliderType { BOX, CIRCLE, EDGE };
	char* tag;

	Collider(const char* _tag) {
		tag = const_cast<char*>(_tag);
	}

	virtual ColliderType GetType() = 0;

	virtual void updateShape(Texture* texture) = 0;
};

class BoxCollider : public Collider 
{
public:
	SDL_Rect colliderRect;

	BoxCollider(const char* _tag, int x, int y, int width, int height) : Collider(_tag = _tag)
	{
		colliderRect.x = x;
		colliderRect.y = y;
		colliderRect.w = width;
		colliderRect.h = height;
	}

	BoxCollider(const char* _tag, SDL_Rect& rect) : Collider(_tag = _tag)
	{
		colliderRect = rect;
	}

	virtual ColliderType GetType() { return ColliderType::BOX; }

	virtual void updateShape(Texture* texture);
};

class CircleCollider : public Collider
{
public:
	int radius;
	vector2 pos;

	CircleCollider(const char* _tag, int _radius = 1) : Collider(_tag = _tag)
	{
		radius = _radius;
	}

	virtual ColliderType GetType() { return ColliderType::BOX; }

	virtual void updateShape(Texture* texture);
};