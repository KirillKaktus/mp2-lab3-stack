#include <iostream>
#include"TStack.h"
#include"Tcalc.h"
#include<string>
using namespace std;
int BracketChecking(string str)
{
Tstack<char> s(20);
int res = 0;
for (int i = 0; i < str.size(); i++)
{
	if (str[i] == '(')
		s.push(str[i]);
	if (str[i] == ')')
	{
		if (!s.empty())
			s.pop();
		else res = 1;
	}
}
if (!s.empty())
res = 2;
return res;
}

int main()
{
	Tcalc c("5+6*(2-3))");
	cout << c.get_postfix();
   
}

