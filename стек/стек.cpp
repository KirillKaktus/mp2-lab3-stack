#include <iostream>
#include"TStack.h"
int BracketChecking(char *str)
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
}

int main()
{
   
}

