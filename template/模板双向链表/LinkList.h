#pragma once 

#include <iostream>
using namespace std;
#include <cassert>

template <typename T>
class Node
{
public:
	Node(const T& data)
		:_data(data)
		,_pnext(NULL)
		, _prev(NULL)
	{
	}
public:
	T _data;
	Node<T>* _pnext;
	Node<T>* _prev;
};

template<typename T>
class LinkList
{

public:
	LinkList();
	LinkList(const LinkList<T>& list);
	LinkList<T>& operator=(LinkList<T> list);
	~LinkList();
public:
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	void Display();
	void Remove(const T& d);
	void Sort_Bubble();
	void Sort_Insert();
	void Sort_Select();
	void Unique();
	void Merge();
	void Reverse();
	void Remove(Node<T>* pos);
private:
	Node<T>* _phead;
	Node<T>* _ptail;
};
/*********************************************************************************************************/

template<typename T>
LinkList<T>::LinkList()
			:_phead(NULL)
			, _ptail(NULL)
{}

template<typename T>
LinkList<T>::LinkList(const LinkList& list)
: _phead(NULL)
, _ptail(NULL)
{
	Node<T>* cur = list._phead;
	while (cur != NULL)
	{
		this->PushBack(cur->_data);
	}
}

template<typename T>
LinkList<T>&  LinkList<T>::operator=(LinkList<T> list)
{
	std::swap(_phead,list._phead);
	std::swap(_ptail, list._ptail);
	return *this;
}

template<typename T>
LinkList<T>::~LinkList()
{
	Node<T>* cur = _phead;
	while (cur != NULL)
	{
		Node<T>* tmp = cur;
		cur = cur->_pnext;
		delete tmp;
	}
	_phead = NULL;
	_ptail = NULL;
}

/*********************************************************************************************************/
template<typename T>
void LinkList<T>::Display()
{
		Node<T>* cur = _phead;
		while (cur != NULL)
		{
			cout << cur->_data << "  ";
			cur = cur->_pnext;
		}
		cout << endl;
}

template<typename T>
void LinkList<T>::PushBack(const T& d)
{
	Node<T>* cur = _phead;
	Node<T>* node = new Node<T>(d);
	if (cur == NULL)
	{
		_phead = node;
		_ptail = node;
	}
	else
	{
		_ptail->_pnext = node;
		node->_prev = _ptail;
		_ptail = _ptail->_pnext;
	}
}

template<typename T>
void LinkList<T>::PopBack()
{
	if (_ptail == NULL)
	{
		return;
	}
	else if (_ptail->_prev == NULL)
	{
		delete _ptail;
		_ptail = NULL;
		_phead = NULL;
	}
	else
	{
		_ptail = _ptail->_prev;
		delete _ptail->_pnext;
		_ptail->_pnext = NULL;
	}
}

template<typename T>
void LinkList<T>::PushFront(const T& d)
{
	Node<T>* node = new Node<T>(d);
	if (_phead == NULL)
	{
		_phead = node;
		_ptail = node;
	}
	else
	{
		node->_pnext = _phead;
		_phead->_prev = node;
		_phead = node;
	}
}

template<typename T>
void LinkList<T>::PopFront()
{
	if (_phead == NULL)
	{
		return;
	}
	else if (_phead ->_pnext == NULL)
	{
		delete _phead;
		_phead = NULL;
		_ptail = NULL;
	}
	else
	{
		_phead = _phead->_pnext;
		delete _phead->_prev;
		_phead->_prev = NULL;
	}
}

template<typename T>
void LinkList<T>::Remove(const T& d)
{
	Node<T>* cur = _phead;
	while (cur != NULL)
	{
		if (cur->_data == d)
		{
			if (cur == _phead)
			{
				PopFront();
			}
			else
			{
				cur->_prev->_pnext = cur->_pnext;
				if (cur->_pnext != NULL)
				{
					cur->_pnext->_prev = cur->_prev;
				}
				delete cur;
				cur = NULL;
			}
			return;
		}
		else
		{
			cur = cur->_pnext;
		}
	}
}

template<typename T>
void LinkList<T>::Sort_Bubble()
{
	Node<T>* cur = _phead;
	Node<T>* tmp_tail = NULL;
	while (cur != tmp_tail)
	{
		while (cur->_pnext != tmp_tail)
		{
			if (cur->_data > cur->_pnext->_data)
			{
				T tmp = cur->_data;
				cur->_data = cur->_pnext->_data;
				cur->_pnext->_data = tmp;
			}
			cur = cur->_pnext;
		}
		tmp_tail = cur;
		cur = _phead;
	}
}

template<typename T>
void LinkList<T>::Sort_Insert()
{
	assert(_phead);
	Node<T>* cur = _phead;
	while (cur->_pnext != NULL)
	{
		T data = cur->_pnext->_data; 
		Node<T>* node = cur;
		while (((node->_data) > data) && (node!= NULL))
		{
			node->_pnext->_data = node->_data;
			if (node->_prev != NULL)
			{
				node = node->_prev;
			}
			else
			{
				break;
			}
		}
		node->_data = data;
		cur = cur->_pnext;
	}
}

template<typename T>
void LinkList<T>::Sort_Select()
{
	assert(_phead);
	Node<T>* cur = _phead;
	while (cur->_pnext != NULL)
	{
		Node<T>* index = cur;
		Node<T>* node = cur->_pnext;
		while (node != NULL)
		{
			if ((index->_data) > (node->_data))
			{
				index = node;
			}
			node = node->_pnext;
		}
		T data = index->_data;
		index->_data = cur->_data;
		cur->_data = data;
		cur = cur->_pnext;
	}
}

template<typename T>
void LinkList<T>::Remove(Node<T>* pos)
{
	assert(pos);
	if (pos == _phead)
	{
		PopFront();
	}
	else if (pos == _ptail)
	{
		PopBack();
	}
	else
	{
		pos->_prev->_pnext = pos->_pnext;
		pos->_pnext->_prev = pos->_prev;
		delete pos;
		pos = NULL;
	}
}

template<typename T>
void LinkList<T>::Unique()
{
	if ((_phead == NULL) || (_phead->_pnext == NULL))
	{
		return;
	}
	Node<T>* cur = _phead;
	while ((cur != NULL) && (cur->_pnext != NULL))
	{
		Node<T>* node = cur->_pnext;
		while (cur->_data == node->_data)
		{
			Node<T>* tmp = node;
			node = node->_pnext;
			Remove(tmp);
			if (node == NULL)
			{
				return;
			}
		}
		cur = cur->_pnext;
	}
}

template<typename T>
void LinkList<T>::Reverse()
{
	if ((_phead == NULL) || (_phead->_pnext == NULL))
	{
		return;
	}
	Node<T>* cur = _phead;
	_ptail = _phead;
	while (cur != NULL)
	{
		Node<T>* tmp = cur;
		if (cur->_pnext == NULL)
		{
			_phead = cur;
		}
		cur = cur->_pnext;
		tmp->_pnext = tmp->_prev;
		tmp->_prev = cur;
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




