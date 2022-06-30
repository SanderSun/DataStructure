#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#define ѭ��������
#ifdef ѭ��������

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*LinkList;

//��ʼ��һ��ѭ��������
bool InitList(LinkList &L)
{
	L = (LNode*)malloc(sizeof(LNode));  //����һ��ͷ���
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

//�ж�ѭ���������Ƿ�Ϊ��
bool Empty(LinkList L)
{
	if (L->next == L)
		return true;
	else
		return false;
}

//�жϽ��p�Ƿ�Ϊѭ��������ı�β���
bool isTail(LinkList L, LNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;
}

#endif

#define ѭ��˫����
#ifdef ѭ��˫����

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;

//��ʼ���յ�ѭ��˫����
bool InitDLinkList(DLinkList &L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = L; //ͷ����priorָ��ͷ���
	L->next = L;	//ͷ����nextָ��ͷ���
	return true;
}

bool Empty(DLinkList L)
{
	if (L->next == L)
		return true;
	else
		return false;
}

//�жϽ��p�Ƿ�Ϊѭ��˫����ı�β���
bool isTail(DLinkList L, DNode* p)
{
	if (p->next == L)
		return true;
	else
		return false;
}

//��p���֮�����s���
bool InsertNextDNode(DNode* p, DNode* s)
{
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
}

//ɾ��p�ĺ�̽��
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
	//��ʼ��ѭ��˫����
	DLinkList L; //����һ��ͷָ��
	InitDLinkList(L);
}

#endif