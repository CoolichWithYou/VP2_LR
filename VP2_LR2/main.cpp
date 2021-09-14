#include <iostream>
#include <fstream>
#include <vector>

#include "CMenu.h"
#include "Client.h"
#include "Employee.h"
#include "Account.h"

using namespace std;
using namespace otv;

typedef int(*func)();

string CLI = "client.bin", EMP = "employee.bin",

MENU_AUTH = "menu_auth.txt",
MENU_CLI = "menu_client.txt",
MENU_EMP = "menu_employee.txt";

ifstream FIN_BIN, FIN_TXT;
char* buff = new char[1024]{};

vector<Client> CLIENT{};
vector <Employee> EMPLOYEE{};
vector <Account> ACCOUNT{};
int VERIFY;
User* CUR_USER{};

int AddClient();
int AddEmployee();
int Verify();


int OutputAcc();
int VerifyOut();

//шаблоны
int AddIt();
int DelIt();
int EditIt();
int SortIt();
int FilterIt();



void Screen_0();
void Screen_1();
void Screen_2();







int main()
{
	setlocale(0, "");

#pragma region Загрузка файла клиентов

	FIN_BIN.open(CLI, ios_base::in);

	size_t item_count{};
	FIN_BIN >> item_count;
	FIN_BIN.ignore();


	Client tmp_client{};
	for (int i = 0; i < item_count && FIN_BIN.is_open(); i++)
	{
		FIN_BIN.read((char*)&tmp_client, sizeof(Client));
		CLIENT.push_back(tmp_client);
	}
	FIN_BIN.close();
#pragma endregion

#pragma region Загрузка файла сотрудников

	FIN_BIN.open(EMP, ios_base::in);

	item_count = 0;
	FIN_BIN >> item_count;
	FIN_BIN.ignore();


	Employee tmp_employee{};
	for (int i = 0; i < item_count && FIN_BIN.is_open(); i++)
	{
		FIN_BIN.read((char*)&tmp_employee, sizeof(Employee));
		EMPLOYEE.push_back(tmp_employee);
	}
	FIN_BIN.close();
#pragma endregion

#pragma region Загрузка файла карт

	FIN_BIN.open(EMP, ios_base::in);

	item_count = 0;
	FIN_BIN >> item_count;
	FIN_BIN.ignore();


	Account tmp_account{};
	for (int i = 0; i < item_count && FIN_BIN.is_open(); i++)
	{
		FIN_BIN.read((char*)&tmp_account, sizeof(Account));
		ACCOUNT.push_back(tmp_account);
	}
	FIN_BIN.close();
#pragma endregion

	Screen_0();
	if (!CUR_USER->GetLvl())
	{
		Screen_1();
	}
	else
	{
		Screen_2();
	}

	system("pause");
	return 0;
}



#pragma region функции меню авторизации
int AddClient()
//добавляет клиента в вектор
{
	Client tmp_cli{};
	tmp_cli.In();
	CLIENT.push_back(tmp_cli);

	return 0;
}
int AddEmployee()
//добавляет сотрудника в вектор
{
	Employee tmp_emp{};
	tmp_emp.In();
	EMPLOYEE.push_back(tmp_emp);
	return 0;
}
int Verify()
//проходит по векторам пользователей, сверяет логины и пароли
{
	User tmp_user{};
	tmp_user.In();
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (tmp_user.GetLogin() == CLIENT[i].GetLogin())
		{
			cout << "Пользователь найден!" << endl;
			if (tmp_user.GetPass() == CLIENT[i].GetPass()) {
				CUR_USER = &CLIENT[i];
				cout << "Пароль верный" << endl;
			}
		}
	}
	for (int i = 0; i < EMPLOYEE.size(); i++)
	{
		if (tmp_user.GetLogin() == EMPLOYEE[i].GetLogin())
		{
			cout << "Пользователь найден!" << endl;
			if (tmp_user.GetPass() == EMPLOYEE[i].GetPass()) {
				CUR_USER = &EMPLOYEE[i];
				cout << "Пароль верный" << endl;
			}
		}
	}
	if (CUR_USER == nullptr)
	{
		cout << "Неверно введены данные" << endl;
	}
	return 0;
}
#pragma endregion
void Screen_0()
{
#pragma region заполнение массива пунктов меню авторизации

	FIN_BIN.open(MENU_AUTH);

	size_t item_count_1{};
	FIN_BIN >> item_count_1;
	FIN_BIN.ignore();

	ItemMenu* items_1 = new ItemMenu[item_count_1]{};
	for (int i = 0; i < item_count_1 && FIN_BIN.is_open(); i++)
	{
		FIN_BIN.getline(buff, 1023);
		items_1[i].SetItemName(buff);
	}
	FIN_BIN.close();


	items_1[0].SetFunc(AddClient);
	items_1[1].SetFunc(AddEmployee);
	items_1[2].SetFunc(Verify);
#pragma endregion
#pragma region вызов меню авторизции

	CMenu menu_auth = CMenu("Меню входа", items_1, item_count_1);

	while (CUR_USER == nullptr)
	{
		cout << menu_auth;
		menu_auth.RunCommand();
	}
#pragma endregion
}


#pragma region функции меню клиента

#pragma endregion

void Screen_1()
{
#pragma region заполнение массива пунктов меню клиента

	FIN_TXT.open(MENU_AUTH);

	size_t item_count{};
	FIN_TXT >> item_count;
	FIN_TXT.ignore();

	ItemMenu* item = new ItemMenu[item_count]{};
	for (int i = 0; i < item_count && FIN_TXT.is_open(); i++)
	{
		FIN_TXT.getline(buff, 1023);
		item[i].SetItemName(buff);
	}
	FIN_TXT.close();


	item[0].SetFunc(EditIt);
	item[1].SetFunc(OutputAcc);
	item[2].SetFunc(AddIt);
	item[3].SetFunc(DelIt);
	item[4].SetFunc(DelIt);
	item[5].SetFunc(VerifyOut);

#pragma endregion
#pragma region вызов меню клиента

	CMenu menu_cli = CMenu("Меню клиента", item, item_count);

	while (CUR_USER == nullptr)
	{
		cout << menu_cli;
		menu_cli.RunCommand();
	}
#pragma endregion
}


#pragma region функции меню сотрудника

int AddIt() {
	return 0;
};
int DelIt() {
	return 0;
};
int EditIt() {
	return 0;
};
int SortIt() {
	return 0;
};
int FilterIt() {
	return 0;
};

int VerifyOut()
{
	VERIFY = 0;
	return 0;
};

int OutputAcc() {
	return 0;
}

#pragma endregion
void Screen_2()
{
#pragma region заполнение массива пунктов меню сотрудника
	ifstream FIN_TXT;
	FIN_TXT.open(MENU_CLI);
	size_t item_count{};
	FIN_TXT >> item_count;

	ItemMenu* item = new ItemMenu[item_count]{};
	for (int i = 0; i < item_count && FIN_TXT.is_open(); i++)
	{
		FIN_TXT >> buff;
		item[i].SetItemName(buff);
	}
	FIN_TXT.close();

	item[0].SetFunc(AddIt);
	item[1].SetFunc(DelIt);
	item[2].SetFunc(EditIt);
	item[3].SetFunc(SortIt);
	item[4].SetFunc(FilterIt);
	item[5].SetFunc(VerifyOut);
#pragma endregion

	CMenu menu_func = CMenu("Меню пользователя", item, item_count);
	do
	{
		cout << menu_func;
		cin >> menu_func;
	} while (VERIFY);
}

