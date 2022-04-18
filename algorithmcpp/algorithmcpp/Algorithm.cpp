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
	}//��ʼ��Ϊ0
	for (i = 1; i <= 10; i++) //ѭ������5����
	{
		cin >> t;//��ÿһ������������t��
		a[t]++; //���м���
	}
	cout << "�����:";
	for (i = 0; i <= arraylen; i++) {
		mtimes++;//�����ж�a[0]~a[10]
		for (j = 1; j <= a[i]; j++) { //�����˼��ξʹ�ӡ����
			cout << i << " ";
			mtimes++;
		}
	}
	cout << "���Ӷ�" << mtimes << endl;
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
	cout << "�����";
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "���Ӷ�" << mtimes;
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
	cout << "�����";
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
	temp = a[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ��Ҫ�ȴ���������
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		//�ٴ���������
		while (a[i] <= temp && i < j)
		{
			i++;
		}
		//�����������������е�λ��
		if (i < j)//���ڱ�i���ڱ�jû������ʱ
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		//���ս���׼����λ
		a[left] = a[i];
		a[i] = temp;
		quickSort(left, i - 1, a);//����������ߵģ�������һ���ݹ�Ĺ���
		quickSort(i + 1, right, a);//���������ұߵģ�������һ���ݹ�Ĺ���
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
	} //��ʼ��

	for (i = 1; i <= n; i++) //ѭ������n��ͼ���ISBN��
	{
		cin >> t; //��ÿһ��ISBN�Ŷ�������t��
		a[t] = 1; //��ǳ��ֹ���ISBN��
	}
	cout << "�����";
	for (i = 1; i <= 1000; i++) //�����ж�1~1000���1000��Ͱ
	{
		if (a[i] == 1)//������ISBN�ų��ֹ����ӡ����
		{
			cout << i << " ";
		}
	}
}