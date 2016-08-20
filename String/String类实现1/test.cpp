#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class String
{
	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = "")
		:_sz(strlen(str))
		, _capacity(_sz +1)
		, _str(new char[_capacity])
	{
		strcpy(_str,str);
	}
	String(const String& s)//值传递会递归调用拷贝构造 
		:_sz(s._sz)
		, _capacity(s._capacity)
		, _str(new char[_capacity])
	{
		strcpy(_str,s._str);
	}
	String& operator=(String s)
	{
		std::swap(_str,s._str);
		std::swap(_sz, s._sz);
		std::swap(_capacity, s._capacity);
		return *this;
	}
	~String()
	{
		if (_str != NULL)
		{
			cout << "~String()" << endl;
			delete[]_str;
			_sz = 0;
			_capacity = 0;
		}
	}
public:
	char& operator[](int index)
	{
		return _str[index];
	}
	char *c_str()
	{
		return _str;
	}
	void PushBack(char c)
	{
		if ((_sz + 1) >= _capacity)//1代表一个字符c    
		{
			CheckString(1);
		}
		_str[_sz++] = c;
		_str[_sz] = '\0';
	}
	String operator+(const String& s)
	{
		String tmp(*this);
		if ((tmp._sz + s._sz) >= _capacity)//需要同时传递String类型的tmp变量，CheckString函数使用受限
		{
			int NewSize = (2 * tmp._capacity) > (tmp._sz + s._sz) ? (2 * tmp._capacity) : (tmp._sz + s._sz);
			char* tmp_str = new char[NewSize];
			strcpy(tmp_str, tmp._str);
			delete[]tmp._str;
			tmp._str = tmp_str;
			tmp._capacity = NewSize;
		}
		tmp._sz += s._sz;
		strcat(tmp._str,s._str);
		return tmp;
	}
	//库函数string类实现，如果pos不在字符串有效范围内，程序崩溃
	String& insert(size_t pos1, const String& s)
	{
		if ((pos1 < 0) || (pos1 > _sz) || (s._sz == 0))
		{
			return *this;
		}
		if (_sz + s._sz >= _capacity)
		{
			CheckString(s._sz);
		}
		char* tmp_str = new char[_sz + 1];
		strcpy(tmp_str, _str);
		memcpy(_str+pos1,s._str,s._sz);
		memcpy(_str + pos1 + s._sz, tmp_str + pos1,  _sz-pos1+1);
		_sz += s._sz;
		return *this;
	}

private:
	void CheckString(int count)
	{
		int NewSize = (2 * _capacity) > (_sz + count) ? (2 * _capacity) : (_sz + count);
		char* tmp_str = new char[NewSize];
		strcpy(tmp_str, _str);
		delete[]_str;
		_str = tmp_str;
		_capacity = NewSize;
	}

private:
	size_t _sz;		//实际字符个数
	size_t _capacity;  //容量
	char* _str;
};
ostream& operator<<(ostream& out, const String& s)
{
	out << s._str;
	return out;
}

void test1()
{
	String str1("abcdef");
	String str2(str1);
	String str3;
	str3 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	str1[2] = 'm';
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
}

void test2()
{
	String str1("hello world");
	String str2(str1);
	String str3;
	str3 = str1;
	cout << str1 << endl;
	//cout << str1.c_str() << endl;
	cout << str1+"abc" << endl;
	//str1.PushBack('1');
	//cout << str1 << endl;
}
void test3()//库函数string测试
{
	string str1 = "hello";
	//str1.insert(2,"abc");
	//str1.insert(7, "abc");
	str1.insert(6, 4,'d');
//	str1.insert(2, "\0");

	cout << str1 << endl;
}

void test4()
{
	String str1("hello world");
	String str2(str1);
	str1.insert(5,str2);
	cout << str1 << endl;
}
int main()
{
	test4();
	system("pause");
	return 0;
}