// ������ �����
// ������� ��������, ������� 2 "������������� STL. ��������� �����������.  ������������� ������ Vector."
// 25.06.2015

#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <sstream>

using namespace std;

enum class Menu {
	enter_vector_first = 1, enter_vector_second = 2, insert_in_vector = 3,
	delete_from_vector = 4, replace_in_vector = 5, sort_vector = 6,
	find_in_vector = 7, compare_vectors = 8, copy_vector = 9,
	merge_vectors = 10, sum_vectors = 11, resize_vector = 12,
	get_vector_capacity = 13, get_vector_count = 14, 
	get_vector_capacity_remained = 15, swap = 16, 
	show_vector_first = 17, show_vector_second = 18, exit = 0
};

void showMenu();
void showPause();
void showPause(std::string const& s);

template <typename T>
std::ostream& operator << (std::ostream&, std::vector<T> const&);
template <typename T>
std::istream& operator >> (std::istream&, std::vector<T>&);

int main()
{
	try{
		setlocale(LC_ALL, ".1251");
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		int choice, tmp_int;
		bool exit = false;
		vector<int> v1, v2, tmp;
		vector<int>::iterator from, to, it;
		string tmp_string;
		do
		{
			showMenu();
			cin >> choice;
			std::getline(cin, tmp_string);
			switch (static_cast<Menu>(choice))
			{
			case ::Menu::exit:
				exit = true;
				break;
			case ::Menu::enter_vector_first:
				cout << "\n������� �������� ������� � ������� Enter:\n";
				cin >> v1;
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::enter_vector_second:
				cout << "\n������� �������� ������� � ������� Enter:\n";
				cin >> v2;
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			case ::Menu::insert_in_vector:
				tmp.clear();
				cout << "\n������� c ����� ������� �������� ������� � ������� Enter:\n";
				cin >> tmp_int;
				it = v1.begin();
				while (tmp_int-- && tmp_int >= 0 && it != v1.end()) ++it;
				cout << "\n������� �������� ��� ������� � ������� Enter:\n";
				cin >> tmp;
				while (tmp_int-- && tmp_int >= 0 && it != v1.end()) ++it;
				v1.insert(it, tmp.begin(), tmp.end());
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::delete_from_vector:
				cout << "\n������� c ����� ������� �������� �������� � ������� Enter:\n";
				cin >> tmp_int;
				from = v1.begin();
				while (tmp_int-- && tmp_int >= 0 && from != v1.end()) ++from;
				cout << "\n������� ���������� ��������� ��� �������� � ������� Enter:\n";
				cin >> tmp_int;
				to = from;
				while (tmp_int-- && tmp_int >= 0 && to != v1.end()) ++to;
				v1.erase(from, to);
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::replace_in_vector:
				tmp.clear();
				cout << "\n������� c ����� ������� �������� ������ � ������� Enter:\n";
				cin >> tmp_int;
				to = v1.begin();
				while (tmp_int-- && tmp_int >= 0 && to != v1.end()) ++to;
				cout << "\n������� �������� ��� ������ � ������� Enter:\n";
				cin >> tmp;
				from = tmp.begin();
				while (to != v1.end() && from != tmp.end()) {
					*to = *from;
					++to;
					++from;
				}
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::sort_vector:
				cout << "\n������� c ����� ������� �������� ���������� � ������� Enter:\n";
				cin >> tmp_int;
				from = v1.begin();
				while (tmp_int-- && tmp_int >= 0 && from != v1.end()) ++from;
				cout << "\n������� ���������� ��������� ��� ���������� � ������� Enter:\n";
				cin >> tmp_int;
				to = from;
				while (tmp_int-- && tmp_int >= 0 && to != v1.end()) ++to;
				sort(from, to, std::less<int>());
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::find_in_vector:
				cout << "\n������� ������� ��� ������ � ������� Enter:\n";
				cin >> tmp_int;
				it = std::find(v1.begin(), v1.end(), tmp_int);
				if (it == v1.end()) {
					showPause("������� �� ������");
				}
				else {
					cout << "\n������� ������ �� ������� " << it - v1.begin() << "\n";
					showPause();
				}
				break;
			case ::Menu::compare_vectors:
				if (std::equal(v1.begin(), v1.end(), v2.begin())) {
					showPause("������� ���������!");
				}
				else showPause("������� �� ���������");
				break;
			case ::Menu::copy_vector:
				v2.resize(v1.size());
				std::copy(v1.begin(), v1.end(), v2.begin());
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			case ::Menu::merge_vectors:
				tmp_int = v2.size();
				v2.resize(v2.size() + v1.size());
				it = v2.begin();
				while (tmp_int-- && tmp_int >= 0) ++it;
				std::copy(v1.begin(), v1.end(), it);
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			case ::Menu::sum_vectors:
				from = v1.begin();
				to = v2.begin();
				while (to != v2.end() && from != v1.end()) {
					*to += *from;
					++to;
					++from;
				}
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			case ::Menu::resize_vector:
				cout << "\n������� ����� ������ ������� � ������� Enter:\n";
				cin >> tmp_int;
				v1.resize(tmp_int);
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::get_vector_capacity:
				showPause("����������� ������� ������� - " + std::to_string(v1.capacity()));
				break;
			case ::Menu::get_vector_count:
				showPause("���������� ��������� ������� ������� - " + std::to_string(v1.size()));
				break;
			case ::Menu::get_vector_capacity_remained:
				showPause("���������� ���������, ������� ������� ������ ������ - " + std::to_string(v1.capacity() - v1.size()));
				break;
			case ::Menu::swap:
				swap(v1, v2);
				cout << "\n������ ������:\n" << v1;
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			case ::Menu::show_vector_first:
				cout << "\n������ ������:\n" << v1;
				showPause();
				break;
			case ::Menu::show_vector_second:
				cout << "\n������ ������:\n" << v2;
				showPause();
				break;
			}
			cin.clear();
			cin.ignore(1000, '\n');
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
		"\n��������� \"��������� �����������.  ������������� ������ Vector.\"\n"
		"�������� ���� �� ������� ����:\n"
		"[1] - ������ ������ ������\n"
		"[2] - ������ ������ ������\n"
		"[3] - �������� � ������ ������ \n"
		"[4] - ������� �� ������� �������\n"
		"[5] - �������� � ������ �������\n"
		"[6] - ����������� ������ ������\n"
		"[7] - ����� � ������ �������\n"
		"[8] - �������� �������\n"
		"[9] - ����������� ������ ������ �� ������\n"
		"[10] - ���������� ������� � ��������� �� ������ ������\n"
		"[11] - ������� ������� � ��������� �� ������ ������\n"
		"[12] - �������� ������� ������� �������\n"
		"[13] - �������� ������� ������� �������\n"
		"[14] - �������� ���������� ��������� � ������ �������\n"
		"[15] - �������� ���������� ������� � ������ �������\n"
		"[16] - �������� �������� ��������\n"
		"[17] - ������� �� ����� ������ ������\n"
		"[18] - ������� �� ����� ������ ������\n"
		"[0] - �����\n";
}

void showPause(){ showPause(""); }

void showPause(std::string const& s)
{
	cout << "\n\n";
	if (s.size() > 0) cout << s << "\n";
	cout << "������� Enter ��� �����������";
}

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T> const& v)
{
	out << "array(" << v.size() << ") >> ";
	int i = 0;
	for (auto it : v) {
		cout << "[" << i++ << "] = " << it << " ";
	}
	return out;
}
template <typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v)
{
	v.clear();
	T k;
	string line;
	std::getline(cin, line);
	std::istringstream stream(line);
	while (stream >> k)
		v.push_back(k);
	return in;
}

