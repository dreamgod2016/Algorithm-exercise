// master-mind hints.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define maxn 25

/*
实现一个经典"猜数字"游戏。给定答案序列和用户猜的序列，统计有多少数字位置正确
（A），有多少数字在两个序列都出现过但位置不对（B）。
输入包含多组数据。每组输入第一行为序列长度n，第二行是答案序列，接下来是若干
猜测序列。猜测序列全0时该组数据结束。n=0时输入结束。
*/

int main()
{
	int num, a[maxn], b[maxn];
	int numsA[10] = { 0 }, numsB[10] = { 0 };
	while (scanf_s("%d", &num) && num)
	{
		//把待确定的输入进去,同时统计各个数字的分布
		for (int i = 0,temp; i < num; i++)
		{
			scanf_s("%d", &temp);
			a[i] = temp;
			numsA[temp]++;
		}
		//接下来循输入剩下的。
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
			//为0就跳出。
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

