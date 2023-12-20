#pragma once
#include<iostream>
#include"TStack.h"
#include<string>
using namespace std;
class Tcalc
{
	string infix, postfix;
	Tstack<double> D;
	Tstack <char> C;
public:
	Tcalc()
	{
		infix = "";
	}
	Tcalc(string s)
	{
		infix = s;
		this->to_postfix();
	}
	void set_infix(string a)
	{
		infix = a;
	}
	string get_infix()
	{
	return infix;	
	}
	string get_postfix()
	{
	return postfix;
	
	}
	void to_postfix();
	double calcpostfix();
	int prioritet(char a);
	double calc();

};

