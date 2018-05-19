// so-easy-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <math.h>
int isShuiXian(int n)
{
	int sum = 0, num = n;
	for (int i = 0; i < 3; i++)
	{
		sum = sum + pow(num % 10, 3);
		num = num / 10;
	}
	if (sum == n)
		return 1;
	else
		return 0;
}
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		if (isShuiXian(i))
			printf("%d\n", i);
	}
    return 0;
}

