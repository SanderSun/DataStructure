#include <stdlib.h>


//�������Ľ�㣨��ʽ�洢��
typedef struct BiTNode{
	int data;	//������
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode, *BiTree;

//�����������Ĵ洢�ṹ
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;	//���Һ���ָ��
	int ltag, rtag;	//����������־
}ThreadNode,*ThreadTree;

//#define ���ҽ��p��ǰ��
#ifdef ���ҽ��p��ǰ��
//����ȫ�ֱ��������ڲ��ҽ��p��ǰ��
BiTNode* p;	//pָ��Ŀ����
BiTNode* pre = NULL;	//ָ��ǰ���ʽ���ǰ��
BiTNode* final = NULL;	//���ڼ�¼���ս��

//�������
void InOrder(BiTree T){
	if (T != NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//���ʽ��q
void visit(BiTNode* q){
	if (q == p)			//��ǰ���ʽ��պ��ǽ��p
		final = pre;	//�ҵ�p��ǰ��
	else
		pre = q;	//preָ��ǰ���ʵĽ��
}
#endif

#define ������������
#ifdef ������������
void InThread(ThreadTree T){
	if (T != NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);

	}
}

//ȫ�ֱ���pre��ָ��ǰ���ʽ�����ǰ��
ThreadNode* pre = NULL;


void visit(ThreadNode* q)
{
	if (q->lchild == NULL){	//������Ϊ�գ�����ǰ������
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL&&pre->rchild == NULL){
		pre->rchild = q;	//����ǰ�����ĺ������
		pre->rtag = 1;
	}
	pre = q;
}

//����������������T
void CreateInThread(ThreadTree T){
	pre = NULL;	//pre��ʼ��ΪNULL
	if (T != NULL){		//�ǿն���������������
		InThread(T);	//����������������
		if (pre->rchild == NULL)
			pre->rtag = 1;	//������������һ�����
	}
}

//����������������������
//�ҵ���pΪ���������У���һ������������Ľ��
ThreadNode *Firstnode(ThreadNode* p){
	//ѭ���ҵ������½��(��һ����Ҷ���)
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode* Nextnode(ThreadNode* p){
	//�������������½��
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	else
		return p->rchild;	//rtag==1ֱ�ӷ��غ������
}

//���������������������������(��������ʵ�ֵķǵݹ��㷨)
void Inorder(ThreadNode* T){
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		visit(p);
}

//��������������������ǰ��
//�ҵ���pΪ���������У����һ������������Ľ��
ThreadNode* Lastnode(ThreadNode* p)
{
	//ѭ���ҵ������½��(��һ����Ҷ���)
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

//�������������������ҵ����p��ǰ�����
ThreadNode* Prenode(ThreadNode *p){
	//�������������½��
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	else
		return p->lchild; //ltag==1ֱ�ӷ���ǰ������
}

//�������������������������������
void RevInorder(ThreadNode *T){
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
		visit(p);
}






#endif