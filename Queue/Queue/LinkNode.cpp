#include <stdlib.h>
#define 带头结点

#ifdef 带头结点
typedef struct LinkNode // 链式队列结点
{
	int data;
	struct LinkNode *next;
}LinkNode;
 
typedef struct	//链式队列
{
	LinkNode *front, *rear; //队列的队头和队尾指针

}LinkQueue;

//初始化队列

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//新元素入队
void EnQueue(LinkQueue &Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s; //新结点插入到rear之后
	Q.rear = s; //修改表尾指针
}

//出队
bool DeQueue(LinkQueue &Q, int &x)
{
	if (Q.front == Q.rear)
		return false; //空队
	LinkNode* p = Q.front->next;
	x = p->data;	//用变量x返回队头元素
	Q.front->next = p->next; //修改头结点的next指针
	if (Q.rear == p) //此次是最后一个结点出队
		Q.rear = Q.front;
	free(p);
	return true;

}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool GetHead(LinkQueue Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.front->next->data;
	return true;
}

void testLinkQueue()
{
	LinkQueue Q; //声明一个队列

	InitQueue(Q); //初始化队列
}
#endif