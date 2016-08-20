#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <cstdlib>

using namespace std;

//写时拷贝Copy_On_Write
//写时拷贝在动态库加载和释放过程中可能会产生副作用

//class String
//{
//	friend ostream& operator<<(ostream& out,const String& s);
//public:
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//		, _count(new int(1))
//	{
//		strcpy(_str,str);
//	}
//	String(const String& s)
//		:_str(s._str)
//		, _count(s._count)
//	{
//		++_count[0];
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			if (--_count[0] == 0)
//			{
//				delete[]_str;
//				delete _count;
//			}
//			_str = s._str;
//			s._count[0]++;
//			_count = s._count;
//		}
//		return *this;
//	}
//	~String()
//	{
//		if (_str != NULL)
//		{
//			if (--_count[0] == 0)
//			{
//				delete[] _str;
//				delete _count;
//				_str = NULL;
//				_count = NULL;
//			}
//		}
//	}
//private:
//	char* _str;
//	int* _count;
//};


class String
{
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 5])
	{
		*(int*)(_str) = 1;
		_str += 4;
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(s._str)
	{
		++get_ref();
	}
	String& operator=(const String& s)
	{
		if(this != &s)
		{
			if (--get_ref() == 0)
			{
				delete[](_str - 4);
			}
			_str = s._str;
			++get_ref();
		}
		return *this;
	}
	~String()
	{
		if (_str != NULL)
		{
			if (--get_ref() == 0)
			{
				delete[] (_str-4);
			}
		}
	}
	char& operator[](int index)
	{
		if (get_ref() != 1)
		{
			String tmp(*this);
			--get_ref();
			_str = new char[strlen(tmp._str) + 5];
			*(int*)(_str) = 1;
			_str += 4;
			strcpy(_str,tmp._str);
		}
		return _str[index];
	}
private:
	int& get_ref()
	{
		return *(int*)(_str - 4);
	}
private:
	char* _str;
};

ostream& operator<<(ostream& out, const String& s)
{
	out << s._str;
	return out;
}
int main()
{
	{
		String s1("hello world");
		String s2(s1);
		String s3;
		s3 = s1;
		cout << s1 << endl;
		s2[2] = 'z';
		cout << s1 << endl;
		cout << s2 << endl;
	}
	system("pause");
	return 0;
}
