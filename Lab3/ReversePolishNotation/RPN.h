#pragma once
#include <string>
#include <stack>

using namespace std;

class RPN
{
	string Infix; //��������� ����� ������
	string Postfix; //����������� ����� ������
	int Priority(char a, char b); //���������� ��������, ����������� ��� �������� �� InFix � PostFix
	bool Is_num(char s); //�������� �������� ������(�����)
	bool Is_operator(char s); //�������� �������� ������(��������,������)
	void Space(string& l); //������ ������ ����� ����������

public:
	string GetInfix() {    //�������� ��������� ���������
		return Infix;
	}
	string GetPostfix() {  //�������� ����������� ���������
		return Postfix;
	}
	string Perv();         //��������� ��������� ��������� � ����������� �����
	double calculate();    //���������� ���������� � ����������� �����
	
	RPN(string tmp = "")	{   //�����������
		Infix = tmp + " ";
		Postfix = "";
	}

	RPN(RPN& v)	{               //�����������
		Infix = v.Infix;
		Postfix = v.Postfix;
	}
};

