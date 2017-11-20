#include<iostream>
using namespace std;
/*
冒泡排序思想：在排序过程中对元素进行两两比较，越小的元素会经由交换慢慢“浮”到数组的前面（低下标处），像气泡一样慢慢浮起，由此得名。
*/
void Bubblesort(int a[], int n=6) {
	for (int i = 0; i < n-1; i++)  //控制排序的趟数。
	{
		for (int j = n-1; j > i; j--) // 从后往前，两两比较，若后一个小就被交换到前面。
		{
			if (a[j]<a[j-1])
			{
				int tem = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tem;
			}
		}
	}

}

int main()
{
	//int n, a[100] = {0};
	//scanf("%d", &n);
	//for (int i = 0; i < n; i++)
	//{
	//	scanf("%d", &a[i]);
	//}

	int b[] = { 6,5,4,3,2,1 };
	Bubblesort(b);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", b[i]);
	}
    return 0;
}
