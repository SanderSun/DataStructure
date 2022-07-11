#include <stdlib.h>

#define ˳�����
#ifdef ˳�����
typedef struct{		//���ұ�����ݽṹ(˳���)
	int *elem;		//��̬�����ַ
	int tableLen;	//��ĳ���
}SSTable;

//˳�����
int Search_Seq(SSTable ST, int key){
	int i;
	for (i = 0; i < ST.tableLen&&ST.elem[i] != key; ++i);
	//���ҳɹ����򷵻�Ԫ���±ꣻ����ʧ�ܣ��򷵻�0
	return i == ST.tableLen ? -1 : i;
}
#endif

#define �۰����
#ifdef �۰����
typedef struct{		//���ұ�����ݽṹ(˳���)
	int *elem;		//��̬���鼯ַ
	int TableLen;	//��ĳ���
}SeTable;

int Binary_Search(SeTable L, int key){
	int low = 0, high = L.TableLen - 1, mid;
	while (low<=high)
	{
		mid = (low + high) / 2;		//ȡ�м�λ��
		if (L.elem[mid] == key)
			return mid;				//���ҳɹ��򷵻�����λ��
		else if (L.elem[mid] > key)
			high = mid - 1;			//��ǰ�벿�ּ�������
		else
			low = mid + 1;			//�Ӻ�벿�ּ�������
	}
	return -1;						//����ʧ�ܣ�����-1 
}
#endif // �۰����

#define �ֿ����
#ifdef �ֿ����
//������
typedef struct{
	int maxValue;
	int low, high;
}Index;

//˳���洢ʵ��Ԫ��
int List[100];
#endif // �ֿ����

//�������������
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild, *rchild;
}BSTNode,*BSTree;

#define ����˳�����Ĳ���
#ifdef ����˳�����Ĳ���

//�ڶ����������в���ֵΪkey�Ľ��
//BSTNode *BST_Search(BSTree T, int key){
//	while (T != NULL&&key!=T->key)	//�����ջ���ڸ����ֵ�������ѭ��
//	{
//		if (key < T->key)
//			T = T->lchild;	//С�ڣ������������ϲ���
//		else
//			T = T->rchild;	//���ڣ������������ϲ���
//	}
//	return T;	//���ҳɹ������ؽ��ָ�룬ʧ�ܣ�����NULL
//}

//�ݹ�ʵ��
BSTNode	*BSTSearch(BSTree T, int key){
	if (T == NULL)
		return NULL;	//����ʧ��
	if (key == T->key)
		return T;
	else if (key < T->key)
		return BSTSearch(T->lchild, key);	//������������
	else
		return BSTSearch(T->rchild, key);	//������������
}
#endif // ����˳�����Ĳ���

#define �����������Ĳ���
#ifdef �����������Ĳ���
//��������������Ԫ��(�ݹ�ʵ��)
int BST_Insert(BSTree &T, int k){
	if (T == NULL){			//ԭ��Ϊ�գ��²���Ľ��Ϊ�����
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = NULL;
		T->rchild = NULL;
		return 1;			//����1������ɹ�
	}
	else if (k == T->key)		//���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
		return 0;
	else if (k < T->key)
		return BST_Insert(T->lchild, k);	//���뵽T��������
	else
		return BST_Insert(T->rchild, k);	//���뵽T��������
}
#endif // �����������Ĳ���

#define �����������Ĺ���
#ifdef �����������Ĺ���
//����str[]�еĹؼ������н�������������
void Creat_BST(BSTree &T, int str[], int n){
	T = NULL;	//��ʼʱTΪ����
	int i = 0;
	while (i < n){	//���ν�ÿ���ؼ��ֲ��뵽������������
		BST_Insert(T, str[i]);
		i++;
	}
}
#endif // �����������Ĺ���

#define ƽ�������
#ifdef ƽ�������
//ƽ����������
typedef struct AVLNode{
	int key;	//������
	int balance;	//ƽ������
	struct AVLNode *lchild, *rchild;
}AVLNode,*AVLTree;

#endif // ƽ�������

#define �����
#ifdef �����
struct RBnode{		//������Ľ�㶨��
	int key;	//�ؼ��ֵ�ֵ
	RBnode* parent;		//�����ָ��
	RBnode* lChild;		//����ָ��
	RBnode* rChild;		//�Һ���ָ��
	int color;			//�����ɫ���磺����0/1 ��/�� ö����enum��ʾ��ɫ
};
#endif // �����
