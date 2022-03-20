#include "Collider.h"

#pragma once
class Collision
{
public:
	static bool isCollidingAABB(const BoxCollider& first, const BoxCollider& second);
	static bool isCollidingCircleAndCircle(const CircleCollider& first, const CircleCollider& second);
};

