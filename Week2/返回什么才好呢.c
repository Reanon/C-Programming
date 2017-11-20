// week2_010.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
public:
	int val;

	A(int
		// 在此处补充你的代码
		v = 123) {
		val = v;
	}
	A & GetObj() {
	
		return *this;
	}

		// 在此处补充你的代码
};
int main()
{
	int m, n;
	A a;
	cout << a.val << endl;
	while (cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val << endl;
	}
	return 0;
}
