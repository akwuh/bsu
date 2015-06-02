
class ArrayStack		/* ���� �� ������� */
{
private:
	int  size;	/* ����������� ������� */
	int* p;	/* ��������� �� ������ */
	int  top;	/* �������� ����� */
public:
ArrayStack(const int& _size);  /* ����������� */
ArrayStack(const ArrayStack& s);  // ����������� �����������
~ArrayStack();	        /* ���������� */
void push(const int& n);  /* ��������� ������� � ���� */
int pop();	              /* ���������� ������� �� ����� */
bool isEmpty();	        /* ������ ����? */
bool isFull();	        /* ������ ����? */
};