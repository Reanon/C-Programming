// week2_008.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	// 在此处补充你的代码
	Complex() {}
	Complex (const char * p  ) {
		r = p[0] - '0';   //竟然可以这么简单！！！！！
		i = p[2] - '0';
	}

	// 在此处补充你的代码
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	return 0;
}

