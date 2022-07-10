#include <stdlib.h>

//判断图G是否存在边
//Adjacent(G, x, y);

//列出图G中与结点X邻接的边
//Neighbors(G, x);

//在图G中插入顶点x
//InsertVertex(G,x);

//从图G中删除顶点x
//Delete(G,x)

//若无向边(x,y)或有向边<x,y>不存在，则向图G中添加该边
//AddEdge(G,x,y);

#define MAX_VERTEX_NUM 100	//顶点数目的最大值

typedef char VertexType;	//顶点的数据类型
typedef int EdgeType;	//带权图中边上权值的数据类型
//图的邻接矩阵
typedef struct{
	VertexType Vex[MAX_VERTEX_NUM];	//顶点表
	EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//邻接矩阵，边表
	int vernum, arcnum;	//图的当前顶点数和弧数
}Graph;
//图的邻接矩阵

//图的邻接表
typedef struct ArcNode{		//边表结点
	int adjvex;		//该弧指向的顶点的位置
	struct ArcNode *next;	//指向下一条弧的指针
	//InfoType info; //网的边权值
}ArcNode;

typedef struct VNode{	//顶点表结点
	VertexType data;	//顶点信息
	ArcNode* first;		//指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;	//邻接表
	int vernum, arcnum;	//图的顶点数和弧数
}ALGraph;
//图的邻接表
bool visited[MAX_VERTEX_NUM]; //访问标记数组 初始值都为false

#define 广度优先搜索
#ifdef 广度优先搜索
//广度优先遍历
void BFSTraverse(Graph G){	//对图G进行广度优先遍历
	for (int i = 0; i < G.vernum; ++i){
		visited[i] = false;	//访问标记数组初始化
	}

	InitQueue(Q);	//初始化辅助队列Q
		
	for (int i = 0; i < G.vernum; ++i){	//从0号顶点开始遍历
		if (!visited[i])	//对每个连通分量调用一次BFS
			BFS(G, i);		//vi未访问过，从vi开始BFS
	}
}

void BFS(Graph G, int v){	//从顶点v出发，广度优先遍历图G
	visit(v);	//访问初始顶点v
	visited[v] = true;	//对v做已访问标记
	Enqueue(Q, v);		//顶点v入队列Q
	while (!isEmpty(Q))
	{
		DeQueue(Q, v);	//顶点v出队列
		for (int w = FirstNeighbor(G, v); w >= -; w = NextNeighbor(G, v, w)){
			if (!visited[w]){
				visit(w);
				visited[w] = true;	//对w做已访问标记 
				EnQueue(Q, w);	//顶点w入队列
			}
		}

	}
}

#endif

#define 深度优先搜索
#ifdef 深度优先搜索
void DFSTraverse(Graph G){
	for (int v = 0; v < G.vernum; ++v)
		visited[v] = false;
	for (int v = 0; v < G.vernum; ++v){
		if (!visited[v])
			DFS(G, v);

	}
}

void DFS(Graph G, int v){
	visit(v);
	visited[v] = true;
	for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)){
		if (!visited[w]){
			DFS(G, w);
		}
	}
}

#endif
 