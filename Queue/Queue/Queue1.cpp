#define MaxSize 10

typedef struct
{
	int data[MaxSize];
	int front, rear;
	int size; //队列当前长度
}SqQueue;

void InitQueue1(SqQueue &Q)
{
	//初始化 队头、队尾指针指向0
	Q.front = Q.rear = 0;
	Q.size = 0;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.size==0)  //队空操作
		return true;
	else
		return false;
}

bool EnQueue(SqQueue &Q, int x)
{
	if (Q.size==MaxSize)
		return false; //判断队满
	Q.data[Q.rear] = x;	//新元素插入队尾
	Q.rear = (Q.rear + 1) % MaxSize; //队尾指针加1取模
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
	SqQueue Q; //声明一个队列
}