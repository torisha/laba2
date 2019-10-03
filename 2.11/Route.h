#pragma once
#include<string>
#include<Windows.h>
using namespace std;

class Route
{
private:
	string A;
	string B;
	int num;
public:
	Route(): A(""), B(""), num(0) {}
	Route(string a, string b, int n) { this->A = a; this->B = b; this->num = n; }
	~Route(){}
	
	
	void add_route(string a, string b, int n) {A = a; B = b; num = n;}

	//вывод типа  Route g; cout<<g;
	friend std::ostream& operator <<(std::ostream &out, Route &route)
	{
		cout << "Route є" << route.GetNum() << endl;
		cout << "A: " << route.GetA() << endl;
		cout << "B: " << route.GetB() << endl << endl;
		return out;
	}

	//ввод типа Route f; cin>>f;
	friend std::istream& operator >>(std::istream &in, Route &route)
	{
		string a = "";
		string b = "";
		int n = 0;
		cout << "¬ведите A: ";

		SetConsoleCP(1251);
		cin >> a;
		SetConsoleCP(866);

		cout << endl << "¬ведите B: ";

		SetConsoleCP(1251);
		cin >> b;
		SetConsoleCP(866);

		cout <<endl<< "¬ведите номер марштура: ";

		SetConsoleCP(1251);
		cin >> n;
		SetConsoleCP(866);

		cout << endl << endl;
		route.add_route(a, b, n);
		return in;
	}

	void SetA(string a) { A = a; }
	void SetB(string b) { B = b; }
	void SetNum(int n) { this->num = n; }

	string GetA() { return this->A; }
	string GetB() { return this->B; }
	int GetNum() { return this->num; }

};