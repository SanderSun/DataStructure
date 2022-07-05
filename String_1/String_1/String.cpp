#define MAXLEN 255	//预定义最大串长为255

typedef struct{
	char ch[MAXLEN];	//每个分量存储一个字符串
	int length;		//串的实际长度
}SString; 

//求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
	//子串范围越界
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}

//比较操作。若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(SString S, SString T){
	for (int i = 1; i <= S.length&&i <= T.length; i++){
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//扫描过的所有的字符都相同，则长度长的串更大
	return S.length - T.length;
}

//定位操作，朴素模式匹配算法
int Index(SString S, SString T){
	int i = 1, n = S.length, m = T.length; //s是主串，m是子串
	SString sub; //用于暂存子串
	while (i<=n-m+1)
	{
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
			i++;
		else
			return i; //返回字串在主串中的位置
	}
	return 0; //S中不存在与T相等的子串
}