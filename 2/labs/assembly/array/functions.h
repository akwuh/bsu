#ifndef _FUNCTIONS_
#define _FUNCTIONS_

// ������������� �������, �������� ��������� ��������
extern "C" void __cdecl transpose(int**, int, int);

// ���������� ����� ���������� ������������������ ���������� ���������
extern "C" int __cdecl find_max_sequence(int*, int);

// ��������� �� ������� ������������� �������� � ���������� � ����� ������
extern "C" void __cdecl unique_array(int*, int, int*, int&);

// ������� ����������� ���� ��������, �������� ���������
extern "C" void __cdecl  array_conjuction(int*, int, int*, int, int*, int&);

// ������� ���������� ���������� ���������
extern "C" int __cdecl count_unique(int*, int);

// ��������� ��� ������� � ������� �� � ����
extern "C" void __cdecl merge(int*, int, int*, int, int*, int&);

// ��������� ������
extern "C" void __cdecl sort_array(int*, int);

#endif