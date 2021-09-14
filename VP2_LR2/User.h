#pragma once
#include <iostream>
using namespace std;

static size_t ID_user = 1000;
class User {
protected:
	size_t m_id{};
	string m_login{};
	string m_pass{};
	bool m_lvl{};
	char* m_date{};

	string m_name{};

public:
	
	User();
	void In();
	string OutLvl();
	virtual void PrintParent() const;
	friend ostream& operator<<(ostream& out, const User& man);
};