// ��������� ������ matrix

struct Bad_dimensions {};

class matrix
{
	long	n, m;	// ����������� �������
	double*	p;		// ��������� �� �������
	matrix();		// �� ��������� ������� ��������� ������
public:
		// ������������
	matrix(long _n, long _m);
	matrix(const matrix& m);
		// ����������
	~matrix();
		// �������� ������������
	matrix& operator = (const matrix& m);	// throw Bad_dimensions
		// �������� ��������������
	double* operator [] (long i);
	const double* operator [] (long i) const;
		// ������� ���������
	matrix& operator += (const matrix& m);	// throw Bad_dimensions
	matrix& operator -= (const matrix& m);	// throw Bad_dimensions
	matrix& operator *= (const matrix& m);	// throw Bad_dimensions
	matrix& operator *= (const double& d);
		// ������� ���������
	friend matrix operator -(const matrix& m);
	friend matrix operator +(const matrix& m);
		// �������� ���������
	friend matrix operator * (const double& d, const matrix& m);
	friend matrix operator * (const matrix& m, const double& d);
		// ��������� �������� ��������� 
		// ����� ��������� ���������� Bad_dimensions
	friend matrix operator + (const matrix& m1, const matrix& m2);	 
	friend matrix operator - (const matrix& m1, const matrix& m2);
	friend matrix operator * (const matrix& m1, const matrix& m2);
};