#pragma once
#include <iostream>
using namespace std;

class Account
{
	size_t m_id_owner{};
	size_t m_id{};
	string m_name{};
	char* m_date;	
	unsigned long m_balance{};
public:
	Account();
	void Trans(Account scd, int summ_tr);

	void Print() const;
	friend ostream& operator<<(ostream& out, const Account& acc);

	Account operator=(Account a);
	friend bool operator> (const Account& a, const Account& b);
};
