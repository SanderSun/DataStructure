#define ��������
#ifdef ��������
//ֱ�Ӳ�������
void InsertSort(int A[], int n){
	int i, j, temp;
	for (i = 1; i < n; i++){		//����Ԫ�ز������ź����������
		if (A[i] < A[i - 1]){		//��A[i]�ؼ���С��ǰ��
			temp = A[i];			//��temp�ݴ�A[i]
			for (j = i - 1; j >= 0 && A[j]>temp; --j)	//�������ǰ�����ź����Ԫ��
				A[j + 1] = A[j];	//���д���temp��Ԫ�ض����Ųλ
			A[j + 1] = temp;		//���Ƶ�����λ��
		}
	}
}
#endif	//�������� 

#define �۰��������
#ifdef �۰��������
//�۰��������
void InsertSort(int A[], int n){
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++){	//���ν�A[2]~A[n]����ǰ�������������
		A[0] = A[i];			//��A[i]�ݴ浽A[0]
		low = 1;				//�����۰���ҵķ�Χ
		high = i - 1;			
		while (low<=high)		//�۰����
		{
			mid = (low + high) / 2;	//ȡ�м��
			if (A[mid] > A[0])
				high = mid - 1;		//��������ӱ�
			else
				low = mid + 1;		//�����Ұ��ӱ�
		}
		for (j = i - 1; j >= low; --j)
			A[j + 1] = A[j];	//ͳһ����Ԫ��
		A[low] = A[0];			//�������
	}
}

#endif // �۰��������

#define ϣ������
#ifdef ϣ������
void ShellSort(int A[], int n){
	int d, i, j;
	//A[0]ֻ���ݴ浥Ԫ�������ڱ�����j<=0ʱ������λ���ѵ�
	for (d = n / 2; d >= 1; d = d / 2){		//�����仯
		for (i = d + 1; i <= n; ++i){
			if (A[i] < A[i - d]){			//�轫A[i]�������������ӱ�
				A[0] = A[i];				//�ݴ���A[0]
				for (j = i - d; j>0 && A[0] < A[j]; j -= d)
					A[j + d] = A[j];		//��¼���ƣ����Ҳ����λ��
				A[j + d] = A[0];			//����
			}//if
		}
	}	

}
#endif // ϣ������

#define ð������
#ifdef ð������
//����
void swap(int &a, int &b){	//�Ƚ�һ�κ�����ƶ�3��Ԫ��λ��
	int temp = a;
	a = b;
	b = temp;
}
//ð������
void BubbleSort(int A[], int n){
	for (int i = 0; i < n - 1; i++){
		bool flag = false;				//��ʾ����ð���Ƿ��������ı�־
		for (int j = n - 1; j>i; j--){	//һ��ð�ݹ���
			if (A[j - 1] > A[j]){		//��Ϊ����
				swap(A[j - 1], A[j]);	//����
				flag = true;
			}
		}
		if (flag == false)
			return;				//���˱�����û�з���������˵�����Ѿ�����
	}
}
#endif // ð������
