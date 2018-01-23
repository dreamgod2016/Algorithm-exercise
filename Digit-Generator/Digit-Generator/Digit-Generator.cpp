// Digit-Generator.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
���x����x�ĸ�������֮�͵õ�y����˵x��y������Ԫ������n��1��n��100000��������С
����Ԫ���޽����0�����磬n=216��121��2005ʱ�Ľ�ֱ�Ϊ198��0��1979��
*/

#include "stdafx.h"
#define maxn 10005

int main()
{
	int generator[maxn] = { 0 };
	int n = 0;
	//�����������е�����Ԫ�Ľ��
	for (int i = 0; i < maxn; i++)
	{
		int x = i, y = i;
		while (x > 0)
		{
			y += x % 10;
			x /= 10;
		}
		//����𰸵�λ����0���������ҵ��Ľ����ԭ���Ľ��С��
		if (generator[y] == 0 || i < generator[y])
			generator[y] = i;
	}
	scanf_s("%d", &n);
	printf("%d\n", generator[n]);
    return 0;
}

