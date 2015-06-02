
//�� ����� ��������� ������ �������� N x M ������� ��������� ������.
//����������, �� ������� ������� ������ ����������� ���������� ����� �����. 
//	� - ���������� �������� ������.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
struct queue  //������������ �������
	{
		int x;       //����� ������ �������
		int y;	     //����� ������� �������
		queue* next; //������� �� ���� �������
  };
	queue  *head,*tail;

void InitQueue() //�������������  �������
{
	head = 0;
	tail = 0;
}
bool isEmpty()  //�������� �� �������
{
	return head == 0 ? true : false;
}
void peek( int *a,int *b) //������ ��   ������� ������� �������� ��� ��������
{
  if (!isEmpty())
  {
	*a = head->x;
	*b = head->y;
  }
}

void pop()    // �������� ��   ������� ������� ��������
{
  if (!isEmpty())
  {
	queue* tmp = head;
	head = head->next;
	delete tmp;
  }
}

void push(int a,int b)  // ���������� �   �������  ��������
{
	queue* tmp = new queue;
	tmp->x=a;
	tmp->y=b;
	tmp->next = 0;
	if(head == 0)
	{
		head = tmp;
		tail = head;
		return;
	}
	tail->next = tmp;
	tail = tmp;
	tail->next=0;
}

void main()
{   setlocale(LC_ALL,"rus");
	ifstream f1;
	f1.open("input1.txt");
	if(!f1.is_open())
	{
		cerr<<"Open file failed."<<endl;
		return;
	}
	int i,j,n,m,k,x,y,x1,y1;
	int **Lst;  //������� ��� �������� ����� ������
	f1>>n>>m;
	
	Lst=new int *[n];
	for(i=0;i<n;i++)
	   Lst[i]=new int[m];
	cout<<"���� ������ ����� -1 "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			f1>>Lst[i][j];
			cout<<setw(3)<<Lst[i][j]<<" ";
		}
		cout<<endl<<endl;
	}

InitQueue();	
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{ 
	 	if (Lst[i][j]==0)
		  {
		   k++;
		   push(i,j);
		   Lst[i][j]=k;
   
		   while (!isEmpty()) 
		    {  
			while (!isEmpty()) 
			 {
				peek(&x,&y);
                if (  x>0 && Lst[x-1][y]==0 ) 
					{ x1=x-1; 
				      push(x1,y);
					  Lst[x1][y]=k;
				    }

				 if (  x<n-1 && Lst[x+1][y]==0 ) 
					{ x1=x+1; 
				      push(x1,y);
					  Lst[x1][y]=k;
				    }
				 if (  y>0 && Lst[x][y-1]==0 ) 
					{ y1=y-1; 
				      push(x,y1);
					  Lst[x][y1]=k;
				    }
				  if (  y<m-1 && Lst[x][y+1]==0 ) 
					{ y1=y+1; 
				      push(x,y1);
					  Lst[x][y1]=k;
				    }
				  pop();
			 }// for 
		   }//while is_empty
		  }//if
		  }   //for j
		}   //for i

		cout<<"���������� ������ k="<<k<<endl;
} 
