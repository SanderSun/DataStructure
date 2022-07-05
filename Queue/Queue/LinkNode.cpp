#include <stdlib.h>
#define ��ͷ���

#ifdef ��ͷ���
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
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//��Ԫ�����
void EnQueue(LinkQueue &Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s; //�½����뵽rear֮��
	Q.rear = s; //�޸ı�βָ��
}

//����
bool DeQueue(LinkQueue &Q, int &x)
{
	if (Q.front == Q.rear)
		return false; //�ն�
	LinkNode* p = Q.front->next;
	x = p->data;	//�ñ���x���ض�ͷԪ��
	Q.front->next = p->next; //�޸�ͷ����nextָ��
	if (Q.rear == p) //�˴������һ��������
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
	LinkQueue Q; //����һ������

	InitQueue(Q); //��ʼ������
}
#endif