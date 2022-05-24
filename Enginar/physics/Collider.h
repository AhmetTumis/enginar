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

	float widthMultipler;
	float heightMultipler;

	/// <summary>
	/// Creates the collider
	/// </summary>
	/// <param name="_tag"></param>
	/// <param name="x">Origin X</param>
	/// <param name="y">Origin Y</param>
	/// <param name="width">How many times bigger/smaller from the original Width? (Default=1. Equals to original width)</param>
	/// <param name="height">How many times bigger/smaller from the original Height? (Default=1. Equals to original height)</param>
	BoxCollider(const char* _tag, int x, int y, float _widthMultipler, float _heightMultipler, Texture* texture) : Collider(_tag = _tag), widthMultipler(_widthMultipler), heightMultipler(_heightMultipler)
	{
		colliderRect.x = x;
		colliderRect.y = y;
		colliderRect.w = texture->physicsRect.w * _widthMultipler;
		colliderRect.h = texture->physicsRect.h * _heightMultipler;
	}

	BoxCollider(const char* _tag, SDL_Rect& rect) : Collider(_tag = _tag)
	{
		widthMultipler = 1;
		heightMultipler = 1;
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

	virtual ColliderType GetType() { return ColliderType::CIRCLE; }

	virtual void updateShape(Texture* texture);
};