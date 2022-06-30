#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#define ��ͷ����˫����
#ifdef ��ͷ����˫����


typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;

//��ʼ��˫����
bool InitDLinkList(DLinkList &L)
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

//�ж�˫�����Ƿ�Ϊ��
bool Empty(DLinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

//��p���֮�����s���
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

//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL)
		return false;
	DNode* q = p->next; //�ҵ�p�ĺ�̽��q
	if (q == NULL)
		return false;	//pû�к�̽��
	p->next = q->next;
	if (q->next != NULL)	//q��㲻�����һ�����
		q->next->prior = p;
	free(q);	//�ͷŽ��ռ�
	return true;

}

void DestoryList(DLinkList &L)
{
	//ѭ���ͷŸ������ݽ��
	while (L->next != NULL)
		DeleteNextDNode(L);
	free(L);	//�ͷ�ͷ���
	L = NULL; //ͷָ��ָ��NULL
}

void testDLinkList()
{
	//��ʼ��˫����
	DLinkList L;
	InitDLinkList(L);


}

#endif