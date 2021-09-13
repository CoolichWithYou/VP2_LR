#pragma once
#include "ItemMenu.h"

namespace otv
{
	class CMenu
		//��������� ���� � ���������� ������� ����, ������ ������� void() 
		//��������� ������� ������ ����
		//������ �� ����������
	{
	private:
		int m_select = -1; // ��������� ���� ������������
		bool m_running = false; // ��������� ���������� ����
		string m_title{}; // ������ �� C-������ -- ��������� ����
		size_t m_count = 0; //����������� ������� ���� 
		ItemMenu* m_items{}; // ��������� �� ������ �������� ������������ ������ ItemMenu

	public:
		CMenu(string title, ItemMenu* items, size_t item_count);

		int GetSelect() const;
		string GetTitle() const;
		size_t GetCount() const;
		bool IsRun() const;
		ItemMenu* GetItems() const;

		void Print() const;
		void RunCommand();
		friend ostream& operator<< (ostream& out, const CMenu& m);
		friend istream& operator>> (istream& in, CMenu& m);
	};
}