#include "Transform.h"

Transform::Transform()
{
	rect1.x = 0;
	rect1.y = 0;

	position = new VEC2_ZERO;
	scale = new VEC2_ZERO;
	forward = new VEC2_RIGHT;
	up = new VEC2_DOWN;
}

void Transform::setPosition(vector2* newPosition)
{
	auto delta = (*position - *newPosition);
	for (int i = 0; i < ownerGameObject->children.size(); i++)
	{
		if (delta.m < 0)
		{
			continue;
		}
		ownerGameObject->children[i]->getTransform()->setPosition(&(*(ownerGameObject->children[i]->getTransform()->getPosition()) + delta));
	}

	position = newPosition;
	rect1.x = (int)position->x;
	rect1.y = (int)position->y;

	posX = position->x;
	posY = position->y;
}

void Transform::setPositionX(float x)
{
	auto oldPosition = new vector2();
	oldPosition->copyFrom(*position);

	position->x = x;
	rect1.x = (int)position->x;

	auto delta = (*position - *oldPosition);

	for (int i = 0; i < ownerGameObject->children.size(); i++)
	{
		ownerGameObject->children[i]->getTransform()->setPosition(&(*(ownerGameObject->children[i]->getTransform()->getPosition()) + delta));
	}

	posX = x;
}

void Transform::setPositionY(float y)
{
	auto oldPosition = new vector2();
	oldPosition->copyFrom(*position);

	position->y = y;
	rect1.y = (int)position->y;

	auto delta = (*position - *oldPosition);

	for (int i = 0; i < ownerGameObject->children.size(); i++)
	{
		ownerGameObject->children[i]->getTransform()->setPosition(&(*(ownerGameObject->children[i]->getTransform()->getPosition()) + delta));
	}

	posY = y;
}

void Transform::setScale(float _scale)
{
	scale->x = _scale;
	scale->y = _scale;

	scale->data[0][0] = _scale;
	scale->data[0][1] = _scale;

	rect1.w = (int)_scale;
	rect1.h = (int)_scale;
}

void Transform::setScale(vector2* newScale)
{
	scale->x = newScale->x;
	scale->y = newScale->y;

	scale->data[0][0] = newScale->x;
	scale->data[0][1] = newScale->y;

	rect1.w = (int)newScale->x;
	rect1.h = (int)newScale->y;
}

void Transform::setScaleX(float x)
{
	scale->x = x;
	rect1.w = (int)x;
}

void Transform::setScaleY(float y)
{
	scale->y = y;
	rect1.h = (int)y;
}

void Transform::setRotation(int r)
{
	rotation = r;
	forward->x = cos((rotation < 0 ? 360 + rotation : rotation) * PI / 180);
	forward->y = sin((rotation < 0 ? 360 + rotation : rotation) * PI / 180);
	float upRot = rotation - 90;

	up->x = cos((upRot < 0 ? 360 + upRot : upRot) * PI / 180);
	up->y = sin((upRot < 0 ? 360 + upRot : upRot) * PI / 180);

}
