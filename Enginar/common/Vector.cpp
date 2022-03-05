#include<Vector.h>

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

	float dotProduct(vector2 b)
	{
		return this->x * b.x + this->y * b.y;
	}

	float crossProduct(vector2 b)
	{
		return this->getMagnitude() * b.getMagnitude() * sin(getAngle(b));
	}

	float getAngle(vector2 b)
	{
		return acosf(this->dotProduct(b) / (this->getMagnitude() * b.getMagnitude()));;
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

	float getDistance(vector2 b)
	{
		return (b - *this)->getMagnitude();
	}

};

struct Rect
{
	int x, y;
	int w, h;

	bool operator == (const Rect& rhs) const
	{
		return x == rhs.x && y == rhs.y && w == rhs.w && h == rhs.h;
	}
};

inline int nextP2(int x)
{
	x += (x == 0);
	x--;
	for (unsigned int i = 1; i < sizeof(int) * CHAR_BIT; i <<= 1) x |= x >> i;
	return ++x;
}

inline float nextP2(float x)
{
	return (float)nextP2((int)x);
}

inline float fastInverseSqrt(float x)
{
	float x2 = x * 0.5F;
	float y = x;
	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;

	y *= 1.5F - x2 * y * y; 	// first iter
	// y *= 1.5F - x2*y*y; 	// second iter...
	return y;
}