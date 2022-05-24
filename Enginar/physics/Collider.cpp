#include "Collider.h"

void BoxCollider::updateShape(Texture* texture)
{
	colliderRect.x = texture->physicsRect.x;
	colliderRect.y = texture->physicsRect.y;
	colliderRect.w = texture->physicsRect.w * widthMultipler;
	colliderRect.h = texture->physicsRect.h * heightMultipler;
}

void CircleCollider::updateShape(Texture* texture)
{
	pos.x = texture->physicsRect.x;
	pos.y = texture->physicsRect.y;
}
