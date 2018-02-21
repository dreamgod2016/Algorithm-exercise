// 1011-A+BandC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int t;
	long long a, b, c;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b >> c;
		if (a + b > c)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
    return 0;
}

