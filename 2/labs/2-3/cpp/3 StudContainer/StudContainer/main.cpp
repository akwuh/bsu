// ������ �����
// 25.02.2015
// ������������ ��������� ���������

#include <iostream>
#include <fstream>
#include <string>
#include "container.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	int group;
	double gpa;
	Container c;
	if (in.fail()) exit(1);
	while (!in.eof()) {
		char* s = new char[100];
		in >> s >> group >> gpa;
		c.push(Student(s, group, gpa));
	}
	int choice = 1;
	while (choice && cin.good()) {
		cout << "\n[0] - �����";
		cout << "\n[1] - ������� �� ����� ������ ���� ���������";
		cout << "\n[2] - ����������� ��������� �� ��������";
		cout << "\n[3] - ����������� ��������� �� ������� � ��������";
		cout << "\n[4] - ����� �������� �� �������";
		cout << "\n[5] - ������� �� ����� ����� � �������";
		cout << "\n";
		cin >> choice;
		system("cls");
		Student *tmp;
		char* str;
		switch(choice) {
			case 0:
				break;
			case 1:
				c.print(cout);
				break;
			case 2:
				c.sortByName();
				break;
			case 3: 
				c.sortByGroupAndName();
				break;
			case 4:
				str = new char[100];
				cout << "������� ������� ��� ������:\n";
				cin >> str;
				tmp = c.findByName(str);
				cout.flags(std::ios::left);
				cout << std::setw(2) << '#' << std::setw(20) << "�������" << std::setw(10) << "������" << std::setw(20) << "������� ����" << "\n";
				if (tmp) 
					cout << std::setw(2) << 1 << std::setw(20) << tmp->name << std::setw(10) <<tmp->group << std::setw(20) <<tmp->gpa << std::endl;
				else cout << "������ �� �������\n";
				break;
			case 5:
				c.report(cout);
				break;
		}
	}
	return 0;
}