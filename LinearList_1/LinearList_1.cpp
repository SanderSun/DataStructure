#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define ��̬����
#ifdef ��̬����

#define MaxSize 10 //������󳤶�
#define PRINT(I,E) printf("��ɾ����"#I"��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",E)

typedef struct{
	int data[MaxSize]; //�þ�̬�ġ����顱�������Ԫ��
	int length; //˳���ĵ�ǰ����
}SqList; //˳�������Ͷ���
//��������--��ʼ��һ��˳���

void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0; //�����е�����Ԫ������ΪĬ�ϳ�ʼֵ
	L.length = 0; //˳����ʼ����Ϊ0
}

bool ListInsert(SqList &L, int i, int e)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--) //����i��Ԫ�ؼ�֮���Ԫ�غ���
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; //��λ��i������e
	L.length++; //���ȼ�1
	return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
	if (i<1 || i>L.length) //�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	e = L.data[i - 1]; // ����ɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j]; //����i��λ�ú��Ԫ��ǰ��
	L.length--;
	return true;
}

//��˳���L�в��ҵ�һ��Ԫ��ֵ����e��Ԫ�أ���������λ��
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i + 1;
	}
	return 0;
}

int main()
{
	SqList L; //����һ��˳���

	InitList(L); //��ʼ��˳���

	bool b = ListInsert(L, 3, 3); //��˳���ָ��λ�ò���Ԫ��
	printf("%d\n", b);

	int e = -1; //�ñ���e��ɾ����Ԫ�ء���������
	if (ListDelete(L, 3, e))
		PRINT(3, e);
	else
		printf("λ��%d���Ϸ���ɾ��ʧ��\n",3);

	LocateElem(L, 9);
	return 0;
}

#endif

//#define ��̬����
#ifdef ��̬����

#define InitSize 10
typedef struct{
	int *data;
	int Maxsize;
	int Length;
}SeqList;

void InitList(SeqList &L)
{
	L.data = (int*)malloc(InitSize*sizeof(int));
	L.Length = 0;
	L.Maxsize = InitSize;
}

void IncreaseSize(SeqList &L, int len)
{
	int* p = L.data;
	L.data = (int*)malloc((L.Maxsize + len)*sizeof(int));
	for (int i = 0; i < L.Length; i++)
	{
		L.data[i] = p[i]; //�����ݸ��Ƶ�������
	}
	L.Maxsize = L.Maxsize + len; //˳�����󳤶�����len
	free(p); //�ͷ�ԭ�����ڴ�ռ�
}

int main()
{
	SeqList L;
	InitList(L);
	//...��˳����������뼸��Ԫ��

	///��̬��������ĳ���
	IncreaseSize(L, 5);
	return 0;
}

#endif