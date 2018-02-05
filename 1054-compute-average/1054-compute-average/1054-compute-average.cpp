// 1054-compute-average.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <cstdio>


using namespace std;

int main()
{
	int T,cnt = 0;
	char a[50], b[50];
	double temp, sum = 0.0;
	cin >> T;
	while (T--)
	{
		cin >> a;
		//sscanf() – 从一个字符串中读进与指定格式相符的数据
		sscanf(a, "%lf", &temp);
		//sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
		sprintf(b, "%.2lf", temp);
		bool flag = false;
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] != b[i])
				flag = true;
		}
		if (flag || temp < -1000 || temp > 1000)
		{
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}
		else
		{
			sum += temp;
			cnt++;
		}

	}
	if (cnt == 1)
		printf("The average of 1 number is %.2lf", sum / cnt);
	else if (cnt > 1)
		printf("The average of %d numbers is %.2lf",cnt, sum / cnt);
	else
		printf("The average of 0 numbers is Undefined");
	return 0;
}

