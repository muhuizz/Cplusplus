#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"


Seqlist::Seqlist()
	:_sz(0)
	, _capacity(0)
	, _pdata(NULL)
{}
Seqlist::Seqlist(const Seqlist& seq)
	: _sz(seq._sz)
	, _capacity(seq._capacity)
	, _pdata(new DataType[_capacity])
{
	memcpy(_pdata, seq._pdata, seq._sz* sizeof(DataType));
}
Seqlist::~Seqlist()
{
	if (_pdata != NULL)
	{
		delete[] _pdata;
	}
	_sz = 0;
	_capacity = 0;
}
Seqlist& Seqlist::operator=(const Seqlist& seq)
{
	DataType* tmp = new DataType[seq._capacity];
	for (int i = 0; i <seq. _sz; i++)
	{
		tmp[i] = seq._pdata[i];
	}
	delete[]_pdata;
	_pdata = tmp;
	_sz = seq._sz;
	_capacity = seq._capacity;
	return *this;
}


void Seqlist::PushBack(const DataType& x)
{
	if (_sz >= _capacity)
	{
		CheckCapacity();
	}
	_pdata[_sz] = x;
	_sz++;
}
void Seqlist::PopBack()
{
	if (_sz == 0)
	{
		return;
	}
	_sz--;
}
void Seqlist::Pushfront(const DataType& x)
{
	if (_sz >= _capacity)
	{
		CheckCapacity();
	}
	memcpy(_pdata + 1, _pdata, _sz* sizeof(DataType));
	_pdata[0] = x;
	_sz++;
}
void Seqlist::PopFront()
{
	if (_sz == 0)
	{
		return;
	}
	memcpy(_pdata, _pdata + 1, (_sz - 1)* sizeof(DataType));
	_sz--;
}
void Seqlist::Insert(int pos,const DataType& x)
{
	if ((pos <0) || (pos > _sz))
	{
		return;
	}
	if (_sz >= _capacity)
	{
		CheckCapacity();
	}
	if (pos == _sz)
	{
		PushBack(x);
		return;
	}
	memcpy(_pdata + pos + 1, _pdata + pos, (_sz - pos)* sizeof(DataType));
	_pdata[pos] = x;
	_sz++;
}
int Seqlist::Find(const DataType& x)
{
	for (int i = 0; i < _sz; i++)
	{
		if (_pdata[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}
void Seqlist::Remove(const DataType& x)
{
	int ret = Find(x);
	if (ret == -1)
	{
		return;
	}
	if (ret == 1)
	{
		PopFront();
	}
	else if (ret == _sz)
	{
		PopBack();
	}
	else
	{
		memcpy(_pdata + ret - 1, _pdata + ret, (_sz - ret)*sizeof(DataType));
		--_sz;
	}
}
void Seqlist::Remove_All(const DataType& x)
{
	while (Find(x) != -1)
	{
		Remove(x);
	}
}
void Seqlist::Sort_Bubble()
{
	int flag = 1;
	int k = _sz - 1;

	for (int i = 0; i < _sz-1; i++)
	{
		int m = 0;
		flag = 1;
		for (int j = 0; j<k; j++)
		{
			if (_pdata[j] > _pdata[j + 1])
			{
				DataType tmp = _pdata[j];
				_pdata[j] = _pdata[j + 1];
				_pdata[j + 1] = tmp;
				flag = 0;
				m = j;
			}
		}
		if (flag == 1)
		{
			return;
		}
		k = m;
	}
}
void Seqlist::Sort_Select()
{
	for (int i = 0; i < _sz; i++)
	{
		int index = i;
		for (int j = i+1; j < _sz; j++)
		{
			if (_pdata[index] > _pdata[j])
			{
				index = j;
			}
		}
		DataType tmp = _pdata[index];
		_pdata[index] = _pdata[i];
		_pdata[i] = tmp;
	}
}
void Seqlist::Sort_Insert()
{
	for (int i = 1; i < _sz; i++)
	{
		DataType tmp = _pdata[i];
		int j = i - 1;
		while ((j >= 0) && (_pdata[j] > tmp))
		{
			_pdata[j + 1] = _pdata[j];
			j--;
		}
		_pdata[j + 1] = tmp;
	}
}
void Seqlist::CheckCapacity()
{
	_capacity += _capacity + 10;
	DataType *tmp = new DataType[_capacity];
	memcpy(tmp, _pdata, _sz*sizeof(DataType));
	delete[] _pdata;
	_pdata = tmp;
}

ostream& operator<<(ostream& out, const Seqlist& seq)
{
	for (int i = 0; i < seq._sz; i++)
	{
		out << seq._pdata[i] << " ";
	}
	return out;
}

