// 1020-mooncake.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct mooncake
{
	float mount, price, unit;
};

bool operator < (mooncake a, mooncake b)
{
	return a.unit > b.unit;
}

int main()
{
	int n, need;
	cin >> n >> need;
	float result = 0.0;
	vector<mooncake> a(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &a[i].mount);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &a[i].price);
		a[i].unit = a[i].price / a[i].mount;
	}
	//��֪�������в���
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		//�����Ļ�
		if (a[i].mount <= need)
		{
			result += a[i].price;
		}
		else
		{
			result = result + a[i].unit*need;
			break;
		}
		need = need - a[i].mount;
	}

	printf("%.2f", result);

	return 0;
}

