#define MaxSize 10

typedef struct
{
	int data[MaxSize];
	int front, rear;
	int size; //���е�ǰ����
}SqQueue;

void InitQueue1(SqQueue &Q)
{
	//��ʼ�� ��ͷ����βָ��ָ��0
	Q.front = Q.rear = 0;
	Q.size = 0;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.size==0)  //�ӿղ���
		return true;
	else
		return false;
}

bool EnQueue(SqQueue &Q, int x)
{
	if (Q.size==MaxSize)
		return false; //�ж϶���
	Q.data[Q.rear] = x;	//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MaxSize; //��βָ���1ȡģ
	Q.size++;
	return true;
}

bool DeQueue(SqQueue &Q, int &x)
{
	if (Q.size == 0)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.size--;
	return true;
}

bool GetHead(SqQueue Q, int &x)
{
	if (Q.size == 0)
		return false;
	x = Q.data[Q.front];
	return true;
}

void testQueue()
{
	SqQueue Q; //����һ������
}