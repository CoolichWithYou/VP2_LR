#include <iostream>
#include <fstream>
#include <vector>

#include "CMenu.h"
#include "Client.h"
#include "Employee.h"

using namespace std;
using namespace otv;

typedef int(*func)();

string CLI = "client.bin", EMP = "employee.bin", 

MENU_AUTH = "menu_auth.txt", 
MENU_CLI = "menu_client.txt", 
MENU_EMP = "menu_employee.txt";

char* buff = new char[1024]{};

vector<Client> CLIENT{};
vector <Employee> EMPLOYEE{};
int VERIFY;
User* CUR_USER{};


int AddIt();
int DelIt();
int EditIt();
int SortIt();
int FilterIt();
int VerifyOut();
int AddClient();
int AddEmployee();
int Verify();
int Screen_2();

int main()
{
	setlocale(0, "");

#pragma region Загрузка файла клиентов
	ifstream fin;
	fin.open(CLI, ios_base::in);

	size_t item_count{};
	fin >> item_count;
	fin.ignore();

	
	Client tmp_client{};
	for (int i = 0; i < item_count && fin.is_open(); i++)
	{
		fin.read((char*)&tmp_client, sizeof(Client));
		CLIENT.push_back(tmp_client);
	}
	fin.close();
#pragma endregion

#pragma region Загрузка файла сотрудников

	fin.open(EMP, ios_base::in);

	item_count = 0;
	fin >> item_count;
	fin.ignore();

	
	Employee tmp_employee{};
	for (int i = 0; i < item_count && fin.is_open(); i++)
	{
		fin.read((char*)&tmp_client, sizeof(Employee));
		EMPLOYEE.push_back(tmp_employee);
	}
	fin.close();
#pragma endregion

#pragma region заполнение массива пунктов первого меню

	fin.open(MENU_AUTH);

	size_t item_count_1{};
	fin >> item_count_1;
	fin.ignore();

	ItemMenu* items_1 = new ItemMenu[item_count_1]{};
	for (int i = 0; i < item_count_1 && fin.is_open(); i++)
	{
		fin.getline(buff, 1023);
		items_1[i].SetItemName(buff);
	}
	fin.close();


	items_1[0].SetFunc(AddClient);
	items_1[1].SetFunc(AddEmployee);
	items_1[2].SetFunc(Verify);
#pragma endregion

#pragma region вызов первого меню
	CMenu menu_auth = CMenu("Меню входа", items_1, item_count_1);

	while (CUR_USER == nullptr)
	{
		cout << menu_auth;
		menu_auth.RunCommand();
	}
			
	Screen_2();


	system("pause");
	return 0;
}
#pragma endregion





int AddClient()
{
	cout << "Enter login, password, name:\n";
	Client tmp_cli{};
	cout << "";
	tmp_cli.In();
	CLIENT.push_back(tmp_cli);

	return 0;
}
int AddEmployee()
{
	Employee tmp_emp{};
	cout << "Enter login, password, name:\n";
	tmp_emp.In();
	EMPLOYEE.push_back(tmp_emp);
	return 0;
}
int Verify()
//пройти по векторам пользователей, сверить логины и пароли
{
	User tmp_user{};
	tmp_user.In();
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (true)
		{
			CUR_USER = &CLIENT[i]; 

		}
	}
	for (int i = 0; i < EMPLOYEE.size(); i++)
	{
		if (true)
		{
			CUR_USER = &EMPLOYEE[i];
		}
	}
	return 0;
}



int Screen_2()
{
#pragma region заполнение массива пунктов второго меню
	ifstream fin;
	fin.open(MENU_CLI);
	size_t item_count_2{};
	fin >> item_count_2;

	ItemMenu* items_2 = new ItemMenu[item_count_2]{};
	for (int i = 0; i < item_count_2 && fin.is_open(); i++)
	{
		fin >> buff;
		items_2[i].SetItemName(buff);
	}
	fin.close();

	items_2[0].SetFunc(AddIt);
	items_2[1].SetFunc(DelIt);
	items_2[2].SetFunc(EditIt);
	items_2[3].SetFunc(SortIt);
	items_2[4].SetFunc(FilterIt);
	items_2[5].SetFunc(VerifyOut);
#pragma endregion

	CMenu menu_func = CMenu("Меню пользователя", items_2, item_count_2);
	do
	{
		cout << menu_func;
		cin >> menu_func;
	} while (VERIFY);
	return 0;
}





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
