#define Maxsize 10
#define ջ������ƥ���е�Ӧ��

#ifdef ջ������ƥ���е�Ӧ��

typedef struct{	//����ջ��Ԫ�ص�������
	char data[Maxsize]; //��̬������ջ��Ԫ��
	int top; //ջ��ָ��
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S)

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S){

}

//��Ԫ����ջ
bool Push(SqStack &S, char x){

}

// ջ��Ԫ�س�ջ����x����
bool Pop(SqStack &S, char &x)
{

}


bool bracketCheck(char str[], int length){
	SqStack S;
	InitStack(S); //��ʼ��һ��ջ
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
			Push(S, str[i]); //ɨ�赽�����ţ���ջ
		}
		else{
			if (StackEmpty(S)) //ɨ�赽�����ţ��ҵ�ǰջ��
				return false; //ƥ��ʧ��

			char topElem;
			Pop(S, topElem); //ջ��Ԫ�س�ջ
			if (str[i] == ')'&&topElem != '(')
				return false;
			if (str[i] == ']'&&topElem != '[')
				return false;
			if (str[i] == '}'&&topElem != '{')
				return false;
		}
	}
	return StackEmpty(S);
}
#endif