#include <stdlib.h>

#define ��������
#ifdef ��������
int Partition(int A[], int low, int high){
	int pivot = A[low];		//��һ��Ԫ����Ϊ����
	while (low<high)		//��low,high�������������λ��
	{
		while (low<high&&A[high]>=pivot)
			--high;
		A[low] = A[high];	//������С��Ԫ���ƶ������
		while (low < high&&A[low] <= pivot)
			++low;
		A[high] = A[low];	//��������Ԫ���ƶ����Ҷ�

	}
	A[low] = pivot;			//����Ԫ�ش�ŵ�����λ��
	return low;				//��������Ԫ�ص�����λ��
}

//��������
void QuickSort(int A[], int low, int high){
	if (low < high){	//�ݹ�����������
		int pivotpos = Partition(A, low, high);		//����
		QuickSort(A, low, pivotpos - 1);	//�������ӱ�
		QuickSort(A, pivotpos + 1, high);	//�������ӱ�
	}
}

#endif // ��������

#define ��ѡ������
#ifdef ��ѡ������
void SelectSort(int A[], int n){
	for (int i = 0; i < n - 1; i++){
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (A[j] < A[min])
				min = j;
		}
		if (min != i){
			int temp = A[min];
			A[min] = A[i];
			A[i] = temp;
		}
	}
}
#endif // ��ѡ������

#define ������
#ifdef ������
//���������
void BuildMaxHeap(int A[], int len){
	for (int i = len / 2; i > 0; i--)//�Ӻ���ǰ�������з��ն˽��
		HeadAdjust(A, i, len);
}

//����kΪ������������Ϊ�����
void HeadAdjust(int A[], int k, int len){
	A[0] = A[k];							//A[0]�ݴ������ĸ����
	for (int i = 2 * k; i <= len; i *= 2){	//��key�ϴ���ӽ������ɸѡ
		if (i < len&&A[i] < A[i + 1])
			i++;							//ȡkey�ϴ���ӽ����±�
		if (A[0] >= A[i])
			break;							//ɸѡ����
		else{
			A[k] = A[i];					//��A[i]������˫�׽����
			k = i;							//�޸�kֵ���Ա��������ɸѡ
		}
	}
	A[k] = A[0];							//��ɸѡ����ֵ��������λ��
}

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//������������߼�
void HeapSort(int A[], int len){
	BuildMaxHeap(A, len);	//��ʼ����
	for (int i = len; i > 1; i--){	//n-1�˵Ľ����ͽ��ѹ���
		Swap(A[i], A[1]);			//�Ѷ�Ԫ�غͶѵ�Ԫ�ؽ���
		HeadAdjust(A, 1, i - 1);
	}
}
#endif // ������

#define �鲢����
#ifdef �鲢����
int *B = (int *)malloc(len*sizeof(int));

//A[low...mid]��A[mid+1...high]�������򣬽��������ֹ鲢
void Merge(int A[], int low, int mid, int high){
	int i, j, k;
	for (k = low; k <= high; k++){
		B[k] = A[k];				//��A������Ԫ�ظ��Ƶ�B��
	}
	for (i = low, j = mid + 1, k = i; i <= mid&&j <= high; k++){
		if (B[i] <= B[j])
			A[k] = B[i++];			//����Сֵ���Ƶ�A��
		else
			A[k] = B[j++];
	}//for
	while (i <= mid)
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high){
	if (low < high){
		int mid = (low + high) / 2;	//���м仮��
		MergeSort(A, low, mid);		//����벿�ֹ鲢����
		MergeSort(A, mid + 1, high);//���Ұ벿�ֹ鲢����
		Merge(A, low, mid, high);	//�鲢
	}//if 
}
#endif // �鲢����
 
#define ��������
#ifdef ��������
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LinkNode,*LinkList;

typedef struct{				//��ʽ����
	LinkNode *front, *rear;	//���еĶ�ͷ�Ͷ�βָ��
}LinkQueue; 
#endif // ��������
