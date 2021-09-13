#include "ItemMenu.h"
#include "ItemMenuAbstract.h"
#include <iostream>

namespace otv
{
	ItemMenu::ItemMenu(string name, func F) {}
	ItemMenu::ItemMenu() {}
	typedef void(*func)();
	string ItemMenu::GetItemName()
	{
		return m_item_name;
	}
	void ItemMenu::SetItemName(string name)
	{
		m_item_name = name;
	}
	void ItemMenu::SetFunc(func F)
	{
		m_func = F;
	}

	void ItemMenu::Print()
	{
		std::cout << m_item_name;
	}
	int ItemMenu::Run()
	{
		return m_func();
	}
}