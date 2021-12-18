#include "Transform.h"

Transform::Transform()
{
	rect1.x = 0;
	rect1.y = 0;

	position = new vector2();
	scale = new vector2();
	forward = new vector2(cos((rotation < 0 ? 360 + rotation : rotation) * PI / 180), sin((rotation < 0 ? 360 + rotation : rotation) * PI / 180));
	float upRot = rotation - 90;
	up = new vector2(cos((upRot < 0 ? 360 + upRot : upRot) * PI / 180), sin((upRot < 0 ? 360 + upRot : upRot) * PI / 180));
}

void Transform::setPosition(vector2* newPosition)
{
	position = newPosition;
	rect1.x = (int)position->x;
	rect1.y = (int)position->y;
}

void Transform::setPositionX(float x)
{
	position->x = x;
	rect1.x = (int)position->x;
}

void Transform::setPositionY(float y)
{
	position->y = y;
	rect1.y = (int)position->y;
}

void Transform::setScale(float _scale)
{
	scale->x = _scale;
	scale->y = _scale;

	rect1.w = (int)_scale;
	rect1.h = (int)_scale;
}

void Transform::setScale(vector2* newScale)
{
	scale->x = newScale->x;
	scale->y = newScale->y;

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
