#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>

using namespace std;

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) +1])
	{
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(String s)
	{
		std::swap(_str,s._str);
		return *this;
	}
	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
		}
	}
private:
	char* _str;
};

int main()
{
	String s1("hello world");
	String s2(s1);
	String s3;
	s3 = s1;
	String s4("hehe");

	system("pause");
	return 0;
}