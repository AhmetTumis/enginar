#pragma once

#include "math.h"

struct vector2 
{
	float x, y, magnitude = 0;
	vector2() 
	{
		this->x = 0;
		this->y = 0;
		this->magnitude = 0;
	}
	vector2(float _x, float _y) 
	{
		this->x = _x;
		this->y = _y;
	}

	bool operator==(vector2 b)
	{
		return (this->x == b.x && this->y == b.y);
	}

	void operator=(vector2 b)
	{
		this->x = b.x;
		this->y = b.y;
	}

	vector2* operator+(float b)
	{
		this->x += b;
		this->y += b;
		return this;
	}

	vector2* operator+(vector2 b) 
	{
		this->x += b.x;
		this->y += b.y;
		return this;
	}

	vector2* operator-(float b)
	{
		this->x -= b;
		this->y -= b;
		return this;
	}

	vector2* operator-(vector2 b)
	{
		this->x -= b.x;
		this->y -= b.y;
		return this;
	}

	vector2* operator*(float b)
	{
		this->x *= b;
		this->y *= b;
		return this;
	}

	vector2* operator/(float b)
	{
		this->x /= b;
		this->y /= b;
		return this;
	}

	float getMagnitude()
	{
		float sumOfSquares = x * x + y * y;
		magnitude = sqrt(sumOfSquares);
		return magnitude;
	}

	void Normalize()
	{
		auto c = *this / getMagnitude();
		this->x = c->x;
		this->y = c->y;
	}

	vector2* getNormalized() 
	{
		return *this / getMagnitude();
	}

};