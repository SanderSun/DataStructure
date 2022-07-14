#include <stdlib.h>

#define 快速排序
#ifdef 快速排序
int Partition(int A[], int low, int high){
	int pivot = A[low];		//第一个元素作为枢轴
	while (low<high)		//用low,high搜索枢轴的最终位置
	{
		while (low<high&&A[high]>=pivot)
			--high;
		A[low] = A[high];	//比枢轴小的元素移动到左端
		while (low < high&&A[low] <= pivot)
			++low;
		A[high] = A[low];	//比枢轴大的元素移动到右端

	}
	A[low] = pivot;			//枢轴元素存放到最终位置
	return low;				//返回枢轴元素的最终位置
}

//快速排序
void QuickSort(int A[], int low, int high){
	if (low < high){	//递归跳出的条件
		int pivotpos = Partition(A, low, high);		//划分
		QuickSort(A, low, pivotpos - 1);	//划分左子表
		QuickSort(A, pivotpos + 1, high);	//划分右子表
	}
}

#endif // 快速排序

#define 简单选择排序
#ifdef 简单选择排序
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
#endif // 简单选择排序

#define 堆排序
#ifdef 堆排序
//建立大根堆
void BuildMaxHeap(int A[], int len){
	for (int i = len / 2; i > 0; i--)//从后往前调整所有非终端结点
		HeadAdjust(A, i, len);
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len){
	A[0] = A[k];							//A[0]暂存子树的根结点
	for (int i = 2 * k; i <= len; i *= 2){	//沿key较大的子结点向下筛选
		if (i < len&&A[i] < A[i + 1])
			i++;							//取key较大的子结点的下标
		if (A[0] >= A[i])
			break;							//筛选结束
		else{
			A[k] = A[i];					//将A[i]调整到双亲结点上
			k = i;							//修改k值，以便继续向下筛选
		}
	}
	A[k] = A[0];							//被筛选结点的值放入最终位置
}

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//堆排序的完整逻辑
void HeapSort(int A[], int len){
	BuildMaxHeap(A, len);	//初始建堆
	for (int i = len; i > 1; i--){	//n-1趟的交换和建堆过程
		Swap(A[i], A[1]);			//堆顶元素和堆低元素交换
		HeadAdjust(A, 1, i - 1);
	}
}
#endif // 堆排序

#define 归并排序
#ifdef 归并排序
int *B = (int *)malloc(len*sizeof(int));

//A[low...mid]和A[mid+1...high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high){
	int i, j, k;
	for (k = low; k <= high; k++){
		B[k] = A[k];				//将A中所有元素复制到B中
	}
	for (i = low, j = mid + 1, k = i; i <= mid&&j <= high; k++){
		if (B[i] <= B[j])
			A[k] = B[i++];			//将较小值复制到A中
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
		int mid = (low + high) / 2;	//从中间划分
		MergeSort(A, low, mid);		//对左半部分归并排序
		MergeSort(A, mid + 1, high);//对右半部分归并排序
		Merge(A, low, mid, high);	//归并
	}//if 
}
#endif // 归并排序
 
#define 基数排序
#ifdef 基数排序
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LinkNode,*LinkList;

typedef struct{				//链式队列
	LinkNode *front, *rear;	//队列的队头和队尾指针
}LinkQueue; 
#endif // 基数排序
