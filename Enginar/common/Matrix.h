#pragma once

#include <stdlib.h>
#include <stdio.h>

template <class T>
class Matrix
{
public:
	int m;
	int n;

	float** data;

	Matrix<T>(int _m, int _n)
	{
		m = _m;
		n = _n;
		data = (float**)malloc(sizeof(float*) * m);
		for (int i = 0; i < m; i++)
		{
			data[i] = (float*)malloc(sizeof(float) * n);
			for (int j = 0; j < n; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	virtual ~Matrix<T>() {};

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

	T& operator + (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] += b;
			}
		}
		return static_cast<T&>(*this);
	}
	T& operator - (int b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] -= b;
			}
		}
		return static_cast<T&>(*this);
	}
	T& operator * (int b) 
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] *= b;
			}
		}
		return static_cast<T&>(*this);
	}
	T& operator / (int b) {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] /= b;
			}
		}
		return static_cast<T&>(*this);
	}
	T& operator + (Matrix b) 
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] += b.data[i][j];
			}
		}

		return static_cast<T&>(*this);
	}
	T& operator - (Matrix b) 
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] -= b.data[i][j];
			}
		}
		return static_cast<T&>(*this);
	}
	T& operator * (Matrix b)
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
		return static_cast<T&>(*this);
	}
	T& Inverse()
	{
		Matrix ret = Matrix(n, m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret.data[j][i] = data[i][j];
			}
		}
		return static_cast<T&>(*this);
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