#pragma once

#include <iostream>
using namespace std;
#include <cstdlib>




template<typename T>
class SeqList
{
	//friend ostream& operator<<(ostream& out,const SeqList<T>& seq);
	friend ostream& operator<<(ostream& out, const SeqList<T>& seq)
	{
		for (int i = 0; i < seq._sz; i++)
		{
			out << seq._pdata[i] << "  ";
		}
		return out;
	}

public:
	SeqList();
	SeqList(const SeqList<T>& s);
	SeqList<T>& operator=(const SeqList<T>& s);
	~SeqList();
public:
	void PushBack(const T& data);
	void PopBack();
	void PushFront(const T& data);
	void PopFront();
	void Remove(const T& x);
	void Remove_All(const T& x);
	void Reserve(int NewCapa);
	void Insert(const T& x);
	void Sort_Bubble();
	void Sort_Select();
	void Sort_Insert();
	T& operator[](int index);
	void show();
private:
	void checkCapacity();
private:
	int _sz;
	int _capacity;
	T* _pdata;
};