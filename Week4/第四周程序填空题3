// week4_018.cpp: 定义控制台应用程序的入口点。
//

/*
输入
无

输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,


样例输入
None

样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/
#include "stdafx.h"

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
	// 在此处补充你的代码
public:
	int * p;
	int column, row;
	Array2() { p = NULL; }
	Array2(int a,int b):row(a),column(b) {
		p = new int[row*column];
	}

	Array2(Array2 &a) :row(a.row),column(a.column){
		p = new int[row*column];               //动态数组，真是神奇呐
		memcpy(p, a.p, sizeof(int)*row*column);// 数组复制函数
	}

	Array2 & operator =(Array2 & a) {
		if (p) {
			delete [] p;
		}
		column = a.column;
		row = a.row;
		p = new int[row*column];
		memcpy(p, a.p, sizeof(int)*row*column);// 数组复制函数
		return *this;
	}
	~Array2() {
		if(p)
			delete[]p;
	}
	int * operator[](int i) {
		*p;
		return p + i*column; //第一个[]是重载函数，第二个[]就不是了，就是原生的 [] .原生的 [] 外面本来就是指针
		
	}


	int & operator()(int i,int j) {
		return p[i*column+j];
	}

	// 在此处补充你的代码
};

int main() {
	Array2 a(3,4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i,j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";  //第一个[]W是重载函数，第二个[]就不是了，就是原生的[].原生的[] 外面本来就是指针
		}
		cout << endl;
	}
	return 0;
}
