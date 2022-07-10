#include <stdlib.h>

//�ж�ͼG�Ƿ���ڱ�
//Adjacent(G, x, y);

//�г�ͼG������X�ڽӵı�
//Neighbors(G, x);

//��ͼG�в��붥��x
//InsertVertex(G,x);

//��ͼG��ɾ������x
//Delete(G,x)

//�������(x,y)�������<x,y>�����ڣ�����ͼG����Ӹñ�
//AddEdge(G,x,y);

#define MAX_VERTEX_NUM 100	//������Ŀ�����ֵ

typedef char VertexType;	//�������������
typedef int EdgeType;	//��Ȩͼ�б���Ȩֵ����������
//ͼ���ڽӾ���
typedef struct{
	VertexType Vex[MAX_VERTEX_NUM];	//�����
	EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	//�ڽӾ��󣬱߱�
	int vernum, arcnum;	//ͼ�ĵ�ǰ�������ͻ���
}Graph;
//ͼ���ڽӾ���

//ͼ���ڽӱ�
typedef struct ArcNode{		//�߱���
	int adjvex;		//�û�ָ��Ķ����λ��
	struct ArcNode *next;	//ָ����һ������ָ��
	//InfoType info; //���ı�Ȩֵ
}ArcNode;

typedef struct VNode{	//�������
	VertexType data;	//������Ϣ
	ArcNode* first;		//ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;	//�ڽӱ�
	int vernum, arcnum;	//ͼ�Ķ������ͻ���
}ALGraph;
//ͼ���ڽӱ�
bool visited[MAX_VERTEX_NUM]; //���ʱ������ ��ʼֵ��Ϊfalse

#define �����������
#ifdef �����������
//������ȱ���
void BFSTraverse(Graph G){	//��ͼG���й�����ȱ���
	for (int i = 0; i < G.vernum; ++i){
		visited[i] = false;	//���ʱ�������ʼ��
	}

	InitQueue(Q);	//��ʼ����������Q
		
	for (int i = 0; i < G.vernum; ++i){	//��0�Ŷ��㿪ʼ����
		if (!visited[i])	//��ÿ����ͨ��������һ��BFS
			BFS(G, i);		//viδ���ʹ�����vi��ʼBFS
	}
}

void BFS(Graph G, int v){	//�Ӷ���v������������ȱ���ͼG
	visit(v);	//���ʳ�ʼ����v
	visited[v] = true;	//��v���ѷ��ʱ��
	Enqueue(Q, v);		//����v�����Q
	while (!isEmpty(Q))
	{
		DeQueue(Q, v);	//����v������
		for (int w = FirstNeighbor(G, v); w >= -; w = NextNeighbor(G, v, w)){
			if (!visited[w]){
				visit(w);
				visited[w] = true;	//��w���ѷ��ʱ�� 
				EnQueue(Q, w);	//����w�����
			}
		}

	}
}

#endif

#define �����������
#ifdef �����������
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
 