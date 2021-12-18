/*#ifndef MATH_H
#define MATH_H

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

namespace enginar
{

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

}

#endif // MATHATH_H

*/