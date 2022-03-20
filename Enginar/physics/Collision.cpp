#include "Collision.h"

bool Collision::isCollidingAABB(const BoxCollider& first, const BoxCollider& second)
{

	auto recA = first.colliderRect;
	auto recB = second.colliderRect;

	return
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y;
}

bool Collision::isCollidingCircleAndCircle(const CircleCollider& first, const CircleCollider& second)
{
	auto posA = first.pos;
	auto posB = second.pos;

	auto d = (posA - posB);

	float distance = d.getMagnitude();

	return distance < first.radius + second.radius;
}
