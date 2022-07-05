#define MAXLEN 255	//Ԥ������󴮳�Ϊ255

typedef struct{
	char ch[MAXLEN];	//ÿ�������洢һ���ַ���
	int length;		//����ʵ�ʳ���
}SString; 

//���Ӵ�
bool SubString(SString &Sub, SString S, int pos, int len)
{
	//�Ӵ���ΧԽ��
	if (pos + len - 1 > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}

//�Ƚϲ�������S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0
int StrCompare(SString S, SString T){
	for (int i = 1; i <= S.length&&i <= T.length; i++){
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//ɨ��������е��ַ�����ͬ���򳤶ȳ��Ĵ�����
	return S.length - T.length;
}

//��λ����������ģʽƥ���㷨
int Index(SString S, SString T){
	int i = 1, n = S.length, m = T.length; //s��������m���Ӵ�
	SString sub; //�����ݴ��Ӵ�
	while (i<=n-m+1)
	{
		SubString(sub, S, i, m);
		if (StrCompare(sub, T) != 0)
			i++;
		else
			return i; //�����ִ��������е�λ��
	}
	return 0; //S�в�������T��ȵ��Ӵ�
}