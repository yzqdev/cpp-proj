#include "DataStruct.h"
#include <iostream>
using namespace std;

DataStruct::DataStruct()
{
	cout << "datastruct started" << endl;
}

DataStruct::~DataStruct()
{
	 
	cout << "�����㷨";
}
void DataStruct::getQueue()
{
	struct queue
	{
		int data[100];//���е����壬�����洢����
		int head;//����
		int tail;//��β
	} q;
	//int q[102] = { 0,6,3,1,7,5,8,9,2,4 }, head, tail;

	int i;
	//��ʼ������
	q.head = 1;
	q.tail = 1;
	for (i = 1; i <= 9; i++)
	{
		//��������в���9����
		cin >> q.data[q.tail];
		//scanf("%d", &q.data[q.tail]);
		q.tail++;
	}
	cout << "���е���ֵ��";
	while (q.head < q.tail) //�����в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		//��ӡ���ײ������׳���
		cout << q.data[q.head];
		q.head++;

		//�Ƚ��¶��׵�����ӵ���β
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//�ٽ����׳���
		q.head++;
	}
}

void DataStruct::getPlalindrome()
{
	char a[101], s[101];
	int i, len, mid, next, top;
	for (i = 1; i <= 5; i++)
	{
		cin >> a;
	}

	len = strlen(a); //���ַ����ĳ���
	mid = len / 2 - 1; //���ַ������е�

	top = 0;//ջ�ĳ�ʼ��
	//��midǰ���ַ�������ջ
	for (i = 0; i <= mid; i++)
		s[++top] = a[i];

	//�ж��ַ����ĳ�������������ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
	if (len % 2 == 0)
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}

	//��ʼƥ��
	for (i = next; i <= len - 1; i++) {
		if (a[i] != s[top])
			break;
		top--;
	}

	//���top��ֵΪ0����˵��ջ�����е��ַ�����һһƥ����
	if (top == 0)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
}