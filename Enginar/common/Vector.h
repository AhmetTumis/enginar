#pragma once

#include "Matrix.h"
class vector2 :public Matrix
{
public:
	float x=0;
	float y=0;
	float magnitude=0;

	vector2();
	vector2(float _x, float _y);
	vector2 operator + (vector2 b) {

		auto orospu = b.data[0][0];
		auto evladi = b.data[1][0];

		auto t = (this->Matrix::operator+(b));
		this->x = t.data[0][0];
		this->y = t.data[1][0];
		return *this;
	}
	vector2 operator - (vector2 b) {
		auto t = (this->Matrix::operator-(b));
		auto p3 = static_cast<vector2*>(&t);
		return *p3;
	}
	/*bool operator==(vector2 b);
	void operator=(vector2 b);
	vector2* operator+(float b);
	vector2* operator+(vector2 b);
	vector2* operator-(float b);
	vector2* operator-(vector2 b);
	vector2* operator*(float b);
	vector2* operator/(float b);*/
	float dotProduct(vector2 b);
	float crossProduct(vector2 b);
	float getAngle(vector2 b);
	float getMagnitude();
	void Normalize();
	vector2 getNormalized();
	float getDistance(vector2 b);
};