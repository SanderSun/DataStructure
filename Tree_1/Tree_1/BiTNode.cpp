#include <stdlib.h>
#include <stdio.h>

//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode{
	int data;	//������
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//�������������
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;	//����������־
}ThreadNode,*ThreadNode;

void visit(BiTree T){
	printf("%d\n", T->data);
}

//��������
void BiTreeInsert(BiTree &T){
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = { 1 };
	T->lchild = NULL;
	T->rchild = NULL;
}

//�����½��
void BiTNodeInsert(BiTree T){
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = { 2 };
	p->lchild = NULL;
	p->rchild = NULL;
	T->lchild = p;
}

//�������
void PreOrder(BiTree T){
	if (T != NULL){
		visit(T);				//���ʸ����
		PreOrder(T->lchild);	//�ݹ����������
		PreOrder(T->rchild);	//�ݹ����������
	}
}

//�������
void InOrder(BiTree T){
	if (T != NULL){
		PreOrder(T->lchild);	//�ݹ����������
		visit(T);				//���ʸ����
		PreOrder(T->rchild);	//�ݹ����������
	}
}

//�������
void PostOrder(BiTree T){
	if (T != NULL){
		PreOrder(T->lchild);	//�ݹ����������
		PreOrder(T->rchild);	//�ݹ����������
		visit(T);				//���ʸ����
	}
}

//�������
//��ʽ���н��
typedef struct LinkNode{
	BiTNode *data;
	struct LinkNode* next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear; //��ͷ��β
}LinkQueue;

//�������
void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);	//��ʼ����������
	BiTree p;
	EnQueue(Q, T);	//����������
	while (!IsEmpty(Q)){
		DeQueue(Q, p);	//��ͷ������
		visit(p);	//���ʳ��ӽ��
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);	//�������
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);	//�Һ������
	}
}

void testBiTNode(){
	BiTree T = NULL; //����һ�ſ���
	BiTreeInsert(T);
	BiTNodeInsert(T);
}