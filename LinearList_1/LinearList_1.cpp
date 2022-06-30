#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define 静态分配
#ifdef 静态分配

#define MaxSize 10 //定义最大长度
#define PRINT(I,E) printf("已删除第"#I"个元素，删除元素值为%d\n",E)

typedef struct{
	int data[MaxSize]; //用静态的“数组”存放数据元素
	int length; //顺序表的当前长度
}SqList; //顺序表的类型定义
//基本操作--初始化一个顺序表

void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; i++)
		L.data[i] = 0; //将所有的数据元素设置为默认初始值
	L.length = 0; //顺序表初始长度为0
}

bool ListInsert(SqList &L, int i, int e)
{
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--) //将第i个元素及之后的元素后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; //在位置i处放入e
	L.length++; //长度加1
	return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
	if (i<1 || i>L.length) //判断i的范围是否有效
		return false;
	e = L.data[i - 1]; // 将被删除的元素赋值给e
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j]; //将第i个位置后的元素前移
	L.length--;
	return true;
}

//在顺序表L中查找第一个元素值等于e的元素，并返回其位序
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
	SqList L; //声明一个顺序表

	InitList(L); //初始化顺序表

	bool b = ListInsert(L, 3, 3); //向顺序表指定位置插入元素
	printf("%d\n", b);

	int e = -1; //用变量e把删除的元素“带回来”
	if (ListDelete(L, 3, e))
		PRINT(3, e);
	else
		printf("位序%d不合法，删除失败\n",3);

	LocateElem(L, 9);
	return 0;
}

#endif

//#define 动态分配
#ifdef 动态分配

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
		L.data[i] = p[i]; //将数据复制到新区域
	}
	L.Maxsize = L.Maxsize + len; //顺序表最大长度增加len
	free(p); //释放原来的内存空间
}

int main()
{
	SeqList L;
	InitList(L);
	//...往顺序表中随便插入几个元素

	///动态增加数组的长度
	IncreaseSize(L, 5);
	return 0;
}

#endif