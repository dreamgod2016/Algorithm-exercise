// three-number-permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "time.h"
/*
用1，2，3，…，9组成3个三位数abc，def和ghi，每个数字恰好使用一次，要
求abc：def：ghi＝1：2：3。按照“abc def ghi”的格式输出所有解，每行一个解。提示：不必
太动脑筋。
*/
int isDiff(int num);
int numbers[9] = { 0 };

int main()
{
	//第一个数字最小123，第三个数字最大329（987/3）
	for (int i = 123; i < 330 ; i++)
	{
		int sum = 0;
		if (isDiff(i) && isDiff(2*i) && isDiff(3*i))
		{
			//判断是不是符合1:2:3的关系
			for (int j = 0; j <= 9; j++)
			{
				//计算数字都出现了几次。
				if (numbers[j] == 1)
					sum++;
			}
			memset(numbers, 0, sizeof(numbers));
			if (sum == 9)
			{
				printf("%d %d %d\n", i, 2 * i, 3 * i);
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
	}
	printf("%lf", (double)clock() / CLOCKS_PER_SEC);
	getchar();
    return 0;
}

int isDiff(int num)
{
	int A = num / 100;
	int B = (num / 10) % 10;
	int C = num % 10;
	if (A!=B && B!=C && A!=C)
	{
		//A不会为0。
		numbers[A-1]++;
		numbers[B-1]++;
		numbers[C-1]++;
		return num;
	}
	else
	{
		return 0;
	}
}
