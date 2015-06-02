// ��������� ������ Polynom

struct Polynom_exceptions {};
struct Zero_divide: Polynom_exceptions {};
struct Negative_degree: Polynom_exceptions {};
struct Wrong_index: Polynom_exceptions {};

class Polynom
{
	int		n;		// ������� ��������
	double*	coeff;	// ������������ ��������
		// ����������� �� ���������
	Polynom();
public:
		// ������������
	Polynom(int _n, ...);		// throw(Negative_degree)
	Polynom(const Polynom& p);
		// ����������
	~Polynom();
		// ���������� �������� ��������
	double Value(double x);
		// �������� ������������
	Polynom& operator = (const Polynom& p);
		// ��������� ��������������
	double& operator [](int i) const;		// throw(Wrong_index)
		// ������� ���������
	Polynom& operator += (const Polynom& p);
	Polynom& operator -= (const Polynom& p);
	Polynom& operator *= (const Polynom& p);
	Polynom& operator /= (const Polynom& p);	// throw(Zero_divide)
		// ������� ����� � ����
	Polynom& operator -(void);
	Polynom& operator +(void);
		// �������� ���������
	friend Polynom operator + (const Polynom& p1, const Polynom& p2);
	friend Polynom operator - (const Polynom& p1, const Polynom& p2);
	friend Polynom operator * (const Polynom& p1, const Polynom& p2);
	friend Polynom operator / (const Polynom& p1, const Polynom& p2);// throw(Zero_divide)
};
	
		


