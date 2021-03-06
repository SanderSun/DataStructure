#define 插入排序
#ifdef 插入排序
//直接插入排序
void InsertSort(int A[], int n){
	int i, j, temp;
	for (i = 1; i < n; i++){		//将各元素插入已排好序的序列中
		if (A[i] < A[i - 1]){		//若A[i]关键字小于前驱
			temp = A[i];			//用temp暂存A[i]
			for (j = i - 1; j >= 0 && A[j]>temp; --j)	//检查所有前面已排好序的元素
				A[j + 1] = A[j];	//所有大于temp的元素都向后挪位
			A[j + 1] = temp;		//复制到插入位置
		}
	}
}
#endif	//插入排序 

#define 折半插入排序
#ifdef 折半插入排序
//折半插入排序
void InsertSort(int A[], int n){
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++){	//依次将A[2]~A[n]插入前面的已排序序列
		A[0] = A[i];			//将A[i]暂存到A[0]
		low = 1;				//设置折半查找的范围
		high = i - 1;			
		while (low<=high)		//折半查找
		{
			mid = (low + high) / 2;	//取中间点
			if (A[mid] > A[0])
				high = mid - 1;		//查找左半子表
			else
				low = mid + 1;		//查找右半子表
		}
		for (j = i - 1; j >= low; --j)
			A[j + 1] = A[j];	//统一后移元素
		A[low] = A[0];			//插入操作
	}
}

#endif // 折半插入排序

#define 希尔排序
#ifdef 希尔排序
void ShellSort(int A[], int n){
	int d, i, j;
	//A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	for (d = n / 2; d >= 1; d = d / 2){		//步长变化
		for (i = d + 1; i <= n; ++i){
			if (A[i] < A[i - d]){			//需将A[i]插入有序增量子表
				A[0] = A[i];				//暂存在A[0]
				for (j = i - d; j>0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];		//记录后移，查找插入的位置
				A[j + d] = A[0];			//插入
			}//if
		}
	}	

}
#endif // 希尔排序

#define 冒泡排序
#ifdef 冒泡排序
//交换
void swap(int &a, int &b){	//比较一次后必须移动3次元素位置
	int temp = a;
	a = b;
	b = temp;
}
//冒泡排序
void BubbleSort(int A[], int n){
	for (int i = 0; i < n - 1; i++){
		bool flag = false;				//表示本趟冒泡是否发生交换的标志
		for (int j = n - 1; j>i; j--){	//一趟冒泡过程
			if (A[j - 1] > A[j]){		//若为逆序
				swap(A[j - 1], A[j]);	//交换
				flag = true;
			}
		}
		if (flag == false)
			return;				//本趟遍历后没有发生交换，说明表已经有序
	}
}
#endif // 冒泡排序
