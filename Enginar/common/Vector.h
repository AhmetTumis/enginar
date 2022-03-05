#include<Matrix.h>
class Vector :public Matrix
{
public:
	vector2();
	vector2(float _x, float _y);
	bool operator==(vector2 b);
	void operator=(vector2 b);
	vector2* operator+(float b);
	vector2* operator+(vector2 b);
	vector2* operator-(float b);
	vector2* operator-(vector2 b);
	vector2* operator*(float b);
	vector2* operator/(float b);
};