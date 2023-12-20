#pragma once
template <class T>
struct Tnode {
	T val;
	Tnode* pNext;
};
int count(Tnode<int>* pFirst)
{
	Tnode<int>* p = pFirst; int k = 0;
	while (p != nullptr)
	{
		p = (*p).pNext;//p=p->pNext
		k++;
	}
	return k;
}

template <class T>
class TLstack
{
	Tnode<T>* pFirst;
public:

	TLstack()
	{
		*pfirst = nullptr;
	}

	TLstack(const TLstack& s)
	{
		Tnode<int>* tmp = s.pFirst;
		while (tmp != nullptr)
		{
			push(tmp->val);
			tmp = tmp->pNext;
		}
	}
	bool empty()
	{
		if (*pfirst = nullptr)
			return true;
		else return false;
	}

	void push(const T el);

	T pop();

	T top()
	{
		return pFirst->val;
	}

	void clear()
	{
		while (!this.empty())
		{
			this.pop();
		}
	}

	~TLstack()
	{
		while (!empty())
		{
			pop();
		}
	}

};
template<class T>
void TLstack<T>::push(const T el)
{
	Tnode<T>* tmp = new Tnode<T>;
	tmp->val = el;
	tmp->pNext = pFirst;
	pFirst = tmp;
}
template<class T>
T TLstack<T>::pop()
{
	if (this->empty())
	{
		throw("stack is empty");
	}
	else {
		Tnode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		T res = p->val;
		delete p;
		return res;
	}
}

