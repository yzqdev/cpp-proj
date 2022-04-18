#include <iostream>

#include "Algorithm.h"
using namespace std;
Algorithm::Algorithm()
{
	cout << "program started" << endl;
}

Algorithm::~Algorithm()
{
}

void Algorithm::bucketSort()
{
	const int arraylen = 1001;
	int mtimes = 0;
	int a[arraylen], i, j, t;
	for (i = 0; i <= arraylen; i++)
	{
		a[i] = 0;
	}//初始化为0
	for (i = 1; i <= 10; i++) //循环读入5个数
	{
		cin >> t;//把每一个数读到变量t中
		a[t]++; //进行计数
	}
	cout << "排序后:";
	for (i = 0; i <= arraylen; i++) {
		mtimes++;//依次判断a[0]~a[10]
		for (j = 1; j <= a[i]; j++) { //出现了几次就打印几次
			cout << i << " ";
			mtimes++;
		}
	}
	cout << "复杂度" << mtimes << endl;
}

void Algorithm::bubbleSort()
{
	const int arraylen = 100;
	int a[arraylen], i, j, t;
	int n = 10;
	int mtimes = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; i++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	cout << "排序后";
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "复杂度" << mtimes;
}

void Algorithm::quickSortMain()
{
	int i, j, t;

	const int n = 10; int a[n];
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	quickSort(1, n, a);
	cout << "排序后";
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
}

void Algorithm::quickSort(int left, int right, int a[])
{
	const int n = 10;

	int i, j, t, temp;
	if (left > right)
	{
		return;
	}
	temp = a[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右往左找
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		//再从左往右找
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		//交换两个数在数组中的位置
		if (i < j)//当哨兵i和哨兵j没有相遇时
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		//最终将基准数归位
		a[left] = a[i];
		a[i] = temp;
		quickSort(left, i - 1, a);//继续处理左边的，这里是一个递归的过程
		quickSort(i + 1, right, a);//继续处理右边的，这里是一个递归的过程
	}
}

void Algorithm::getBooks()
{
	int n = 10;
	int	i, t;
	const int arrlen = 1000;
	int	a[arrlen];
	for (i = 1; i <= arrlen - 1; i++)
	{
		a[i] = 0;
	} //初始化

	for (i = 1; i <= n; i++) //循环读入n个图书的ISBN号
	{
		cin >> t; //把每一个ISBN号读到变量t中
		a[t] = 1; //标记出现过的ISBN号
	}
	cout << "排序后";
	for (i = 1; i <= 1000; i++) //依次判断1~1000这个1000个桶
	{
		if (a[i] == 1)//如果这个ISBN号出现过则打印出来
		{
			cout << i << " ";
		}
	}
}