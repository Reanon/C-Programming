// week4_019.cpp: 定义控制台应用程序的入口点。
//

/*
输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示

输出
对每组数据，输出6行，内容分别是：


样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6

样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
*/
#include "stdafx.h"
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	// 在此处补充你的代码
private:
	char buf[220];
public:
	void reverse(char *p) {// 倒置后的数值字符串更加方便进行计算，并且容易判断出计算结束。
		int len =strlen(p);
		int i = 0, j = len - 1;
		while (i<=j)
		{
			swap(p[i], p[j]);// 这是一个模板函数
			++i;
			--j;
		}
	}
	CHugeInt(char * p) {
		memset(buf, 0, sizeof(buf)); //将buf中的所有元素置成0
		strcpy(buf, p);
		reverse(buf);
	}
	CHugeInt(int n) {
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d", n);      //将n以%d的字符串形式保存buf
		reverse(buf);
	}
	CHugeInt operator+(int n) {
		return *this + CHugeInt(n);
	}
	CHugeInt operator +(const CHugeInt & n)const{  //常量函数，函数内的值不可更改
		CHugeInt tmp(0);
		int carry = 0;//进位
		for (int i = 0; i < 210; i++)
		{
			char c1 = buf[i];
			char c2 = n.buf[i];
			if (c1 == 0 && c2 == 0 && carry == 0) //三者都为0时，说明读取到了字符串
				break;
			if (c1==0)
			{
				c1 = '0';
			}
			if (c2==0)
			{
				c2 = '0';
			}
			int k = c1 - '0' + c2 - '0' + carry;// 这里的K是数值
			if (k>=10)
			{
				carry = 1;
				tmp.buf[i] = k - 10 + '0';//又转成字符串
			}
			else {
				carry = 0;
				tmp.buf[i] = k + '0';
			}
		}
		return tmp; //放回值不是引用的原因:tmp在调用后就会消亡
	}
	friend CHugeInt operator +(int n, CHugeInt & h) { //友元函数可以写在类里面
		return h + n;//类型转换构造函数变成两个对象相加，其实都是对象相加；
	}
	friend ostream &operator<<(ostream &os, const CHugeInt & h) {
		int len = strlen(h.buf);
		for (int i =len-1; i >= 0; --i)//本来是倒着的，所以倒着输出。
		{
			cout<< h.buf[i];
		}
		return os;

	}
	CHugeInt & operator +=(int n) {
		*this = *this + n;
		return *this;
	}
	CHugeInt & operator ++() {
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator ++(int) {//后置++
		CHugeInt tmp(*this);
		*this = tmp + 1;
		return tmp;
	}
	// 在此处补充你的代码
};
int  main()
{
	char s[210];
	int n;
	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
