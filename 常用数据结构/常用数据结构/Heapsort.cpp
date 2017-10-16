#include<iostream>
using namespace std;
void MinHeapFixup(int a[], int i)
{
	int j, temp;
	temp = a[i];
	j = (i - 1) / 2;//���ڵ�
	while (j >= 0 && i != 0)
	{
		if (a[j] <= temp)break;
		a[i] = a[i];//���ڵ�ϴ�ʱ
		i = j;
		j = (i - 1) / 2;
	}
	a[i] = temp;
}
void MinHeapFixdown(int a[], int i, int n)
{//�µ�
	int j, temp;
	j = 2 * i + 1;
	temp = a[i];
	while (j < n)
	{
		if (j + 1 < n && a[j + 1] < a[j])//�����Һ�����Ѱ����С��
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
//������С��
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixdown(a, i, n);
}
void MinHeapsort(int a[], int n)
{//������
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