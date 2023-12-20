#pragma once
template <class T>
class Tstack
{
	T* pMem;
	int Maxsize;
	int Currind;
public:

	Tstack(int s = 10)
	{
		if (s <= 0) throw "wrong size";
		else {
			Maxsize = s;
			pMem = new T[s];
			Currind = -1;
		}
	}

	~Tstack()
	{
		delete pMem;
	}

	Tstack(const Tstack& s)
	{
		Maxsize = s.Maxsize;
		pMem = new T[Maxsize];
		Currind = s.Currind;
		for (int i = 0; i <= Currind; i++)
		{
			pMem[i] = s.pMem[i];
		}
	}

	bool empty()
	{
		if (Currind == -1) return true;
		else return false;
	}
	bool full()
	{
		if (Currind == Maxsize - 1) return true;
		else return false;
	}
	void push(const T& el)
	{
			Currind++;
		if (Currind >= Maxsize)
		{
			throw ("overload");
		}
		else {
			pMem[Currind] = el;
		}
	}

	T pop()
	{
		if (Currind == -1)
		{
			throw("Stack is empty");
		}
		else {
			Currind--;
			return pMem[Currind + 1];
		}// в тетради написано currind-1
	}

	T top()
	{
		if (Currind == -1)
		{
			throw("Stack is empty");
		}
		return pMem[Currind];
	}

	void clear()
		{
		Currind = -1;
		}

};

