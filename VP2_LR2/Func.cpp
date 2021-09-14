#include "Func.h"

template<typename Type>
void Sort(Type* arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		for (size_t j = 0; j < arr.size(); ++j)
		{
			if (arr[j] > arr[i])
			{
				Type tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

template<typename Type, typename T>
Type* Filter(Type* arr, T par)
{
	vector <Type> filtred;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == par)
			filtred.push_back(arr[i]);
	}
	return filtred;
}

template<typename Type>
void Del(Type* arr, size_t index)
{
	for (size_t i = index; i < arr.size() - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}
	arr.pop_back();
}

template<typename Type>
void Add(Type* arr)
{
	Type tmp{};
	cin << tmp;
	arr.push_back(tmp);
}

template<typename Type, typename T>
void Edit(Type* arr, size_t index)
{
	Type tmp{};
	cout << arr[index];
	cout << "Input new date:	" << endl;
	cin >> tmp;
	arr[index] = tmp;
}
