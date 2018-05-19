// so-easy-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>

int main()
{
	int a, b, c, the_max;
	scanf("%d %d %d", &a, &b, &c);
	the_max = a;
	if (b > the_max)
		the_max = b;
	if (c > the_max)
		the_max = c;
	printf("%d", the_max);
    return 0;
}

