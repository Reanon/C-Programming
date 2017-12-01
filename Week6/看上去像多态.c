
// week6_01.cpp: 定义控制台应用程序的入口点。
//
/*
样例输入
无
样例输出
D::Fun
B::Fun
D::Fun
nBVal=2
nBVal=24
nDVal=8
B::Fun
nBVal=12
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
class B {
private:
        int nBVal;
public:
        void Print()
        {
               cout << "nBVal=" << nBVal << endl;
        }
        void Fun()
        {
               cout << "B::Fun" << endl;
        }
        B(int n) { nBVal = n; }
};
// 在此处补充你的代码
class D :public B {
private:
        int nDVal;
public:
        D(int n) :nDVal(n), B(3*n) {}
        void Print() {
               B::Print();
               cout << "nDVal=" << nDVal << endl;
        }
        void Fun() {
               cout << "D::Fun" << endl;
        }
};
// 在此处补充你的代码
int main() {
        B * pb; D * pd;
        D d(4); d.Fun();
        pb = new B(2);
        pd = new D(8);
        pb->Fun();
        pd->Fun();
        pb->Print();
        pd->Print();
        pb = &d; pb->Fun();
        pb->Print();
        return 0;
}
