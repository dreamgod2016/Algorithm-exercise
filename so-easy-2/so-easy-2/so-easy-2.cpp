// so-easy-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int n, positive = 0, negative = 0, zero = 0;
	double temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &temp);
		if (temp > 0.0)
			positive++;
		else if (temp < 0.0)
			negative++;
		else
			zero++;
	}
	printf("%d %d %d", positive, negative, zero);
    return 0;
}

