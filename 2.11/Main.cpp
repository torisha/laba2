#include<iostream>
#include<string>
#include"Route.h"
#include<Windows.h>
#include<fstream>
//#include<sstream> //��������� ������
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
	
	cout << ">>> ��� 1: ���� ������ " << "\n" << "\n";

	for (int i = 0; i < size; i++)//���� ������
	{
		
		cin >> route[i];
		
	}

	cout << ">>> ��� 2: ���������� ������... " << "\n" << "\n";

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
	cout << ">>> ��� 3: ����� ������... " << "\n" << "\n";
	
	for (int i = 0; i < size; i++)//����� ������
	{
		cout << route[i] << endl;
	}
	

	do
	{
		cout << "��� ������ ������� 1 " << "\n";
		cout << "��� ������ ������� 2" << "\n";
	//	cout << "*********����**********" << endl << endl;
	//	cout << "1) �����" << endl << endl;
	//	cout << "2) ����� ������" << endl << endl;
	//	cout << "3) �����" << endl << endl;
		cout << "������� �������: ";
		cin >> number;
		cout << "\n" << "\n";
		try
		{
				//switch (number)
				//{
				//case'1':
				//�����: ������ ������ � ���� ���� ���������� �� ������� ���
			if (number == '1')
			{


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
					throw  "!!! ��� ���������� !!!";
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
			cout << "������ �������� �����" << endl;
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
				// ���� �� ����� ������� �����
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
					//������� �� ���� ������
					f << "\n";
				}
				else
				{
					//��������� �� ������ ������ �� ���� ������� ��� ������!!
					//getline(f, line);
					cout << line << "\n";
				}


				// ������ ��� ����� ��������� ����� � ����� ������ �����
				// ��������� seekg() � ������� �������
				//f.seekg(f.tellg(), ios::beg);

				break;
			}}*/


	}while (number != '2');
	
	
	delete[] route;
	system("pause");
	return 0;
}