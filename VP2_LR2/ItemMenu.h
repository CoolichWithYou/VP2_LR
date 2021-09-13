#pragma once
#include "ItemMenuAbstract.h"

namespace otv
{
	class ItemMenu : public ItemMenuForm
	{
	public:
		ItemMenu(string name, func F);
		ItemMenu();
		string GetItemName();
		void SetItemName(string name);
		void SetFunc(func F);
		void Print();
		int Run();
	};
}