// ConsoleApplication1（排序）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;
void insertsort(int r[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
	{
		r[0] = r[i];
		for (j = i - 1; r[0] < r[j]; j--)
			r[j + 1] = r[j];
		r[j + 1] = r[0];
	}
	cout << "直接插入排序结果为" << endl;
	for (j = 1; j <= n; j++)
		cout << r[j] << " ";
	cout << endl;
}
void bubblesort(int r[], int n)
{
	int exchange = n;
	int temp,j;
	while (exchange != 0)
	{
		int bound = exchange; exchange = 0;
		for(j=1;j<bound;j++)
			if (r[j] > r[j + 1])
			{
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
				exchange = j;
			}
	}
	cout << "冒泡排序结果为" << endl;
	for (j = 1; j <= n; j++)
		cout << r[j] << " ";
	cout << endl;
}

void selectsort(int r[], int n)
{
	int i,j,index,temp;
	for (i = 1; i < n; i++)
	{
		index = i;
		for (j = i + 1; j <= n; j++)
			if (r[j] < r[index])index = j;
		if (index != i)
		{
			temp = r[i];
			r[i] = r[index];
			r[index] = temp;
		}
	}
	cout << "选择排序结果为" << endl;
	for (j = 1; j <= n; j++)
		cout << r[j] << " ";
	cout << endl;
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BigHeadAdjust(int* arr, int index, int length)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (lchild<length && arr[lchild]>arr[max])
	{
		max = lchild;
	}
	if (rchild<length && arr[rchild]>arr[max])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap(&arr[max], &arr[index]);
		BigHeadAdjust(arr, max, length);
	}
	return;
}
int Kuaisupaixu(int* a, int low, int high)
{
	int temp = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= temp)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low <= temp])
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = temp;
	return low;
}
void zhu(int* a, int low, int high) {
	int middle;
	if (low < high)
	{
		middle = Kuaisupaixu(a, low, high);
		zhu(a, low, middle - 1);
		zhu(a, middle + 1, high);
	}
}
int main()
{
	int r[8] = { 0,12,15,9,20,6,31,24 };//第一个数为哨兵，不存在//
	selectsort(r, 7);
	bubblesort(r, 7);
	insertsort(r, 7);
	Kuaisupaixu(r, 1, 7);//快速排序
	zhu(r, 1, 7);
	cout << "快速排序结果为：" << endl;
	for (int i = 1; i < 8; i++) {
		cout << r[i] << " ";
	}
	cout << endl;
	cout << "堆排序结果为：" << endl;
	for (int i = 1; i < 8; i++) {
		cout << r[i] << " ";
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
