#include <iostream>
#include "CMenu.h"

using namespace std;
namespace otv
{
    CMenu::CMenu(string title, ItemMenu* items, size_t item_count)
    {
        // CMenu::CMenu(char *title, ItemMenu *items, int itemCount) : m_title(title), m_items(items), m_count(count) {}
        m_title = title;
        m_items = items;
        m_count = item_count;
    }
#pragma region GetSet
    int CMenu::GetSelect() const
    {
        return m_select;
    }
    size_t CMenu::GetCount() const
    {
        return m_count;
    }

    string CMenu::GetTitle() const
    {
        return m_title;
    }
    bool CMenu::IsRun() const
    {
        return m_running;
    }
    ItemMenu* CMenu::GetItems() const
    {
        return m_items;
    }
#pragma endregion
    void CMenu::Print() const
    {
        system("cls");
        cout << m_title << endl;
        for (int i = 0; i < m_count; i++)
        {
            cout << i + 1 << ". ";
            m_items[i].Print();
            cout << endl;
        }
        cout << "0. Exit" << endl;
    }
    void CMenu::RunCommand()
    {
        cout << "\n   Select >> ";
        cin >> m_select;
        if (m_select == 0)
        {
            exit(0);
        }
        m_items[m_select - 1].Run();
    }

    ostream& operator<< (ostream& out, const CMenu& m)
    {
        m.Print();
        return out;
    }
    istream& operator>> (istream& in, CMenu& m)
    {
        m.RunCommand();
        return in;
    }
}
