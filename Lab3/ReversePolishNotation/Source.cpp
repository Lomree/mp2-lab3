#include "iostream"
#include "string"
#include "stack"
#include "stdlib.h"
#include "RPN.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	

	while (cin) {	
			string expression;
			cout << "������� �������������� ���������: ";
			getline(cin, expression);
			RPN line(expression);
			cout << "��������� �����: " << line.GetInfix() << endl;
			line.Perv();
			cout << "����������� �����: " << line.GetPostfix() << endl;
			cout << "�����: " << line.calculate() << endl;		
	}

	system("pause");
	return 0;
}