// three-number-permutation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "time.h"
/*
��1��2��3������9���3����λ��abc��def��ghi��ÿ������ǡ��ʹ��һ�Σ�Ҫ
��abc��def��ghi��1��2��3�����ա�abc def ghi���ĸ�ʽ������н⣬ÿ��һ���⡣��ʾ������
̫���Խ
*/
int isDiff(int num);
int numbers[9] = { 0 };

int main()
{
	//��һ��������С123���������������329��987/3��
	for (int i = 123; i < 330 ; i++)
	{
		int sum = 0;
		if (isDiff(i) && isDiff(2*i) && isDiff(3*i))
		{
			//�ж��ǲ��Ƿ���1:2:3�Ĺ�ϵ
			for (int j = 0; j <= 9; j++)
			{
				//�������ֶ������˼��Ρ�
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
		//A����Ϊ0��
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
