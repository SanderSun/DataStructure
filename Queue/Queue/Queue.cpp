#include <stdio.h>

#define MaxSize 10 //���������Ԫ�ص�������
typedef struct
{
	int data[MaxSize];	//�þ�̬�����Ŷ���Ԫ��
	int front, rear;	//��ͷָ��Ͷ�βָ��
}SqQueue;

void InitQueue(SqQueue &Q)
{
	//��ʼ�� ��ͷ����βָ��ָ��0
	Q.front = Q.rear = 0;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)  //�ӿղ���
		return true;
	else
		return false;
}

//���
bool EnQueue(SqQueue &Q, int x)
{
	if ((Q.rear+1)%MaxSize==Q.front) 
		return false; //�ж϶���
	Q.data[Q.rear] = x;	//��Ԫ�ز����β
	Q.rear = (Q.rear + 1)%MaxSize; //��βָ���1ȡģ
	return true;
}

//����
bool DeQueue(SqQueue &Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//��ȡ��ͷԪ�� 
bool GetHead(SqQueue Q, int &x)
{
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	return true;
}

void testQueue()
{
	SqQueue Q; //����һ������
}

