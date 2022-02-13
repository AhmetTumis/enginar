#include "Collision.h"

bool Collision::isCollidingAABB(const Collider& first, const Collider& second)
{

	auto recA = first.colliderRect;
	auto recB = second.colliderRect;

	return
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y;
}