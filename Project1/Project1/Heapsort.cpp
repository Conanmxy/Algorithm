#include<iostream>
using namespace std;
void MinHeapFixup(int a[], int i)
{
	int j, temp;
	temp = a[i];
	j = (i - 1) / 2;//父节点
	while (j >= 0 && i != 0)
	{
		if (a[j] <= temp)break;
		a[i] = a[i];//父节点较大时
		i = j;
		j = (i - 1) / 2;
	}
	a[i] = temp;
}
void MinHeapFixdown(int a[], int i, int n)
{//下调
	int j, temp;
	j = 2 * i + 1;
	temp = a[i];
	while (j < n)
	{
		if (j + 1 < n && a[j + 1] < a[j])//在左右孩子中寻找最小的
			j++;
		if (a[j] >= temp)
			break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = temp;
}
void MakeMinHeap(int a[], int n)
//建立最小堆
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixdown(a, i, n);
}
void MinHeapsort(int a[], int n)
{//堆排序
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[i], a[0]);
		MinHeapFixdown(a, 0, i);
	}
}
int main()
{
	int a[5] = { 2,6,4,3,1 };
	MakeMinHeap(a, 5);
	MinHeapsort(a, 5);
	for (int i = 0; i < 5; i++)
		cout << a[i] << endl;
}