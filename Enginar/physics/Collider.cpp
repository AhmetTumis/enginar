#include "Collider.h"

void BoxCollider::updateShape(Texture* texture)
{
	colliderRect = texture->textureRect;

}

void CircleCollider::updateShape(Texture* texture)
{
	pos.x = texture->textureRect.x;
	pos.y = texture->textureRect.y;
}
