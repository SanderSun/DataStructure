#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int front, rear;
	int tag; //最近进行的是删除/插入
}SqQueue;

void InitQueue1(SqQueue &Q)
{
	//初始化 队头、队尾指针指向0
	Q.front = Q.rear = 0;
	Q.tag = 0;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.front==Q.rear && Q.tag == 0)  //队空判断
		return true;
	else
		return false;
}

//入队
bool EnQueue(SqQueue &Q, int x)
{
	if (Q.front == Q.rear&&Q.tag == 1)
		return false; //判断队满
	Q.data[Q.rear] = x;	//新元素插入队尾
	Q.rear = (Q.rear + 1) % MaxSize; //队尾指针加1取模
	Q.tag == 1;
	return true;
}

//出队
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
	SqQueue Q; //声明一个队列
}