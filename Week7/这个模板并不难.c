
// week7_06.cpp: 定义控制台应用程序的入口点。
//
/*  程序填空，输出指定结果
输入
多组数据。每组第一行是一个不含空格的字符串
第二行是整数n
第三行是n个整数
输出
对每组数据，先依次输出输入字符串的每个字母，并且在每个字母后面加逗号
然后依次再输出输入的n个整数 ，在每个整数后面加逗号
样例输入
Tom
3
3 4 5
Jack
4
1 2 3 4
样例输出
T,o,m,
3,4,5,
J,a,c,k,
1,2,3,4,
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>
class myclass {
        // 在此处补充你的代码
public:
        T * p;
        int size;
        myclass(T * str, int s) {//这里还可以加条件判断，还是不要弄得那么复杂的好
               p = new T[s];
               size = s;
               memcpy(p, str,sizeof(T)*s);
        }
        // 在此处补充你的代码
        ~myclass() {
               delete[] p;
        }
        void Show()
        {
               for (int i = 0; i < size; i++) {
                       cout << p[i] << ",";
               }
               cout << endl;
        }
};
int a[100];
int main() {
        char line[100];
        while (cin >> line) {
               myclass<char> obj(line, strlen(line));;
               obj.Show();
               int n;
               cin >> n;
               for (int i = 0; i < n; ++i)
                       cin >> a[i];
               myclass<int> obj2(a, n);
               obj2.Show();
        }
        return 0;
}
