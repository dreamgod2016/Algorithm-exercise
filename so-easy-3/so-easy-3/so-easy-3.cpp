// so-easy-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	long sum = 0;
	for(int n = 1; n*n <= 1000; n++)
		sum += n*n;
	printf("%ld", sum);
    return 0;
}

