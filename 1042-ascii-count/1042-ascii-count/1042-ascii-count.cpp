// 1042-ascii-count.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��ͷ��β��ÿ������ͳ���ꡣ
	for (int i = 0; i < 26; i++)
	{
		//������У�����С�ģ��Ͳ�Ҫ���¡�
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

