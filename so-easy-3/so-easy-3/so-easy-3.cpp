// so-easy-3.cpp : �������̨Ӧ�ó������ڵ㡣
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

