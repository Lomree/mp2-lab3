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
			cout << "Введите арифметическое выражение: ";
			getline(cin, expression);
			RPN line(expression);
			cout << "Инфиксная форма: " << line.GetInfix() << endl;
			line.Perv();
			cout << "Постфиксная форма: " << line.GetPostfix() << endl;
			cout << "Ответ: " << line.calculate() << endl;		
	}

	system("pause");
	return 0;
}