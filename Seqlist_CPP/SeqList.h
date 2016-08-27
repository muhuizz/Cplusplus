#ifndef __SEQLIST_H__
#define __SEQLIST_H__

typedef int DataType;
#include <cstdlib>
#include <iostream>
using namespace std;
class Seqlist
{
	friend ostream& operator<<(ostream& out, const Seqlist& seq);
public:
	Seqlist();
	Seqlist(const Seqlist& seq);
	Seqlist& operator=(const Seqlist& seq);
	~Seqlist();
public:
	void PushBack(const DataType& x);
	void PopBack();
	void Pushfront(const DataType& x);
	void PopFront();
	void Insert(int pos, const DataType& x);
	int Find(const DataType& x);
	void Remove(const DataType& x);
	void Remove_All(const DataType& x);
	void Sort_Bubble();
	void Sort_Select();
	void Sort_Insert();
private:
	void CheckCapacity();
private:
	int _sz;
	int _capacity;
	DataType* _pdata;
};

#endif//__SEQLIST_H__