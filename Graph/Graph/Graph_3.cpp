#define Floyd�㷨
#ifdef Floyd�㷨
for (int k = 0; k < n; k++){	//������vk��Ϊ��ת��
	for (int i = 0; i < n; i++){	//������������iΪ�кţ�jΪ�к�
		for (int j = 0; j < n; j++){	
			if (A[i][j]>A[i][k] + A[k][j]){	//��vkΪ��ת���·������
				A[i][j] = A[i][k] + A[k][j];//�������·������
				path[i][j] = k;		//
			}
		}
	}
}
#endif