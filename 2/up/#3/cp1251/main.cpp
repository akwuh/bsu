// ������ �����
// ������� ��������, ������� 3 "����������� ��������� ��� ������ � ������������� (multimap). �������������� ���� ������� �������� ������������ ����� ���������, ���������� ���(������), ������� (������������ �����). ������������ ����������� �������� ����������(*).��������� ������ �������� �� ����� ���������� ���� ����:
// 1. �������� �������� �� ��������� ���������(�� ������� ��� �� ������� �����������)
// 2. ������� �������
// 3. ����� ��������� ������� ������ ��������� �����
// 4. ����������  �������� ���� ��������(�����������)
// 5. ������ ��������
// 6. ���������  �����������
// 7. ����� �� ���������"
//
// 27.06.2015

#include "MapForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^args)
{
	try{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		up::MapForm form;
		Application::Run(%form);
	}
	catch (System::Exception^ e) {
		MessageBox::Show(e->Message);
	}
	return 0;
}