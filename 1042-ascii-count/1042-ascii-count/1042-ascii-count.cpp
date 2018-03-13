// 1042-ascii-count.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string data;
	int nums[26];
	int the_max = -1, index = -1;
	memset(nums, 0, sizeof(nums));
	getline(cin, data);
	for (int i = 0; i < data.length(); i++)
	{
		data[i] = tolower(data[i]);
		if (islower(data[i]))
		{
			nums[data[i] - 'a']++;
		}
	}
	//从头到尾，每个数字统计完。
	for (int i = 0; i < 26; i++)
	{
		//如果并列，用最小的，就不要更新。
		if (nums[i] > the_max)
		{
			index = i;
			the_max = nums[i];
		}

	}
	printf("%c %d", 'a' + index, the_max);
	//cout << 'a' + index << the_max;

    return 0;
}

