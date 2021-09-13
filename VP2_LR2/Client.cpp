#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"

Client::Client()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
	m_lvl = false;
}

void Client::Print() const
{
	cout << "Тип пользователя - Клиент" << endl;
	cout << "ID пользователя - " << m_id << endl;
	cout << "Имя польззователя - " << m_name << endl;
}


/*Client Client::operator=(Client a)
{
	m_id = a.m_id;
	m_lvl = a.m_lvl;
	m_date = a.m_date;
	m_name = a.m_name;
	m_login = a.m_login;
	m_pass = a.m_pass;
	//m_cards = a.m_cards;
}*/
void Client::In()
{
	cin >> m_login;
	cin >> m_pass;
	cin >> m_name;
}
bool operator> (const Client& a, const Client& b)
{
	return a.m_name > b.m_name;
}
bool operator== (const Client& a, const Client& b)
{
	bool r{};
	r = (a.m_login == b.m_login && a.m_pass == b.m_pass);
	return r;
}
