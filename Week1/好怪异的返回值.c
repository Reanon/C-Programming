#include<iostream>
using namespace std;

int& getElment(int *a, int i) {  //作业提交：int&
	return a[i];
}

int main() {

	int a[] = { 1,2,3 };
	getElment(a, 1) = 10;
	cout << a[1] << endl;
	return 0;
	
}
