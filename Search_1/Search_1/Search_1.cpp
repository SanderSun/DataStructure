#include <stdlib.h>

#define 顺序查找
#ifdef 顺序查找
typedef struct{		//查找表的数据结构(顺序表)
	int *elem;		//动态数组基址
	int tableLen;	//表的长度
}SSTable;

//顺序查找
int Search_Seq(SSTable ST, int key){
	int i;
	for (i = 0; i < ST.tableLen&&ST.elem[i] != key; ++i);
	//查找成功，则返回元素下标；查找失败，则返回0
	return i == ST.tableLen ? -1 : i;
}
#endif

#define 折半查找
#ifdef 折半查找
typedef struct{		//查找表的数据结构(顺序表)
	int *elem;		//动态数组集址
	int TableLen;	//表的长度
}SeTable;

int Binary_Search(SeTable L, int key){
	int low = 0, high = L.TableLen - 1, mid;
	while (low<=high)
	{
		mid = (low + high) / 2;		//取中间位置
		if (L.elem[mid] == key)
			return mid;				//查找成功则返回所在位置
		else if (L.elem[mid] > key)
			high = mid - 1;			//从前半部分继续查找
		else
			low = mid + 1;			//从后半部分继续查找
	}
	return -1;						//查找失败，返回-1 
}
#endif // 折半查找

#define 分块查找
#ifdef 分块查找
//索引表
typedef struct{
	int maxValue;
	int low, high;
}Index;

//顺序表存储实际元素
int List[100];
#endif // 分块查找

//二叉排序树结点
typedef struct BSTNode{
	int key;
	struct BSTNode *lchild, *rchild;
}BSTNode,*BSTree;

#define 二叉顺序树的查找
#ifdef 二叉顺序树的查找

//在二叉排序树中查找值为key的结点
//BSTNode *BST_Search(BSTree T, int key){
//	while (T != NULL&&key!=T->key)	//若树空或等于根结点值，则结束循环
//	{
//		if (key < T->key)
//			T = T->lchild;	//小于，则在左子树上查找
//		else
//			T = T->rchild;	//大于，则在右子树上查找
//	}
//	return T;	//查找成功，返回结点指针，失败，返回NULL
//}

//递归实现
BSTNode	*BSTSearch(BSTree T, int key){
	if (T == NULL)
		return NULL;	//查找失败
	if (key == T->key)
		return T;
	else if (key < T->key)
		return BSTSearch(T->lchild, key);	//在左子树查找
	else
		return BSTSearch(T->rchild, key);	//在右子树查找
}
#endif // 二叉顺序树的查找

#define 二叉排序树的插入
#ifdef 二叉排序树的插入
//二叉排序树插入元素(递归实现)
int BST_Insert(BSTree &T, int k){
	if (T == NULL){			//原树为空，新插入的结点为根结点
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = NULL;
		T->rchild = NULL;
		return 1;			//返回1，插入成功
	}
	else if (k == T->key)		//树中存在相同关键字的结点，插入失败
		return 0;
	else if (k < T->key)
		return BST_Insert(T->lchild, k);	//插入到T的左子树
	else
		return BST_Insert(T->rchild, k);	//插入到T的右子树
}
#endif // 二叉排序树的插入

#define 二叉排序树的构造
#ifdef 二叉排序树的构造
//按照str[]中的关键子序列建立二叉排序树
void Creat_BST(BSTree &T, int str[], int n){
	T = NULL;	//初始时T为空树
	int i = 0;
	while (i < n){	//依次将每个关键字插入到二叉排序树中
		BST_Insert(T, str[i]);
		i++;
	}
}
#endif // 二叉排序树的构造

#define 平衡二叉树
#ifdef 平衡二叉树
//平衡二叉树结点
typedef struct AVLNode{
	int key;	//数据域
	int balance;	//平衡因子
	struct AVLNode *lchild, *rchild;
}AVLNode,*AVLTree;

#endif // 平衡二叉树

#define 红黑树
#ifdef 红黑树
struct RBnode{		//红黑树的结点定义
	int key;	//关键字的值
	RBnode* parent;		//父结点指针
	RBnode* lChild;		//左孩子指针
	RBnode* rChild;		//右孩子指针
	int color;			//结点颜色，如：可用0/1 黑/红 枚举型enum表示颜色
};
#endif // 红黑树
