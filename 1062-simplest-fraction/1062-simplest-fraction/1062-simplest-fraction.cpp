// 1062-simplest-fraction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int gcd(int a, int b);

int main()
{
	int n1, n2, m1, m2, k, i = 1, num = 0;
	double range1, range2, result = 0.0;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	//突然担心浮点会不会有误差
	range1 = (double)n1 / m1;
	range2 = (double)n2 / m2;
	//输入的结果不一定按照原有的顺序！
	if (n1*m2 > n2*m1)
	{
		swap(n1, n2);
		swap(m1, m2);
		//	swap(range1, range2);

	}
	while (i*m2 < k*n2)
	{
		//result = (double)i / k;
		//可以互质
		//注意！这里不可以是相等的，不然测试点3过不去@。@
		if (gcd(k, i) == 1 && i * m1 > k*n1 && i*m2 < k*n2)
		{
			//符合条件的话
			//考虑怎么输出
			if (num != 0)
				cout << " ";
			cout << i << "/" << k;
			num++;
		}
		//如果不是互质的话
		i++;
	}

    return 0;
}

//有待测试
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}