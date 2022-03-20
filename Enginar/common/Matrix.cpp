#include "Matrix.h"
#include <stdlib.h>
#include <stdio.h>


	int m, n;
	float** data;
	Matrix::Matrix(int _m, int _n)
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

	void Matrix::printMatrix()
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

	Matrix Matrix::operator + (int b)
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
	Matrix Matrix::operator - (int b)
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
	Matrix Matrix::operator * (int b)
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
	Matrix Matrix::operator / (int b)
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
	Matrix Matrix::operator + (Matrix b)
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
	Matrix Matrix::operator - (Matrix b)
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
	Matrix Matrix::operator * (Matrix b)
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
	Matrix Matrix::Inverse()
	{
		Matrix ret = Matrix(n, m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret.data[j][i] = data[i][j];
			}
		}
		return ret;
	}
	void Matrix::operator = (Matrix b)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				data[i][j] = b.data[i][j];
			}
		}
	}
	bool Matrix::operator == (Matrix b)
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