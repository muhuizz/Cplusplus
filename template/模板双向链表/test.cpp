#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"



void test()
{
	//LinkList<int> mylist;
	//mylist.PushBack(1);
	//mylist.PushBack(2);
	//mylist.PushBack(3);
	//mylist.PushBack(4);
	//mylist.PushBack(5);
	//mylist.Display();
	//mylist.PopBack();
	//mylist.PopBack();
	//mylist.Display();
	//mylist.PopBack();
	//mylist.PopBack();
	//mylist.PopBack();
	//mylist.PopBack();
	//mylist.PopBack();
	//mylist.Display();

	LinkList<int> mylist;
	mylist.PushFront(1);
	mylist.PushFront(2);
	mylist.PushFront(3);
	mylist.PushFront(4);
	mylist.PushFront(5);
	mylist.Display();
	mylist.PopFront();
	mylist.PopFront();
	mylist.Display();
	mylist.PopFront();
	mylist.PopFront();
	mylist.PopFront();
	mylist.PopFront();
	mylist.PopFront();
	mylist.Display();

}


void test2()
{
	LinkList<int> mylist;
	mylist.PushBack(9);
	mylist.PushBack(8);
	mylist.PushBack(7);
	mylist.PushBack(6);
	mylist.PushBack(5);
	mylist.Display();
	//mylist.Remove(0);
	//mylist.Display();
	//mylist.Sort_Bubble();
	//mylist.Sort_Select();
	mylist.Sort_Insert();
	mylist.Display();

}
void test3()
{
	LinkList<int> mylist;
	mylist.PushBack(1);
	mylist.PushBack(1);
	mylist.PushBack(1);
	mylist.PushBack(3);
	mylist.PushBack(4);
	mylist.PushBack(4);
	mylist.PushBack(4);
	mylist.Display();
	//mylist.Unique();
	//mylist.Display();
	mylist.Reverse();
	mylist.Display();

}

int main()
{
	test3();
	system("pause");
	return 0;
}