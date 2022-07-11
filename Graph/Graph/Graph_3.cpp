#define Floyd算法
#ifdef Floyd算法
for (int k = 0; k < n; k++){	//考虑以vk作为中转点
	for (int i = 0; i < n; i++){	//遍历整个矩阵，i为行号，j为列号
		for (int j = 0; j < n; j++){	
			if (A[i][j]>A[i][k] + A[k][j]){	//以vk为中转点的路径更短
				A[i][j] = A[i][k] + A[k][j];//更新最短路径长度
				path[i][j] = k;		//
			}
		}
	}
}
#endif