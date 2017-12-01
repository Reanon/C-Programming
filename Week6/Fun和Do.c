
// week6_02.cpp: 定义控制台应用程序的入口点。
//
/*
输入
无
输出
A::Fun
C::Do
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
private:
        int nVal;
public:
        void Fun()
        {
               cout << "A::Fun" << endl;
        };
        void Do()
        {
               cout << "A::Do" << endl;
        }
};
class B :public A {
public:
        virtual void Do()
        {
               cout << "B::Do" << endl;
        }
};
class C :public B {
public:
        void Do()
        {
               cout << "C::Do" << endl;
        }
        void Fun()
        {
               cout << "C::Fun" << endl;
        }
};
void Call(
        // 在此处补充你的代码
        B &p               //这里得写B的& 才行，这个是地址
        // 在此处补充你的代码
) {
        p.Fun(); p.Do();
}
int main() {
        C c;
        Call(c);
        return 0;
}
