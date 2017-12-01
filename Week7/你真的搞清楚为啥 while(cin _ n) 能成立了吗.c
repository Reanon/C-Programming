
// week7_04.cpp: 定义控制台应用程序的入口点。
//
/* 读入两个整数，输出两个整数 ，直到碰到-1
输入
多组数据，每组一行，是两个整数
输出
对每组数据，原样输出
当碰到输入中出现-1 时，程序结束
输入中保证会有 -1
样例输入
12 44
344 555
-1
2 3
样例输出
12 44
344 555
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
class MyCin
{
        // 在此处补充你的代码
public:
        istream & operator >>(int & n) {//将 >> 重载成MyCin的一个函数
               return cin >> n;//cin 的返回值是 istream &
        }
        // 在此处补充你的代码
};
int main()
{
        MyCin m;
        int n1, n2;
        while (m >> n1 >> n2)//m.(函数名）
               cout << n1 << " " << n2 << endl;
        return 0;
}
