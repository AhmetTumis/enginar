#pragma once

class Matrix
{
public:
	int m;
	int n;

	float** data;

	Matrix(int _m, int _n);
	virtual ~Matrix() {};

	void printMatrix();

	virtual Matrix operator + (int b);
	Matrix operator - (int b);
	Matrix operator * (int b);
	Matrix operator / (int b);
	Matrix operator + (Matrix b);
	virtual Matrix operator - (Matrix b);
	Matrix operator * (Matrix b);
	void operator = (Matrix b);
	bool operator == (Matrix b);
	Matrix Inverse();
};