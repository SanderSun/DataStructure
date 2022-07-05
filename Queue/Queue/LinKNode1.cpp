#include <stdlib.h>

#define ����ͷ���Ķ���

#ifdef ����ͷ���Ķ���
typedef struct LinkNode // ��ʽ���н��
{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct	//��ʽ����
{
	LinkNode *front, *rear; //���еĶ�ͷ�Ͷ�βָ��

}LinkQueue;

//��ʼ������
void InitQueue(LinkQueue &Q)
{
	Q.front = NULL;
	Q.rear = NULL;
}

//��Ԫ�����
void EnQueue(LinkQueue &Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)	//�ڿն����в����һ��Ԫ��
	{
		Q.front = s;	//�޸Ķ�ͷ��βָ��
		Q.rear = s;
	}
	else{
		Q.rear->next = s;	//�½����뵽rear���֮��
		Q.rear = s;		//�޸� rear ָ��
	}
}

//��ͷԪ�س���(����ͷ���)
bool DeQueue(LinkQueue &Q, int &x)
{
	if (Q.front == NULL)
		return false;
	LinkNode* p = Q.front;	//pָ��ָ��˴γ��ӵĽ��
	x = p->data;	//�ñ���x���ض�ͷԪ��
	Q.front = p->next;	//�޸� front ָ��
	if (Q.rear == p){	//�˴������һ��������
		//Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);	//�ͷŽ��ռ�
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
	LinkQueue Q; //����һ������
	InitQueue(Q); //��ʼ������
}
#endif