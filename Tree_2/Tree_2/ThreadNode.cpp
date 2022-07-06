#include <stdlib.h>


//二叉树的结点（链式存储）
typedef struct BiTNode{
	int data;	//数据域
	struct BiTNode *lchild, *rchild;	//左、右孩子指针
}BiTNode, *BiTree;

//线索二叉树的存储结构
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;	//左、右孩子指针
	int ltag, rtag;	//左、右线索标志
}ThreadNode,*ThreadTree;

//#define 查找结点p的前驱
#ifdef 查找结点p的前驱
//辅助全局变量，用于查找结点p的前驱
BiTNode* p;	//p指向目标结点
BiTNode* pre = NULL;	//指向当前访问结点的前驱
BiTNode* final = NULL;	//用于记录最终结果

//中序遍历
void InOrder(BiTree T){
	if (T != NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//访问结点q
void visit(BiTNode* q){
	if (q == p)			//当前访问结点刚好是结点p
		final = pre;	//找到p的前驱
	else
		pre = q;	//pre指向当前访问的结点
}
#endif

#define 二叉树线索化
#ifdef 二叉树线索化
void InThread(ThreadTree T){
	if (T != NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);

	}
}

//全局变量pre，指向当前访问结束的前驱
ThreadNode* pre = NULL;


void visit(ThreadNode* q)
{
	if (q->lchild == NULL){	//左子树为空，建立前驱线索
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL&&pre->rchild == NULL){
		pre->rchild = q;	//建立前驱结点的后继线索
		pre->rtag = 1;
	}
	pre = q;
}

//中序线索化二叉树T
void CreateInThread(ThreadTree T){
	pre = NULL;	//pre初始化为NULL
	if (T != NULL){		//非空二叉树才能线索化
		InThread(T);	//中序线索化二叉树
		if (pre->rchild == NULL)
			pre->rtag = 1;	//处理遍历的最后一个结点
	}
}

//中序线索二叉树找中序后继
//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode* p){
	//循环找到最左下结点(不一定是叶结点)
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p){
	//右子树中最左下结点
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	else
		return p->rchild;	//rtag==1直接返回后继线索
}

//对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void Inorder(ThreadNode* T){
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		visit(p);
}

//中序线索二叉树找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode* Lastnode(ThreadNode* p)
{
	//循环找到最右下结点(不一定是叶结点)
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

//在中序线索二叉树中找到结点p的前驱结点
ThreadNode* Prenode(ThreadNode *p){
	//左子树中最右下结点
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	else
		return p->lchild; //ltag==1直接返回前驱线索
}

//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode *T){
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
		visit(p);
}






#endif