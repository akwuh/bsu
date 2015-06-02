// ������ �����
// 26.02.2015
// ����� �����

#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	try{
		Fraction f1(1);
		Fraction f2(1);
		cout << "������� ��������� � ����������� �����:\n";
		cin >> f1;
		cout << "������� ��������� � ����������� �����:\n";
		cin >> f2;
		cout << "����� ������:\t" << f1 + f2;
		cout << "\n�������� ������:\t" << f1 - f2;
		cout << "\n������������ ������:\t" << f1 * f2;
		cout << "\n������� ������:\t" << f1 / f2;
		cout << "\n������ ����� ������ ������:\t" << (f1 > f2);
		cout << "\n����� �����:\t" << (f1 == f2);
		cout << "\n��������������� ������ �����:\t" << (-f1);
		cout << "\n������� ������ ����� � ��� double:\t" << (double)f1;
		// f1 = f1 + 2 - f1 * (f1 + 3);
	} catch (Error& e) {
		cout << "\n������:\t" << e.what() << "\n";
	}
	cout << endl;
	system("pause");
	return 0;
}