#include "RPN.h"
#include <string>

int RPN::Priority(char a, char b)
{
	if ((a == '*' || a == '/') && (b == '*' || b == '/') || (a == '+' || a == '-') && (b == '+' || b == '-'))
		return 0;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if (b == '^' && a != '~')
		return -1;
	if (a == '^' && b != '~')
		return 1;
	if (a == '~')
		return 1;
	if (b == '~')
		return -1;
	throw "Error in priority";
}

bool RPN::Is_num(char s)
{
	return int(s) >= 48 && int(s) <= 57;
}

bool RPN::Is_operator(char s)
{
	if (s == '~' || s == '-' || s == '+' || s == '/' || s == '*' || s == '^' || s == '(' || s == ')')
		return true;
	else
		return false;	
}

void RPN::Space(string & l)
{
	if (l.empty())
		return;
	if (l.back() != ' ')
		l += ' ';
}

string RPN::Perv()
{
	for (int j = 0; j < Infix.size(); j++)
	{
		if (Infix[0] == '-')
			Infix[0] = '~';
		if (Infix[j] == '-' && (Infix[j - 1] == '(' || Infix[j - 1] == '~'))
			Infix[j] = '~';
	}
	int count = -1;
	stack<char> Set;
	for (int i = 0; i < Infix.size(); i++)
	{
		if (Is_operator(Infix[i]))
		{
			if ((Set.empty() || Infix[i] == '(') && Infix[i] != '~')
			{
				if (Infix[i] != '(')
					Space(Postfix);
				Set.push(Infix[i]);
				count++;
				continue;
			}
			else if ((Set.empty() || Set.top() == '~') && Infix[i] == '~')
			{
				Set.push(Infix[i]);
				count++;
				continue;
			}
			else if (Infix[i] == ')')
			{
				while (Set.top() != '(')
				{
					Space(Postfix);
					Postfix += Set.top();
					Set.pop();
					count--;
				}
				Set.pop();
				count--;
			}
			else if ((Set.top()) == '(' || Priority(Infix[i], Set.top()) == 1)
			{
				Set.push(Infix[i]);
				Space(Postfix);
				count++;
			}
			else if (Priority(Infix[i], Set.top()) == -1)
			{
				Space(Postfix);
				while (!(Set.empty()))
				{
					if (Set.top() == '(')
						break;
					Postfix += Set.top();
					Set.pop();
					Space(Postfix);
					count--;
				}
				Set.push(Infix[i]);
				count++;
			}
			else if (Priority(Infix[i], Set.top()) == 0)
			{
				Space(Postfix);
				Postfix += Set.top();
				Set.pop();
				Set.push(Infix[i]);
				Space(Postfix);
			}
		}
		else
			Postfix += Infix[i];
		if (i == Infix.size() - 1)
		{
			for (count; count >= 0; count--)
			{
				Space(Postfix);
				Postfix += Set.top();
				Set.pop();
			}
		}
	}
	return Postfix;
}

double RPN::calculate()
{
	stack<double> Result;
	string str;
	for (int i = 0; i < Postfix.size(); i++)
	{
		if (Postfix[i] == ' ')
			continue;
		if (!Is_operator(Postfix[i]))
		{
			while (Postfix[i] != ' ')
			{
				str += Postfix[i];
				i++;
			}
			Result.push(atof(str.c_str()));
			str = "";
		}
		else
		{
			if (Postfix[i] == '~')
			{
				double a = Result.top();
				Result.pop();
				Result.push(-a);
				continue;
			}
			double a = Result.top();
			Result.pop();
			double b = Result.top();
			Result.pop();
			if (Postfix[i] == '+')
				Result.push(b + a);
			else if (Postfix[i] == '-')
				Result.push(b - a);
			else if (Postfix[i] == '*')
				Result.push(b * a);
			else if (Postfix[i] == '/')
			{
				if (a == 0.0)
					throw "Error Division";
				Result.push(b / a);
			}
			else if (Postfix[i] == '^')
				Result.push(pow(b, a));
		}
	}
	return Result.top();
}
