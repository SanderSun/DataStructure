#include <stdlib.h>
#define MAX_TREE_SIZE 100	//�����������

#define ˫�ױ�ʾ��
#ifdef ˫�ױ�ʾ��
typedef struct{	//���Ľ�㶨��
	int data;	//����Ԫ��
	int parent; //˫��λ����
}PTNode;

typedef struct{	//�������Ͷ���
	PTNode nodes[MAX_TREE_SIZE];	//˫�ױ�ʾ
	int n;		//�����
}PTree;

#endif

#define ���ӱ�ʾ��
#ifdef ���ӱ�ʾ��

struct CTNode{
	int child;	//���ӽ���������е�λ��
	struct CTNode* next; //��һ������
};

typedef struct{
	int data;
	struct CTNode* firstChild; //��һ������
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;	//������͸���λ��
}CTree;

#endif

#define �����ֵܱ�ʾ��
#ifdef �����ֵܱ�ʾ��
typedef struct CSNode{
	int data;	//������
	struct CSNode *firstchild, *nextsibling;	//��һ�����Ӻ����ֵ�ָ��
}CSNode,*CSTree; 

#endif

#define SIZE 13
int UFSets[SIZE]; //����Ԫ������

//��ʼ�����鼯
void Initial(int S[]){
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//Find	"�����"����x��������(����x���������)
int Find(int S[], int x){
	int root = x;
	while (S[root] >= 0)
		root = S[root];	//ѭ���ҵ���

	while (x != root){	//ѹ��·��
		int t = S[x];	//tָ��x�ĸ����
		S[x] = root;	//xֱ�ӹҵ����ڵ���
		x = t;
	}
	return root; //���ظ��ڵ�
		
}

//Union "��"���������������Ϻϲ�Ϊһ��
void Union(int S[], int Root1, int Root2){
	//Ҫ��Root1��Root2�ǲ�ͬ�ļ���
	if (Root1 == Root2)
		return;
	//����Root2���ӵ���һ��Root1����
	if (S[Root2] > S[Root1]){ 
		S[Root1] += S[Root2];	//�ۼӽ������
		S[Root2] = Root1;	//С���ϲ�����
	}
	else
	{
		S[Root2] += S[Root1]; //�ۼӽ������
		S[Root1] = Root2;	//С���ϲ�����
	}
}