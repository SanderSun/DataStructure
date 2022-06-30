#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define ����ͷ���ĵ�����

#ifdef ����ͷ���ĵ�����

typedef struct LNode{ 
	int data;
	struct LNode* next;
}LNode,*LinkList;

//��ʼ��һ���յĵ�����
bool InitList(LinkList &L)
{
	L = NULL;
	return true;
}

//�жϵ������Ƿ�Ϊ��
bool Empty(LinkList L)
{
	return (L == NULL);
}

//ָ��λ�����Ԫ��
bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
		return false;
	if (i == 1) //�����һ�����Ĳ�����������������ͬ
	{
		LNode *s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s; //ͷָ��ָ���½��
		return true;
	}
	LNode *p;  // ָ��pָ��ǰɨ�赽�Ľ��
	int j = 1; // ��ǰpָ����ǵڼ������
	p = L; //pָ���1����㣨ע�⣺����ͷ��㣩
	while (p != NULL&&j<i-1) //ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL) //iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; // ����ɹ�
}

//����������p���֮�����Ԫ��e
bool InsertNextNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

//��λ��ɾ��
bool ListDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
		return false;
	LNode* p;	//ָ��pָ����ɨ�赽�Ľ��
	int j = 0;	//��ǰpָ����ǵڼ������
	p = L;	//Lָ��ͷ��㣬ͷ����ǵ�0�����(��������)
	while (p!=NULL&&j<i-1) //ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)	//iֵ���Ϸ�
		return false;
	if (p->next == NULL) //��i-1�����֮�������������
		return false;
	LNode* q = p->next; //��qָ��ɾ���Ľ��
	e = q->data;	//��e����Ԫ�ص�ֵ
	p->next = q->next; //��*q�������жϿ�
	free(q); //�ͷŽ��Ĵ洢�ռ�
	return true;
}

//ɾ��ָ�����p
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true; 
}

//��λ���ң����ص�i��Ԫ��
LNode* GetElem(LinkList L, int i)
{
	if (i < 0)
		return NULL;
	LNode* p;
	int j = 0;
	p = L;
	while (p!=NULL&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ���ң��ҵ�������==e�Ľ��
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L->next;
	//�ӵ�һ����㿪ʼ����������Ϊe�Ľ��
	while (p != NULL && p->data != 8)
	{
		p = p->next;
	}
	return p;
}

//���ĳ��� 
int Length(LinkList L)
{
	int Len = 0; //ͳ�Ʊ�
	LNode* p = L;
	while (p->next != NULL)
	{	
		p = p->next;
		Len++;
	}
	return Len;
}

//β�巨����������
LinkList List_TailInsert(LinkList &L)
{
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//ͷ�巨����������
LinkList List_HeadInsert(LinkList &L) //������������
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//����ͷ���
	L->next = NULL;
	scanf("%d", &x);	//�������ֵ
	while (x!=9999)		//����9999��ʾ����
	{
		s = (LNode*)malloc(sizeof(LNode)); //�����½��
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}


void test()
{
	LinkList L; //����һ��ָ�������ָ��
	//��ʼ��һ���ձ�
	InitList(L);
}

#endif

#define ��ͷ���ĵ�����

#ifdef ��ͷ���ĵ�����

typedef struct LNode{ //���嵥����������
	int data; //ÿ�������һ������Ԫ��
	struct LNode* next; //ָ��ָ����һ���ڵ�
}LNode, *LinkList;

//��ʼ��һ���ĵ�����(��ͷ���)
bool InitList(LinkList &L)
{
	L = (LNode*)malloc(sizeof(LNode)); //����һ��ͷ���
	if (L == NULL)  //�ڴ治�㣬����ʧ��
		return false;
	L->next = NULL; //ͷ���֮����ʱ��û�нڵ�
	return true;
}

//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

//�ڵ�i��λ�ò���Ԫ��e(��ͷ���)
bool ListInsert(LinkList &L, int i, int e)
{  
	if (i < 1)
		return false;
	LNode *p; //ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0; //��ǰpָ����ǵڼ������
	p = L;
	while (p != NULL&&j<i-1) //ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL) //iֵ���Ϸ�
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;  //�����s����p֮��
	return true; //����ɹ�
}

void test()
{
	LinkList L; //����һ��ָ�������ָ��

	//��ʼ��һ���ĵ�����(��ͷ���)
	InitList(L);

	//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩
	Empty(L);

}

#endif