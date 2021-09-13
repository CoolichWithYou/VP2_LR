#pragma once
#include <iomanip>
using namespace std;

namespace otv
{
	class ItemMenuForm
	{
	protected:
		typedef int(*func)(); // ��������� �� �������, ������� ������ �� ��������� � ���������� �������� ���� int
		string m_item_name{}; // ��������� �� C-������ -- �������� ������
		func m_func{}; // ��������� �� ����������� �������
	public:
		ItemMenuForm();
		ItemMenuForm(string name, func F);
		virtual string GetItemName() = 0;
		virtual void Print() = 0;
		virtual int Run() = 0;
	};
}