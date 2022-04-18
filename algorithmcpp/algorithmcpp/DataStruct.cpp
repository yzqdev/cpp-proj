#include "DataStruct.h"
#include <iostream>
using namespace std;

DataStruct::DataStruct()
{
	cout << "datastruct started" << endl;
}

DataStruct::~DataStruct()
{
	 
	cout << "数据算法";
}
void DataStruct::getQueue()
{
	struct queue
	{
		int data[100];//队列的主体，用来存储内容
		int head;//队首
		int tail;//队尾
	} q;
	//int q[102] = { 0,6,3,1,7,5,8,9,2,4 }, head, tail;

	int i;
	//初始化队列
	q.head = 1;
	q.tail = 1;
	for (i = 1; i <= 9; i++)
	{
		//依次向队列插入9个数
		cin >> q.data[q.tail];
		//scanf("%d", &q.data[q.tail]);
		q.tail++;
	}
	cout << "队列的数值是";
	while (q.head < q.tail) //当队列不为空的时候执行循环
	{
		//打印队首并将队首出队
		cout << q.data[q.head];
		q.head++;

		//先将新队首的数添加到队尾
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//再将队首出队
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

	len = strlen(a); //求字符串的长度
	mid = len / 2 - 1; //求字符串的中点

	top = 0;//栈的初始化
	//将mid前的字符依次入栈
	for (i = 0; i <= mid; i++)
		s[++top] = a[i];

	//判断字符串的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
	if (len % 2 == 0)
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}

	//开始匹配
	for (i = next; i <= len - 1; i++) {
		if (a[i] != s[top])
			break;
		top--;
	}

	//如果top的值为0，则说明栈内所有的字符都被一一匹配了
	if (top == 0)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
}