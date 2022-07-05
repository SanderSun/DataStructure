#define 朴素模式匹配算法

#ifdef 朴素模式匹配算法
#define MAXSIZE 255
typedef struct{
	char ch[MAXSIZE];
	int Length;
}SString;

int Index(SString S, SString T){
	int i = 1, j = 1;
	while (i<=S.Length&&j<=T.Length)
	{
		if (S.ch[i] == T.ch[i]){
			++i; 
			++j;	//继续比较后续字符
		}
		else{
			i = i - j + 2;
			j = 1; //指针后退重新开始匹配
		}
	}
	if (j > T.Length)
		return i - T.Length;
	else
		return 0;
} 
#endif

#define KMP算法
#ifdef KMP算法
int Index_KMP(SString S, SString T, int next[]){
	int i = 1, j = 1;
	while (i <= S.Length&&j <= T.Length)
	{
		if (j == 0 || S.ch[i] == T.ch[j]){
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T.Length)
		return i - T.Length;
	else
		return 0;  
}
#endif