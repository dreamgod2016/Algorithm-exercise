// Digit-Generator.cpp : 定义控制台应用程序的入口点。
//

/*
如果x加上x的各个数字之和得到y，就说x是y的生成元。给出n（1≤n≤100000），求最小
生成元。无解输出0。例如，n=216，121，2005时的解分别为198，0，1979。
*/

#include "stdafx.h"
#define maxn 10005

int main()
{
	int generator[maxn] = { 0 };
	int n = 0;
	//首先生成所有的生成元的结果
	for (int i = 0; i < maxn; i++)
	{
		int x = i, y = i;
		while (x > 0)
		{
			y += x % 10;
			x /= 10;
		}
		//如果答案的位置是0，或者新找到的结果比原来的结果小。
		if (generator[y] == 0 || i < generator[y])
			generator[y] = i;
	}
	scanf_s("%d", &n);
	printf("%d\n", generator[n]);
    return 0;
}

