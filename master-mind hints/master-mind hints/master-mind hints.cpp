// master-mind hints.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define maxn 25

/*
ʵ��һ������"������"��Ϸ�����������к��û��µ����У�ͳ���ж�������λ����ȷ
��A�����ж����������������ж����ֹ���λ�ò��ԣ�B����
��������������ݡ�ÿ�������һ��Ϊ���г���n���ڶ����Ǵ����У�������������
�²����С��²�����ȫ0ʱ�������ݽ�����n=0ʱ���������
*/

int main()
{
	int num, a[maxn], b[maxn];
	int numsA[10] = { 0 }, numsB[10] = { 0 };
	while (scanf_s("%d", &num) && num)
	{
		//�Ѵ�ȷ���������ȥ,ͬʱͳ�Ƹ������ֵķֲ�
		for (int i = 0,temp; i < num; i++)
		{
			scanf_s("%d", &temp);
			a[i] = temp;
			numsA[temp]++;
		}
		//������ѭ����ʣ�µġ�
		while (true)
		{
			int A = 0, B = 0;
			for (int i = 0,temp; i < num; i++)
			{
				scanf_s("%d", &temp);
				b[i] = temp;
				numsB[temp]++;
				if (temp == a[i])
					A++;
			}
			//Ϊ0��������
			if (b[0] == 0)
				break;
			for (int i = 0; i < 10; i++)
				B += numsA[i] < numsB[i] ? numsA[i] : numsB[i];
			printf("(%d,%d)\n", A, B - A);
			memset(numsB, 0, sizeof(numsB));
		}
		memset(numsA, 0, sizeof(numsA));


	}
	getchar();
    return 0;
}

