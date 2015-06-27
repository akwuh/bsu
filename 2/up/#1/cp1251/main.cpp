// ������ �����
// ������� ��������, ������� 1 "������������� STL. ��������� ����� String."
// 24.06.2015

#include <iostream>
#include "clipboard.h"
#define CHARBUF 4096

using namespace std;

enum class Menu {
	enter_string = 1, find_string = 2, copy_string = 3,
	insert_string = 4, compare_string = 5, replace_string = 6,
	insert_string_pos = 7, show_string = 8, exit = 0
};

void showMenu();
void showPause();
void showPause(std::string const& s);
std::ostream& operator << (std::ostream&, std::string const&);

int main()
{
	try{
		setlocale(LC_ALL, ".1251");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		int choice, k;
		size_t index;
		bool exit = false;
		char* tmp = new char[CHARBUF];
		string s, s_tmp;
		do
		{
			showMenu();
			cin >> choice;
			switch (static_cast<Menu>(choice))
			{
				case ::Menu::exit:
					exit = true;
					break;
				case ::Menu::enter_string:
					cout << "\n������� ������ � ������� Enter:\n";
					cin >> tmp;
					s = string(tmp);
					break;
				case ::Menu::show_string:
					cout << "\n������� ������:\n" << s;
					showPause();
					break;
				case ::Menu::copy_string:
					ClipBoard << s;
					showPause("������ ��������� � ����� Windows!");
					break;
				case ::Menu::insert_string:
					ClipBoard >> s;
					showPause("������ �� ������ ������ ������ �������� ������� �������!");
					break;
				case ::Menu::compare_string:
					ClipBoard >> s_tmp;
					if (s == s_tmp) showPause("������� ������ == ������ �� ������ ������");
					else showPause("������� ������ != ������ �� ������ ������");
					break;
				case ::Menu::insert_string_pos:
					cout << "\n������� ������ ��� ������� � ������� Enter:\n";
					cin >> tmp;
					cout << "\n������� ������� ��� ������� � ������� Enter:\n";
					cin >> k;
					if (k >= 0 && k <= s.size()) s.insert(k, string(tmp));
					cout << "\n������� ������:\n" << s;
					showPause();
					break;
				case ::Menu::find_string:
					cout << "\n������� ������ �� ������ � ������� Enter:\n";
					cin >> tmp;
					cout << "\n� ����� ������� ������? [1 - �����, 0 - ������]:\n";
					cin >> k;
					if (k == 1) {
						index = s.find(tmp);
					}
					else if (k == 0) {
						index = s.rfind(tmp);
					}
					else {
						showPause("�������� ���� - ������� 0 ��� 1");
					}
					if (index == string::npos) {
						showPause("������ �� �������");
					}
					else {
						cout << "\n������ ������� �� ������� " << index << "\n";
						showPause();
					}
					break;
				case ::Menu::replace_string:
					cout << "\n������� ��������� ��� ������ � ������� Enter:\n";
					cin >> tmp;
					s_tmp = string(tmp);
					cout << "\n������� ����� ��������� � ������� Enter:\n";
					cin >> tmp;
					index = s.find(s_tmp);
					if (index != string::npos) {
						s.replace(s.begin() + index, s.begin() + index + s_tmp.size(), tmp);
						showPause("������ ������� ��������!");
					}
					else showPause("��������� ��� ������ �� �������");
					break;
			}
			cin.clear();
			cin.ignore(CHARBUF, '\n');
		} while (!exit);
	}
	catch (...) {
		cerr << "\n\nUnknown error!!!";
		system("pause");
	}
	return 0;
}

void showMenu()
{
	cout <<
		"\n��������� \"������������� STL. ��������� ����� String.\"\n"
		"�������� ���� �� ������� ����:\n"
		"[1] - ������ ����� ������\n"
		"[2] - ����� ���������\n"
		"[3] - ��������� ������ � ����� ������\n"
		"[4] - �������� ������ �� ������ ������\n"
		"[5] - �������� ��������� ������ �� ������� �� ������ ������\n"
		"[6] - �������� ���� �������� ������ �� ������\n"
		"[7] - �������� � ������ ������ ������ � �������� �������\n"
		"[8] - ������� ������ �� �����\n"
		"[0] - �����\n";
}

void showPause(){ showPause(""); }

void showPause(std::string const& s)
{
	cout << "\n\n";
	if (s.size() > 0) cout << s << "\n";
	cout << "������� Enter ��� �����������";
	cin.ignore();
}

std::ostream& operator << (std::ostream& out, std::string const& s)
{
	out << s.c_str();
	return out;
}