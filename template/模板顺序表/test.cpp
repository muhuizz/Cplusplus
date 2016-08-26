#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "SeqList.cpp"

void test1()
{
	SeqList <int>myseq;
	//myseq.PushBack(1);
	//myseq.PushBack(2);
	//myseq.PushBack(3);
	//myseq.PushBack(4);
	//myseq.PushBack(5);
	//myseq.PushBack(6);
	//myseq.show();
	//myseq.PopBack();
	//myseq.PopBack();
	//myseq.show();
	//myseq.PopBack();
	//myseq.PopBack();
	//myseq.PopBack();
	//myseq.PopBack();
	//myseq.PopBack();
	//myseq.show();

	myseq.PushFront(1);
	myseq.PushFront(2);
	myseq.PushFront(3);
	myseq.PushFront(4);
	myseq.PushFront(5);
	myseq.show();
	myseq.PopFront();
	myseq.PopFront();
	myseq.show();
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	myseq.show();
}


void test2()
{
	SeqList <int>myseq;
	myseq.PushBack(2);
	myseq.PushBack(1);
	myseq.PushBack(2);
	myseq.PushBack(3);
	myseq.PushBack(2);
	myseq.PushBack(4);
	myseq.show();
	//myseq.Remove(2);
	myseq.Remove_All(2);
	myseq.show();
}

void test3()
{
	SeqList <int>myseq;
	myseq.PushBack(9);
	myseq.PushBack(1);
	myseq.PushBack(2);
	myseq.PushBack(8);
	myseq.PushBack(4);
	myseq.PushBack(7);
	myseq.show();
	////myseq.Reserve(7);
	//myseq[3] = 99;
	//myseq.Sort_Bubble();
	//myseq.Sort_Select();
	myseq.Sort_Insert();
	myseq.show();

}

void test4()
{
	SeqList <int>myseq;
	myseq.PushBack(1);
	myseq.PushBack(2);
	myseq.PushBack(3);
	myseq.PushBack(4);
	myseq.PushBack(5);
	//myseq.show();
	cout << myseq << endl;
	//SeqList<int> seq2;
	//seq2 = myseq;
	//seq2.show();
}

int main()
{
	test4();
	system("pause");
	return 0;
}