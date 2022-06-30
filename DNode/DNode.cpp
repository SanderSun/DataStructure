#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#define 带头结点的双链表
#ifdef 带头结点的双链表


typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;

//初始化双链表
bool InitDLinkList(DLinkList &L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

//判断双链表是否为空
bool Empty(DLinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next; //找到p的后继结点q
	if (q == NULL)
		return false;	//p没有后继结点
	p->next = q->next;
	if (q->next != NULL)	//q结点不是最后一个结点
		q->next->prior = p;
	free(q);	//释放结点空间
	return true;

}

void DestoryList(DLinkList &L)
{
	//循环释放各个数据结点
	while (L->next != NULL)
		DeleteNextDNode(L);
	free(L);	//释放头结点
	L = NULL; //头指针指向NULL
}

void testDLinkList()
{
	//初始化双链表
	DLinkList L;
	InitDLinkList(L);


}

#endif