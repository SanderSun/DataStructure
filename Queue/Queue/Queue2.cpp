#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int front, rear;
	int tag; //������е���ɾ��/����
}SqQueue;

void InitQueue1(SqQueue &Q)
{
	//��ʼ�� ��ͷ����βָ��ָ��0
	Q.front = Q.rear = 0;
	Q.tag = 0;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.front==Q.rear && Q.tag == 0)  //�ӿ��ж�
		return true;
	else
		return false;
}

//���
bool EnQueue(SqQueue &Q, int x)
{
	if (Q.front == Q.rear&&Q.tag == 1)
		return false; //�ж϶���
	Q.data[Q.rear] = x;	//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MaxSize; //��βָ���1ȡģ
	Q.tag == 1;
	return true;
}

//����
bool DeQueue(SqQueue &Q, int &x)
{
	if (Q.front==Q.rear && Q.tag == 0)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag=0;
	return true;
}

bool GetHead(SqQueue Q, int &x)
{
	if (Q.front == Q.rear && Q.tag == 0)
		return false;
	x = Q.data[Q.front];
	return true;
}

void testQueue()
{
	SqQueue Q; //����һ������
}