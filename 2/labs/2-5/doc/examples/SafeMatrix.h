
// ����������
struct BadDimensions {};
struct BadFirstIndex {};
struct BadSecondIndex {};

// ��������� ������ matrix
class matrix
{
	long	n, m;	// ����������� �������
	double*	p;		// ��������� �� �������
	matrix();
	class row
	{
		long	m;	// ����������� ������
		double* p;	// ��������� �� ������
	public:
		row(long _m, double* _p);
			// �������� ��������������
		double& operator [] (long j);				// throw BadFirstIndex
		const double& operator [] (long j) const;	// throw BadSecondIndex
	};
public:
		// ������������
	matrix(long _n, long _m);
	matrix(const matrix& m);
		// ����������
	~matrix();
		// �������� ������������
	matrix& operator = (const matrix& m);	// throw BadDimensions
		// �������� ��������������
	row operator [] (long i);				// throw BadFirstIndex
	const row operator [] (long i) const;	// throw BadFirstIndex
		// ������� ���������
	matrix& operator += (const matrix& m);	// throw BadDimensions
	matrix& operator -= (const matrix& m);	// throw BadDimensions
	matrix& operator *= (const matrix& m);	// throw BadDimensions
	matrix& operator *= (const double& d);
		// ������� ���������
	friend matrix operator -(const matrix& m);
	friend matrix operator +(const matrix& m);
		// �������� ���������
	friend matrix operator * (const double& d, const matrix& m);
	friend matrix operator * (const matrix& m, const double& d);
		// ��������� �������� ��������� 
		// ����� ��������� ���������� BadDimensions
	friend matrix operator + (const matrix& m1, const matrix& m2);	 
	friend matrix operator - (const matrix& m1, const matrix& m2);
	friend matrix operator * (const matrix& m1, const matrix& m2);
};