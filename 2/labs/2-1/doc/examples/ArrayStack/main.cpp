/*������������ ������ �3
���� �� �������*/
#include <iostream>
#include "stack.h"
using namespace std;
//�������� ������� ������
void main ()
{
	int k;
	printf("Checking basic features. Input num\n");
	cin>>k;
	ArrayStack m(k);
	for(int i=0;i<k;i++)
	{
		m.push(i);
	}
	ArrayStack n(m);
	for(int i=0;i<=2*k;i++)
	{
		cout<<m.pop()<<"  "<<n.pop()<<endl;
		n.push(i);

	}
	

}