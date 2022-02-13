#include "Collision.h"

bool Collision::isCollidingAABB(const Collider& first, const Collider& second)
{

	auto recA = first.colliderRect;
	auto recB = second.colliderRect;

	bool condition1 = recA.x + recA.w >= recB.x;
	bool condition2 = recB.x + recB.w >= recA.x;
	bool condition3 = recA.y + recA.h >= recB.y;
	bool condition4 = recB.y + recB.h >= recA.y;

	return
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y;
}