// MyString.cpp: 定义控制台应用程序的入口点。
//
/*
输入
多组数据，每组一行，是两个不带空格的字符串

输出
对每组数据，先输出一行，打印输入中的第一个字符串三次
然后再输出一行，打印输入中的第二个字符串三次


样例输入
abc def
123 456

样例输出
abc,abc,abc
def,def,def
123,123,123
456,456,456
*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;
	}
	~MyString() { if (p) delete[] p; }
	// 在此处补充你的代码
	MyString & operator=(const MyString & str ){
		if (str.p == p){	return *this;}
		if (p){	delete [] p;}
		if (str.p!=NULL)
		{
			p = new char[strlen(str.p) + 1];
			strcpy(p, str.p);
		}
		else
			p = NULL;
		return *this;
	}
	void Copy(const char * s) {
		if (p) delete[] p;
		if (s )
		{
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else {
			p = NULL;
		}
	}
	friend ostream & operator <<(ostream & o,const MyString & s) {
		o << s.p;
		return o;
	}
	MyString(const MyString &s) {
		if (s.p) {
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
		else
		{
			p = NULL;
		}
	}
	MyString & operator=(const char *s) {
		if (p) delete[] p;
		if (s != NULL)
		{
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;
		return *this;
	}
	// 在此处补充你的代码
};

int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;  // 缺了一个复制构造函数，就会多删除一个指针，然后报错……C++管理内存真麻烦呐……
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}
