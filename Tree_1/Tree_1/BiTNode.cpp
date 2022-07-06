#include <stdlib.h>
#include <stdio.h>

//二叉树的结点（链式存储）
typedef struct BiTNode{
	int data;	//数据域
	struct BiTNode *lchild, *rchild;	//左、右孩子指针
}BiTNode,*BiTree;

//线索二叉树结点
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;	//左右线索标志
}ThreadNode,*ThreadNode;

void visit(BiTree T){
	printf("%d\n", T->data);
}

//插入根结点
void BiTreeInsert(BiTree &T){
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = { 1 };
	T->lchild = NULL;
	T->rchild = NULL;
}

//插入新结点
void BiTNodeInsert(BiTree T){
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->lchild = NULL;
	p->rchild = NULL;
	T->lchild = p;
}

//先序遍历
void PreOrder(BiTree T){
	if (T != NULL){
		visit(T);				//访问根结点
		PreOrder(T->lchild);	//递归遍历左子树
		PreOrder(T->rchild);	//递归遍历右子树
	}
}

//中序遍历
void InOrder(BiTree T){
	if (T != NULL){
		PreOrder(T->lchild);	//递归遍历左子树
		visit(T);				//访问根结点
		PreOrder(T->rchild);	//递归遍历右子树
	}
}

//后序遍历
void PostOrder(BiTree T){
	if (T != NULL){
		PreOrder(T->lchild);	//递归遍历左子树
		PreOrder(T->rchild);	//递归遍历右子树
		visit(T);				//访问根结点
	}
}

//层序遍历
//链式队列结点
typedef struct LinkNode{
	BiTNode *data;
	struct LinkNode* next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear; //队头队尾
}LinkQueue;

//层序遍历
void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);	//初始化辅助队列
	BiTree p;
	EnQueue(Q, T);	//将根结点入队
	while (!IsEmpty(Q)){
		DeQueue(Q, p);	//队头结点出队
		visit(p);	//访问出队结点
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);	//左孩子入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);	//右孩子入队
	}
}

void testBiTNode(){
	BiTree T = NULL; //定义一颗空树
	BiTreeInsert(T);
	BiTNodeInsert(T);
}