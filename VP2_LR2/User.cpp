#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
using namespace std;

//ïåðåãðóçèòü îïåðàòîðû ñðàâíåíèÿ íà int è char è ïðèñâîåíèÿ 

User::User()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
}

void User::In()
{
	cout << "Input login:	";
	cin >> m_login;
	cout << "\nInput password:	";
	cin >> m_pass;
}




#pragma region  âûâîä
string User::OutLvl()
{
	return (m_lvl) ? ("Ñîòðóäíèê") : ("Êëèåíò");
}
void User::PrintParent() const
{
	//OutLvl();
	cout << "ID - " << m_id << endl;
	cout << "Name - " << m_name << endl;
}
ostream& operator<<(ostream& out, const User& man)
{
	man.PrintParent();
	return out;
}
#pragma endregion

