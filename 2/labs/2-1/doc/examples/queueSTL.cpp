#include <queue>
#include <iostream>
#include <conio.h>
#include <time.h>
 
using namespace std;
 
 
void main()
{setlocale (LC_ALL, "Russian");
srand((unsigned) time(NULL));
int b,action,n;
queue <int> Q;
cout << "������� ���������� ��������� �������: ";
cin >> n;
for (int i=0; i<n; i++)
Q.push (b=rand() % 50);
queue <int> newQ = Q;
 
while (!newQ.empty()){
cout << newQ.front() << " ";
newQ.pop();}
cout << "\n������ ������� �������: " << Q.front()<<endl;
cout << "��������� ������� �������: " << Q.back()<<endl;
newQ = Q;
newQ.pop();
cout << "������� ������ ������� �������: \n";
Q = newQ;
cout << "���������� �������� \n";
while (!newQ.empty()){
    cout << newQ.front() << " ";
    newQ.pop();}
cout << "\n���������� ��������� �������: " << Q.size(); 
_getch();
}

