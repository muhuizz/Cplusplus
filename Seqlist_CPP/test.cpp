#define _CRT_SECURE_NO_WARNINGS 1


#include "SeqList.h"

void test1()
{
	Seqlist myseq;
	myseq.PushBack(1);
	myseq.PushBack(2);
	myseq.PushBack(3);
	myseq.PushBack(4);
	myseq.PushBack(5);
	myseq.PushBack(6);
	cout << myseq << endl;
	myseq.PopBack();
	myseq.PopBack();
	myseq.PopBack();
	cout << myseq << endl;
	myseq.PopBack();
	myseq.PopBack();
	myseq.PopBack();
	myseq.PopBack();
	myseq.PopBack();
	cout << myseq << endl;
}
void test2()
{
	Seqlist myseq;
	myseq.Pushfront(1);
	myseq.Pushfront(2);
	myseq.Pushfront(3);
	myseq.Pushfront(4);
	myseq.Pushfront(5);
	cout << myseq << endl;
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	cout << myseq << endl;
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	myseq.PopFront();
	cout << myseq << endl;

}
void test3()
{
	Seqlist myseq;
	myseq.PushBack(1);
	//myseq.PushBack(2);
	//myseq.PushBack(3);
	//myseq.PushBack(4);

	//cout << myseq << endl;
	//myseq.Insert(1, 99);
	//cout << myseq << endl;

	cout<<myseq.Find(1)<<endl;
}

void test4()
{
	Seqlist myseq;
	//myseq.PushBack(1);
	myseq.PushBack(2);
	myseq.PushBack(2);
	myseq.PushBack(2);
	myseq.PushBack(2);

	//myseq.PushBack(3);
	cout << myseq << endl;
	//myseq.Remove(2);
	myseq.Remove_All(2);

	cout << myseq << endl;

}
void test5()
{
	Seqlist myseq;
	myseq.Pushfront(1);
	myseq.Pushfront(2);
	myseq.Pushfront(3);
	myseq.Pushfront(4);
	myseq.Pushfront(5);
	cout << myseq << endl;
	myseq.Sort_Bubble();
	//myseq.Sort_Select();
	//myseq.Sort_Insert();
	cout << myseq << endl;

}
void test6()
{
	Seqlist myseq;
	myseq.Pushfront(1);
	myseq.Pushfront(2);
	myseq.Pushfront(3);
	myseq.Pushfront(4);
	myseq.Pushfront(5);
	cout << myseq << endl;
	Seqlist s;
	s = myseq;
	cout << s << endl;
}
int main()
{
	test6();
	system("pause");
	return 0;
}