// week5_020.cpp: 定义控制台应用程序的入口点。
//
/*

输入
无

输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-

*/
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
using namespace std;
#pragma C1010
int strlen_(const char * s)
{
	int i = 0;
	for (; s[i]; ++i);// 真是简略，不把‘\0’算作一个字符
	return i;
}
void strcpy_(char * d, const char * s)
{
	int i = 0;
	for (i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;//结尾加上‘\0’

}
int strcmp_(const char * s1, const char * s2)  //前者大返回1，后者大返回-1
{
	for (int i = 0; s1[i] && s2[i]; ++i) { //两者都没到字符的结尾
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat_(char * d, const char * s)//剪切；
{
	int len = strlen_(d);
	strcpy_(d + len, s);
}
class MyString
{
	// 在此处补充你的代码
private:
	char *str;
	int size;//这个size我之前设置了，但是没有用
public:
	MyString() {
		str = new char[2];//确保分配的是数组，如果是NULL则无法用cout输出；
		str[0] = 0;//既然是字符串，里面起码要是个空串，不能让str==NULL 
		size = 0;
	}
	MyString(const char *s) {
		//如果s==NULL,就让它出错吧
		size = strlen_(s);
		str = new char[size + 1];
		strcpy_(str, s);
	}
	MyString & operator= (const char *s) {
		//如果s==NULL,就让它出错吧
		int len = strlen_(s);
		if (size<len)     //动态数组分配节约思想啊
		{
			delete [] str;
			str = new char[len + 1];
		}
		strcpy_(str, s);
		size = len;
		return *this;//= 应该返回左边的值本身，实现（a=b)=c
	}
	void duplicate(const MyString &s) {//避免复制构造函数调用，用const防止更改；以前没用过。
		if (size<s.size)
		{
			delete[] str;
			str = new char[s.size + 1];
		}
		strcpy_(str, s.str);
		size = s.size;
	}
	MyString(const MyString &s) :size(0), str(new char[1]) {//复制构造函数也可以调用初始化列表，省去了判断s是否是空的步骤，机智！！
		duplicate(s);
	}
	MyString & operator =(const MyString &s) {//对象之间赋值
		if (str==s.str)
		{
			return *this;
		}
		duplicate(s);//写成函数是个多么方便的实情呐！！
		return *this;
	}
	bool operator == (const MyString &s)const {//这里返回值是bool类型：ture、false.比直接回1和0要好很多
		return strcmp_(str, s.str) == 0;// 比我写的简略很多呐
	}
	bool operator<(const MyString &s)const {
		return strcmp_(str, s.str) < 0; //strcmp_ 返回值有-1、0、1；
	}
	bool operator >(const MyString &s)const {
		return strcmp_(str, s.str) > 0;
	}
	MyString operator +(const MyString &s) {
		char *tmp = new char[size + s.size + 2];//确保能分配一个数组；这里很重要，也就是这里体现出了size的重要性，确报两个数组连接不会越界。
		strcpy_(tmp, str);
		strcat_(tmp, s.str);
		MyString os(tmp);
		delete[] tmp;//注意释放内存
		return os;
	}
	MyString &operator +=(const MyString &s) {
		char *tmp = new char[size + s.size + 2];
		strcpy_(tmp, str);
		strcat_(tmp, s.str);
		size += s.size;
		delete[]str;//str 指向的内存空间的内容被删除
		str = tmp;//这里不删除tmp,是因为str接管了tmp所指向的空间内容，而函数结束后tmp指针就消亡
		return *this;
	}
	char & operator[](int i)const {
		return str[i];
	 }
	MyString operator ()(int start, int len)const {//不调用非常量成员函数，不修改成员变量的值，那么将其写成常量成员函数是个好习惯
		char *tmp = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			tmp[i] = str[start + i];
		}
		tmp[len] = 0;
		MyString s(tmp);
		delete[]tmp;
		return s;
	}
	~MyString() {
		delete [] str;
	}
	friend ostream &operator<<(ostream &os, const MyString &s) {
		os << s.str;
		return os;
	}
	friend ostream & operator<<(ostream &os, char *s) {
		os << s;
		return os;
	}
	friend MyString operator +(const char *s1, const MyString & s2) {//在dev c++ 中，后面一个参数额const必须得写，不然会报错
		MyString tmp(s1);
		tmp += s2;
		return tmp;
	}//如果指针不乱放，内存好好管理，运行是很快的
	// 在此处补充你的代码
};
int CompareString(const void * e1, const void * e2)
{
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}


