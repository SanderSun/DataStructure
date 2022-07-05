#include <stdlib.h>

#define 不带头结点的队列

#ifdef 不带头结点的队列
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
	Q.front = NULL;
	Q.rear = NULL;
}

//新元素入队
void EnQueue(LinkQueue &Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)	//在空队列中插入第一个元素
	{
		Q.front = s;	//修改队头队尾指针
		Q.rear = s;
	}
	else{
		Q.rear->next = s;	//新结点插入到rear结点之后
		Q.rear = s;		//修改 rear 指针
	}
}

//队头元素出队(不带头结点)
bool DeQueue(LinkQueue &Q, int &x)
{
	if (Q.front == NULL)
		return false;
	LinkNode* p = Q.front;	//p指针指向此次出队的结点
	x = p->data;	//用变量x返回队头元素
	Q.front = p->next;	//修改 front 指针
	if (Q.rear == p){	//此次是最后一个结点出队
		//Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);	//释放结点空间
	return true;
}

bool GetHead(LinkQueue Q, int &x)
{
	if (Q.front == NULL)
		return false;
	x = Q.front->data;
	return true;
}


bool IsEmpty(LinkQueue Q)
{
	if (Q.front == NULL)
		return true;
	else
		return false;
}


void testLinkQueue()
{
	LinkQueue Q; //声明一个队列
	InitQueue(Q); //初始化队列
}
#endif