// ������ �����
// 25.02.2015
// ������ ������� �� �������� (������ �����������)

#include <iostream>
#include "chainedQueue.h"

typedef ChainedQueue Queue;

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	try{
		Queue q(2);
		q.push(1);
		cout << q.peek() << endl;
		q.pop();
		q.push(2);
		q.push(3);
		cout << q.peek() << endl;
		q.pop();
		cout << q.peek() << endl;
		q.pop();
		cout << q.peek() << endl;
		q.pop();
	} catch (Empty) {
		cout << "\n������: ������� �����";
	} catch (Full) {
		cout << "\n������: ������� �����������";
	}
	cout << endl;
	system("pause");
	return 0;
}