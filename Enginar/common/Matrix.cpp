#include<Matrix.h>

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
				if (i % 2 == 0)
					data[i][j] = 3;
				else
					data[i][j] = 4;
			}
		}
	}

	void printMatrix()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d,", [i][j]);
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
	//1.s�tun=2.sat�r. Sonuc=1.sat�r,2.s�tun
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
	Matrix Inverse()
	{
		Matrix ret = Matrix(this->n, this->m);
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