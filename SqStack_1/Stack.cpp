#define _CRT_SECURE_NO_WARNINGS 1

#define MaxSize 10  //定义栈中元素的最大个数
typedef struct
{
	int data[MaxSize]; //静态数组存放栈中元素  
	int top;	//栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
	S.top = -1;		//初始化栈顶指针
}

//判断栈空
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;	//栈空
	else
		return false;	//不空
}

//新元素入栈
bool Push(SqStack &S, int x)
{
	if (S.top == MaxSize - 1)
		return false;	//栈满，报错
	//S.top = S.top + 1; //指针先加1
	//S.data[S.top] = x; //新元素入栈
	S.data[++S.top] = x;
	return true;
}

//出栈操作
bool Pop(SqStack &S, int &x)
{
	if (S.top == -1)	//栈空，报错
		return false;
	//x = S.data[S.top]; //栈顶元素先出栈
	//S.top = S.top - 1; //指针再减1
	x = S.data[S.top--];

	return true;
}

//读栈顶元素
bool GetTop(SqStack S, int &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}


void testStack()
{
	SqStack S; //声明一个顺序栈(分配空间)
	InitStack(S);
}


#define 共享栈
#ifdef 共享栈
typedef struct
{
	int data[MaxSize];
	int top0;
	int top1;
}ShStack;

void InitShStack(ShStack &S)
{
	S.top0 = -1;
	S.top1 = MaxSize;
}
//栈满条件
//top0 + 1 == top1
#endif

#define 栈的链式存储结构 //不带头结点
#ifdef 栈的链式存储结构


#endif