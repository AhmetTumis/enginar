class Matrix
{
public:
	Matrix operator + (int b);
	Matrix operator - (int b);
	Matrix operator * (int b);
	Matrix operator / (int b);
	Matrix operator + (Matrix b);
	Matrix operator - (Matrix b);
	Matrix operator * (Matrix b);
	void operator = (Matrix b);
	bool operator == (Matrix b);
	Matrix Inverse();
};