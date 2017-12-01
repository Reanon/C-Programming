
// week7_03.cpp: 定义控制台应用程序的入口点。
//
/*编写Filter模板，使得程序产生指定输出
不得编写 Filter函数
输入
无
输出
MikeJackLucy
3,4,5,
输入样例
无
输出样例
MikeJackLucy
3,4,5,
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <typename T,typename pred>
T Filter(T begin,T end,T x,pred op) {//T: string *, op: bool * op(int)
        for  (; begin != end; ++begin){
               if (op(*begin)) {//判断
                       *x = *begin; //太神奇了！！！！
                       ++x;
               }
        }
        return x;
}
// 在此处补充你的代码
bool LargerThan2(int n)
{
        return n > 2;
}
bool LongerThan3(string s)
{
        return s.length() > 3;
}
string as1[5] = { "Tom","Mike","Jack","Ted","Lucy" };
string as2[5];
int  a1[5] = { 1,2,3,4,5 };
int a2[5];
int main() {
        string * p = Filter(as1, as1 + 5, as2, LongerThan3);
        for (int i = 0; i < p - as2; ++i)
               cout << as2[i];
        cout << endl;
        int * p2 = Filter(a1, a1 + 5, a2, LargerThan2);
        for (int i = 0; i < p2 - a2; ++i)//指针可以相减！！！
               cout << a2[i] << ",";
        return 0;
}
