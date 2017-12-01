
// week7_07.cpp: 定义控制台应用程序的入口点。
//
/* 自己编写一个能对任何类型的数组进行排序的mysort函数模版。只能写一个mysort模板，不能写mysort函数！
输入
无
输出
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,
样例输入
无
样例输出
4,8,10,11,123,
123,11,10,8,4,
1.4,1.2,1.8,3.1,3.2,2.1,
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
bool Greater2(int n1, int n2)
{
        return n1 > n2;
}
bool Greater1(int n1, int n2)
{
        return n1 < n2;
}
bool Greater3(double d1, double d2)
{
        return d1 < d2;
}
template <class T1, class T2>
void mysort(
        // 在此处补充你的代码
        T1 * start, T1 * end, T2 myless)
{
        int size = end - start;
        for (int i = size - 1; i >= 0; --i) {
               for (int j = 0; j < i; ++j) {
                       if (myless(start[j + 1], start[j])) {//调用Great x 函数，只要成立就行，所以可以进行多种排列
                              T1 tmp = start[j];   //指针的下标，需要多注意一下。
                              start[j] = start[j + 1];
                              start[j + 1] = tmp;
                       }
               }
        }
}
/*
答案2：
template<class T>
void Swap(T & a, T & b)
{
        T tmp;
        tmp = a;
        a = b;
        b = tmp;
}
template <class T1, class T2>
void mysort(T1  start, T1  end, T2 myless)
{
        int size = end - start;
        for (int i = size - 1; i >= 0; --i) {
               for (int j = 0; j < i; ++j) {
                       if (myless(*(start + j + 1), *(start + j))) { //多写了一个函数。
                              Swap(*(start + j + 1), *(start + j));
                       }
               }
        }
}
答案 3：
template <class T1, class T2>
void mysort(T1  start, T1  end, T2 myless)
{
        int size = end - start;
        for (int i = size - 1; i >= 0; --i) {
               for (int j = 0; j < i; ++j) {
                       if (myless(*(start + j + 1), *(start + j))) { //这里不用下标的形式去控制指针
                              auto tmp = *(start + j);
                              *(start + j) = *(start + j + 1);
                              *(start + j + 1) = tmp;
                       }
               }
        }
}
*/
        // 在此处补充你的代码
#define NUM 5
        int main()
{
        int an[NUM] = { 8,123,11,10,4 };
        mysort(an, an + NUM, Greater1); //从小到大排序
        for (int i = 0; i < NUM; i++)
               cout << an[i] << ",";
        mysort(an, an + NUM, Greater2); //从大到小排序
        cout << endl;
        for (int i = 0; i < NUM; i++)
               cout << an[i] << ",";
        cout << endl;
        double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
        mysort(d + 1, d + 5, Greater3); //将数组从下标1到下标4从小到大排序
        for (int i = 0; i < 6; i++)
               cout << d[i] << ",";
        return 0;
}
