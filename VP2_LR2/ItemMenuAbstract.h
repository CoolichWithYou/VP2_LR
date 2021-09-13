#pragma once
#include <iomanip>
using namespace std;

namespace otv
{
	class ItemMenuForm
	{
	protected:
		typedef int(*func)(); // указатель на функцию, которая ничего не принимает и возвращает значение типа int
		string m_item_name{}; // указатель на C-строку -- название пункта
		func m_func{}; // указатель на запускаемую функцию
	public:
		ItemMenuForm();
		ItemMenuForm(string name, func F);
		virtual string GetItemName() = 0;
		virtual void Print() = 0;
		virtual int Run() = 0;
	};
}