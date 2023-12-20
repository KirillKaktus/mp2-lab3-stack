#include "Tcalc.h"
#include<math.h>
double Tcalc::calcpostfix()
{
	D.clear();
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= '0') && (postfix[i] <= '9'))
		{
			D.push(postfix[i] - '0');
		}
		if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^'))
		{
			double x1, x2, y;
			x2 = D.pop();
			x1 = D.pop();
			if (postfix[i] == '+') y = x1 + x2;
			if (postfix[i] == '-') y = x1 - x2;
			if (postfix[i] == '*') y = x1 * x2;
			if (postfix[i] == '/') y = x1 / x2;
			if (postfix[i] == '^')
			{
				int x3 = x2;
				y = pow(x1, x3);
			}
			D.push(y);
		}
	}
	return(D.pop());
}
int Tcalc::prioritet(char a)
{
	if (a == '+') return 1;
	if (a == '-') return 1;
	if (a == '*') return 2;
	if (a == '/') return 2;
	if (a == '^') return 3;
	if (a == '(') return 0;

}
void Tcalc::to_postfix()
{
	C.clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			C.push(str[i]);
		}
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			postfix += str[i];
		}
		if (str[i] == ')')
		{
			char el = C.pop();
			while (el!='(')
			{
				postfix += el;
				el = C.pop();
			}
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
		{
			char el = C.pop();
			while (prioritet(el) >= prioritet(str[i]))
			{
				postfix += el;
				el = C.pop();
			}
			C.push(el);
			C.push(str[i]);
		}
	}
}

double Tcalc::calc()
{
	D.clear(); C.clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			C.push(str[i]);
		}
		if (str[i] == ')')
		{
			char el = C.pop();
			while (el != '(')
			{
				double x1, x2, y = 0;
				x2 = D.pop();
				x1 = D.pop();
				if (el == '+') y = x1 + x2;
				if (el == '-') y = x1 - x2;
				if (el == '*') y = x1 * x2;
				if (el == '/') y = x1 / x2;
				if (el == '^')
				{
					int x3 = x2;
					y = pow(x1, x3);
				}
				D.push(y);
				el = C.pop();
			}
		}
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			size_t pos;
			double x;
			x = stod(&str[i], &pos);
			D.push(x);
			i = i + pos - 1;
		}
		if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
		{
			char el = C.pop();
			while (prioritet(el) >= prioritet(str[i]))
			{
				double y;
				double x2 = D.pop();
				double x1 = D.pop();
				if (el == '+') y = x1 + x2;
				if (el == '-') y = x1 - x2;
				if (el == '*') y = x1 * x2;
				if (el == '/') y = x1 / x2;
				if (el == '^')
				{
					int x3 = x2;
					y = pow(x1, x3);
				}
				D.push(y);
				el = C.pop();
			}
			C.push(el);
			C.push(str[i]);
		}
	}
	double res;	
	res = D.pop();	
	if (!D.empty())
	{
		throw "troubles with result";
	}
	else
	{
		return res;
	}
}
