#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <cassert>

template <typename T>
SeqList<T>::SeqList()
:_sz(0)
, _capacity(3)
, _pdata(NULL)
{
	_pdata = new T[_capacity];
}

template <typename T>
SeqList<T>::SeqList(const SeqList<T>& s)
{
	_pdata = new T[s._capacity];
	for (int i = 0; i < s._sz; i++)
	{
		_pdata[i] = s._pdata[i];
	}
	_sz = s._sz;
	_capacity = s._capacity;
}

template <typename T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& s)
{
	T* tmp = new T[s._capacity];
	for (int i = 0; i < s._sz; i++)
	{
		tmp[i] = s._pdata[i];
	}
	delete[] _pdata;
	_pdata = tmp;
	_sz = s._sz;
	_capacity = s._capacity;
	return *this;
}

template <typename T>
SeqList<T>::~SeqList()
{
	if (_pdata != NULL)
	{
		delete[]_pdata;
		_sz = 0;
		_capacity = 0;
	}
}

//template <typename T>
//ostream& operator<<(ostream& out, const SeqList<T>& seq)
//{
//	for (int i = 0; i < seq._sz; i++)
//	{
//		out << seq._pdata[i] << "  ";
//	}
//	return out;
//}

template <typename T>
void SeqList<T>::PushBack(const T& data)
{
	checkCapacity();
	_pdata[_sz] = data;
	_sz++;
}

template <typename T>
void SeqList<T>::PopBack()
{
	if (_sz == 0)
	{
		return;
	}
	_sz--;
}

template <typename T>
void SeqList<T>::PushFront(const T& data)
{
	checkCapacity();
	for (int i = _sz; i > 0;i--)
	{
		_pdata[i] = _pdata[i - 1];
	}
	_pdata[0] = data;
	_sz++;
}

template <typename T>
void SeqList<T>::PopFront()
{
	for (int i = 0; i < _sz-1; i++)
	{
		_pdata[i] = _pdata[i + 1];
	}
	_sz--;
}

template <typename T>
void SeqList<T>::show()
{
	for (int i = 0; i < _sz; i++)
	{
		cout << _pdata[i] << "  ";
	}
	cout << endl;
}

template <typename T>
void SeqList<T>::Remove(const T& x)
{
	int i = 0;
	for (i = 0; i < _sz; i++)
	{
		if (_pdata[i] == x)
		{
			break;
		}
	}
	if (i!= _sz)
	{
		for (; i < _sz-1; i++)
		{
			_pdata[i] = _pdata[i + 1];
		}
		_sz--;
	}
}

template <typename T>
void SeqList<T>::Remove_All(const T& x)
{
	int count = 0;
	for (int i = 0; i < _sz;i++)
	{
		if (_pdata[i] == x)
		{
			count++;
		}
		else
		{
			_pdata[i - count] = _pdata[i];
		}
	}
	_sz -= count;
}

template <typename T>
void SeqList<T>::Reserve(int NewCapa)
{
	assert(NewCapa > _sz);
	T* tmp = new T[NewCapa];
	for (int i = 0; i < _sz;i++)
	{
		tmp[i] = _pdata[i];
	}
	delete[] _pdata;
	_pdata = tmp;
	_capacity = NewCapa;
}

template <typename T>
void SeqList<T>::Sort_Bubble()
{
	int flag = 1;
	int k = _sz - 1;
	for (int i = 0; i < _sz - 1; i++)
	{
		int m = 0;
		flag = 1;
		for (int j = 0; j < k; j++)
		{
			if (_pdata[j] > _pdata[j + 1])
			{
				T tmp = _pdata[j];
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
		k = m,
	}
}

template <typename T>
void SeqList<T>::Sort_Select()
{
	for (int i = 0; i < _sz-1; i++)
	{
		int index = i;
		for (int j =i+1; j < _sz; j++)
		{
			if (_pdata[index] > _pdata[j])
			{
				index = j;
			}
		}
		T tmp = _pdata[index];
		_pdata[index] = _pdata[i];
		_pdata[i] = tmp;
	}
}

template <typename T>
void SeqList<T>::Sort_Insert()
{
	for (int i = 1; i < _sz;i++)
	{
		T tmp = _pdata[i];
		int j = i - 1;
		while ((_pdata[j] >tmp) && (j >= 0))
		{
			_pdata[j + 1] = _pdata[j];
			j--;
		}
		_pdata[j + 1] = tmp;
	}
}

template <typename T>
T& SeqList<T>::operator[](int index)
{
	assert(index >= 0);
	assert(index < _sz);
	return _pdata[index];
}

/*****************************************************************************************************************/
template<typename T>
void SeqList<T>::checkCapacity()
{
	int NewCapacity = 2 * _capacity + 3;
	T* tmp = new T[NewCapacity];
	for (int i = 0; i < _sz;i++)
	{
		tmp[i] = _pdata[i];
	}
	delete[] _pdata;
	_pdata = tmp;
	_capacity = NewCapacity;
}
