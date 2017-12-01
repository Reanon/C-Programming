
// week7_01.cpp: 定义控制台应用程序的入口点。
//
/*
输入
无
输出
TomJackMaryJohn
10
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
        // 在此处补充你的代码
        T *begin,T* end)  
{
        T * tmp = begin;
        // T tmp =*begin;
        ++begin;
        for (; begin!=end; ++begin)  //如何完美解决参数是数组的两个指针的问题，太神了！！！自己怎么也想不出来呀
        {
               *tmp += *begin;
               //tmp+=*begin;
        }
        return *tmp;
        // 在此处补充你的代码
}
int main() {
        string array[4] = { "Tom","Jack","Mary","John" };
        cout << SumArray(array, array + 4) << endl;
        int a[4] = { 1, 2, 3, 4 };  //提示：1+2+3+4 = 10
        cout << SumArray(a, a + 4) << endl;
        return 0;
}
