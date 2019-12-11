#pragma once
#include <string>
#include <stack>

using namespace std;

class RPN
{
	string Infix; //инфиксная форма записи
	string Postfix; //постфиксная форма записи
	int Priority(char a, char b); //Приоритеты операций, необходимые при переходе из InFix в PostFix
	bool Is_num(char s); //Проверка элемента строки(Число)
	bool Is_operator(char s); //Проверка элемента строки(Операция,скобка)
	void Space(string& l); //Ставит пробел между элементами

public:
	string GetInfix() {    //получить инфиксное выражение
		return Infix;
	}
	string GetPostfix() {  //получить постфиксное выражение
		return Postfix;
	}
	string Perv();         //переводит введенное выражение в постфиксную форму
	double calculate();    //производит вычисления в постфиксной форме
	
	RPN(string tmp = "")	{   //конструктор
		Infix = tmp + " ";
		Postfix = "";
	}

	RPN(RPN& v)	{               //конструктор
		Infix = v.Infix;
		Postfix = v.Postfix;
	}
};

