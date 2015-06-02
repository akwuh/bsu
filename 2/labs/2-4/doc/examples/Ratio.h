// ��������� ������ Fractionnal
#include <iostream.h>

struct Zero_divide {};

class Fraction
{
	long n, d;		// ��������� � �����������
	void Reduce();	// ��������� �����
public:
		// ������������
	Fraction();
	Fraction(long n, long d);
	Fraction(const Fraction& r);
		// �������� ������������
	Fraction& operator = (const Fraction& r);
		// ������� ���������
	Fraction& operator += (const Fraction& r);
	Fraction& operator -= (const Fraction& r);
	Fraction& operator *= (const Fraction& r);
	Fraction& operator /= (const Fraction& r);
		// �������� �������������� ����
	operator double(void) const; 
		// ������� ����� � ����
	friend Fraction operator -(const Fraction& r);
	friend Fraction operator +(const Fraction& r);
		// ��������� ���������
	friend bool operator < (const Fraction& r1, const Fraction& r2);
	friend bool operator > (const Fraction& r1, const Fraction& r2);
	friend bool operator == (const Fraction& r1, const Fraction& r2);
	friend bool operator != (const Fraction& r1, const Fraction& r2);
	friend bool operator <= (const Fraction& r1, const Fraction& r2);
	friend bool operator >= (const Fraction& r1, const Fraction& r2);
		// �������� ���������
	friend Fraction operator + (const Fraction& r1, const Fraction& r2);
	friend Fraction operator - (const Fraction& r1, const Fraction& r2);
	friend Fraction operator * (const Fraction& r1, const Fraction& r2);
	friend Fraction operator / (const Fraction& r1, const Fraction& r2);
		// ��������� �����-������
	friend istream& operator>>(istream& in, Fraction& r);
	friend ostream& operator<<(ostream& out, const Fraction& r);

};
	
		


