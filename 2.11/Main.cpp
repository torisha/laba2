#include<iostream>
#include<string>
#include"Route.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	//srand(time(NULL));
	int const size = 4;
	Route route[size];
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



	system("pause");
	return 0;
}