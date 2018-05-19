// so-easy-4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5 - i; j++)
			printf(" ");
		for (int k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}
    return 0;
}

