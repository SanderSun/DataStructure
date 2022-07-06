#include <stdlib.h>
#define MAX_TREE_SIZE 100	//树中最多结点数

#define 双亲表示法
#ifdef 双亲表示法
typedef struct{	//树的结点定义
	int data;	//数据元素
	int parent; //双亲位置域
}PTNode;

typedef struct{	//树的类型定义
	PTNode nodes[MAX_TREE_SIZE];	//双亲表示
	int n;		//结点数
}PTree;

#endif

#define 孩子表示法
#ifdef 孩子表示法

struct CTNode{
	int child;	//孩子结点在数组中的位置
	struct CTNode* next; //下一个孩子
};

typedef struct{
	int data;
	struct CTNode* firstChild; //第一个孩子
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;	//结点数和根的位置
}CTree;

#endif

#define 孩子兄弟表示法
#ifdef 孩子兄弟表示法
typedef struct CSNode{
	int data;	//数据域
	struct CSNode *firstchild, *nextsibling;	//第一个孩子和右兄弟指针
}CSNode,*CSTree; 

#endif

#define SIZE 13
int UFSets[SIZE]; //集合元素数组

//初始化并查集
void Initial(int S[]){
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//Find	"查操作"，找x所属集合(返回x所属根结点)
int Find(int S[], int x){
	int root = x;
	while (S[root] >= 0)
		root = S[root];	//循环找到根

	while (x != root){	//压缩路径
		int t = S[x];	//t指向x的父结点
		S[x] = root;	//x直接挂到根节点下
		x = t;
	}
	return root; //返回根节点
		
}

//Union "并"操作，将两个集合合并为一个
void Union(int S[], int Root1, int Root2){
	//要求Root1与Root2是不同的集合
	if (Root1 == Root2)
		return;
	//将根Root2连接到另一根Root1下面
	if (S[Root2] > S[Root1]){ 
		S[Root1] += S[Root2];	//累加结点总数
		S[Root2] = Root1;	//小树合并大树
	}
	else
	{
		S[Root2] += S[Root1]; //累加结点总数
		S[Root1] = Root2;	//小树合并大树
	}
}