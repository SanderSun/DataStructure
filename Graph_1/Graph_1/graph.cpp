#define MaxVertexNum 100	//������Ŀ�����ֵ

#define �ڽӾ���
#ifdef �ڽӾ���
typedef struct{
	char Ver[MaxVertexNum];	//�����
	int Edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��󣬱߱�
	int vexnum, arcnum;		//ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;
#endif

#define �ڽӱ�
#ifdef �ڽӱ�
//"��/��"
typedef struct ArcNode{
	int adjvex;		//��/��ָ���ĸ����
	struct ArcNode* next;	//ָ����һ������ָ��
	//InfoType info;	//��Ȩֵ
}ArcNode;

//"����"
typedef struct VNode{
	char data; //������Ϣ
	ArcNode* first; //��һ����/��
}VNode,AdjList[MaxVertexNum];	//������

//���ڽӱ�洢��ͼ
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;	//ͼ�ܹ��еıߺͻ�
}ALGraph;
#endif