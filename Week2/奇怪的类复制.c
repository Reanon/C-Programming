// week2_006.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;
class Sample {
public:
	int v;
	Sample(){}
	Sample(int a) {
		v = a;
	}
	Sample(const Sample & a) {
		v = a.v+2;
	}
	// 在此处补充你的代码
};
void PrintAndDouble(Sample o)
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5);
	Sample b = a;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
