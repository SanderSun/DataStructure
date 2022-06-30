#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>

#define 静态链表
#ifdef 静态链表
#define MaxSize 10 //静态链表的最大长度
typedef struct Node
{
	int data;
	int next;
}SLinkList[MaxSize];

void testSLinkList()
{
	SLinkList a; //数组a作为静态链表
}
 
#endif