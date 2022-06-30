#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#define 循环单链表
#ifdef 循环单链表

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//初始化一个循环单链表
bool InitList(LinkList &L)
{
	L = (LNode*)malloc(sizeof(LNode));  //分配一个头结点
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

//判断循环单链表是否为空
bool Empty(LinkList L)
{
	if (L->next == L)
		return true;
	else
		return false;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(LinkList L, LNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;
}

#endif

#define 循环双链表
#ifdef 循环双链表

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;

//初始化空的循环双链表
bool InitDLinkList(DLinkList &L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = L; //头结点的prior指向头结点
	L->next = L;	//头结点的next指向头结点
	return true;
}

bool Empty(DLinkList L)
{
	if (L->next == L)
		return true;
	else
		return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}

//删除p的后继结点
bool DeleteNextDNode(DNode* p)
{
	DNode* q;
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
}

void testDLinkList()
{
	//初始化循环双链表
	DLinkList L; //声明一个头指针
	InitDLinkList(L);
}

#endif