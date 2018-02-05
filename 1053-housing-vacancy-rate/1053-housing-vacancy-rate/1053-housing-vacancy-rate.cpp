// 1053-housing-vacancy-rate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int N, D, days, may_be_vacant = 0, vacant = 0;
	double e,temp;
	cin >> N >> e >> D;
	for (int i = 0; i < N; i++)
	{
		int low_to_e = 0;
		cin >> days;
		for (int j = 0; j < days; j++)
		{
			cin >> temp;
			if (temp < e)
				low_to_e++;
		}
		if ( (2*low_to_e) > days)
			//这个规则有点奇怪-。- 这里是判断待测期有没有超过
			days > D ? vacant++ : may_be_vacant++;
	}
	double may_be_vacant_rate = (double)may_be_vacant / N *100;
	double vacant_rate = (double)vacant / N *100 ;
	printf("%.1f%% %.1f%%", may_be_vacant_rate, vacant_rate);
	return 0;
}

