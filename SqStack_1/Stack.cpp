#define _CRT_SECURE_NO_WARNINGS 1

#define MaxSize 10  //����ջ��Ԫ�ص�������
typedef struct
{
	int data[MaxSize]; //��̬������ջ��Ԫ��  
	int top;	//ջ��ָ��
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S)
{
	S.top = -1;		//��ʼ��ջ��ָ��
}

//�ж�ջ��
bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;	//ջ��
	else
		return false;	//����
}

//��Ԫ����ջ
bool Push(SqStack &S, int x)
{
	if (S.top == MaxSize - 1)
		return false;	//ջ��������
	//S.top = S.top + 1; //ָ���ȼ�1
	//S.data[S.top] = x; //��Ԫ����ջ
	S.data[++S.top] = x;
	return true;
}

//��ջ����
bool Pop(SqStack &S, int &x)
{
	if (S.top == -1)	//ջ�գ�����
		return false;
	//x = S.data[S.top]; //ջ��Ԫ���ȳ�ջ
	//S.top = S.top - 1; //ָ���ټ�1
	x = S.data[S.top--];

	return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack S, int &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}


void testStack()
{
	SqStack S; //����һ��˳��ջ(����ռ�)
	InitStack(S);
}


#define ����ջ
#ifdef ����ջ
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
//ջ������
//top0 + 1 == top1
#endif

#define ջ����ʽ�洢�ṹ //����ͷ���
#ifdef ջ����ʽ�洢�ṹ


#endif