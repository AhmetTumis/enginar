#include "Transform.h"

void Transform::setPositionX()
{
	xx += 50;
	rect1.x = xx;
}

void Transform::setScale(int scale)
{
	rect1.w = scale;
	rect1.h = scale;
}

void Transform::setScale(vector2& newScale)
{
	rect1.w = newScale.x;
	rect1.h = newScale.y;
}

void Transform::setScaleX(int x)
{
	rect1.w = x;
}

void Transform::setScaleY(int y)
{
	rect1.h = y;
}