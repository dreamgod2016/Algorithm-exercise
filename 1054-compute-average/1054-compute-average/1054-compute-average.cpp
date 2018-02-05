// 1054-compute-average.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//sscanf() �C ��һ���ַ����ж�����ָ����ʽ���������
		sscanf(a, "%lf", &temp);
		//sprintf() �C �ַ�����ʽ�������Ҫ�����ǰѸ�ʽ��������д��ĳ���ַ�����
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

