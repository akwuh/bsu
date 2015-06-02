// ������ �����
// 25.02.2015
// ��������� ���� �� ��������

#include <iostream>
#include "stack_static.h"

typedef StackStatic<int> Stack;

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	try{
		Stack s(100);
		s.push(1);
		cout << s.top() << endl;
		s.pop();
		s.push(2);
		s.push(3);
		cout << s.peek() << endl;
		s.pop();
		cout << s.peek() << endl;
		s.pop();
		cout << s.peek() << endl;
		s.pop();
	} catch (Empty) {
		cout << "\n������: ���� ����";
	} catch (Full) {
		cout << "\n������: ���� �����";
	}
	cout << endl;
	system("pause");
	return 0;
}