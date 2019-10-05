#include<iostream>
#include<string>
#include"Route.h"
#include<Windows.h>
#include<fstream>
//#include<sstream> //строковые потоки
using namespace std;





void check(string line) 
{

	for (int i = 0; i < line.size(); ++i) 
	{

		if (isdigit(line[i])) 
		{

			int counter = 0;

			while (isdigit(line[i++]))
				counter++;

			if (counter == 2)
				return;

		}

	}

	cout << line << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char number=' ';
	string word = "";
	bool flag = false;
	int const size = 4;//size=8
	Route *route= new Route[size];
	Route temp;
	
	cout << ">>> Шаг 1: ввод данных " << "\n" << "\n";

	for (int i = 0; i < size; i++)//ввод данных
	{
		
		cin >> route[i];
		
	}

	cout << ">>> Шаг 2: сортировка данных... " << "\n" << "\n";

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
	cout << ">>> Шаг 3: вывод данных... " << "\n" << "\n";
	
	for (int i = 0; i < size; i++)//вывод данных
	{
		cout << route[i] << endl;
	}
	

	do
	{
		cout << "ДЛЯ ПОИСКА НАЖМИТЕ 1 " << "\n";
		cout << "ДЛЯ ВЫХОДА НАЖМИТЕ 2" << "\n";
	//	cout << "*********МЕНЮ**********" << endl << endl;
	//	cout << "1) ПОИСК" << endl << endl;
	//	cout << "2) ВЫВОД ДАННЫХ" << endl << endl;
	//	cout << "3) ВЫХОД" << endl << endl;
		cout << "ВВЕДИТЕ КОМАНДУ: ";
		cin >> number;
		cout << "\n" << "\n";
		try
		{
				//switch (number)
				//{
				//case'1':
				//поиск: вводим стринг и если есть совпадения то выводим рут
			if (number == '1')
			{


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
					throw  "!!! НЕТ СОВПАДЕНИЙ !!!";
				}
				//break;
			}
			//}
			




		}
		catch (const char* msg)
		{
			cout << msg << "\n" << "\n";
		}




		/*
		fstream f;
		f.open("File.txt", fstream::in);
		if (!f.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{

			string line;
			while (getline(f, line))
			{
				check(line);
			}

		}

		f.close();

		*/


		/*while (f.get(chChar))
		{

			switch (chChar)
			{
				// Если мы нашли гласную букву
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':


				f.seekg(1, ios::cur);
				f.get(chChar);
				if (chChar == '0' || chChar == '1' || chChar == '2' || chChar == '3'
					|| chChar == '4' || chChar == '5'
					|| chChar == '6' || chChar == '7' || chChar == '8' || chChar == '9')
				{
					//перейти на след строку
					f << "\n";
				}
				else
				{
					//вернуться на начало строки тк надо вывести всю строку!!
					//getline(f, line);
					cout << line << "\n";
				}


				// Теперь нам нужно вернуться назад в режим чтения файла
				// Выполняем seekg() к текущей позиции
				//f.seekg(f.tellg(), ios::beg);

				break;
			}}*/


	}while (number != '2');
	
	
	delete[] route;
	system("pause");
	return 0;
}