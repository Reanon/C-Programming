#include<iostream>
using namespace std;
void swap(int* &a, int * &b) {  //作业提交：int* &a, int * &b
	int *tep = a;
	a = b;
	b = tep;
}

int main()
{	

	int a = 3, b = 5;
	int *pa = &a;
	int *pb = &b;
	swap(pa, pb);
	cout << *pa << "," << *pb;
    return 0;
}
