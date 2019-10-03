#include<iostream>
#include<string>
#include"Route.h"
#include<Windows.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");

	int const size = 4;//size=8
	Route *route= new Route[size];
	Route temp;
	

	for (int i = 0; i < size; i++)//ввод данных
	{
		
		cin >> route[i];
		
	}

	for (int i = 0; i < size-1; i++)//сортировка 
	{
		for (int j = 0; j < size-1 - i; j++)
		{
			if (route[j].GetNum() > route[j + 1].GetNum())
			{
				temp = route[j];
				route[j] = route[j + 1];
				route[j + 1] = temp;
			}
		}
		
	}

	
	for (int i = 0; i < size; i++)//вывод данных
	{
		cout << route[i] << endl;
	}

	
	//поиск: вводим стринг и если есть совпадения то выводим рут
	string word = "";
	bool flag = false;
	cout << ">>> Введите слово для поиска: ";
	SetConsoleCP(1251);
	cin >> word;
	SetConsoleCP(866);
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (word == route[i].GetA() || word == route[i].GetB())
		{
			cout << ">>> Результат: " << route[i] << endl;
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "!!! НЕТ СОВПАДЕНИЙ !!!" << endl << endl;
	}
		
		
		
		 

	delete[] route;
	system("pause");
	return 0;
}