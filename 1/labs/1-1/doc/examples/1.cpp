#include <iostream>
#include <math.h>
using namespace std;
//���������� �������������� ������ ����������� ��������� 
void main()
{
  setlocale (LC_ALL,".1251");  //��� ������ �������� ������
//  setlocale (LC_ALL,"rus");  //��� ������ �������� ������
  double a,b,c,x1,x2,d;
 
   cout<<"����� ������������ \n";
   cin>>a>>b>>c;
   cout<<"����������"<<endl;
 

   d= b*b-4*a*c;
   if (a==0)
   {     if (b==0)
		   cout<<"�� ���������� ����  ";
	   else
	   {
		   x1=(-c)/b;
		   cout<<"x="<<x1;
	   }      }
   else
	   if (d<0)
		   cout<<"��� �������������� ������\n";
	   else
	   {
		   x1=(-b+sqrt(d))/(2*a);
		   x2=(-b-sqrt(d))/(2*a);
		   cout<<"x1="<<x1; 
		   cout<<"x2="<<x2; 
	   }
}
