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
	

	for (int i = 0; i < size; i++)//���� ������
	{
		
		cin >> route[i];
		
	}

	for (int i = 0; i < size-1; i++)//���������� 
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

	
	for (int i = 0; i < size; i++)//����� ������
	{
		cout << route[i] << endl;
	}

	
	//�����: ������ ������ � ���� ���� ���������� �� ������� ���
	string word = "";
	bool flag = false;
	cout << ">>> ������� ����� ��� ������: ";
	SetConsoleCP(1251);
	cin >> word;
	SetConsoleCP(866);
	cout << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (word == route[i].GetA() || word == route[i].GetB())
		{
			cout << ">>> ���������: " << route[i] << endl;
			flag = true;
		}
	}

	if (flag == false)
	{
		cout << "!!! ��� ���������� !!!" << endl << endl;
	}
		
		
		
		 

	delete[] route;
	system("pause");
	return 0;
}