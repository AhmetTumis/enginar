#pragma once

#include <stdio.h>
#include "math.h"
#include <climits>
#include <cstdlib>


#define MATH_E        2.71828182845904523536
#define MATH_LOG2E    1.44269504088896340736
#define MATH_LOG10E   0.434294481903251827651
#define MATH_LN2      0.693147180559945309417
#define MATH_LN10     2.30258509299404568402
#define MATH_PI       3.14159265358979323846
#define MATH_PI_2     1.57079632679489661923
#define MATH_PI_4     0.785398163397448309616
#define MATH_1_PI     0.318309886183790671538
#define MATH_2_PI     0.636619772367581343076
#define MATH_2_SQRTPI 1.12837916709551257390
#define MATH_SQRT2    1.41421356237309504880
#define MATH_SQRT1_2  0.707106781186547524401
#define MATH_TORAD	(float)(MATH_PI/180.0)
#define MATH_TODEG    (float)(180.0/MATH_PI)
#define MATH_TORAD(x)	(float)(x*MATH_TORAD)
#define MATH_TODEG(x)	(float)(x*MATH_TODEG)

#define VEC2_ZERO vector2(0, 0)
#define VEC2_ONE vector2(1, 1)
#define VEC2_UP vector2(0, 1)
#define VEC2_RIGHT vector2(1, 0)
#define VEC2_DOWN vector2(0, -1)
#define VEC2_LEFT vector2(-1, 0)

typedef struct Matrix
{
	int m, n;
	int** data;
	Matrix(int _m, int _n)
	{
		m = _m;
		n = _n;
		data = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++)
		{
			data[i] = (int*)malloc(sizeof(int) * n);
			for (int j = 0; j < n; j++)
			{
				data[i][j] = 0;
			}
		}
	}

	void printMatrix()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d,", data[i][j]);
			}
			printf("\n");
		}
	}

	Matrix operator + (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] += b;
			}
		}
		return *this;
	}
	Matrix operator - (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] -= b;
			}
		}
		return *this;
	}
	Matrix operator * (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] *= b;
			}
		}
		return *this;
	}
	Matrix operator / (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] /= b;
			}
		}
		return *this;
	}
	Matrix operator + (Matrix b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] += b.data[i][j];
			}
		}
		return *this;
	}
	Matrix operator - (Matrix b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] -= b.data[i][j];
			}
		}
		return *this;
	}
	//1.sütun=2.satýr. Sonuc=1.satýr,2.sütun
	Matrix operator * (Matrix b)
	{
		Matrix ret = Matrix(this->m, b.n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (k == 0)
						ret.data[i][j] = 0;
					ret.data[i][j] += data[i][k] * b.data[k][j];
				}
			}
		}
		return ret;
	}
	Matrix Inverse ()
	{
		Matrix ret = Matrix(this->n,this->m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret.data[j][i] = data[i][j];
			}
		}
		return ret;
	}
	void operator = (Matrix b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] = b.data[i][j];
			}
		}
	}
	bool operator == (Matrix b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (data[i][j] != b.data[i][j])
				{
					return false;
				}
			}
			return true;
		}
	}
};

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

	bool operator == (const Rect &rhs) const
	{
		return x == rhs.x && y == rhs.y && w == rhs.w && h == rhs.h;
	}
};

inline int nextP2(int x)
{
	x += (x == 0);
	x--;
	for (unsigned int i = 1; i < sizeof(int)*CHAR_BIT; i <<= 1) x |= x >> i;
	return ++x;
}

inline float nextP2(float x)
{
	return (float) nextP2((int) x);
}

inline float fastInverseSqrt(float x) 
{
	float x2 = x * 0.5F;
	float y = x;
	long i = *(long *) &y;
	i = 0x5f3759df - ( i >> 1 );
	y = *(float *) &i;

	y *= 1.5F - x2*y*y; 	// first iter
	// y *= 1.5F - x2*y*y; 	// second iter...
	return y;
}