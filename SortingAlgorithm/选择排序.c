#include<iostream>
using namespace std;
/*
选择排序的思想：如果有N个元素需要排序，那么首先从N个元素中找到最小的那个（称为第0小的）放在第0个位置上（和原来第0个位置的元素交换）
然后再从剩下的N-1个元素中找到最小的放在第1个位置上，之后再从剩下的N-2的元素中找到最小的放在第2个位置上……
直到剩下两个，这两个是有序的，这也就是只循环N-1次的原因。
*/
void SelectionSort(int a[], int Size = 6) {
	for (int i = 0; i < Size-1; i++)  //从前到后排序的。从小到大，
	{
		int MinIndex = i;   //记录第i个到size-1个元素中最小元素的下标
		for (int j =  i+1; j < Size; j++) //从第i+1个开始找小于第i个元素的值，默认前面i-1个已经排好了序。
		{
			if (a[j]<a[MinIndex])
			{
				MinIndex = j;
			}
		}
		if (MinIndex!=i)
		{
			int tem = a[MinIndex];
			a[MinIndex] = a[i];
			a[i] = tem;
		}
	}
}

int main()
{
	int a[6] = { 6,5,4,3,2,1 };
	SelectionSort(a);
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
    return 0;
}
