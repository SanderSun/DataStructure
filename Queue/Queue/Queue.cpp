#include <stdio.h>

#define MaxSize 10 //定义队列中元素的最大个数
typedef struct
{
	int data[MaxSize];	//用静态数组存放队列元素
	int front, rear;	//队头指针和队尾指针
}SqQueue;

void InitQueue(SqQueue &Q)
{
	//初始化 队头、队尾指针指向0
	Q.front = Q.rear = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)  //队空操作
		return true;
	else
		return false;
}

//入队
bool EnQueue(SqQueue &Q, int x)
{
	if ((Q.rear+1)%MaxSize==Q.front) 
		return false; //判断队满
	Q.data[Q.rear] = x;	//新元素插入队尾
	Q.rear = (Q.rear + 1)%MaxSize; //队尾指针加1取模
	return true;
}

//出队
bool DeQueue(SqQueue &Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//获取队头元素 
bool GetHead(SqQueue Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	return true;
}

void testQueue()
{
	SqQueue Q; //声明一个队列
}

