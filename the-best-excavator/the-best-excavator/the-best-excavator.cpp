// the-best-excavator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int school[100005] = { 0 };
int main()
{
	int T, school_num, scores;
	scanf("%d", &T);
	while (T--)
	{
		cin >> school_num;
		cin >> scores;
		school[school_num] += scores;
	}
	scores = 0;//利用它存最大的总成绩
	for (int i = 0; i < 100005; i++)
	{
		if (school[i] > scores)
		{
			scores = school[i];
			school_num = i;
		}
		//有可能有学号一直是0，所以必须遍历到结尾。
	}
	cout << school_num << " " << scores;
    return 0;
}

