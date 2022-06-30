#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define 不带头结点的单链表

#ifdef 不带头结点的单链表

typedef struct LNode{ 
	int data;
	struct LNode* next;
}LNode,*LinkList;

//初始化一个空的单链表
bool InitList(LinkList &L)
{
	L = NULL;
	return true;
}

//判断单链表是否为空
bool Empty(LinkList L)
{
	return (L == NULL);
}

//指定位点插入元素
bool ListInsert(LinkList &L, int i, int e)
{
	if (i < 1)
		return false;
	if (i == 1) //插入第一个结点的操作与其他结点操作不同
	{
		LNode *s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s; //头指针指向新结点
		return true;
	}
	LNode *p;  // 指针p指向当前扫描到的结点
	int j = 1; // 当前p指向的是第几个结点
	p = L; //p指向第1个结点（注意：不是头结点）
	while (p != NULL&&j<i-1) //循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL) //i值不合法
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; // 插入成功
}

//后插操作：在p结点之后插入元素e
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

//前插操作：在p结点之前插入元素e
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

//按位序删除
bool ListDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
		return false;
	LNode* p;	//指针p指向单曲扫描到的结点
	int j = 0;	//当前p指向的是第几个结点
	p = L;	//L指向头结点，头结点是第0个结点(不存数据)
	while (p!=NULL&&j<i-1) //循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)	//i值不合法
		return false;
	if (p->next == NULL) //第i-1个结点之后已无其他结点
		return false;
	LNode* q = p->next; //令q指向被删除的结点
	e = q->data;	//用e返回元素的值
	p->next = q->next; //将*q结点从链中断开
	free(q); //释放结点的存储空间
	return true;
}

//删除指定结点p
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

//按位查找，返回第i个元素
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

//按值查找，找到数据域==e的结点
LNode* LocateElem(LinkList L, int e)
{
	LNode* p = L->next;
	//从第一个结点开始查找数据域为e的结点
	while (p != NULL && p->data != 8)
	{
		p = p->next;
	}
	return p;
}

//求表的长度 
int Length(LinkList L)
{
	int Len = 0; //统计表长
	LNode* p = L;
	while (p->next != NULL)
	{	
		p = p->next;
		Len++;
	}
	return Len;
}

//尾插法建立单链表
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

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L) //逆向建立单链表
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));//创建头结点
	L->next = NULL;
	scanf("%d", &x);	//输入结点的值
	while (x!=9999)		//输入9999表示结束
	{
		s = (LNode*)malloc(sizeof(LNode)); //创建新结点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}


void test()
{
	LinkList L; //声明一个指向单链表的指针
	//初始化一个空表
	InitList(L);
}

#endif

#define 带头结点的单链表

#ifdef 带头结点的单链表

typedef struct LNode{ //定义单链表结点类型
	int data; //每个结点存放一个数据元素
	struct LNode* next; //指针指向下一个节点
}LNode, *LinkList;

//初始化一个的单链表(带头结点)
bool InitList(LinkList &L)
{
	L = (LNode*)malloc(sizeof(LNode)); //分配一个头结点
	if (L == NULL)  //内存不足，分配失败
		return false;
	L->next = NULL; //头结点之后暂时还没有节点
	return true;
}

//判断单链表是否为空（带头结点）
bool Empty(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

//在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, int e)
{  
	if (i < 1)
		return false;
	LNode *p; //指针p指向当前扫描到的结点
	int j = 0; //当前p指向的是第几个结点
	p = L;
	while (p != NULL&&j<i-1) //循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL) //i值不合法
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;  //将结点s连到p之后
	return true; //插入成功
}

void test()
{
	LinkList L; //声明一个指向单链表的指针

	//初始化一个的单链表(带头结点)
	InitList(L);

	//判断单链表是否为空（带头结点）
	Empty(L);

}

#endif