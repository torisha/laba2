#pragma once
#include<string>
using namespace std;

class Route
{
private:
	string A;
	string B;
	int num;
public:
	Route(): A(""), B(""), num(0) {}
	~Route(){}
	
	void show_route();//вывод инфы про маршрут
	void set_route(string a, string b, int n);//установить всю инфу

	void SetA(string a) { A = a; }
	void SetB(string b) { B = b; }
	void SetNum(int n) { this->num = n; }

	string GetA() { return this->A; }
	string GetB() { return this->B; }
	int GetNum() { return this->num; }

};