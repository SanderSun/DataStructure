#define MaxVertexNum 100	//顶点数目的最大值

#define 邻接矩阵法
#ifdef 邻接矩阵法
typedef struct{
	char Ver[MaxVertexNum];	//顶点表
	int Edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵，边表
	int vexnum, arcnum;		//图的当前顶点数和边数/弧数
}MGraph;
#endif

#define 邻接表法
#ifdef 邻接表法
//"边/弧"
typedef struct ArcNode{
	int adjvex;		//边/弧指向哪个结点
	struct ArcNode* next;	//指向下一条弧的指针
	//InfoType info;	//边权值
}ArcNode;

//"顶点"
typedef struct VNode{
	char data; //顶点信息
	ArcNode* first; //第一条边/弧
}VNode,AdjList[MaxVertexNum];	//顶点数

//用邻接表存储的图
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;	//图总共有的边和弧
}ALGraph;
#endif