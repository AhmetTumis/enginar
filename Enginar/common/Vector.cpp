#include "Vector.h"
#include <math.h>

	float x, y, magnitude = 0;
	vector2::vector2() :Matrix(2, 1)
	{
		this->x = 0;
		this->y = 0;
		this->magnitude = 0;
	}
	vector2::vector2(float _x, float _y) :Matrix(2, 1)
	{
		this->x = _x;
		this->y = _y;
		this->Matrix::data[0][0] = _x;
		this->Matrix::data[1][0] = _y;
	}

	/*bool operator==(vector2 b)
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
	}*/

	float vector2::dotProduct(vector2 b)
	{
		return x * b.x + y * b.y;
	}

	float vector2::crossProduct(vector2 b)
	{
		return getMagnitude() * b.getMagnitude() * sin(getAngle(b));
	}

	float vector2::getAngle(vector2 b)
	{
		return acosf(dotProduct(b) / (getMagnitude() * b.getMagnitude()));;
	}

	float vector2::getMagnitude()
	{
		float sumOfSquares = x * x + y * y;
		magnitude = sqrt(sumOfSquares);
		return magnitude;
	}

	void vector2::Normalize()
	{
		auto c = (*this) / getMagnitude();
		this->x = c.data[0][0];
		this->y = c.data[0][1];
	}

	vector2 vector2::getNormalized()
	{
		auto div = *this / getMagnitude();
		return vector2(div.data[0][0], div.data[0][1]);
	}

	float vector2::getDistance(vector2 b)
	{
		auto aa = (b - *this);
		auto k = dynamic_cast<vector2*>(&aa);
		vector2 vec = vector2(k->x, k->y);
		return vec.getMagnitude();
	}